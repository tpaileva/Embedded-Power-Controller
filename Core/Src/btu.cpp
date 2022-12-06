/*
 * btu.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#include "btu.h"

BTU battery;

BTU::BTU()
{

}

// TODO: Destructor
BTU::~BTU() {}

void BTU::Init()
{
	// Initialize the I2C peripheral
	I2c1.Init();
	I2c2.Init();

	// Clear alarm status
	bb2590_alarm_status_ = NoAlarm;

	// Clear fault status
	bb2590_fault_status_.Init(NoFault, Nominal);

	// Clear BB2590 timeout counter
	bb2590_timeout_count_ = 0;

	// Initialize battery telemetry values
	bb2590_.voltage = 0;
	bb2590_.current = 0;
	bb2590_.temperature = 0;
	bb2590_.remainingcharge = 0;
	bb2590_.percentcharge = 0;

	// Reset the bb2590 recovery counter
	bb2590_recovery_counter_ = 0;

	// Delay to allow the system initialize
	Delay(50);

	// Attempt to read SOC five times as a method of checking if a BB2590 is connected and present at boot
	bb2590_present_at_boot_ = false;	// Default: No BB2590 present

	for (int i = 0; i < 5; i++) {
		// Create array for received data
		uint8_t received_data[2];

		if (I2c1.RegRead(RELATIVESTATEOFCHARGE, received_data, CELL_ADDRESS, 2) == kI2cSuccess) {
			// BB2590 Found!
			bb2590_present_at_boot_ = true;
			break;
		}
		Delay(50);
	}

}

Fault BTU::Update()
{
	Fault btu_status;
	btu_status.Init(NoFault, Nominal);

	// Create array for received data
	uint8_t received_data[2];

	// BB2590 Timeout Handler
	if (bb2590_timeout_count_ != 0) {

		// If we are timed out, keep resetting the I2C and attempt a read after a few seconds, but before the LOS timeout
		if ( (GetTicks() - bb2590_recovery_counter_) > bb2590_recovery_wait_period_)
		{
			bb2590_timeout_count_ = (I2c1.RegRead(RELATIVESTATEOFCHARGE, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;

			bb2590_recovery_counter_ = GetTicks();
		}
		else {
			// If we are timing out, reset the I2C interface in an attempt to recover
			I2c1.Init();
		}

		// Limit the timeout counter to prevent overflow conditions
		if (bb2590_timeout_count_ > 100) {
			bb2590_timeout_count_ = 100;
		}
	}
	// If we are not timed out, read telemetry
	else {
		// Read Voltage - UNITS: mV
		bb2590_timeout_count_ = (I2c1.RegRead(VOLTAGE, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;
		// Since we only measure one section of the BB2590 via SMBus, we assume the adjacent section within the pack
		// is at a similar voltage, so we multiply the voltage by 2 because the BB2590 Battery Hat connects the two sections in series
		if (bb2590_timeout_count_ == 0) {	// Only update if we are clear of timeouts
			bb2590_.voltage = (int32_t)( 2 * (((uint32_t)received_data[1] << 8) + received_data[0]) );
			btu_time_last_message_ = GetTicks();
		}

		// Read Current - UNITS: mA
		bb2590_timeout_count_ = (I2c1.RegRead(CURRENT, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;
		if (bb2590_timeout_count_ == 0) {	// Only update if we are clear of timeouts
			bb2590_.current = (int32_t)(((uint32_t)received_data[1] << 8) + received_data[0]);
			btu_time_last_message_ = GetTicks();
		}

		// Read Temperature - UNITS: C
		bb2590_timeout_count_ = (I2c1.RegRead(TEMPERATURE, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;
		if (bb2590_timeout_count_ == 0) {	// Only update if we are clear of timeouts
			bb2590_.temperature = (((uint32_t)received_data[1] << 8) + received_data[0])/BTU_TEMP_DIV + BTU_TEMP_OFFSET;
			btu_time_last_message_ = GetTicks();
		}

		// Read Remaining Charge - UNITS: mAh
		bb2590_timeout_count_ = (I2c1.RegRead(REMAININGCAPACITY, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;
		if (bb2590_timeout_count_ == 0) {	// Only update if we are clear of timeouts
			bb2590_.remainingcharge = (int32_t)(((uint32_t)received_data[1] << 8) + received_data[0]);
			btu_time_last_message_ = GetTicks();
		}

		// Read SoC - UNITS: %
		bb2590_timeout_count_ = (I2c1.RegRead(RELATIVESTATEOFCHARGE, received_data, CELL_ADDRESS, 2) != kI2cSuccess) ? bb2590_timeout_count_ + 1 : 0;
		if (bb2590_timeout_count_ == 0) {	// Only update if we are clear of timeouts
			bb2590_.percentcharge = (int32_t)(((uint32_t)received_data[1] << 8) + received_data[0]);
			btu_time_last_message_ = GetTicks();
		}
	}

	return btu_status;
}

int32_t BTU::getVoltage()
{
	return bb2590_.voltage;
}

int32_t BTU::getCurrent()
{
	return bb2590_.current;
}

int32_t BTU::getTemperature()
{
	return bb2590_.temperature;
}

int32_t BTU::getRemainingCapacity()
{
	return bb2590_.remainingcharge;
}

int32_t BTU::getRelativeSOC()
{
	return bb2590_.percentcharge;
}


BatteryAlarm BTU::getBatteryAlarmStatus()
{
	int32_t bb2590_voltage = getVoltage();
	int32_t bb2590_soc = getRelativeSOC();

	// Check Battery SOC and Voltage for alarm conditions

	// If the input power is not GSE powered, run alarm logic
	if ( !(PowerSystem.isGsePowered()) && BTU_FAULT_OVERIDE == 0) {

		// If the vehicle is a Spot
		if (VehID.GetVehicleType() == kSpot) {
			// If battery failed to communicate, Loss of Signal (LOS), raise an alarm
			if ( isLOS() ) {
				bb2590_alarm_status_ = Bb2590LossOfSignal;
			}
			// If battery voltages are out of range, throw an alarm
			else if (  (bb2590_voltage <= BATTERY_VOLTAGE_ALARM_THRES || bb2590_soc <= BATTERY_SOC_ALARM_THRES)
					&& (BATTERY_VOLTAGE_MIN_THRES < bb2590_voltage && BATTERY_SOC_MIN_THRES < bb2590_soc )
					&& !isLOS() ) {
				bb2590_alarm_status_ = LowBatteryAlarm;
			}
			else {
				bb2590_alarm_status_ = NoAlarm;
			}
		}
		// If the vehicle is not a Spot, it's a Husky (or another robot with no BMS)
		else {

			if (PowerSystem.GetVoltage(PowerRail::VinLogicSw) <= BATTERY_HUSKY_MIN_THRES)
			{
				bb2590_alarm_status_ = LowBatteryAlarm;
			}
			else {
				bb2590_alarm_status_ = NoAlarm;
			}
		}
	}
	else {
		bb2590_alarm_status_ = NoAlarm;
	}

	return bb2590_alarm_status_;
}

Fault BTU::getBatteryFaultStatus()
{
	int32_t bb2590_voltage = getVoltage();
	int32_t bb2590_soc = getRelativeSOC();

	// If the input power is not GSE powered, run alarm logic
	if( !(PowerSystem.isGsePowered()) && BTU_FAULT_OVERIDE == 0 ) {

		// If the vehicle is a Spot
		if (VehID.GetVehicleType() == kSpot) {
			// Check Battery SOC and Voltage for fault conditions
			if (   (bb2590_voltage <= BATTERY_VOLTAGE_CRITICAL_THRES || bb2590_soc <= BATTERY_SOC_CRITICAL_THRES)
				&& (BATTERY_VOLTAGE_MIN_THRES < bb2590_voltage && BATTERY_SOC_MIN_THRES < bb2590_soc )
				&& !isLOS() ) {
				bb2590_fault_status_.setFaultState(BatterySocCritical, Fatal);
			}
		}
		// If the vehicle is not a Spot, it's a Husky (or another robot with no BMS)
		else {
			// Husky does not have battery telemetry, so we do not hard fault.
			// Instead, we rely on the Battery BMS UVP
		}
	}
	else {
		bb2590_fault_status_.setFaultState(NoFault, Nominal);
	}

	return bb2590_fault_status_;
}

bool BTU::isLOS()
{
	// Returns true if we have lost telemetry from the battery
	if ( (GetTicks() - btu_time_last_message_) > btu_timeout_period_ )
	{
		// Reset all telemetry values
		bb2590_.voltage = 0;
		bb2590_.current = 0;
		bb2590_.temperature = 0;
		bb2590_.remainingcharge = 0;
		bb2590_.percentcharge = 0;

		return true;  // True, we have loss of signal from the BTU
	}
	else
	{
		return false; // False, we are actively communicating with the BTU
	}

	return true;	  // Default to true (unreachable)
}

bool BTU::getRosAlarmStatus()
{
	bool battery_soc_alarm = true;

	if (bb2590_alarm_status_ == LowBatteryAlarm) {
		battery_soc_alarm = true;
	}
	else if (bb2590_alarm_status_ == NoAlarm) {
		battery_soc_alarm = false;
	}

	return battery_soc_alarm;
}

void BTU::printAlarmStatus(void) {

	switch (bb2590_alarm_status_) {
		case NoAlarm:
			Serial.WriteString("[ ALARM ] - BTU - No Alarm\r\n");
			break;
		case LowBatteryAlarm:
			Serial.WriteString("[ ALARM ] - Low Battery\r\n");
			break;
		case Bb2590LossOfSignal:
			Serial.WriteString("[ ALARM ] - BTU Loss of Signal\r\n");
			break;
		default:
			Serial.WriteString("[ ALARM ] - Unreachable State...\r\n");
			break;
	}

}
