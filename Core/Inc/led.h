/*
 * led.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "switch.h"
#include "tim.h"
#include "util.h"


// Forward declaration
class Led;

extern Led led;

enum ArmLEDStatus {
	DisarmedLEDStatus,
	PreArmedLEDStatus,
	ArmedLEDStatus,
};

class Led {
public:
	Led(void);

	virtual ~Led();

	void Init(void);

	void setWhiteLEDS(float duty_cycle);
	void setArmStatusLED(ArmLEDStatus status);

	void updateWhiteLEDToggle(void);

private:

	uint8_t current_wled_duty_cycle_ = 0;
};



#endif /* INC_LED_H_ */
