/*
 * btu.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_BTU_H_
#define INC_BTU_H_

#include "i2c.h"
#include "fault.h"
#include "power.h"
#include "util.h"
#include "vehicleid.h"

// 1 = OVERRIDE, BYPASS BTU fault protection
// 0 = Listen to BTU fault protection
#define BTU_FAULT_OVERIDE 0

#define BTU_TEMP_DIV	10
#define BTU_TEMP_OFFSET -273

// Forward declaration
class BTU;

extern BTU battery;


// Smart Battery Defines
#define CELL_ADDRESS            (0x0B << 1)		// Smart Battery Cell Address

#define MANUFACTURERACCESS      0x00    // Manufacturer specific
#define REMAININGCAPACITYALARM  0x01    // First level near end of discharge
#define REMAININGTIMEALARM      0x02    // Set remaining time alarm
#define BATTERYMODE             0x03    // Configuration
#define ATRATE                  0x04    // Two-function call-set for rate calc
#define ATRATETIMETOFULL        0x05    // Time to Full
#define ATRATETIMETOEMPTY       0x06    // Time to Empty
#define ATRATEOK                0x07    // Test if energy is available for 10sec
#define TEMPERATURE             0x08    // Cell temperature (Kelvin)
#define VOLTAGE                 0x09    // Cell voltage (mV)
#define CURRENT                 0x0A    // Cell current (mA)
#define AVERAGECURRENT          0x0B    // Cell average current (mA)
#define MAXERROR                0x0C    // Percent margin of error in charge (%)
#define RELATIVESTATEOFCHARGE   0x0D    // Relative remaining cell capacity (%)
#define ABSOLUTESTATEOFCHARGE   0x0E    // Absolute remaining cell capacity (%)
#define REMAININGCAPACITY       0x0F    // Remaining capacity (mAh or 10mWh)
#define FULLCHARGECAPACITY      0x10    // Predicted full capacity(mAh or 10mWh)
#define RUNTIMETOEMPTY          0x11    // Present operation time left (mins)
#define AVERAGETIMETOEMPTY      0x12    // Average operation time left (mins)
#define AVERAGETIMETOFULL       0x13    // Average time left until full (mins)
#define BATTERYSTATUS           0x16    // Battery status with alarm codes
#define CYCLECOUNT              0x17    // Number of cycles on the battery
#define DESIGNCAPACITY          0x18    // Theoretical capacity of the cell
#define DESIGNVOLTAGE           0x19    // Theoretical voltage of the cell (mV)
#define SPECIFICATIONINFO       0x1A    // Rev, Version, Vscale, IPScale
#define MANUFACTUREDATE         0x1B    // Date Manufactured
#define SERIALNUMBER            0x1C    // Serial Number
#define MANUFACTURERNAME        0x20    // Manufacturer Name
#define DEVICENAME              0x21    // Device Name
#define DEVICECHEMISTRY         0x22    // Device Chemistry
#define MANUFACTURERDATA        0x23    // Reserved for manufacturer

#define BATTERY_VOLTAGE_ALARM_THRES		19000.0f	// Battery Voltage Alarm Threshold
#define BATTERY_VOLTAGE_CRITICAL_THRES	18500.0f	// Battery Voltage Fault Threshold
#define BATTERY_VOLTAGE_MIN_THRES		1000.0f		// Battery Voltage Minimum Threshold

#define BATTERY_SOC_ALARM_THRES			15.0f	// Battery SoC Alarm Threshold
#define BATTERY_SOC_CRITICAL_THRES		10.0f	// Battery SoC Alarm Threshold
#define BATTERY_SOC_MIN_THRES			1.0f	// Battery SoC Minimum Threshold

#define BATTERY_HUSKY_LEADACID_MIN_THRES 		20.5f	// Husky Lead Acid Battery Min Volt Threshold
#define BATTERY_HUSKY_LIPO_MIN_THRES 			21.5f	// Husky Battery Min Volt Threshold

#define BATTERY_HUSKY_MIN_THRES 		BATTERY_HUSKY_LEADACID_MIN_THRES

#define ALARM_MSG_DELAY		1000	   // Time (ms)

struct Cell
{
   int32_t voltage;                    // Voltage (mV)
   int32_t current;                    // Current (mA)
   int32_t temperature;                // Temperature (C)
   int32_t remainingcharge;            // Remaining Charge (mAh)
   int32_t percentcharge;              // Percent Charge (%)
};

enum BatteryAlarm {
	NoAlarm = 0,
	LowBatteryAlarm,
	Bb2590LossOfSignal
};

extern BatteryAlarm battery_alarm_status_;

class BTU {
public:

	// Class constructor
	BTU(void);

	virtual ~BTU();

	// Initialization function
	void Init(void);

	// Query BB2590 State
	Fault Update(void);

	// Returns voltage in mV
	int32_t getVoltage(void);

	// Returns current in mA
	int32_t getCurrent(void);

	// Returns temperature in C
	int32_t getTemperature(void);

	// Returns remaining capacity in mAh
	int32_t getRemainingCapacity(void);

	// Returns relative state of charge in %
	int32_t getRelativeSOC(void);

	// Returns the battery alarm status
	BatteryAlarm getBatteryAlarmStatus(void);

	// Returns the battery fault status
	Fault getBatteryFaultStatus(void);

	// Returns true if we have lost telemetry from the battery
	bool isLOS(void);

	// Return Battery SoC Alarm Status for ROS
	bool getRosAlarmStatus(void);

	// Print Battery Alarm Status
	void printAlarmStatus(void);

private:

	BatteryAlarm bb2590_alarm_status_;
	Fault bb2590_fault_status_;
	Cell bb2590_;

	bool bb2590_present_at_boot_;
	uint8_t bb2590_timeout_count_;

	// Timeouts
	unsigned long btu_time_last_message_ = 0;
	unsigned long btu_timeout_period_ = 60000;	// 60 seconds

	unsigned long bb2590_recovery_counter_ = 0;
	unsigned long bb2590_recovery_wait_period_ = 6000; // 6 seconds
};


#endif /* INC_BTU_H_ */
