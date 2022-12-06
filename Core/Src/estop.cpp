/*
 * estop.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#include "estop.h"

EmergencyStop Estop;

//------------------------------------------------------------------//
//     						  Estop Class							//
//------------------------------------------------------------------//

EmergencyStop::EmergencyStop() {

}


// TODO: Destructor
EmergencyStop::~EmergencyStop(){}

void EmergencyStop::Init() {

	// Initialize the ROS E-Stop (Tier1)
	Tier1.Init();

	// Initialize RF E-ESTOP (Tier2)
	Tier2.Init();

	// Initialize Physical E-Stop (Tier3)
	Tier3.Init();

	// Set the activate times for the robots
	switch (VehID.GetVehicleType()) {
	    case (vehicle_type::kHusky  ) :
	    case (vehicle_type::kTelemax) :
		    Tier1.SetActivateTime(0);
	        Tier2.SetActivateTime(0);
	        break;

	    default:
	    	// Leave times as per their defaults
	    	break;

	}
}

void EmergencyStop::Update(void) {

	// Update Physical, RF and SW E-Stop states
	Tier2.Update();
	Tier3.Update();

	// Check for faults                   // RFEstop_
	if (Tier3.getState() == EstopFault || Tier2.getState() == EstopFault || Tier1.getState() == EstopFault) {

		if (Tier3.getState() == EstopFault) {
			Serial.WriteString("[ ESTOP ] - Tier3 Fault!\r\n");
		}
		if (Tier2.getState() == EstopFault) {
			Serial.WriteString("[ ESTOP ] - Tier2 Fault!\r\n");
		}
		if (Tier1.getState() == EstopFault) {
			Serial.WriteString("[ ESTOP ] - Tier1 Fault!\r\n");
		}

		SystemEstop_ = EstopFault;
	}
	// 'OR' the E-Stop states - If any one of them are enabled, the system E-Stop is enabled
	else if (Tier3.getState() == EstopEnabled || Tier2.getState() == EstopEnabled || Tier1.getState() == EstopEnabled) {
		SystemEstop_ = EstopEnabled;
	}
	// 'AND' the E-Stop states - If all of them are disabled, the system E-Stop is disabled
	else if (Tier3.getState() == EstopDisabled && Tier2.getState() == EstopDisabled && Tier1.getState() == EstopDisabled) {
		SystemEstop_ = EstopDisabled;
	}
	// Else fault out
	else {
		SystemEstop_ = EstopFault;
	}


}

EstopState EmergencyStop::getSystemEstopState(void) {

	// Run the E-Stop update logic
	Update();

	return SystemEstop_;
}

uint32_t EmergencyStop::TimeRemaining(void) {

	// Returns the time remaining before a powerdown
	uint32_t retval = std::min(Tier1.TimeRemaining(),
			          std::min(Tier2.TimeRemaining(),
   	                           Tier2.TimeoutRemaining()));

	return (retval);

}


bool EmergencyStop::isArmed(void) {
	// Returns if the system is armed or not
    // We look at the raw state of the load switch pin for this
    if (n_estop_output.GetBit()) {
        return (true);
    } else {
        return (false);
    }

	// All done
	return (false);
}

void EmergencyStop::setEstopOutput(bool state) {

	// Set E-Stop Output Pin using System E-Stop state
	// E-Stop Output Pin is used to relay the E-Stop state to Spot (and future vehicles)

	// Sanity check the function call by checking
	// if the system E-Stop is disabled (Robot Active), set Tier1 pin high
	if (state == false && SystemEstop_ == EstopDisabled) {
		n_estop_output.SetBit(1);
	}
	else {
		n_estop_output.SetBit(0);
	}

}

void EmergencyStop::printEstopStatus(void) {
	// Print Tier 3 (Physical) E-Stop State
	if (Tier3.getState() == EstopEnabled) {
		Serial.WriteString("[ STATE ] - Tier 3 (Physical) E-Stop: Enabled\r\n");
	}
	else {
		Serial.WriteString("[ STATE ] - Tier 3 (Physical) E-Stop: Disabled\r\n");
	}

	// Print Tier2 (RF) E-Stop State
	if (Tier2.getState() == EstopEnabled) {
		Serial.WriteString("[ STATE ] - Tier 2 (RF) E-Stop: Enabled\r\n");
	}
	else {
		Serial.WriteString("[ STATE ] - Tier 2 (RF) E-Stop: Disabled\r\n");
	}

	// Print Tier1 (ROS) E-Stop State
	if (Tier1.getState() == EstopEnabled) {
		Serial.WriteString("[ STATE ] - Tier 1 (ROS) E-Stop: Enabled\r\n");
	}
	else {
		Serial.WriteString("[ STATE ] - Tier 1 (ROS) E-Stop: Disabled\r\n");
	}
}


std::string EmergencyStop::estopString() {

	std::string str = "";

	if (isArmed()) {

		// If countdown timer going, display that
		if (TimeRemaining() < 60UL*1000) {
			str += "Countdown: " + std::to_string(TimeRemaining()/1000) + "s";
			return (str);
		}

		// Otherwise just display the armed string
		str += "    -- Armed! --";
		return  (str);
	}

	str += "E-Stop: ";

	if (Tier1.getState() == EstopEnabled) {
		str += "ROS ";
	}

	// Print Tier2 (RF) E-Stop State
	if (Tier2.getState() == EstopEnabled) {
		str += "XBee ";
	}

	if (Tier2.Timeout() == true) {
		str += "XBee (Timeout) ";
	}

	// Print Tier1 (ROS) E-Stop State
	if (Tier3.getState() == EstopEnabled) {
		str += "Button";
	}

	// Limit the length of the string
	str.resize(20);

	return (str);
}
