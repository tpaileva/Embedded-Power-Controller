/*
 * util.c
 *
 *  Created on: May 13, 2020
 *      Author: t. pailevanian
 */

#include "util.h"

void Delay(uint32_t ms)
{
	HAL_Delay(ms);
}

uint32_t GetTicks(){

	// Get milisecond tics
	return HAL_GetTick();
}

/**
 * Initialization routine.
 * You might need to enable access to DWT registers on Cortex-M7
 *   DWT->LAR = 0xC5ACCE55
 */
void DwtInit(void)
{
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}

/**
 * Delay routine itself.
 * Time is in microseconds (1/1000000th of a second), not to be
 * confused with millisecond (1/1000th).
 *
 * No need to check an overflow. Let it just tick :)
 *
 * @param uint32_t us  Number of microseconds to delay for
 */
void DwtDelayMicroseconds(uint32_t us) // microseconds
{
    uint32_t start_tick = DWT->CYCCNT,
             delay_ticks = us * (SystemCoreClock/1000000);

    while (DWT->CYCCNT - start_tick < delay_ticks);
}

uint32_t DwtGetMicrosecondTicks(){
	return DWT->CYCCNT;
}

