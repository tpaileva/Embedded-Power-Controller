/*
 * tier3.h
 *
 *  Created on: Jul 27, 2021
 *      Author: akourchi
 */

#ifndef INC_TIER3_H_
#define INC_TIER3_H_

#include "tier1.h"
#include "tier2.h"
#include "data_structures.h"


// Forward declaration
class TIER3;

extern TIER3 Tier3;

class TIER3 {
public:
	TIER3(void);

	virtual ~TIER3();

	void Init(void);

	EstopState getState();

	bool Enabled();

	void Update();

	bool waitForEstopCycle();
	void clearEstopCycle();

	void resetTier3Estop();

private:
	// True  = Emergency Stop Active = Robot Disabled
	// False = Emergency Stop Inactive = Robot Enabled
	EstopState PhysicalEstop_;		// Physical E-STOP State

	// Variables for Physical E-Stop cycle state tracking
	uint8_t cycleCounter_ = 0;
	bool cycleState_ = false;

	// Timings
	uint32_t tier1_wait_ = 10UL*1000; // Time since last ROS/XBee E-Stop message before
	uint32_t tier2_wait_ = 10UL*1000; // we'll automatically clear Tier1/Tier2 on physical
	                                  // e-stop release

	// Debugging
	uint8_t _tier3_debug = 1;

	// Last Physical E-Stop State used for triggering
	EstopState _last_PhysicalEstop;

};

#endif /* INC_TIER3_H_ */
