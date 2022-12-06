/*
 * crc.h
 *
 */

#ifndef CRC_H_
#define CRC_H_

//#if defined(STM32F373xC)
//#include "stm32f3xx_hal.h"
//#elif defined(STM32G474xx)
//#include "stm32g4xx_hal.h"
//#endif

#include <stdint.h>

// Used when the data is in one continuous location
uint16_t CRC16(uint16_t crc_accum, uint8_t *data_blk_ptr, uint16_t data_blk_size);

// Used when the data is in a circular buffer which needs to wrap around
uint16_t CRC16(uint16_t crc_accum, uint8_t *buffer, uint16_t buffer_ind,
				uint16_t buffer_size, uint16_t data_blk_size);

#endif /* CRC_H_ */
