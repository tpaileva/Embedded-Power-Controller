/*
 * fault.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_FAULT_H_
#define INC_FAULT_H_

#include <string>
#include "util.h"


#define FAULT_MSG_DELAY		1000	// Time (ms)

enum FaultState
{
	NoFault,

	LogicOverVoltage,
	LogicUnderVoltage,

	LogicSwOverVoltage,
	LogicSwUnderVoltage,

	V5BusOverVoltage,
	V5BusUnderVoltage,

	V12BusOverVoltage,
	V12BusUnderVoltage,

	V17BusOverVoltage,
	V17BusUnderVoltage,

	MotorOverVoltage,
	MotorUnderVoltage,

	LogicSwOverCurrent,
	LogicSwUnderCurrent,

	MotorOverCurrent,
	MotorUnderCurrent,

	VehicleTypeOvervolt,
	VehicleTypeInvalid,

	BatterySocCritical,
	BatteryLossOfSignal,

	EstopSystemFault,

	XBeeTimedOut,

	PowerSwitchDisable
};

enum FaultSeverity
{
	Nominal,
	Critical,
	Fatal
};

class Fault;

extern Fault fault_status_;

class Fault {
public:
	Fault(void){};
	void Init(void);
	void Init(FaultState setState, FaultSeverity setSeverity);

	FaultState getFaultState();
	FaultSeverity getFaultSeverity();
	void setFaultState(FaultState setState, FaultSeverity setSeverity);

	bool isFaulted();

	std::string faultString();
	std::string printFault();
	std::string printSeverity();

private:
	FaultState state;
	FaultSeverity severity;

};

#endif /* INC_FAULT_H_ */
