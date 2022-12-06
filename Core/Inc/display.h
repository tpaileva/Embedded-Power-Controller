/*
 * display.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "ssd1306.h"
#include "ssd1306_tests.h"

#include "power.h"
#include "btu.h"
#include "fault.h"
#include "estop.h"
#include "vehicleid.h"

// Forward declaration
class Display;

extern Display display;


class Display {
public:

	Display(void);

	virtual ~Display();

	void Init(void);
	void Test(void);
	void Update(void);
	void Clear(void);
	void PrintString(std::string str);

private:

};

#endif /* INC_DISPLAY_H_ */
