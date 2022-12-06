/*
 * gpio.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: T. Pailevanian
 */

#include "gpio.h"

// Power supply enables
GpioPin enable_5v;
GpioPin enable_12v;
GpioPin enable_17v;

// Load switch enables
GpioPin load_en_logic;
GpioPin load_en_5v;
GpioPin load_en_12v;
GpioPin load_en_17v;
GpioPin load_en_lidar1;
GpioPin load_en_lidar2;
GpioPin load_en_lidar3;
GpioPin load_en_lidar4;
GpioPin load_en_24v_1;
GpioPin load_en_24v_2;
GpioPin load_en_24v_3;

// Oled GPIO Pins
GpioPin oled_reset;
GpioPin oled_sa0;
GpioPin oled_cs;

// Estop Pins
GpioPin estop_phy_p;
GpioPin estop_phy_n;
GpioPin n_estop_output;

// Input Switches
//GpioPin power_switch;
GpioPin user_switch;
GpioPin white_led_switch;

// Vehicle ID Switches
GpioPin veh_id_0;
GpioPin veh_id_1;
GpioPin veh_id_2;

// Traffic LED
GpioPin traffic_led;

// One interrupt/pin, don't need information about GPIO port
typedef struct {
  IRQn_Type irqnb;
  gpio_callback_function_t callback;
} GpioIrqTable;

/* Private_Defines */
#define NUM_EXTI	16

/* Private Variables */
static GpioIrqTable irq_table[NUM_EXTI] = {
  {.irqnb = EXTI0_IRQn,     .callback = NULL}, //GPIO_PIN_0
  {.irqnb = EXTI1_IRQn,     .callback = NULL}, //GPIO_PIN_1
  {.irqnb = EXTI2_IRQn, 	.callback = NULL}, //GPIO_PIN_2
  {.irqnb = EXTI3_IRQn,     .callback = NULL}, //GPIO_PIN_3
  {.irqnb = EXTI4_IRQn,     .callback = NULL}, //GPIO_PIN_4
  {.irqnb = EXTI9_5_IRQn,   .callback = NULL}, //GPIO_PIN_5
  {.irqnb = EXTI9_5_IRQn,   .callback = NULL}, //GPIO_PIN_6
  {.irqnb = EXTI9_5_IRQn,   .callback = NULL}, //GPIO_PIN_7
  {.irqnb = EXTI9_5_IRQn,   .callback = NULL}, //GPIO_PIN_8
  {.irqnb = EXTI9_5_IRQn,   .callback = NULL}, //GPIO_PIN_9
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}, //GPIO_PIN_10
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}, //GPIO_PIN_11
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}, //GPIO_PIN_12
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}, //GPIO_PIN_13
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}, //GPIO_PIN_14
  {.irqnb = EXTI15_10_IRQn, .callback = NULL}  //GPIO_PIN_15
};

static uint8_t GetPinID(uint16_t pin)
{
  uint8_t id = 0;

  while (pin != 0x0001) {
    pin = pin >> 1;
    id++;
  }

  return id;
}


//------------------------------------------------------------------//
//     						GPIO Pin Class							//
//------------------------------------------------------------------//

GpioPin::GpioPin()
{
}

// GPIO Initializer for Output Pins
void GpioPin::Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode,
		GpioSpeed speed, GpioState initState, GpioPull pupdType)
{

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	InitializeClocks(port);

	pinNumber_ = pin;
	portName_ = port;
	mode_ = mode;

	// Determine the IO type
	if (mode == kGpioModeOutputPP || mode == kGpioModeOutputOD) {
		ioType_ = kGpioTypeOutput;
	}

	// Set the initial sate of the pin
	SetBit(initState);

	// Use the HAL libraries to initialize the pin
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Pull = pupdType;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Speed = speed;
	HAL_GPIO_Init(port, &GPIO_InitStruct);

}


// GPIO Initializer for Input, IT and Analog Pins
void GpioPin::Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode,
		GpioPull pupdType)
{

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	InitializeClocks(port);

	pinNumber_ = pin;
	portName_ = port;
	mode_ = mode;

	// Determine the IO type
	if (mode == kGpioModeInput || mode == kGpioModeAnalog
			|| mode == kGpioModeITRising || mode == kGpioModeITFalling
			|| mode == kGpioModeITRisingFalling)
	{
		ioType_ = kGpioTypeInput;
	}

	// Use the HAL libraries to initialize the pin
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Pull = pupdType;
	GPIO_InitStruct.Mode = mode;
	HAL_GPIO_Init(port, &GPIO_InitStruct);

	// Interrupt is initialized when the callback function is registered
}

// GPIO Initializer for AF pins
void GpioPin::Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode, GpioSpeed speed,
		GpioPull pupdType, uint8_t afSelection)
{

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	InitializeClocks(port);

	pinNumber_ = pin;
	portName_ = port;
	mode_ = mode;

	// Determine the IO type
	if (mode == kGpioModeAFPP || mode == kGpioModeAFOD) {
		ioType_ = kGpioAlternateFunction;
	}

	// Use the HAL libraries to initialize the pin
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Pull = pupdType;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Alternate = afSelection;
	HAL_GPIO_Init(port, &GPIO_InitStruct);
}

// TODO: Destructor
GpioPin::~GpioPin(){}


void GpioPin::SetBit(bool value)
{
	// Only set bit if the pin is an output type
	if (ioType_ == kGpioTypeOutput) {
		if (value == 1) {
			HAL_GPIO_WritePin(portName_, pinNumber_, GPIO_PIN_SET);
		}
		else {
			HAL_GPIO_WritePin(portName_, pinNumber_, GPIO_PIN_RESET);
		}
	}
}

void GpioPin::operator = (bool value)
{
    SetBit(value);
}

bool GpioPin::GetBit(void)
{
    return  HAL_GPIO_ReadPin(portName_, pinNumber_) ?
    		kGpioStateHigh : kGpioStateLow;
}

GpioPin::operator bool()
{
    return GetBit();
}

GpioStatus GpioPin::RegisterCallback(gpio_callback_function_t callback, uint32_t preempt_proprity, uint32_t subpriority)
 {
	GpioStatus status;

	if (mode_ != kGpioModeITRising &&
			mode_ != kGpioModeITFalling &&
			mode_ != kGpioModeITRisingFalling) {
		status = kIntNotAssignedErr;
	} else {
		uint8_t id = GetPinID(pinNumber_);

		// Check if interrupt has already been assigned
		if (irq_table[id].callback != NULL) {
			status = kExtiAssignedErr;
		} else {
			// If no interrupt is assigned then assign the callback function
			irq_table[id].callback = callback;

			// Enable interrupt for pin
			HAL_NVIC_SetPriority(irq_table[id].irqnb, preempt_proprity,
					subpriority);
			HAL_NVIC_EnableIRQ(irq_table[id].irqnb);

			status = kNoError;
		}
	}

	return status;
}

// Private Functions
//===========================================


void GpioPin::InitializeClocks(GPIO_TypeDef *port){
	// GPIO Ports Clock Enable
	if (port == GPIOA) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if (port == GPIOB) {
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if (port == GPIOC) {
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}
	else if (port == GPIOD) {
		__HAL_RCC_GPIOD_CLK_ENABLE();
	}
	else if (port == GPIOE) {
		__HAL_RCC_GPIOE_CLK_ENABLE();
	}
	else if (port == GPIOF) {
		__HAL_RCC_GPIOF_CLK_ENABLE();
	}
	else if (port == GPIOG) {
		__HAL_RCC_GPIOG_CLK_ENABLE();
	}
	else if (port == GPIOH) {
		__HAL_RCC_GPIOH_CLK_ENABLE();
	}
	else if (port == GPIOI) {
		__HAL_RCC_GPIOI_CLK_ENABLE();
	}
	else if (port == GPIOJ) {
		__HAL_RCC_GPIOJ_CLK_ENABLE();
	}
	else if (port == GPIOK) {
		__HAL_RCC_GPIOK_CLK_ENABLE();
	}

}



//------------------------------------------------------------------//
//     						GPIO Class								//
//------------------------------------------------------------------//

void Gpio::Init()
{

	//------------------------------------------------------------------//
	//     					Digital Output Pins							//
	//------------------------------------------------------------------//

	//-------------------------------------
	//  		Power Supply Enables
	//-------------------------------------

	enable_5v.Init(ENABLE_5V_GPIO_Port, ENABLE_5V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	enable_12v.Init(ENABLE_12V_GPIO_Port, ENABLE_12V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	enable_17v.Init(ENABLE_17V_GPIO_Port, ENABLE_17V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	//-------------------------------------
	//  		Load Switch Outputs
	//-------------------------------------

	load_en_logic.Init(LOAD_EN_LOGIC_PWR_GPIO_Port,
								LOAD_EN_LOGIC_PWR_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_5v.Init(LOAD_EN_5V_GPIO_Port,
								LOAD_EN_5V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_12v.Init(LOAD_EN_12V_GPIO_Port,
								LOAD_EN_12V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_17v.Init(LOAD_EN_17V_GPIO_Port,
								LOAD_EN_17V_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_lidar1.Init(LOAD_EN_LIDAR_1_GPIO_Port,
								LOAD_EN_LIDAR_1_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_lidar2.Init(LOAD_EN_LIDAR_2_GPIO_Port,
								LOAD_EN_LIDAR_2_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_lidar3.Init(LOAD_EN_LIDAR_3_GPIO_Port,
								LOAD_EN_LIDAR_3_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_lidar4.Init(LOAD_EN_LIDAR_4_GPIO_Port,
								LOAD_EN_LIDAR_4_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	load_en_24v_1.Init(LOAD_EN_24V_1_GPIO_Port,
								LOAD_EN_24V_1_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullDown);

	load_en_24v_2.Init(LOAD_EN_24V_2_GPIO_Port,
								LOAD_EN_24V_2_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullDown);

	load_en_24v_3.Init(LOAD_EN_24V_3_GPIO_Port,
								LOAD_EN_24V_3_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullDown);

	// Temporary
	oled_reset.Init(OLED_RESET_GPIO_Port, OLED_RESET_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	oled_sa0.Init(OLED_SA0_DC_GPIO_Port, OLED_SA0_DC_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

	oled_cs.Init(OLED_CS_GPIO_Port, OLED_CS_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	//-------------------------------------
	//  		ESTOP Input Pins
	//-------------------------------------
	estop_phy_p.Init(ESTOP2_GPIO_Port, ESTOP2_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	estop_phy_n.Init(ESTOP1_GPIO_Port, ESTOP1_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	//-------------------------------------
	//  		ESTOP Output Pins
	//-------------------------------------
	n_estop_output.Init(ESTOP_OUTPUT_GPIO_Port, ESTOP_OUTPUT_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);


	//-------------------------------------
	//  		Digital Input Pins
	//-------------------------------------
	//power_switch.Init(POWER_SWITCH_GPIO_Port, POWER_SWITCH_Pin,
	//							kGpioModeInput,
	//							kGpioSpeedLow,
	//							kGpioStateHigh,
	//							kGpioPullOff);

	user_switch.Init(USER_SWITCH_GPIO_Port, USER_SWITCH_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	white_led_switch.Init(WHITE_LED_SW_GPIO_Port, WHITE_LED_SW_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);


	//-------------------------------------
	//  		Vehicle ID Input Pins
	//-------------------------------------
	veh_id_0.Init(ID0_GPIO_Port, ID0_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	veh_id_1.Init(ID1_GPIO_Port, ID1_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	veh_id_2.Init(ID2_GPIO_Port, ID2_Pin,
								kGpioModeInput,
								kGpioSpeedLow,
								kGpioStateHigh,
								kGpioPullOff);

	//-------------------------------------
	//  		Traffic LED Inidicator
	//-------------------------------------
	traffic_led.Init(TRAFFIC_LED_GPIO_Port, TRAFFIC_LED_Pin,
								kGpioModeOutputPP,
								kGpioSpeedLow,
								kGpioStateLow,
								kGpioPullOff);

}


//------------------------------------------------------------------//
//     				HAL GPIO Callback Functions						//
//------------------------------------------------------------------//


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	uint8_t irq_id = GetPinID(GPIO_Pin);

	if (irq_table[irq_id].callback != NULL) {
		irq_table[irq_id].callback();
	}
}
