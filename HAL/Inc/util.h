/*
 * util.h
 *
 *  Created on: May 13, 2020
 *      Author: t. pailevanian
 */

#ifndef INC_UTIL_H_
#define INC_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

void Delay(uint32_t ms);
uint32_t GetTicks();
void DwtInit(void);
void DwtDelayMicroseconds(uint32_t us);
uint32_t DwtGetMicrosecondTicks();


#ifdef __cplusplus
}
#endif

#endif /* INC_UTIL_H_ */
