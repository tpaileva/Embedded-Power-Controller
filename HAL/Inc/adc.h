/*
 * adc.h
 *
 *  Created on: Jun 1, 2020
 *      Author: t. pailevanian
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include "gpio.h"
#include "filter.h"
#include "logs.h"

// Notes on ADC and ADC Channel Classes
//	ADC class is a static class used for initializing the ADC peripherals
//	The ADC channel class is derived from the ADC class so that it has access
//	to all of the handles necessary for channel conversion

// Forward declaration
class AdcChannel;

// Channel Extern
extern AdcChannel adc_extra_1;
extern AdcChannel sense_5v;

#define GAIN_1		1
#define OFFSET_0	0
#define VREF		2.5f

enum AdcChannelType{
	kSdadcDifferentialZeroRef = 0,
	kSdadcSingleEnded,
	kSdadcDifferentialMidRef,
	kAdcSingleEnded
};

enum AdcInitStatus{
	kAdcInitSuccess = 0,
	kAdc1InitFail,
	kSdadc1InitFail
};

enum AdcChannelNumber{
	kAdcChannel0 = 0,
	kAdcChannel1,
	kAdcChannel2,
	kAdcChannel3,
	kAdcChannel4,
	kAdcChannel5,
	kAdcChannel6,
	kAdcChannel7,
	kAdcChannel8,
	kAdcChannel9,
	kAdcChannel10,
	kAdcChannel11,
	kAdcChannel12,
	kAdcChannel13,
	kAdcChannel14,
	kAdcChannel15,

	kNumAdcChanels
};

class Adc {

public:
	// ADC Initialization function
	static AdcInitStatus Init(void);

	static ADC_HandleTypeDef * GetAdc1Handle(void);

	static void Adc1Callback(void);
	static void Adc1StartConversion(void);

protected:

	static volatile uint8_t adc1_current_channel;

	static ADC_HandleTypeDef 	h_adc1;		// ADC Handle

	static bool Adc1ConfigureChannels(void);

private:

	static bool adc1_initialized_;

	static bool adc1_active_channel_available_;

	static bool InitAdc1();

};

class AdcChannel {

public:

	//Constructors
	AdcChannel(){};
	~AdcChannel(){};

	// Standrad ADC Channel Constructor
	void Init(GPIO_TypeDef *port, uint16_t pin, ADC_TypeDef *adc,
			uint32_t adc_channel, float gain = 1, float offset = 0,
			uint32_t tau = 0, float initial_value = 0);

	// Member Function
	void Callback(void);
	void ConfigureChannel(void);

	uint16_t GetValue(void);
	float GetFilteredValue(void);

	// Returns the filtered value with the appropate gain and offset
	float GetFilteredCorrectedValue(void);

	// TODO Add sampling function
	//bool SampleChannel(uint16_t * buf, uint16_t num_samples);

private:

	LPF	filter_;					// Filter

	ADC_HandleTypeDef *h_adc_;		// ADC Handle

	GpioPin 	pin_;				// Particular GPIO Pin Positive Input

	uint32_t 	adc_channel_;		// ADC Channel number

	AdcChannelType	channel_type_;	// ADC Channel type

	// Gain and offset for the ADC channel
	float gain_;
	float offset_;
	float cal_gain_;

	uint8_t channel_index_;

	int16_t raw_value_;
	float filtered_value_;

	// Initialize ADC Channel
	void InitializeChannel(GPIO_TypeDef *port, uint16_t pin, ADC_TypeDef *adc,
			uint32_t adc_channel, float gain, float offset, uint32_t tau, float initial_value);

	ADC_HandleTypeDef * GetAdcHandle(ADC_TypeDef * adc);

	uint8_t GetAdcChannelIndex(uint32_t channel);

	// Starts the ADC conversion
	void StartConversion(void);

};


//------------------------------------------------------------------//
//     				HAL ADC Callback Functions						//
//------------------------------------------------------------------//

#ifdef __cplusplus
extern "C" {
#endif

void	HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

#ifdef __cplusplus
}
#endif

#endif /* ADC_H_ */
