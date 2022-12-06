/*
 * adc.cpp
 *
 *  Created on: Jun 1, 2020
 *      Author: t. pailevanian
 */

#include "adc.h"
//#include "parameters.h"

AdcChannel adc_extra_1;
AdcChannel sense_5v;

/* Private_Defines */
#define NUM_ADC1_CHANNELS		19

/* Private Variables */
static AdcChannel* adc1_irq_table[NUM_ADC1_CHANNELS] = {
	NULL,	//ADC Channel 0
	NULL,	//ADC Channel 1
	NULL,	//ADC Channel 2
	NULL,	//ADC Channel 3
	NULL,	//ADC Channel 4
	NULL,	//ADC Channel 5
	NULL,	//ADC Channel 6
	NULL,	//ADC Channel 7
	NULL,	//ADC Channel 8
	NULL,	//ADC Channel 9
	NULL,	//ADC Channel 10
	NULL,	//ADC Channel 11
	NULL,	//ADC Channel 12
	NULL,	//ADC Channel 13
	NULL,	//ADC Channel 14
	NULL,	//ADC Channel 15
	NULL,	//ADC Channel 16
	NULL,	//ADC Channel 17
	NULL	//ADC Channel 18
};

/* Static Variables Defines*/
ADC_HandleTypeDef Adc::h_adc1;
volatile uint8_t Adc::adc1_current_channel;
bool Adc::adc1_initialized_;
bool Adc::adc1_active_channel_available_;

//------------------------------------------------------------------//
//     					 ADC Channel Class							//
//------------------------------------------------------------------//

// Standard ADC Channel Constructor
void AdcChannel::Init(GPIO_TypeDef *port, uint16_t pin, ADC_TypeDef *adc,
		uint32_t adc_channel, float gain, float offset,
		uint32_t tau, float initial_value) {

	InitializeChannel(port, pin, adc, adc_channel, gain, offset, tau, initial_value);

	// Populate the channel in the ISR table to use interrupts
	//	for ADC conversions
	if (h_adc_->Instance == ADC1) {
		adc1_irq_table[channel_index_] = this;
	}

	// Start the ADC conversions in case this is the first channel that was configured
	StartConversion();
}

void AdcChannel::ConfigureChannel(){

	ADC_ChannelConfTypeDef sConfig = { 0 };

	if (h_adc_ != NULL) {
		sConfig.Channel = adc_channel_;
		sConfig.Rank = 1;
		sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;

		if(HAL_ADC_ConfigChannel(h_adc_, &sConfig) != HAL_OK) {
			Logs::Log::Error("ADC: ADC channel configuration failed, Channel ", (uint8_t) channel_index_);
		}

	} else { // Something went really wrong
		Logs::Log::Error("ADC: ADC Channel Corrupted");

		// TODO call some type of error handler
	}
}

void AdcChannel::Callback()
{

	if (h_adc_ != NULL) {
		raw_value_ = h_adc_->Instance->DR;

	} else { // Something went really wrong
		Logs::Log::Error("ADC: ADC Channel Corrupted");

		// TODO call some type of error handler
	}

	// Perform filter step
	if (filter_.GetTau()) {
		filtered_value_ = filter_.FilterUpdate((float)raw_value_);
	}
}

uint16_t AdcChannel::GetValue(){
	return raw_value_;
}

float AdcChannel::GetFilteredValue(){
	return filtered_value_;
}

float AdcChannel::GetFilteredCorrectedValue() {

	float value;

	if(channel_type_ == kAdcSingleEnded) {
		value = filtered_value_ * (VREF / 4096.0) * gain_ + offset_;
	}

	return value;
}

// Private Functions
//===========================================

// Initializer for ADC Channels
void AdcChannel::InitializeChannel(GPIO_TypeDef *port, uint16_t pin, ADC_TypeDef *adc,
			uint32_t adc_channel, float gain, float offset, uint32_t tau,
			float initial_value){

	// Populate the handle depending on what type of ADC channel this is
	h_adc_ = GetAdcHandle(adc);

	// Initialize GPIO pin
	pin_.Init(port, pin, kGpioModeAnalog, kGpioPullOff);

	// Store channel information
	adc_channel_ = adc_channel;
	channel_index_ = GetAdcChannelIndex(adc_channel);

	// Store channel type
	channel_type_ = kAdcSingleEnded;

	// Store gain and offset
	gain_ = gain;
	offset_ = offset;
	cal_gain_ = 1;

	// Initialize filter
	filter_ = LPF(tau, initial_value);
}

ADC_HandleTypeDef * AdcChannel::GetAdcHandle(ADC_TypeDef *adc){

	ADC_HandleTypeDef * handle = NULL;

	if(adc == ADC1){
		handle = Adc::GetAdc1Handle();
	}

	return handle;

}

uint8_t AdcChannel::GetAdcChannelIndex(uint32_t channel){

	uint8_t channel_index;

	switch(channel){
	case ADC_CHANNEL_0:
		channel_index = 0;
		break;
	case ADC_CHANNEL_1:
		channel_index = 1;
		break;
	case ADC_CHANNEL_2:
		channel_index = 2;
		break;
	case ADC_CHANNEL_3:
		channel_index = 3;
		break;
	case ADC_CHANNEL_4:
		channel_index = 4;
		break;
	case ADC_CHANNEL_5:
		channel_index = 5;
		break;
	case ADC_CHANNEL_6:
		channel_index = 6;
		break;
	case ADC_CHANNEL_7:
		channel_index = 7;
		break;
	case ADC_CHANNEL_8:
		channel_index = 8;
		break;
	case ADC_CHANNEL_9:
		channel_index = 9;
		break;
	case ADC_CHANNEL_10:
		channel_index = 10;
		break;
	case ADC_CHANNEL_11:
		channel_index = 11;
		break;
	case ADC_CHANNEL_12:
		channel_index = 12;
		break;
	case ADC_CHANNEL_13:
		channel_index = 13;
		break;
	case ADC_CHANNEL_14:
		channel_index = 14;
		break;
	case ADC_CHANNEL_15:
		channel_index = 15;
		break;
	case ADC_CHANNEL_16:
		channel_index = 16;
		break;
	case ADC_CHANNEL_17:
		channel_index = 17;
		break;
	case ADC_CHANNEL_18:
		channel_index = 18;
		break;
	}

	return channel_index;

}

void AdcChannel::StartConversion() {

	if (h_adc_ != NULL) {
		if(h_adc_->Instance == ADC1){
			Adc::Adc1StartConversion();
		}

	}

}

//------------------------------------------------------------------//
//     						ADC Class								//
//------------------------------------------------------------------//

AdcInitStatus Adc::Init()
{
	// Initialize variables
	adc1_current_channel = 0;

	adc1_initialized_ = false;

	adc1_active_channel_available_ = false;

	// Initialize ADCs
	if(!InitAdc1()) return kAdc1InitFail;

	// Configure channels
	if(Adc1ConfigureChannels()){
		// Start conversion if an active channel is available
		Adc1StartConversion();
	}

	return kAdcInitSuccess;

}

ADC_HandleTypeDef * Adc::GetAdc1Handle(){
	return &h_adc1;
}

void Adc::Adc1Callback() {

	// Call the ADC channel callback
	adc1_irq_table[adc1_current_channel]->Callback();

	Adc1ConfigureChannels();

}

void Adc::Adc1StartConversion() {

	__IO uint32_t counter = 0U;

	if(HAL_IS_BIT_CLR(h_adc1.Instance->CR2, ADC_CR2_ADON)) {
		__HAL_ADC_ENABLE(&h_adc1);

	    // Delay for ADC stabilization time
	    // Compute number of CPU cycles to wait for */
	    counter = (ADC_STAB_DELAY_US * (SystemCoreClock / 1000000U));
	    while(counter != 0U)
	    {
	      counter--;
	    }
	}
	// Check if conversion is not ongoing (if not then start conversion)
	if (!(h_adc1.Instance->SR & ADC_SR_STRT)) {

		// If no active channels area available, it is possible that this is the first time
		//	this function is being called by the AdcChannel class.
		if(!adc1_active_channel_available_) {
			Adc1ConfigureChannels();
		}

		// Start conversion if an active channel is available
		if(adc1_active_channel_available_){

			// Check to see if ADC is enabled
			if(HAL_IS_BIT_SET(h_adc1.Instance->CR2, ADC_CR2_ADON)) {
				SET_BIT(h_adc1.Instance->CR2, ADC_CR2_SWSTART);
			}
		}
	}
}

// Protected Functions
//===========================================

// Returns true if there is at least 1 active channel in the queue
bool Adc::Adc1ConfigureChannels() {

	if (!(h_adc1.Instance->SR & ADC_SR_STRT)) {

		// Active channel indicator
		adc1_active_channel_available_ = false;

		for (uint8_t i = 1; i <= NUM_ADC1_CHANNELS; i++) {

			uint8_t index = (adc1_current_channel + i) % NUM_ADC1_CHANNELS;

			// Loop through all channels
			if (adc1_irq_table[index] != NULL) {

				// If there is an active channel in the queue, increment the counter
				adc1_active_channel_available_ = true;

				// Update current channel
				adc1_current_channel = index;

				// Call the conversion function for that channel
				adc1_irq_table[index]->ConfigureChannel();

				break;
			}
		}
	}

	return adc1_active_channel_available_;
}


// Private Functions
//===========================================

bool Adc::InitAdc1()
{
	// Enable ADC1 Clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	// Initialize peripheral parameters
	h_adc1.Instance = ADC1;
	h_adc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	h_adc1.Init.Resolution = ADC_RESOLUTION_12B;
	h_adc1.Init.ScanConvMode = DISABLE;
	h_adc1.Init.ContinuousConvMode = DISABLE;
	h_adc1.Init.DiscontinuousConvMode = DISABLE;
	h_adc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	h_adc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	h_adc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	h_adc1.Init.NbrOfConversion = 1;
	h_adc1.Init.DMAContinuousRequests = DISABLE;
	h_adc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	if (HAL_ADC_Init(&h_adc1) != HAL_OK) {
		return false;
	}

	// Clear and Enable EOC interrupt
	__HAL_ADC_CLEAR_FLAG(&h_adc1, ADC_FLAG_EOC);
	__HAL_ADC_ENABLE_IT(&h_adc1, ADC_IT_EOC);

	// Initialize Interrupts
	HAL_NVIC_SetPriority(ADC_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(ADC_IRQn);

	return true;
}


//------------------------------------------------------------------//
//     				ADC Callback Functions						//
//------------------------------------------------------------------//

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	if (hadc->Instance == ADC1) {

		// If source of interrupt is the EOC interrupt
		if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOC)) {

			// Clear EOC flag
			__HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);

			// Clear Start flag
			__HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT);

			// Perform callback
			Adc::Adc1Callback();

			// Start another conversion
			Adc::Adc1StartConversion();
		}
	}
}
