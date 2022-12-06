/*
 * display.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */



#include "display.h"

Display display;

//------------------------------------------------------------------//
//     						  Display Class							//
//------------------------------------------------------------------//

Display::Display() {

}


// TODO: Destructor
Display::~Display(){}

void Display::Init() {

	// Initialize SSD1306 Display
	ssd1306_Init();

	// Blackout the screen
	Clear();

	return;
}

void Display::Test(void) {

	// Runs a basic screen test.
	// You must call Init before running this function.
	ssd1306_TestFPS();
	Delay(3000);
	ssd1306_TestBorder();
	ssd1306_TestFonts();
	Delay(3000);
	ssd1306_Fill(Black);
	ssd1306_TestRectangle();
	ssd1306_TestLine();
	Delay(3000);
	ssd1306_Fill(Black);
	ssd1306_TestPolyline();
	Delay(3000);
	ssd1306_Fill(Black);
	ssd1306_TestArc();
	Delay(3000);
	ssd1306_Fill(Black);
	ssd1306_TestCircle();
	Delay(3000);

}

void Display::Clear(void) {
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
	return;
}

void Display::PrintString(std::string str) {
	ssd1306_Fill(Black);

	// Limit the length of the string
	str.resize(20);

	uint8_t y = 0;
	char screenline[21];

	ssd1306_SetCursor(2, y);
	sprintf(screenline, str.c_str());
	ssd1306_WriteString(screenline, Font_6x8, White);

	ssd1306_UpdateScreen();

	return;

}

void Display::Update(void) {

	ssd1306_Fill(Black);

	uint8_t y = 0;
	char screenline[21];

    ssd1306_SetCursor(2, y);
    //sprintf(screenline, "V_Battery = %.2f", (double)(battery.getVoltage()/1000));
    sprintf(screenline, " ");
    ssd1306_WriteString(screenline, Font_6x8, White);

    if (PowerSystem.getPowerSwitchState() == 1) {
        // Display battery voltage
        y += 20;
        ssd1306_SetCursor(2, y);
        sprintf(screenline, " Batt: %4.1fV",
        		PowerSystem.GetVoltage(PowerRail::VinLogic));
        ssd1306_WriteString(screenline, Font_6x8, White);

    } else {
    	// Display Bus Voltage
        y += 10;
        ssd1306_SetCursor(2, y);
        sprintf(screenline, "  Bus: %4.1fV %4.1fA",
        		PowerSystem.GetVoltage(PowerRail::VinLogicSw),
    			PowerSystem.GetCurrent(PowerRail::VinLogicSw));
        ssd1306_WriteString(screenline, Font_6x8, White);

        if (VehID.GetVehicleType() == vehicle_type::kSpot) {
        	y += 10;
        	ssd1306_SetCursor(2, y);

        	if (battery.getBatteryAlarmStatus() == BatteryAlarm::Bb2590LossOfSignal) {
        		sprintf(screenline, "  BTU: No Signal");
        	} else {
        	 	sprintf(screenline, "  BTU: %2ld %%", battery.getRelativeSOC());
        	}

        	ssd1306_WriteString(screenline, Font_6x8, White);

        } else {
        	y += 10;
        	ssd1306_SetCursor(2, y);
        	sprintf(screenline, "Motor: %4.1fV %4.1fA",
        			PowerSystem.GetVoltage(PowerRail::VinMotor),
        			PowerSystem.GetCurrent(PowerRail::VinMotor));
        	ssd1306_WriteString(screenline, Font_6x8, White);

        }
    }

	if (PowerSystem.getPowerSwitchState() == 1) {

		// Display on power switch off
		y += 15;
		ssd1306_SetCursor(2, y);
		sprintf(screenline, "  Power Switch Off");
		ssd1306_WriteString(screenline, Font_6x8, White);

		// Display the firmware version
		y += 15;
		ssd1306_SetCursor(2, y);
		sprintf(screenline, "Ver: %s",FIRMWARE_VERSION);
		ssd1306_WriteString(screenline, Font_6x8, White);

	} else {

		 // Display current errors
		y += 10;
		ssd1306_SetCursor(2, y);
		sprintf(screenline, fault_status_.printFault().c_str());
		ssd1306_WriteString(screenline, Font_6x8, White);

		y += 10;
		ssd1306_SetCursor(2, y);
		sprintf(screenline, fault_status_.printSeverity().c_str());
		ssd1306_WriteString(screenline, Font_6x8, White);

		y += 10;
		ssd1306_SetCursor(2, y);
		sprintf(screenline, Estop.estopString().c_str());
		ssd1306_WriteString(screenline, Font_6x8, White);

	}

	ssd1306_UpdateScreen();
	return;

}

