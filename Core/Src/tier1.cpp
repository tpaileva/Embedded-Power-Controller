/*
 * tier1.cpp
 *
 *  Created on: Jul 1, 2021
 *      Author: akourchi
 */


#include "tier1.h"

TIER1 Tier1;

TIER1::TIER1(void)
{

}

// TODO: Destructor
TIER1::~TIER1(){}

void TIER1::Init() {

	// Do nothing
	return;
}

EstopState TIER1::getState(void) {

	// Exit out as we've got the override on
	if(Ignore()) {
		return(EstopState::EstopDisabled);		// OVERRIDE AND BYPASS E-STOP, Robot Active
	}

	// Check for a timer timeout
	if (TimeRemaining()) {
		state_ = EstopState::EstopDisabled;
	} else {
		state_ = EstopState::EstopEnabled;
	}

	return (state_);
}

bool TIER1::Enabled(void) {

	if (getState() == EstopState::EstopDisabled) {
		// Robot OK to move
		return (0);
	}

	return (1);
}

uint32_t TIER1::TimeRemaining(void) {
	// Returns the number of ms left on the Tier2 timer
	// NOT overflow protected but I think that's ok tbh

	if (t_shutdown_ == UINT32_MAX) {
		// Timer hasn't been stated yet, just return the max value we can
		return (UINT32_MAX);
	}

	if (t_shutdown_ < GetTicks()) {
		// Time expired, return 0
		return (0);
	} else {
		// We're in the countdown, simple subtraction
		return (t_shutdown_ - GetTicks());
	}

	// Something is wrong, return system should be killed
	return (0);

};

void TIER1::Disable() {
	// Disables the Tier2 E-Stop
	t_shutdown_ = UINT32_MAX;

	// All Done
	return;
}

void TIER1::StartCountdown() {

	if (TimeRemaining() == UINT32_MAX) {
		// Count-down not in progress, start one
		t_shutdown_ = GetTicks() + ms_activate_;
	}

	// Store the time of the request
	t_stop_request_ = GetTicks();

	if (_tier1_debug) {
		Serial.WriteString("[ Tier1 ] - Software E-Stop Enabled!\r\n");
		Serial.WriteString("[ Tier1 ] - Starting ROS E-Stop countdown...!\r\n");
	}

	// All done
	return;
}


