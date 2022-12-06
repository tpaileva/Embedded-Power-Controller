/*
 * power.cpp
 *
 *	Author: T. Pailevanian
 *	Co Author: A. Kourchians
 */

#include "power.h"

Power PowerSystem;

Switch pwr_sw;

//------------------------------------------------------------------//
//     						  Power Class							//
//------------------------------------------------------------------//

Power::Power() {

	status_.Init(NoFault, Nominal);

}


// TODO: Destructor
Power::~Power(){}


void Power::Init() {

	// Turn Off Regulators
	enable_17v.SetBit(0);
	enable_12v.SetBit(0);
	enable_5v.SetBit(0);
	load_en_logic.SetBit(0);

	// Disable Load Switches
	load_en_lidar4.SetBit(0);
	load_en_lidar3.SetBit(0);
	load_en_lidar2.SetBit(0);
	load_en_lidar1.SetBit(0);

	load_en_17v.SetBit(0);
	load_en_12v.SetBit(0);
	load_en_5v.SetBit(0);

	load_en_24v_3.SetBit(0);
	load_en_24v_2.SetBit(0);
	load_en_24v_1.SetBit(0);


	// Initialize ADC pins
	vsense_logic_.Init(VSENSE_LOGIC_GPIO_Port, VSENSE_LOGIC_Pin,
						VSENSE_LOGIC_Adc, VSENSE_LOGIC_Adc_Channel, 15.667, 0, 10000, 0);

	vsense_logic_sw_.Init(VSENSE_LOGIC_SW_GPIO_Port, VSENSE_LOGIC_SW_Pin,
						VSENSE_LOGIC_SW_Adc, VSENSE_LOGIC_SW_Adc_Channel, 15.667, 0, 10000, 0);

	vsense_17v_.Init(VSENSE_17V_GPIO_Port, VSENSE_17V_Pin,
						VSENSE_17V_Adc, VSENSE_17V_Adc_Channel, 15.667, 0, 10000, 0);

	vsense_12v_.Init(VSENSE_12V_GPIO_Port, VSENSE_12V_Pin,
						VSENSE_12V_Adc, VSENSE_12V_Adc_Channel, 15.667, 0, 10000, 0);

	vsense_5v_.Init(VSENSE_5V_GPIO_Port, VSENSE_5V_Pin,
						VSENSE_5V_Adc, VSENSE_5V_Adc_Channel, 15.667, 0, 10000, 0);

	vsense_motor_.Init(VSENSE_MOTOR_GPIO_Port, VSENSE_MOTOR_Pin,
						VSENSE_MOTOR_Adc, VSENSE_MOTOR_Adc_Channel, 15.667, 0, 10000, 0);

	isense_logic_.Init(ISENSE_LOGIC_GPIO_Port, ISENSE_LOGIC_Pin,
						ISENSE_LOGIC_Adc, ISENSE_LOGIC_Adc_Channel, 16.0, 0, 10000, 0);

	isense_motor_.Init(ISENSE_MOTOR_GPIO_Port, ISENSE_MOTOR_Pin,
						ISENSE_MOTOR_Adc, ISENSE_MOTOR_Adc_Channel, 8.0, 0, 10000, 0);

	// Configure Power Switch
	pwr_sw.Init(POWER_SWITCH_GPIO_Port, POWER_SWITCH_Pin, kGpioPullOff);
}


float Power::GetVoltage(PowerRail rail) {

	if(rail == PowerRail::VinLogic) {
		return vsense_logic_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::VinLogicSw) {
		return vsense_logic_sw_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::Reg_5v) {
		return vsense_5v_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::Reg_12v) {
		return vsense_12v_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::Reg_17v) {
		return vsense_17v_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::VinMotor) {
		return vsense_motor_.GetFilteredCorrectedValue();
	}

	// Else return a bogus voltage for fault protection to handle
	return -100.0f;
}

Fault Power::CheckVoltageRail(PowerRail rail) {

	float range_min, range_max, measured_voltage;

	switch(rail) {
		case PowerRail::VinLogic:

			// Vin input voltage is flexible. Assign a large input range
			range_min = VLOGIC_VMIN;
			range_max = VLOGIC_VMAX;

			measured_voltage = vsense_logic_.GetFilteredCorrectedValue();

			status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, LogicOverVoltage, LogicUnderVoltage);
			if (status_.getFaultState() != NoFault) return status_;

			break;

		case PowerRail::VinLogicSw:

			// TODO: Modify voltage ranges based on config switches

			// Vin input voltage is flexible. Assign a large input range
			range_min = VLOGIC_VMIN;
			range_max = VLOGIC_VMAX;

			measured_voltage = vsense_logic_sw_.GetFilteredCorrectedValue();

			status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, LogicSwOverVoltage, LogicSwUnderVoltage);
			if (status_.getFaultState() != NoFault) return status_;

			break;

		case PowerRail::Reg_5v:

			// Check that regulator range is within 10%
			range_min = V5BUS_VMIN;
			range_max = V5BUS_VMAX;

			measured_voltage = vsense_5v_.GetFilteredCorrectedValue();

			status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, V5BusOverVoltage, V5BusUnderVoltage);
			if (status_.getFaultState() != NoFault) return status_;

			break;

		case PowerRail::Reg_12v:

			// Check that regulator range is within 10%
			range_min = V12BUS_VMIN;
			range_max = V12BUS_VMAX;

			measured_voltage = vsense_12v_.GetFilteredCorrectedValue();

			status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, V12BusOverVoltage, V12BusUnderVoltage);
			if (status_.getFaultState() != NoFault) return status_;

			break;

		case PowerRail::Reg_17v:

			// Check that regulator range is within range
			//	17V can dip if the input voltage gets too close to 18 so we will be flexible on the lower range
			range_min = V17BUS_VMIN;
			range_max = V17BUS_VMAX;

			measured_voltage = vsense_17v_.GetFilteredCorrectedValue();

			status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, V17BusOverVoltage, V17BusUnderVoltage);
			if (status_.getFaultState() != NoFault) return status_;

			break;

		case PowerRail::VinMotor:

			// Vin Motor input voltage is flexible. Assign a large input range
			range_min = VMOTOR_VMIN;
			range_max = VMOTOR_VMAX;

			measured_voltage = vsense_motor_.GetFilteredCorrectedValue();

			if (!isGsePowered() ) {
				status_ = CheckVoltageInRange(range_min, range_max, measured_voltage, MotorOverVoltage, MotorUnderVoltage);
			}
			if (status_.getFaultState() != NoFault) return status_;

			break;

		default:

			break;
	}

	status_.setFaultState(NoFault, Nominal);
	return status_;

}

Fault Power::CheckVoltageInRange(float range_min, float range_max, float measured_voltage, FaultState overvoltage, FaultState undervoltage) {

	Fault voltage_status;
	voltage_status.Init(NoFault, Nominal);

	if(measured_voltage < range_min) {
		if (_power_debug) { Serial.WriteString("[ POWER ] - Vexp_min: %.2f , Vmeas: %.2f\r\n", range_min, measured_voltage); }
		voltage_status.setFaultState(undervoltage, Critical);
		Delay(25);
		return voltage_status;
	}
	else if ( measured_voltage > range_max ) {
		if (_power_debug) { Serial.WriteString("[ POWER ] - Vexp_max: %.2f , Vmeas: %.2f\r\n", range_max, measured_voltage); }
		voltage_status.setFaultState(overvoltage, Fatal);
		return voltage_status;
	}
	else {
		return voltage_status;
	}

}

Fault Power::CheckInputVoltageForVehicleType(void) {

	float measured_voltage = vsense_logic_.GetFilteredCorrectedValue();

	switch ( VehID.GetVehicleType() ) {

		case kHusky:
			if(measured_voltage > HUSKY_VMAX) {
				// Voltage exceeds Husky's maximum input voltage
				status_.setFaultState(VehicleTypeOvervolt, Fatal);
				return status_;
			}
			break;

		case kSpot:
			if(measured_voltage > SPOT_VMAX) {
				// Voltage exceeds Spot's maximum input voltage
				status_.setFaultState(VehicleTypeOvervolt, Fatal);
				return status_;
			}
			break;

		default:
			// Invalid vehicle type configuration
			status_.setFaultState(VehicleTypeInvalid, Fatal);
			return status_;
			break;
	}

	status_.setFaultState(NoFault, Nominal);
	return status_;
}


float Power::GetCurrent(PowerRail rail) {

	if(rail == PowerRail::VinLogicSw) {
		return isense_logic_.GetFilteredCorrectedValue();
	} else if (rail == PowerRail::VinMotor) {
		return isense_motor_.GetFilteredCorrectedValue();
	}

	// Else return a bogus current for fault protection to handle
	return -100.0f;
}


Fault Power::CheckCurrentRail(PowerRail rail) {

	float measured_current = -1000.0f;

	switch ( rail ) {

		// Check Logic Current
		case (PowerRail::VinLogicSw):
			measured_current = GetCurrent(PowerRail::VinLogicSw);

			if(measured_current < ILOGIC_IMIN) {
				if (_power_debug) { Serial.WriteString("[ POWER ] - Iexp_min: %.2f , Imeas: %.2f\r\n", ILOGIC_IMIN, measured_current); }
				Delay(25);
				status_.setFaultState(LogicSwUnderCurrent, Critical);
				return status_;
			}
			else if ( measured_current > ILOGIC_IMAX ) {
				if (_power_debug) { Serial.WriteString("[ POWER ] - Iexp_max: %.2f , Imeas: %.2f\r\n", ILOGIC_IMAX, measured_current); }
				Delay(25);
				status_.setFaultState(LogicSwOverCurrent, Critical);
				return status_;
			}
			else {
				status_.setFaultState(NoFault, Nominal);
				return status_;
			}
			break;

		// Check Motor Current
		case (PowerRail::VinMotor):
			measured_current = GetCurrent(PowerRail::VinMotor);

			if(measured_current < IMOTOR_IMIN) {
				if (_power_debug) { Serial.WriteString("[ POWER ] - Iexp_min: %.2f , Imeas: %.2f\r\n", IMOTOR_IMIN, measured_current); }
				Delay(25);
				status_.setFaultState(MotorUnderCurrent, Critical);
				return status_;
			}
			else if ( measured_current > IMOTOR_IMAX ) {
				if (_power_debug) { Serial.WriteString("[ POWER ] - Iexp_max: %.2f , Imeas: %.2f\r\n", IMOTOR_IMAX, measured_current); }
				Delay(25);
				status_.setFaultState(MotorOverCurrent, Critical);
				return status_;
			}
			else {
				status_.setFaultState(NoFault, Nominal);
				return status_;
			}
			break;

		// Fall through case
		default:

			break;

	}

	status_.setFaultState(NoFault, Nominal);
	return status_;
}


// Checks all voltage and current rails.
// CAUTION: This function can only be called AFTER PowerUp and BEFORE PowerDown
Fault Power::CheckAllRails(void) {

	// Check input voltage for vehicle type overvolt
	if (CheckInputVoltageForVehicleType().getFaultState() != NoFault) return status_;

	// Check input voltage
	if (CheckVoltageRail(PowerRail::VinLogic).getFaultState() != NoFault) return status_;

	// Check logic voltage
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultState() != NoFault) return status_;
	// Check output logic current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultState() != NoFault) return status_;

	// Check 5V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_5v).getFaultState() != NoFault) return status_;

	// Check 12V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultState() != NoFault) return status_;

	// Check 17V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_17v).getFaultState() != NoFault) return status_;

	// If the vehicle is a Husky
	if (VehID.GetVehicleType() == kHusky) {
		// Check logic voltage
		if (CheckVoltageRail(PowerRail::VinMotor).getFaultState() != NoFault) return status_;
		// Check Motor Current
		if (CheckCurrentRail(PowerRail::VinMotor).getFaultState() != NoFault) return status_;
	}

	return status_;
}

bool Power::isGsePowered(void) {
	if (   (VehID.GetVehicleType() == kHusky && PowerSystem.GetVoltage(PowerRail::VinLogicSw) >=  HUSKY_VGSE)
		 || (VehID.GetVehicleType() == kSpot && PowerSystem.GetVoltage(PowerRail::VinLogicSw) >= SPOT_VGSE) ) {
		return true;
	}
	else {
		return false;
	}

}


Fault Power::PowerUp() {

	if (_power_debug) { Serial.WriteString("[ POWER ] - Power Up Initiated\r\n"); }

	// Wait 5 Seconds
	if (MonitoredDelay(5000).getFaultSeverity() == Fatal) return status_;

	// Main Load On
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting Main Load\r\n"); }
	// Safety check the input voltage against the maximum operating voltage for the vehicle type
	if (CheckInputVoltageForVehicleType().getFaultSeverity() == Fatal) return status_;
	// Check input logic voltage prior to enable Vin Logic
	if (CheckVoltageRail(PowerRail::VinLogic).getFaultSeverity() == Fatal) return status_;
	// Enable the main load
	load_en_logic.SetBit(1);
	if (_power_debug) { Serial.WriteString("[ POWER ] - Main Load Enabled\r\n"); }
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check output logic voltage prior to enabling load switches
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	// Check output logic current prior to enabling load switches
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;

	if (_power_debug) { Serial.WriteString("[ POWER ] - Main Load Cycling\r\n"); }

	load_en_logic.SetBit(0);
	if (MonitoredDelay(5000).getFaultSeverity() == Fatal) return status_;
	load_en_logic.SetBit(1);
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check output logic voltage prior to enabling load switches
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	// Check output logic current prior to enabling load switches
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;

	if (_power_debug) { Serial.WriteString("[ POWER ] - Main Load Enabled\r\n"); }

	// 24V Load Switch Enable
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 24V Load SW 1\r\n"); }
	load_en_24v_1.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check logic voltage and current for fault
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 24V Load SW 1 Enabled\r\n"); }

	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 24V Load SW 2\r\n"); }
	load_en_24v_2.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check logic voltage and current for fault
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 24V Load SW 2 Enabled\r\n"); }

	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 24V Load SW 3\r\n"); }
	load_en_24v_3.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check logic voltage and current for fault
	if (CheckVoltageRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 24V Load SW 3 Enabled\r\n"); }
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;


	// Enable 5V Regulator
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 5V Regulator\r\n"); }
	enable_5v.SetBit(1);
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check 5V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_5v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 5V Regulator Enabled\r\n"); }

	// Enable 12V Regulator
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 12V Regulator\r\n"); }
	enable_12v.SetBit(1);
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 12V Regulator Enabled\r\n"); }

	// Enable 17V Regulator
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 17V Regulator\r\n"); }
	enable_17v.SetBit(1);
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check 17V Regulator output
	if (CheckVoltageRail(PowerRail::Reg_17v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 17V Regulator Enabled\r\n"); }

	// Enable 5V Load
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 5V Load SW\r\n"); }
	load_en_5v.SetBit(1);
	if (MonitoredDelay(1000).getFaultSeverity() == Fatal) return status_;
	// Check 5V Regulator output after switching on the load
	if (CheckVoltageRail(PowerRail::Reg_5v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 5V Load SW Enabled\r\n"); }

	// Enable 12V Load
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 12V Load SW\r\n"); }
	load_en_12v.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output after switching on the load
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 12V Load SW Enabled\r\n"); }

	// Enable 17V Load
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting 17V Load SW\r\n"); }
	load_en_17v.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 17V Regulator output after switching on the load
	if (CheckVoltageRail(PowerRail::Reg_17v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - 17V Load SW Enabled\r\n"); }

	// Enable LIDAR 1
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting LIDAR 1 Load SW\r\n"); }
	load_en_lidar1.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output after switching on LIDAR 1
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - LIDAR 1 Load SW Enabled\r\n"); }

	// Enable LIDAR 2
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting LIDAR 2 Load SW\r\n"); }
	load_en_lidar2.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output after switching on LIDAR 1
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - LIDAR 2 Load SW Enabled\r\n"); }

	// Enable LIDAR 3
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting LIDAR 3 Load SW\r\n"); }
	load_en_lidar3.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output after switching on LIDAR 1
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - LIDAR 3 Load SW Enabled\r\n"); }

	// Enable LIDAR 4
	if (_power_debug) { Serial.WriteString("[ POWER ] - Starting LIDAR 4 Load SW\r\n"); }
	load_en_lidar4.SetBit(1);
	if (MonitoredDelay(100).getFaultSeverity() == Fatal) return status_;
	// Check 12V Regulator output after switching on LIDAR 1
	if (CheckVoltageRail(PowerRail::Reg_12v).getFaultSeverity() == Fatal) return status_;
	// Check Logic Current
	if (CheckCurrentRail(PowerRail::VinLogicSw).getFaultSeverity() == Fatal) return status_;
	if (_power_debug) { Serial.WriteString("[ POWER ] - LIDAR 4 Load SW Enabled\r\n"); }

	// If the vehicle is a Husky
	if (VehID.GetVehicleType() == kHusky) {
		// Check Motor Current
		if (_power_debug) { Serial.WriteString("[ POWER ] - Checking Motor Bus\r\n"); }
		if (CheckCurrentRail(PowerRail::VinMotor).getFaultSeverity() == Fatal) return status_;
		if (_power_debug) { Serial.WriteString("[ POWER ] - Motor Bus Nominal\r\n"); }
	}

	status_.setFaultState(NoFault, Nominal);
	return status_;
}

Fault Power::PowerDown() {

	if (_power_debug) { Serial.WriteString("[ POWER ] - Powering Down...\r\n"); }

	// Turn Off Regulators
	enable_17v.SetBit(0);
	Delay(10);

	enable_12v.SetBit(0);
	Delay(10);

	enable_5v.SetBit(0);
	Delay(10);

	load_en_logic.SetBit(0);
	Delay(10);


	// Disable Load Switches
	load_en_lidar4.SetBit(0);
	Delay(10);

	load_en_lidar3.SetBit(0);
	Delay(10);

	load_en_lidar2.SetBit(0);
	Delay(10);

	load_en_lidar1.SetBit(0);
	Delay(10);

	load_en_17v.SetBit(0);
	Delay(10);

	load_en_12v.SetBit(0);
	Delay(10);

	load_en_5v.SetBit(0);
	Delay(10);

	load_en_24v_3.SetBit(0);
	Delay(10);

	load_en_24v_2.SetBit(0);
	Delay(10);

	load_en_24v_1.SetBit(0);
	Delay(10);

	return status_;
}

Fault Power::MonitoredDelay(uint32_t Delay)
{

	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = Delay;

	/* Add a freq to guarantee minimum wait */
	if (wait < HAL_MAX_DELAY)
	{
	wait += (uint32_t)(uwTickFreq);
	}

	while((HAL_GetTick() - tickstart) < wait)
	{
		if (PowerSystem.getPowerSwitchState() == 1) {
			status_.setFaultState(PowerSwitchDisable, Nominal);
			break;
		}
	}

	return status_;
}

void Power::ResetFaultState(void) {

	status_.setFaultState(NoFault, Nominal);

}

bool Power::getPowerSwitchState(void) {

	pwr_sw.Debounce();

	return pwr_sw.GetState();
}
