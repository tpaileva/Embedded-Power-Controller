/*
 * led.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */


#include "led.h"

Led led;

TimChannel debug_blue, debug_red, debug_green;
TimChannel white_led1, white_led2, white_led3, white_led4;
TimChannel arm_red, arm_blue, arm_green;

UserSwitch led_sw;

//------------------------------------------------------------------//
//     						  LED Class								//
//------------------------------------------------------------------//

Led::Led() {

}


// TODO: Destructor
Led::~Led(){}

void Led::Init() {

	// Configure LEDs (Initializes PWM)
	Tim5.Init(1000);
	Tim4.Init(1000);
	Tim3.Init(1000);


	debug_blue.Init(DEBUG_LEG_B_TIMER, DEBUG_LED_B_GPIO_Port, DEBUG_LED_B_Pin, DEBUG_LED_B_AF, DEBUG_LED_B_TIMER_CHANNEL, kPwmOutput);
	debug_red.Init(DEBUG_LEG_R_TIMER, DEBUG_LED_R_GPIO_Port, DEBUG_LED_R_Pin, DEBUG_LED_R_AF, DEBUG_LED_R_TIMER_CHANNEL, kPwmOutput);
	debug_green.Init(DEBUG_LEG_G_TIMER, DEBUG_LED_G_GPIO_Port, DEBUG_LED_G_Pin, DEBUG_LED_G_AF, DEBUG_LED_G_TIMER_CHANNEL, kPwmOutput);

	white_led1.Init(WHITE_LED_1_TIMER, WHITE_LED_1_GPIO_Port, WHITE_LED_1_Pin, WHITE_LED_1_AF, WHITE_LED_1_TIMER_CHANNEL, kPwmOutput);
	white_led2.Init(WHITE_LED_2_TIMER, WHITE_LED_2_GPIO_Port, WHITE_LED_2_Pin, WHITE_LED_2_AF, WHITE_LED_2_TIMER_CHANNEL, kPwmOutput);
	white_led3.Init(WHITE_LED_3_TIMER, WHITE_LED_3_GPIO_Port, WHITE_LED_3_Pin, WHITE_LED_3_AF, WHITE_LED_3_TIMER_CHANNEL, kPwmOutput);
	white_led4.Init(WHITE_LED_4_TIMER, WHITE_LED_4_GPIO_Port, WHITE_LED_4_Pin, WHITE_LED_4_AF, WHITE_LED_4_TIMER_CHANNEL, kPwmOutput);

	arm_red.Init(ARM_LED_R_TIMER, ARM_LED_R_GPIO_Port, ARM_LED_R_Pin, ARM_LED_R_AF, ARM_LED_R_TIMER_CHANNEL, kPwmOutput);
	arm_green.Init(ARM_LED_G_TIMER, ARM_LED_G_GPIO_Port, ARM_LED_G_Pin, ARM_LED_G_AF, ARM_LED_G_TIMER_CHANNEL, kPwmOutput);
	arm_blue.Init(ARM_LED_B_TIMER, ARM_LED_B_GPIO_Port, ARM_LED_B_Pin, ARM_LED_B_AF, ARM_LED_B_TIMER_CHANNEL, kPwmOutput);

	white_led1.Start();
	white_led2.Start();
	white_led3.Start();
	white_led4.Start();

	Tim5.Start();
	debug_blue.Start();
	debug_red.Start();
	debug_green.Start();

	Tim3.Start();
	arm_red.Start();
	arm_blue.Start();
	arm_green.Start();

	white_led1.SetDuty(0);
	white_led2.SetDuty(0);
	white_led3.SetDuty(0);
	white_led4.SetDuty(0);

	// Configure White LED Toggle Switch
	led_sw.Init(WHITE_LED_SW_GPIO_Port, WHITE_LED_SW_Pin, kGpioPullUp);

}

void Led::setWhiteLEDS(float duty_cycle) {

	white_led1.SetDuty(duty_cycle);
	white_led2.SetDuty(duty_cycle);
	white_led3.SetDuty(duty_cycle);
	white_led4.SetDuty(duty_cycle);

	current_wled_duty_cycle_ = (uint8_t)duty_cycle;

}


void Led::setArmStatusLED(ArmLEDStatus status) {

	switch (status) {
		case DisarmedLEDStatus:
			arm_red.SetDuty(100);
			arm_blue.SetDuty(0);
			arm_green.SetDuty(0);
			break;
		case PreArmedLEDStatus:
			arm_red.SetDuty(0);
			arm_blue.SetDuty(100);
			arm_green.SetDuty(0);
			break;
		case ArmedLEDStatus:
			arm_red.SetDuty(0);
			arm_blue.SetDuty(0);
			arm_green.SetDuty(100);
			break;
		default:
			arm_red.SetDuty(0);
			arm_blue.SetDuty(0);
			arm_green.SetDuty(0);
			break;
	}

}

void Led::updateWhiteLEDToggle(void) {

	led_sw.Debounce();

	ButtonState btn_state = led_sw.GetState();

	if (btn_state == ButtonState::ShortPress || btn_state == ButtonState::LongPress) {

		switch (current_wled_duty_cycle_) {

			case 0:
				current_wled_duty_cycle_ = 1;
				break;
			case 1:
				current_wled_duty_cycle_ = 100;
				break;

			case 100:
				current_wled_duty_cycle_ = 0;
				break;
			default:
				current_wled_duty_cycle_ = 0;
				break;

		}

		white_led1.SetDuty((float)current_wled_duty_cycle_);
		white_led2.SetDuty((float)current_wled_duty_cycle_);
		white_led3.SetDuty((float)current_wled_duty_cycle_);
		white_led4.SetDuty((float)current_wled_duty_cycle_);

		led_sw.ResetState();
	}

}
