/*
 * tim.cpp
 *
 *  Created on: May 5, 2020
 *      Author: akourchi
 */

#include "tim.h"
#include "logs.h"

Tim Tim2(TIM2);
Tim	Tim3(TIM3);
Tim Tim4(TIM4);
Tim Tim5(TIM5);
Tim Tim6(TIM6);
Tim Tim7(TIM7);
Tim	Tim9(TIM9);
Tim Tim10(TIM10);
Tim Tim11(TIM11);
Tim Tim12(TIM12);
Tim Tim13(TIM13);
Tim Tim14(TIM14);

//------------------------------------------------------------------//
//     					  TIM Channel Class							//
//------------------------------------------------------------------//

// Default constructor
TimChannel::TimChannel(){}

// Default destructor
TimChannel::~TimChannel(){};

bool TimChannel::Init(Tim *timer, GPIO_TypeDef *port, uint16_t pin,
		uint8_t alt_func, uint32_t channel, TimChannelType channel_type) {

	bool status = true;

	// Initialize the GPIO Pin
	timer_pin_.Init(port, pin, kGpioModeAFPP, kGpioSpeedVeryHigh, kGpioPullOff, alt_func);

	// Populate timer variables
	tim_ = timer;
	channel_ = channel;
	channel_type_ = channel_type;

	// Set PWM specific variables
	duty_cycle_ = 0;

	// Get Max ARR value
	max_cc_val_ = (tim_->GetTimHandle())->Instance->ARR;

	if (channel_type_ == kPwmOutput) {

		TIM_OC_InitTypeDef sConfigOC = { 0 };

		sConfigOC.OCMode = TIM_OCMODE_PWM1;
		sConfigOC.Pulse = 0;
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		if (HAL_TIM_PWM_ConfigChannel(tim_->GetTimHandle(), &sConfigOC, channel) != HAL_OK) {
			Logs::Log::Error("TIM CHANNEL: PWM initialization failed");
			status = false;
		}
	}

	return status;
}

void TimChannel::SetDuty(float duty_cycle) {

	uint16_t cc_val;

	// Bound checking
	if(duty_cycle < 0.0) duty_cycle = 0.0;
	if(duty_cycle > 100.0) duty_cycle = 100.0;

	if(duty_cycle == 100.0) {
		cc_val = max_cc_val_;
	} else {
		// Covert to a CC value
		cc_val = (uint16_t)((duty_cycle / 100.0) * max_cc_val_);
	}

	__HAL_TIM_SET_COMPARE(tim_->GetTimHandle(), channel_, cc_val);

	// Store duty Cycle value
	duty_cycle_ = duty_cycle;

}

void TimChannel::SetCC(uint16_t capture_compare) {

	__HAL_TIM_SET_COMPARE(tim_->GetTimHandle(), channel_, capture_compare);
}

float TimChannel::GetDuty() {

	return duty_cycle_;
}

uint16_t TimChannel::GetCC() {

	return __HAL_TIM_GET_COMPARE(tim_->GetTimHandle(), channel_);
}

TimChannelStatus TimChannel::Start() {

	TimChannelStatus status = kTimSuccess;

	if (channel_type_ == kPwmOutput) {
		if (HAL_TIM_PWM_Start(tim_->GetTimHandle(), channel_) != HAL_OK) {
			status = kTimStartFailed;
			Logs::Log::Error("TIM CHANNEL: PWM start failed");
		}
	}

	return status;
}

TimChannelStatus TimChannel::Stop() {

	TimChannelStatus status = kTimSuccess;

	if (channel_type_ == kPwmOutput) {
		if (HAL_TIM_PWM_Stop(tim_->GetTimHandle(), channel_) != HAL_OK) {
			status = kTimStopFailed;
			Logs::Log::Error("TIM CHANNEL: PWM stop failed");
		}
	}

	return status;
}

//------------------------------------------------------------------//
//     						  TIM Class								//
//------------------------------------------------------------------//


Tim::Tim(TIM_TypeDef* tim_instance)
{
	tim_instance_ = tim_instance;
	timer_callback_ = NULL;
}

bool Tim::Init(uint32_t freq)
{
	// Initialize Clocks
	InitializeClocks(tim_instance_);

	// Set Timer Frequency
	uint32_t tim_clk_freq = GetTimerClockFreq(tim_instance_);

	uint32_t ticks = tim_clk_freq / freq;
	uint16_t prescaler = (uint16_t)((ticks - 1) / (1 << 16)); 			// PSC
	uint16_t period = (uint16_t)(ticks / (uint32_t)(prescaler + 1)); 	// ARR

	// Configure Timer
	h_tim_.Instance = tim_instance_;
	h_tim_.Init.Prescaler = prescaler;
	h_tim_.Init.CounterMode = TIM_COUNTERMODE_UP;
	h_tim_.Init.Period = period;
	h_tim_.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	h_tim_.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&h_tim_) != HAL_OK) {

		Logs::Log::Error("TIMER: Base initialization failed.");
	}

	// Configure clock source
	sClockSourceConfig_.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&h_tim_, &sClockSourceConfig_) != HAL_OK) {

		Logs::Log::Error("TIMER: Clock source initialization failed.");
	}

	sMasterConfig_.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig_.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&h_tim_, &sMasterConfig_)
			!= HAL_OK) {
		Logs::Log::Error("TIMER: Initialization master output trigger failed.");
	}

	return true;
}

TIM_HandleTypeDef* Tim::GetTimHandle() {

	return &h_tim_;
}

void Tim::TimerCallback(void) {

	if (timer_callback_ != NULL) {
		timer_callback_();
	}
}

void Tim::SetCallback(tim_callback_function_t callback) {

	timer_callback_ = callback;

}

void Tim::Start() {
	HAL_TIM_Base_Start(&h_tim_);
}

void Tim::Stop() {
	HAL_TIM_Base_Stop(&h_tim_);
}

void Tim::StartIT(uint32_t PreemptPriority, uint32_t SubPriority) {

	EnableInterrupts(tim_instance_, PreemptPriority, SubPriority);
	HAL_TIM_Base_Start_IT(&h_tim_);

}

void Tim::StopIT() {

	HAL_TIM_Base_Stop_IT(&h_tim_);
	DisableInterrupts(tim_instance_);

} 

// Private Functions
//===========================================

void Tim::InitializeClocks(TIM_TypeDef *tim) {

	if (tim == TIM2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	} else if (tim == TIM3) {
		__HAL_RCC_TIM3_CLK_ENABLE();
	} else if (tim == TIM4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	} else if (tim == TIM5) {
		__HAL_RCC_TIM5_CLK_ENABLE();
	} else if (tim == TIM6) {
		__HAL_RCC_TIM6_CLK_ENABLE();
	} else if (tim == TIM7) {
		__HAL_RCC_TIM7_CLK_ENABLE();
	} else if (tim == TIM9) {
		__HAL_RCC_TIM9_CLK_ENABLE();
	} else if (tim == TIM10) {
		__HAL_RCC_TIM10_CLK_ENABLE();
	} else if (tim == TIM11) {
		__HAL_RCC_TIM11_CLK_ENABLE();
	} else if (tim == TIM12) {
		__HAL_RCC_TIM12_CLK_ENABLE();
	} else if (tim == TIM13) {
		__HAL_RCC_TIM13_CLK_ENABLE();
	} else if (tim == TIM14) {
		__HAL_RCC_TIM14_CLK_ENABLE();
	}
}

void Tim::HaltClocks(TIM_TypeDef *tim) {
	if (tim == TIM2) {
		__HAL_RCC_TIM2_CLK_DISABLE();
	} else if (tim == TIM3) {
		__HAL_RCC_TIM3_CLK_DISABLE();
	} else if (tim == TIM4) {
		__HAL_RCC_TIM4_CLK_DISABLE();
	} else if (tim == TIM5) {
		__HAL_RCC_TIM5_CLK_DISABLE();
	} else if (tim == TIM6) {
		__HAL_RCC_TIM6_CLK_DISABLE();
	} else if (tim == TIM7) {
		__HAL_RCC_TIM7_CLK_DISABLE();
	} else if (tim == TIM9) {
		__HAL_RCC_TIM9_CLK_DISABLE();
	} else if (tim == TIM10) {
		__HAL_RCC_TIM10_CLK_DISABLE();
	} else if (tim == TIM11) {
		__HAL_RCC_TIM11_CLK_DISABLE();
	} else if (tim == TIM12) {
		__HAL_RCC_TIM12_CLK_DISABLE();
	} else if (tim == TIM13) {
		__HAL_RCC_TIM13_CLK_DISABLE();
	} else if (tim == TIM14) {
		__HAL_RCC_TIM14_CLK_DISABLE();
	}
}

void Tim::EnableInterrupts(TIM_TypeDef *tim, uint32_t PreemptPriority,
		uint32_t SubPriority) {

	if (tim == TIM2) {
		HAL_NVIC_SetPriority(TIM2_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
	} else if (tim == TIM3) {
		HAL_NVIC_SetPriority(TIM3_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	} else if (tim == TIM4) {
		HAL_NVIC_SetPriority(TIM4_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM4_IRQn);
	} else if (tim == TIM5) {
		HAL_NVIC_SetPriority(TIM5_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM5_IRQn);
	} else if (tim == TIM6) {
		HAL_NVIC_SetPriority(TIM6_DAC_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	} else if (tim == TIM7) {
		HAL_NVIC_SetPriority(TIM7_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM7_IRQn);
	} else if (tim == TIM9) {
		HAL_NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
	} else if (tim == TIM10) {
		HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	} else if (tim == TIM11) {
		HAL_NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
	} else if (tim == TIM12) {
		HAL_NVIC_SetPriority(TIM8_BRK_TIM12_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
	} else if (tim == TIM13) {
		HAL_NVIC_SetPriority(TIM8_UP_TIM13_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
	} else if (tim == TIM14) {
		HAL_NVIC_SetPriority(TIM8_TRG_COM_TIM14_IRQn, PreemptPriority, SubPriority);
		HAL_NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
	}
}

void Tim::DisableInterrupts(TIM_TypeDef *tim) {

	if (tim == TIM2) {
		HAL_NVIC_DisableIRQ(TIM2_IRQn);
	} else if (tim == TIM3) {
		HAL_NVIC_DisableIRQ(TIM3_IRQn);
	} else if (tim == TIM4) {
		HAL_NVIC_DisableIRQ(TIM4_IRQn);
	} else if (tim == TIM5) {
		HAL_NVIC_DisableIRQ(TIM5_IRQn);
	} else if (tim == TIM6) {
		HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
	} else if (tim == TIM7) {
		HAL_NVIC_DisableIRQ(TIM7_IRQn);
	} else if (tim == TIM9) {
		HAL_NVIC_DisableIRQ(TIM1_BRK_TIM9_IRQn);
	} else if (tim == TIM10) {
		HAL_NVIC_DisableIRQ(TIM1_UP_TIM10_IRQn);
	} else if (tim == TIM11) {
		HAL_NVIC_DisableIRQ(TIM1_TRG_COM_TIM11_IRQn);
	} else if (tim == TIM12) {
		HAL_NVIC_DisableIRQ(TIM8_BRK_TIM12_IRQn);
	} else if (tim == TIM13) {
		HAL_NVIC_DisableIRQ(TIM8_UP_TIM13_IRQn);
	} else if (tim == TIM14) {
		HAL_NVIC_DisableIRQ(TIM8_TRG_COM_TIM14_IRQn);
	}
}

uint32_t Tim::GetTimerClockFreq(TIM_TypeDef * tim)
{
	uint32_t apb1_timer_clock, apb2_timer_clock;

	uint32_t tim_clk = 0;

	apb1_timer_clock = 2 * HAL_RCC_GetPCLK1Freq();
	apb2_timer_clock = 2 * HAL_RCC_GetPCLK2Freq();

	if (tim == TIM2) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM3) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM4) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM5) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM6) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM7) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM9) {
		tim_clk = apb2_timer_clock;
	} else if (tim == TIM10) {
		tim_clk = apb2_timer_clock;
	} else if (tim == TIM11) {
		tim_clk = apb2_timer_clock;
	} else if (tim == TIM12) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM13) {
		tim_clk = apb1_timer_clock;
	} else if (tim == TIM14) {
		tim_clk = apb1_timer_clock;
	}

	return tim_clk;
}

//------------------------------------------------------------------//
//     				HAL TIM Callback Functions						//
//------------------------------------------------------------------//

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == Tim2.GetTimHandle())
	{
		Tim2.TimerCallback();
	}
	else if (htim == Tim3.GetTimHandle())
	{
		Tim3.TimerCallback();
	}
	else if (htim == Tim4.GetTimHandle())
	{
		Tim4.TimerCallback();
	}
	else if (htim == Tim5.GetTimHandle())
	{
		Tim5.TimerCallback();
	}
	else if (htim == Tim6.GetTimHandle())
	{
		Tim6.TimerCallback();
	}
	else if (htim == Tim7.GetTimHandle())
	{
		Tim7.TimerCallback();
	}
	else if (htim == Tim9.GetTimHandle())
	{
		Tim9.TimerCallback();
	}
	else if (htim == Tim10.GetTimHandle())
	{
		Tim10.TimerCallback();
	}
	else if (htim == Tim11.GetTimHandle())
	{
		Tim11.TimerCallback();
	}
	else if (htim == Tim12.GetTimHandle())
	{
		Tim12.TimerCallback();
	}
	else if (htim == Tim13.GetTimHandle())
	{
		Tim13.TimerCallback();
	}
	else if (htim == Tim14.GetTimHandle())
	{
		Tim14.TimerCallback();
	}
}

