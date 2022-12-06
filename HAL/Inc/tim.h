/*
 * tim.h
 *
 *  Created on: May 5, 2020
 *      Author: akourchi
 */

#ifndef TIM_H
#define TIM_H

#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include "gpio.h"
#include <functional>

// Forward declaration
class Tim;
class TimChannel;

extern Tim Tim2;
extern Tim Tim3;
extern Tim Tim4;
extern Tim Tim5;
extern Tim Tim6;	// Used for timing (no outputs)
extern Tim Tim7;	// Used for timing (no outputs)
extern Tim Tim9;
extern Tim Tim10;
extern Tim Tim11;
extern Tim Tim12;
extern Tim Tim13;
extern Tim Tim14;

enum TimChannelType {
	kPwmOutput = 0,
	kPwmInput,
	kOutputCompare,
	kInputCapture
};

enum TimChannelStatus {
	kTimSuccess = 0,
	kTimFailed,
	kTimStartFailed,
	kTimStopFailed
};

typedef std::function<void()> tim_callback_function_t;

class Tim {

public:
	Tim(TIM_TypeDef* tim_instance);
	bool Init(uint32_t freq);
	TIM_HandleTypeDef * GetTimHandle();

	void TimerCallback(void);
	void SetCallback(tim_callback_function_t callback);

	void Start(void);
	void Stop(void);

	void StartIT(uint32_t PreemptPriority = 0, uint32_t SubPriority = 0);
	void StopIT(void);

	virtual ~Tim(){};

private:
	TIM_TypeDef* tim_instance_;

	TIM_HandleTypeDef h_tim_;

	TIM_ClockConfigTypeDef sClockSourceConfig_ = {0};
	TIM_SlaveConfigTypeDef sSlaveConfig_ = {0};
	TIM_MasterConfigTypeDef sMasterConfig_ = {0};

	tim_callback_function_t timer_callback_;

	void InitializeClocks(TIM_TypeDef * tim);
	void HaltClocks(TIM_TypeDef * tim);
	void EnableInterrupts(TIM_TypeDef * tim, uint32_t PreemptPriority, uint32_t SubPriority);
	void DisableInterrupts(TIM_TypeDef * tim);
	uint32_t GetTimerClockFreq(TIM_TypeDef * tim);
};

class TimChannel {

public:
	TimChannel();
	~TimChannel();
	bool Init(Tim *tim, GPIO_TypeDef *port, uint16_t pin, uint8_t alt_func,
			uint32_t channel, TimChannelType channel_type);
	void SetDuty(float duty_cycle);
	void SetCC(uint16_t capture_compare);

	float 	GetDuty(void);
	uint16_t GetCC(void);

	TimChannelStatus Start(void);
	TimChannelStatus Stop(void);

private:

	GpioPin	timer_pin_;

	// Contains channel type
	TimChannelType channel_type_;

	// Contains the parent timer
	Tim * tim_;

	// Contains timer channel
	uint32_t channel_;

	// PWM Specific Variables
	//--------------------------
	// Current duty cycle and capture compare values
	float duty_cycle_;

	// Maximum cc value based on timer
	uint32_t max_cc_val_;

};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
// 	*Place HAL function constructors here*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#ifdef __cplusplus
}
#endif

#endif /* TIM_H */
