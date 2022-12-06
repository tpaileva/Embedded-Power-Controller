/*
 * switch.cpp
 *
 *      Author: T. Pailevanian
 */

#include "switch.h"

void Switch::Init(GPIO_TypeDef *port, uint16_t pin, GpioPull pupd_type, SwitchLogic logic) {

	// Initialize the GPIO pin
	GpioPin::Init(port, pin, kGpioModeInput, pupd_type);

	// Update the current state
	switch_state_ = last_state_ = (GpioState) GetBit();

	debounce_counter_ = DEBOUNCE_COUNT;

	sw_logic_ = logic;

}

void Switch::Debounce(void) {

	GpioState state = (GpioState) GetBit();

	if(state != last_state_) {
		// Reset the debounce counter
		debounce_counter_ = DEBOUNCE_COUNT;

	} else if (debounce_counter_ == 0) {
		// Switch is already debounced so don't do anything

	} else if (--debounce_counter_ == 0) {
		// Switch is debounced
		switch_state_ = state;
	}

	// Update the last state variable for the next itteration
	//	of the switch debouncer
	last_state_ = state;

}

bool Switch::GetState() {
	return (bool) switch_state_;
}

bool Switch::SwitchPressed(void){

	bool pressed;

	if(sw_logic_ == SwitchLogic::ActiveLow) {
		if(switch_state_ == kGpioStateLow) pressed = true;
		else pressed = false;
	} else { // Active High
		if(switch_state_ == kGpioStateHigh) pressed = true;
		else pressed = false;
	}

	return pressed;
}

UserSwitch::UserSwitch() {

	// Initialize switch properties
	ticks_ = 0;
	press_registered_ = false;
	long_press_ = false;
	num_presses_ = 0;
	multi_press_counter_ = MULTI_PRESS_COUNTDOWN;

	state_ = ButtonState::ButtonReset;
}

void UserSwitch::Init(GPIO_TypeDef *port, uint16_t pin, GpioPull pupd_type) {

	// Initialize the switch base class
	Switch::Init(port, pin, pupd_type);

	// Initialize switch properties
	ticks_ = 0;
	press_registered_ = false;
	long_press_ = false;
	num_presses_ = 0;
	multi_press_counter_ = MULTI_PRESS_COUNTDOWN;

	state_ = ButtonState::ButtonReset;

}

void UserSwitch::Debounce() {

	// Decrement the multi-press countdown counter so that we will only
	//	register multi-presses which are timed close together
	multi_press_counter_--;

	// If countdown timer expires, then reset the number of presses
	if(multi_press_counter_ == 0)
	{
		num_presses_ = 0;
		multi_press_counter_ = MULTI_PRESS_COUNTDOWN;
	}

	// Check the state of the GPIO pin
	if(GetBit() == kGpioStateLow) {

		// If the button was set in the last state, reset the debounce count
		if(last_state_ == kGpioStateHigh){

			debounce_counter_ = DEBOUNCE_COUNT;
		} else if(debounce_counter_ != 0){

			// Keep counting down on the debounce counter
			debounce_counter_--;

		} else if(debounce_counter_ == 0) {

			// Button has been debounced and is reset
			if(press_registered_ == false) {

				// Keep track of current count to determine if the press is a
				//	long or short press
				ticks_ = GetTicks();
				press_registered_ = true;
			}
			// Also check here for long press if the user is pressing and
			//	holding the button
			else if((GetTicks() - ticks_) > 5000 && press_registered_ == true &&
					long_press_ == false) {

				// Register the type of press
				state_ = ButtonState::LongPress;
				long_press_ = true;

				// Long presses will overwrite multi-presses
				num_presses_ = 0;
			}
		}
		last_state_ = kGpioStateLow;

	} else { // Button pin is kGpioStateHigh

		// If the button was reset in the last state, reset the debounce count
		if(last_state_ == kGpioStateLow || press_registered_ == false) {

			debounce_counter_ = DEBOUNCE_COUNT;

		} else if (debounce_counter_ != 0){

			// Keep counting down on the debounce counter
			debounce_counter_--;

		}else if(debounce_counter_ == 0) {

			// Button has been debounced and is set

			// Reset the multi press countdown
			multi_press_counter_ = MULTI_PRESS_COUNTDOWN;

			// Increment the number of presses
			num_presses_++;

			// Check how long it has been that the user has been pressing the button
			ticks_ = GetTicks() - ticks_;

			// Reset the button press registered flag
			press_registered_ = false;

			// Handle the type of button press
			if(num_presses_ > 1 && ticks_ < 1500)
			{
				if(num_presses_ == 2)
				{
					// Register the type of press
					state_ = ButtonState::DoublePress;
				}
				else if(num_presses_ == 3)
				{
					// Register the type of press
					state_ = ButtonState::TriplePress;
				}

			}
			else if(ticks_ < 1500)
			{
				// Register the type of press
				state_ = ButtonState::ShortPress;
			}
			// Make sure we havn't already processed the long press in the bit set statement
			else if(ticks_ > 4000 && long_press_ == false) {

				// Long presses will overwrite multi-presses
				num_presses_ = 0;

				// Register the type of press
				state_ = ButtonState::LongPress;
			}

			// Reset the long press flag if the user released the button
			long_press_ = false;
		}

		last_state_ = kGpioStateHigh;

	}

}

ButtonState UserSwitch::GetState() {
	return state_;
}

void UserSwitch::ResetState() {
	state_ = ButtonState::ButtonReset;
}
