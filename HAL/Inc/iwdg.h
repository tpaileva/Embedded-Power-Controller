/*
 * iwdg.h
 *
 *  Created on: May 11, 2020
 *      Author: t. pailevanian
 */

#ifndef IWDG_H_
#define IWDG_H_

#include "stm32f3xx_hal.h"

// Forward declaration
class Iwdg;

extern Iwdg Watchdog;

class Iwdg{

public:


	Iwdg(void){}

	virtual ~Iwdg(){};

	// Maximum period is 700ms
	bool Init(uint16_t period_ms);

	void Pet(void);

private:

	uint32_t uwLsiFreq_;
	uint32_t uwCaptureNumber_;

	uint16_t captures_[2];

	IWDG_HandleTypeDef h_iwdg_;
	TIM_HandleTypeDef h_tim14_;

	bool GetLsiFrequency();

};


#endif /* IWDG_H_ */
