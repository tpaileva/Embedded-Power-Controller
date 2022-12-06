/*
 * tier3.cpp
 *
 *  Created on: Jul 27, 2021
 *      Author: akourchi
 */



#include <tier3.h>

TIER3 Tier3;

TIER3::TIER3(void)
{

}

// TODO: Destructor
TIER3::~TIER3(){}

void TIER3::Init() {

	// EstopEnabled  = Emergency Stop Active = Robot Disabled
	// EstopDisabled = Emergency Stop Inactive = Robot Enabled
	PhysicalEstop_ = EstopEnabled;

	// Set last e-stop to disabled to prevent auto-cycling on boot
	_last_PhysicalEstop = EstopDisabled;		// E-STOP Released

	cycleCounter_ = 0;
	cycleState_ = false;
}

EstopState TIER3::getState() {

	return PhysicalEstop_;
}


bool TIER3::Enabled() {

	// Returns if the vehicle is stopped by this e-stop
	if (PhysicalEstop_ == EstopEnabled) {
		// Robot is not active
		return (1);
	}
	else if (PhysicalEstop_ == EstopDisabled){
		// Robot OK to move
		return (0);
	}
	else {
		// Default: robot is not active
		return (1);
	}

}

void TIER3::Update(void) {

	// Read and update the Physical E-Stop State
	uint8_t estop_phy = ((estop_phy_p.GetBit() ? 1 : 0) << 1) | (estop_phy_n.GetBit() ? 0 : 1);

	switch (estop_phy) {

		case 1:
			PhysicalEstop_ = EstopEnabled;		// E-STOP Depressed
			break;
		default:
			PhysicalEstop_ = EstopDisabled;		// E-STOP Released
			break;
	}

	// Detect Physical E-Stop Release and reset Tier 1 and Tier 2 E-Stop States
	if (PhysicalEstop_ == EstopDisabled && _last_PhysicalEstop == EstopEnabled) {
		// E-Stop Debug Message
		if (_tier3_debug) { Serial.WriteString("[ ESTOP ] - Tier 3 (Physical) released!\r\n"); }

		// Clear Tier1 (ROS) E-Stop
		// We only do this if ROS hasn't told us to be stopped in a while
        if ((GetTicks() - tier1_wait_) > Tier1.TimeStopRequest()) {
            // Clear Tier1 E-Stop if we haven't been asked to enable it in the last 10 s
            Tier1.Disable();
        }

        // Clear Tier2 (XBee) E-Stop
        Tier2.Reset();

		// E-Stop Debug Message
		if (_tier3_debug) { Serial.WriteString("[ ESTOP ] - Reset Tier 1 and Tier 2 E-Stop.\r\n"); }
	}

	// Store the current Physical E-Stop State as the last known Physical E-Stop State
	_last_PhysicalEstop = PhysicalEstop_;
}

bool TIER3::waitForEstopCycle(void) {

	Update();

	switch (cycleCounter_) {

		case 0:
			if( PhysicalEstop_ == EstopEnabled) {
				cycleCounter_ += 1;
				cycleState_ = true;

				Delay(25);  // Debounce
			}
			break;
		case 1:
			// Hold for clear cycle
			break;
		default:
			cycleCounter_ = 0;
			cycleState_ = false;
			Delay(25);
			break;
	}

	return cycleState_;
}

void TIER3::clearEstopCycle(void) {
	cycleCounter_ = 0;
	cycleState_ = false;

}

void TIER3::resetTier3Estop(void) {
	cycleCounter_ = 0;
	cycleState_ = false;

	_last_PhysicalEstop = EstopDisabled;		// E-STOP Released
}
