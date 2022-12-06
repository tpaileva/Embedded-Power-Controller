/*
 * tier1.h
 *
 *  Created on: Jul 1, 2021
 *      Author: akourchi
 */


// Header for the Tier1 (ROS) E-Stop

#pragma once

#include <cstring>

#include "uart.h"
#include "util.h"

#include "data_structures.h"

// Forward declaration
class TIER1;

extern TIER1 Tier1;

class TIER1 {
public:
	TIER1(void);

	virtual ~TIER1();

	void Init(void);

	void StartCountdown();
	void Disable();

	// State Return
	EstopState getState();  // Returns the raw state
	bool       Enabled();   // Returns if the vehicle is stopped by this EStop

	// Tier 2 Shutdown Timing
	void     SetActivateTime(uint32_t activateTime) { ms_activate_ = activateTime; }
	uint32_t TimeRemaining(void);
	uint32_t TimeStopRequest(void) { return (t_stop_request_); };

	// Override Tier1
	bool Ignore(void) { return (0); };  // Set to 1 to ignore this e-stop

	// Debugging
	uint8_t _tier1_debug = 1;

private:

	EstopState state_ = EstopState::EstopDisabled;

	// Timeouts
	uint32_t      ms_activate_ = 30UL*1000;  // Time taken for the Tier1 stop to activate
	                                         // Dictated by https://www.subtchallenge.com/resources/SubT_Challenge_Finals_Rules.pdf, Section 8.4.6

	// Shutdown Timing
	uint32_t t_shutdown_     = UINT32_MAX;
	uint32_t t_stop_request_ = 0;           // Time the last stop request was asked
};


