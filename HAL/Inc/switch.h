/*
 * switch.h
 *
 *      Author: T. Pailevanian
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "gpio.h"
#include "tim.h"
#include "util.h"

#define	DEBOUNCE_LOOP_FREQ		500 	//Hz
#define DEBOUNCE_COUNT			20;	// 10 counts at a loop frequency of 500Hz (30ms)
#define MULTI_PRESS_COUNTDOWN	1;

enum class ButtonState{

	ButtonReset = 0,
	ShortPress,
	LongPress,
	DoublePress,
	TriplePress

};

enum class SwitchLogic {
	ActiveLow = 0,
	ActiveHigh
};

class Switch : protected GpioPin {

public:
	Switch() {};

	void Init(GPIO_TypeDef *port, uint16_t pin, GpioPull pupd_type,
				SwitchLogic logic = SwitchLogic::ActiveLow);

	void Debounce(void);

	bool GetState(void);

	bool SwitchPressed(void);

protected:

	GpioState 	switch_state_;
	GpioState 	last_state_;
	uint16_t 	debounce_counter_;
	SwitchLogic sw_logic_;

};

class UserSwitch : protected Switch {

public:



	UserSwitch(void);

	void Init(GPIO_TypeDef *port, uint16_t pin, GpioPull pupd_type);

	void Debounce(void);

	ButtonState GetState(void);

	// Called when the button state has been acknowledged
	void ResetState(void);

private:

	// Stores duration of the button press
	uint32_t ticks_;

	// Flag which tracks if the timer has been started to track button
	//	press duration
	bool press_registered_;

	//  Special flag for tracking longgggggg presses
	bool long_press_;

	// Keeps track of the number of presses for registering multiple
	//	presses of the button
	uint8_t num_presses_;
	uint16_t multi_press_counter_;

	ButtonState state_;

};

#endif /* SWITCH_H_ */
