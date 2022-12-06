/*
 * main.cpp
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <tier2.h>
#include "main.h"
#include "adc.h"
#include "btu.h"
#include "buzzer.h"
#include "display.h"
#include "estop.h"
#include "gpio.h"
#include "led.h"
#include "power.h"
#include "tim.h"
#include "uart.h"
//#include "iwdg.h"
#include "usb.h"
#include "util.h"
#include "logs.h"
#include "i2c.h"
#include "spi.h"

#include "statemachine.h"
#include "vehicleid.h"
#include "rosComms.h"
#include "heartBeat.h"
#include "loopTracking.h"

// Variables
float voltage, voltage_sense_5v;
uint16_t voltage_raw;
uint32_t t_1Hz_, t_5s_, t_2Hz_, t_4Hz_, t_10s_, t_5mins_;

// Temporary variable to test serial loopback
uint8_t data;
uint8_t rx_buf[100];

// Debugging
uint8_t main_debug = 1;

// Top Level TODO list
// TODO: When there's more time, merge fault and alarm into a status struct

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals and devices */
	//===================================
	// Initialize microsecond delay
	DwtInit();

	// Initialize GPIOs
	Gpio::Init();

	// Initialize ADC
	Adc::Init();

	// Initialize Vehicle ID
	VehID.Init();

	// Initialize Power System
	PowerSystem.Init();

	// Initialize Buzzer
	buzzer.Init();

	// Initialize LED
	led.Init();

	// Initialize Heartbeat
	heartBeat.Init();

	// Initialize UART
	Serial.Init(115200);
	Xbee.Init(9600);

	// Initialize USB
	Usb.Init();

	// Initialize ESTOP
	Estop.Init();

	// Configure BB2590 (Initializes I2C)
	battery.Init();

	// Configure Display (Initializes SPI)
	display.Init();

	// Make sure the XBee is working here
	Delay(250);
	Tier2.RequestXbeeState();

	while (Tier2.Alive() == false) {
		uint32_t t_enter = GetTicks();
		uint     tries = 1;

		// do nothing
		Tier2.Update();

		if (GetTicks() > (t_enter + 3UL*1000)) {
			// Xbee not responding, reset the system
			display.PrintString("Bad XBee [ "+std::to_string(tries)+" ]");
			Delay(2000);

			// Reset the XBee interface
			Xbee.Init(9600);
			tries++;

		}

	}


	// Initialise ROS
	ROS.init();

	// Initialise timed loops
	t_1Hz_   = GetTicks();
	t_2Hz_   = GetTicks();
	t_5s_    = GetTicks();
	t_10s_   = GetTicks();
	t_5mins_ = GetTicks();

	// Configure Watchdog
	// TODO: Write watchdog code and integrate into LOOP

	Delay(1000);

	if (main_debug) { Serial.WriteString("[ MAIN ] - Init Complete\r\n"); }
	//===================================

	// Initialize the logs
	Logs::Log(INFO_ENABLED, WARNING_ENABLED, ERROR_ENABLED, EXCEPTION_DISABLED,
			DEBUG_ENABLED, VERBOSE_DISABLED);

	// Initialize loop tracking
	loopTracking.Init();

	while (1) {


		// Process the state machine
		processStateMachine();

		// Scheduled tasks
		// These should be offset somewhat so they don't all call at the same time...
		if (GetTicks() - t_1Hz_   >      1UL*1000 ) { Tasks_1Hz(); }
		if (GetTicks() - t_2Hz_   >          500UL) { Tasks_2Hz(); }
		if (GetTicks() - t_4Hz_   >          250UL) { Tasks_4Hz(); }
		if (GetTicks() - t_5s_    >      5UL*1000 ) { Tasks_5s (); }
		if (GetTicks() - t_10s_   >     10UL*1000 ) { Tasks_10s(); }
		if (GetTicks() - t_5mins_ > 5UL*60  *1000 ) { Tasks_5mins(); }

		// ROS Update
		ROS.nh.spinOnce();

		// Update the heartbeat
		heartBeat.Update();
		
		// Update loop tracking
		loopTracking.AddLoop();

	}

}

void Tasks_1Hz() {
	// Update timing
	t_1Hz_ = GetTicks();

	// Publish state over ROS
	// TODO: Check in here to make sure the comms channel is initialised
	//traffic_led.SetBit(!traffic_led.GetBit());
	if (ROS.nh.connected()) {
        // Traffic LED on
		traffic_led.SetBit(1);
        
        // Send messages
		ROS.publishStatus();
		ROS.publishEStop();
        ROS.publishFaultState();
        
        // Traffic LED off
		traffic_led.SetBit(0);
	}

	// Check RF E-Stop status and update the RFEstop_ state.
	// Calling this function too often will result in a Xbee UART buffer overflow,
	// so we placed in the 1Hz main loop.
	//Tier2.RequestXbeeState();

    // Update battery telemetry
    battery.Update();

	// Update the display
	display.Update();

	// All done
	return;

}

void Tasks_2Hz() {
	// Update timing
	t_2Hz_ = GetTicks();

	// All done
	return;
}

void Tasks_4Hz() {
	// Update timing
	t_4Hz_ = GetTicks();

	// XBee update
	Tier2.RequestXbeeState();
	//ROS.publishMsg("XBee Ago: " + std::to_string(GetTicks()-Tier2.TimeLastMessage()));

	// All done
	return;
}

void Tasks_5s() {
	// Update timing
	t_5s_ = GetTicks();

	// Reset the XBee interface if we haven't heard from it
	if (GetTicks() > (Tier2.TimeLastMessage() + 10UL*1000)) {
		// Xbee not responding, reset the system
		ROS.publishMsg("Resetting XBee (Timed Out)");

		// Reset the XBee interface
		Xbee.Init(9600);

	}

	// All done
	return;
}

void Tasks_10s() {
	// Update timing
	t_10s_ = GetTicks();

	// All done
	return;
}

void Tasks_5mins() {
	// Update timing
	t_5mins_ = GetTicks();

	// Publish the version string
	std::string vehicle;

	switch (VehID.GetVehicleType()) {
	case (vehicle_type::kHusky)   : vehicle = "Husky"; break;
	case (vehicle_type::kTelemax) : vehicle = "Telemax"; break;
	case (vehicle_type::kSpot)    : vehicle = "Spot"; break;
	default                       : vehicle = "Unknown"; break;
	}

	ROS.publishMsg(vehicle + ": " + FIRMWARE_VERSION);

	// All done
	return;
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI
			| RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 6;
	RCC_OscInitStruct.PLL.PLLN = 168;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */
