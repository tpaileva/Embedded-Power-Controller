/*
 * iwdg.cpp
 *
 *  Created on: May 11, 2020
 *      Author: t. pailevanian
 */

#include "iwdg.h"

Iwdg Watchdog;

// Maximum period is 700ms
bool Iwdg::Init(uint16_t period_ms)
{

	// Check if input argument is within range
	if(period_ms > 700)
	{
		return false;
	}

	uint32_t reload;

	// Get watchdog clock frequency
//	if (!GetLsiFrequency()) {
//		return false;
//	}

	// FOR DEBUG
	// TODO REMOVE
	uwLsiFreq_ = 48000;

	/*
	 * Calculated as follows:
	 * Given a prescaler factor of 8
	 * watchdog timer period = 8/uwLsiFreq
	 * reload value = (period_ms / 1000) / watchdog timer period
	 * reload value = period_ms * uwLsiFreq / (8 * 1000)
	 */
	reload = (uint32_t)((uwLsiFreq_ * period_ms / 8000) & 0xfff);

	h_iwdg_.Instance = IWDG;
	h_iwdg_.Init.Prescaler = IWDG_PRESCALER_8;
	h_iwdg_.Init.Window = 0xfff;
	h_iwdg_.Init.Reload = reload;

	if (HAL_IWDG_Init(&h_iwdg_) != HAL_OK) {
		return false;
	}

	return true;
}

void Iwdg::Pet()
{
	__HAL_IWDG_RELOAD_COUNTER(&h_iwdg_);
}

// Private Functions
//===========================================

bool Iwdg::GetLsiFrequency() {

	uint32_t lsiperiod = 0;

	TIM_IC_InitTypeDef sConfigIC = { 0 };

	__HAL_RCC_TIM14_CLK_ENABLE();

	h_tim14_.Instance = TIM14;
	h_tim14_.Init.Prescaler = 0;
	h_tim14_.Init.CounterMode = TIM_COUNTERMODE_UP;
	h_tim14_.Init.Period = 0xFFFF;
	h_tim14_.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	h_tim14_.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&h_tim14_) != HAL_OK) {
		return false;
	}
	if (HAL_TIM_IC_Init(&h_tim14_) != HAL_OK) {
		return false;
	}
	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV8;
	sConfigIC.ICFilter = 0;
	if (HAL_TIM_IC_ConfigChannel(&h_tim14_, &sConfigIC, TIM_CHANNEL_1) != HAL_OK) {
		return false;
	}

	// Re-map ch1 to MCO internally
	WRITE_REG(h_tim14_.Instance->OR, TIM_TIM14_MCO);

	// Connect internally the MCO to LSI
	HAL_RCC_MCOConfig(RCC_MCO, RCC_MCO1SOURCE_LSI, RCC_MCODIV_1);

	// Start the TIM Input Capture measurement in interrupt mode
	if (HAL_TIM_IC_Start(&h_tim14_, TIM_CHANNEL_1) != HAL_OK) {
		return false;
	}

	uwCaptureNumber_ = 0;

	// Wait until the TIM14 get 2 LSI edges
	while (uwCaptureNumber_ != 2) {
		// Check capture compare flag register
		if (__HAL_TIM_GET_FLAG(&h_tim14_, TIM_FLAG_CC1)) {
			captures_[uwCaptureNumber_] = __HAL_TIM_GET_COMPARE(&h_tim14_, TIM_CHANNEL_1);
			uwCaptureNumber_++;
		}
	}


	// Compute the period length
	lsiperiod = (uint16_t) (0xFFFF - captures_[0] + captures_[1] + 1);

	// Frequency computation
	//	Timer clock is 2x Peripheral clock
	uwLsiFreq_ = (uint32_t) (HAL_RCC_GetPCLK1Freq() * 2) / lsiperiod;

	// Account for prescalar of 8
	uwLsiFreq_ *= 8;


	if (HAL_TIM_IC_Stop(&h_tim14_, TIM_CHANNEL_1) != HAL_OK) {
		return false;
	}

	// Deinitialize the TIM14 Peripheral Registers
	if (HAL_TIM_IC_DeInit(&h_tim14_) != HAL_OK) {
		return false;
	}
	if (HAL_TIM_Base_DeInit(&h_tim14_) != HAL_OK) {
		return false;
	}

	// Disable peripheral clocks
	__HAL_RCC_TIM14_CLK_DISABLE();

	return true;

}


