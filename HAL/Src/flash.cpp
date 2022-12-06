/*
 * flash.cpp
 *
 *  Created on: May 14, 2020
 *      Author: t. pailevanian
 */


#include "flash.h"

//------------------------------------------------------------------//
//     						Flash Class								//
//------------------------------------------------------------------//

bool Flash::Erase(FlashPage page_start, uint8_t nb_of_pages){

	static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t PageError = 0;

	if (page_start < FLASH_FIRST_PAGE || page_start > FLASH_LAST_PAGE) {

		//Logs::Log::error("FLASH: Wrong start page");

		return false;
	} else if ((uint32_t)(page_start + (nb_of_pages * FLASH_PAGE_SIZE - 1)) > FLASH_MAX_ADDRESS) {

		//Logs::Log::error("FLASH: Wrong number of pages");

		return false;
	}

	// Unlock the flash memory
	HAL_FLASH_Unlock();

	// Fill EraseInit structure
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = page_start;
	EraseInitStruct.NbPages     = (uint32_t) nb_of_pages;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)
	{
		// Lock flash memory in the case of an error
		HAL_FLASH_Lock();

		// Log the error
		//Logs::Log::error("FLASH: Error in writing to page");

		return false;
	}

	// Lock flash memory to prevent accidental corruption
	HAL_FLASH_Lock();

	return true;

}

bool Flash::Read(uint32_t address, uint8_t& data)
{
    if (address < (uint32_t)FLASH_FIRST_PAGE || address > (uint32_t)FLASH_MAX_ADDRESS) {
        // Wrong address
        return false;
    }

    data = (*(volatile uint32_t*)address);
    return true;
}

bool Flash::Read(uint32_t address, uint8_t* data, uint32_t size)
{
    uint32_t sizeCounter = 0;

	if (address < (uint32_t) FLASH_FIRST_PAGE || address > (uint32_t) FLASH_MAX_ADDRESS) {
		//Logs::Log::error("FLASH: Wrong start page");
		return false;
	} else if ((address + size) > (uint32_t) FLASH_MAX_ADDRESS) {
		//Logs::Log::error("FLASH: Wrong flash size trying to be read");
		return false;
	}

	while (sizeCounter < size) {
	    *data = (*(volatile uint32_t*)address);
	    data++;
	    address++;
	    sizeCounter++;
	}
    return true;
}

bool Flash::Write(uint32_t address, uint32_t data_address, size_t size)
{
	HAL_StatusTypeDef status = HAL_OK;

	uint32_t counter;

	// Check if size is
	if(size % 2){
		//Logs::Log::error("FLASH: Flash write operations must be in 16-bit increments");
		return false;
	}

	if (address < (uint32_t) FLASH_FIRST_PAGE || address > (uint32_t) FLASH_MAX_ADDRESS) {
		//Logs::Log::error("FLASH: Wrong start page");
		return false;
	} else if ((address + size) > (uint32_t) FLASH_MAX_ADDRESS) {
		//Logs::Log::error("FLASH: Wrong flash size trying to be read");
		return false;
	}

	 counter = size/2;

	HAL_FLASH_Unlock();

	do {

		status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, *(uint16_t *)data_address);

		address += 2;
		data_address += 2;

	} while (--counter != 0 && status == HAL_OK);


    HAL_FLASH_Lock();

	if(status == HAL_OK){
		return true;
	}
	else{
		//Logs::Log::error("FLASH: Error while writing to flash");
		return false;
	}
}

