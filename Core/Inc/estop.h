/*
 * estop.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_ESTOP_H_
#define INC_ESTOP_H_

#include "gpio.h"
#include "adc.h"
#include "util.h"
#include <string>

#include "data_structures.h"
#include "tier1.h"
#include "tier2.h"
#include "tier3.h"
#include "rosComms.h"

// 1 = OVERRIDE, BYPASS BOTH RF AND SW ESTOP, Robot Active
// 0 = Listen to RF and SW ESTOP
//#define ESTOP_SW_OVERRIDE_ENABLE 1  // moved into tier1 object
// #define ESTOP_RF_OVERRIDE_ENABLE 0 // moved into tier2 object

// Forward declaration
class EmergencyStop;

extern EmergencyStop Estop;

class EmergencyStop {
public:

	EmergencyStop(void);

	virtual ~EmergencyStop();

	void Init(void);

	void Update(void);

	EstopState getSystemEstopState(void);

	bool isArmed(void);
	uint32_t TimeRemaining(void);
	bool waitForEstopCycle(void);
	void clearEstopCycle(void);

	void setEstopOutput(bool);

	void printEstopStatus(void);
	std::string estopString(void);

private:

	// True  = Emergency Stop Active = Robot Disabled
	// False = Emergency Stop Inactive = Robot Enabled
	EstopState SystemEstop_;		// High Level E-STOP State (OR'd E-STOP States)

	// Debugging
	uint8_t _estop_debug = 1;

};

#endif /* INC_ESTOP_H_ */
