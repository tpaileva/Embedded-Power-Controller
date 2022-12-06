/*
 * fault.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */


#include "fault.h"
#include "uart.h"

void Fault::Init() {
	state = NoFault;
	severity = Nominal;

}

void Fault::Init(FaultState setState, FaultSeverity setSeverity) {
	state = setState;
	severity = setSeverity;

}

FaultState Fault::getFaultState() {
	return state;
}

FaultSeverity Fault::getFaultSeverity() {
	return severity;
}

void Fault::setFaultState(FaultState setState, FaultSeverity setSeverity) {
	state = setState;
	severity = setSeverity;
}

bool Fault::isFaulted(void) {
	if (state != NoFault) {
		return true;
	}
	else {
		return false;
	}
}

std::string Fault::printFault(void) {

	std::string str = "";

	switch (state) {
		case NoFault: 				str += "NoFault";				break;
		case LogicOverVoltage:		str += "LogicOverVoltage";		break;
		case LogicUnderVoltage:		str += "LogicUnderVoltage";		break;
		case LogicSwOverVoltage:	str += "LogicSwOverVoltage";	break;
		case LogicSwUnderVoltage:	str += "LogicSwUnderVoltage";	break;
		case V5BusOverVoltage:		str += "V5BusOverVoltage";		break;
		case V5BusUnderVoltage:		str += "V5BusUnderVoltage";		break;
		case V12BusOverVoltage:		str += "V12BusOverVoltage";		break;
		case V12BusUnderVoltage:	str += "V12BusUnderVoltage";	break;
		case V17BusOverVoltage:		str += "V17BusOverVoltage";		break;
		case V17BusUnderVoltage:	str += "V17BusUnderVoltage";	break;
		case MotorOverVoltage:		str += "MotorOverVoltage";		break;
		case MotorUnderVoltage:		str += "MotorUnderVoltage";		break;
		case LogicSwOverCurrent:	str += "LogicSwOverCurrent";	break;
		case LogicSwUnderCurrent:	str += "LogicSwUnderCurrent";	break;
		case MotorOverCurrent:		str += "MotorOverCurrent";		break;
		case MotorUnderCurrent:		str += "MotorUnderCurrent";		break;
		case VehicleTypeOvervolt:	str += "VehicleTypeOvervolt";	break;
		case VehicleTypeInvalid:	str += "VehicleTypeInvalid";	break;
		case BatterySocCritical:	str += "BatterySocCritical";	break;
		case BatteryLossOfSignal:	str += "BatteryLossOfSignal";	break;
		case EstopSystemFault:		str += "EstopSystemFault";		break;
		case XBeeTimedOut:			str += "XBeeTimedOut";			break;
		case PowerSwitchDisable: 	str += "PowerSwitchDisable";	break;

	}

	return (str);

}

std::string Fault::printSeverity(void) {

	std::string str = "";

	switch (severity) {
		case Nominal:	str += "Nominal";		break;
		case Critical:	str += "Critical";		break;
		case Fatal:     str += "Fatal";    		break;
	}

	return (str);

}

std::string Fault::faultString(void) {

	std::string str = "";

	str += printFault();
	str += " (" + printSeverity() + ")";

	// Make the string safe for the screen
	//   Too long of a string causes a segfault
	str.resize(20);

	return (str);

}
