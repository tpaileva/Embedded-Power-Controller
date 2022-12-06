/*
 * flash.h
 *
 *  Created on: May 14, 2020
 *      Author: t. pailevanian
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "stm32f3xx_hal.h"

enum FlashPage{

	// Base address of each flash page

	kFlashPage0 = 	((uint32_t)0x08000000),
	kFlashPage1 = 	((uint32_t)0x08000800),
	kFlashPage2 = 	((uint32_t)0x08001000),
	kFlashPage3 = 	((uint32_t)0x08001800),
	kFlashPage4 = 	((uint32_t)0x08002000),
	kFlashPage5 = 	((uint32_t)0x08002800),
	kFlashPage6 = 	((uint32_t)0x08003000),
	kFlashPage7 = 	((uint32_t)0x08003800),
	kFlashPage8 = 	((uint32_t)0x08004000),
	kFlashPage9 = 	((uint32_t)0x08004800),
	kFlashPage10 = 	((uint32_t)0x08005000),
	kFlashPage11 = 	((uint32_t)0x08005800),
	kFlashPage12 = 	((uint32_t)0x08006000),
	kFlashPage13 = 	((uint32_t)0x08006800),
	kFlashPage14 = 	((uint32_t)0x08007000),
	kFlashPage15 = 	((uint32_t)0x08007800),
	kFlashPage16 = 	((uint32_t)0x08008000),
	kFlashPage17 = 	((uint32_t)0x08008800),
	kFlashPage18 = 	((uint32_t)0x08009000),
	kFlashPage19 = 	((uint32_t)0x08009800),
	kFlashPage20 = 	((uint32_t)0x0800A000),
	kFlashPage21 = 	((uint32_t)0x0800A800),
	kFlashPage22 = 	((uint32_t)0x0800B000),
	kFlashPage23 = 	((uint32_t)0x0800B800),
	kFlashPage24 = 	((uint32_t)0x0800C000),
	kFlashPage25 = 	((uint32_t)0x0800C800),
	kFlashPage26 = 	((uint32_t)0x0800D000),
	kFlashPage27 = 	((uint32_t)0x0800D800),
	kFlashPage28 = 	((uint32_t)0x0800E000),
	kFlashPage29 = 	((uint32_t)0x0800E800),
	kFlashPage30 = 	((uint32_t)0x0800F000),
	kFlashPage31 = 	((uint32_t)0x0800F800),
	kFlashPage32 = 	((uint32_t)0x08010000),
	kFlashPage33 = 	((uint32_t)0x08010800),
	kFlashPage34 = 	((uint32_t)0x08011000),
	kFlashPage35 = 	((uint32_t)0x08011800),
	kFlashPage36 = 	((uint32_t)0x08012000),
	kFlashPage37 = 	((uint32_t)0x08012800),
	kFlashPage38 = 	((uint32_t)0x08013000),
	kFlashPage39 = 	((uint32_t)0x08013800),
	kFlashPage40 = 	((uint32_t)0x08014000),
	kFlashPage41 = 	((uint32_t)0x08014800),
	kFlashPage42 = 	((uint32_t)0x08015000),
	kFlashPage43 = 	((uint32_t)0x08015800),
	kFlashPage44 = 	((uint32_t)0x08016000),
	kFlashPage45 = 	((uint32_t)0x08016800),
	kFlashPage46 = 	((uint32_t)0x08017000),
	kFlashPage47 = 	((uint32_t)0x08017800),
	kFlashPage48 = 	((uint32_t)0x08018000),
	kFlashPage49 = 	((uint32_t)0x08018800),
	kFlashPage50 = 	((uint32_t)0x08019000),
	kFlashPage51 = 	((uint32_t)0x08019800),
	kFlashPage52 = 	((uint32_t)0x0801A000),
	kFlashPage53 = 	((uint32_t)0x0801A800),
	kFlashPage54 = 	((uint32_t)0x0801B000),
	kFlashPage55 = 	((uint32_t)0x0801B800),
	kFlashPage56 = 	((uint32_t)0x0801C000),
	kFlashPage57 = 	((uint32_t)0x0801C800),
	kFlashPage58 = 	((uint32_t)0x0801D000),
	kFlashPage59 = 	((uint32_t)0x0801D800),
	kFlashPage60 = 	((uint32_t)0x0801E000),
	kFlashPage61 = 	((uint32_t)0x0801E800),
	kFlashPage62 = 	((uint32_t)0x0801F000),
	kFlashPage63 = 	((uint32_t)0x0801F800),
	kFlashPage64 = 	((uint32_t)0x08020000),
	kFlashPage65 = 	((uint32_t)0x08020800),
	kFlashPage66 = 	((uint32_t)0x08021000),
	kFlashPage67 = 	((uint32_t)0x08021800),
	kFlashPage68 = 	((uint32_t)0x08022000),
	kFlashPage69 = 	((uint32_t)0x08022800),
	kFlashPage70 = 	((uint32_t)0x08023000),
	kFlashPage71 = 	((uint32_t)0x08023800),
	kFlashPage72 = 	((uint32_t)0x08024000),
	kFlashPage73 = 	((uint32_t)0x08024800),
	kFlashPage74 = 	((uint32_t)0x08025000),
	kFlashPage75 = 	((uint32_t)0x08025800),
	kFlashPage76 = 	((uint32_t)0x08026000),
	kFlashPage77 = 	((uint32_t)0x08026800),
	kFlashPage78 = 	((uint32_t)0x08027000),
	kFlashPage79 = 	((uint32_t)0x08027800),
	kFlashPage80 = 	((uint32_t)0x08028000),
	kFlashPage81 = 	((uint32_t)0x08028800),
	kFlashPage82 = 	((uint32_t)0x08029000),
	kFlashPage83 = 	((uint32_t)0x08029800),
	kFlashPage84 = 	((uint32_t)0x0802A000),
	kFlashPage85 = 	((uint32_t)0x0802A800),
	kFlashPage86 = 	((uint32_t)0x0802B000),
	kFlashPage87 = 	((uint32_t)0x0802B800),
	kFlashPage88 = 	((uint32_t)0x0802C000),
	kFlashPage89 = 	((uint32_t)0x0802C800),
	kFlashPage90 = 	((uint32_t)0x0802D000),
	kFlashPage91 = 	((uint32_t)0x0802D800),
	kFlashPage92 = 	((uint32_t)0x0802E000),
	kFlashPage93 = 	((uint32_t)0x0802E800),
	kFlashPage94 = 	((uint32_t)0x0802F000),
	kFlashPage95 = 	((uint32_t)0x0802F800),
	kFlashPage96 = 	((uint32_t)0x08030000),
	kFlashPage97 = 	((uint32_t)0x08030800),
	kFlashPage98 = 	((uint32_t)0x08031000),
	kFlashPage99 = 	((uint32_t)0x08031800),
	kFlashPage100 = ((uint32_t)0x08032000),
	kFlashPage101 = ((uint32_t)0x08032800),
	kFlashPage102 = ((uint32_t)0x08033000),
	kFlashPage103 = ((uint32_t)0x08033800),
	kFlashPage104 = ((uint32_t)0x08034000),
	kFlashPage105 = ((uint32_t)0x08034800),
	kFlashPage106 = ((uint32_t)0x08035000),
	kFlashPage107 = ((uint32_t)0x08035800),
	kFlashPage108 = ((uint32_t)0x08036000),
	kFlashPage109 = ((uint32_t)0x08036800),
	kFlashPage110 = ((uint32_t)0x08037000),
	kFlashPage111 = ((uint32_t)0x08037800),
	kFlashPage112 = ((uint32_t)0x08038000),
	kFlashPage113 = ((uint32_t)0x08038800),
	kFlashPage114 = ((uint32_t)0x08039000),
	kFlashPage115 = ((uint32_t)0x08039800),
	kFlashPage116 = ((uint32_t)0x0803A000),
	kFlashPage117 = ((uint32_t)0x0803A800),
	kFlashPage118 = ((uint32_t)0x0803B000),
	kFlashPage119 = ((uint32_t)0x0803B800),
	kFlashPage120 = ((uint32_t)0x0803C000),
	kFlashPage121 = ((uint32_t)0x0803C800),
	kFlashPage122 = ((uint32_t)0x0803D000),
	kFlashPage123 = ((uint32_t)0x0803D800),
	kFlashPage124 = ((uint32_t)0x0803E000),
	kFlashPage125 = ((uint32_t)0x0803E800),
	kFlashPage126 = ((uint32_t)0x0803F000),
	kFlashPage127 = ((uint32_t)0x0803F800)

};

#define FLASH_FIRST_PAGE	kFlashPage0
#define FLASH_LAST_PAGE		kFlashPage127
#define FLASH_MAX_PAGES		128
#define FLASH_MAX_ADDRESS	(uint32_t)(FLASH_FIRST_PAGE + (FLASH_MAX_PAGES * FLASH_PAGE_SIZE - 1))

class Flash {
public:

	static bool Erase(FlashPage page_start, uint8_t nb_of_pages);
	static bool Read(uint32_t address, uint8_t& data);
	static bool Read(uint32_t address, uint8_t* data, uint32_t size);
	static bool Write(uint32_t address, uint32_t data_address, size_t size);
	static uint32_t GetSize(void);

private:

};

#endif /* FLASH_H_ */
