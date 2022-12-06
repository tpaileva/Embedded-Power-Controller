#ifndef GPIO_H_
#define GPIO_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include <functional>

// Forward declaration
class GpioPin;

// Extern all GPIO Pins

// Power supply enables
extern GpioPin enable_5v;
extern GpioPin enable_12v;
extern GpioPin enable_17v;

// Load switch enables
extern GpioPin load_en_logic;
extern GpioPin load_en_5v;
extern GpioPin load_en_12v;
extern GpioPin load_en_17v;
extern GpioPin load_en_lidar1;
extern GpioPin load_en_lidar2;
extern GpioPin load_en_lidar3;
extern GpioPin load_en_lidar4;
extern GpioPin load_en_24v_1;
extern GpioPin load_en_24v_2;
extern GpioPin load_en_24v_3;

// Oled GPIO Pins
extern GpioPin oled_reset;
extern GpioPin oled_sa0;
extern GpioPin oled_cs;

// Estop Pins
extern GpioPin estop_phy_p;
extern GpioPin estop_phy_n;
extern GpioPin n_estop_output;

// Input Switches
//extern GpioPin power_switch;
extern GpioPin user_switch;
extern GpioPin white_led_switch;

// Vehicle ID Switches
extern GpioPin veh_id_0;
extern GpioPin veh_id_1;
extern GpioPin veh_id_2;

// Traffic LED
extern GpioPin traffic_led;


enum GpioMode {
	kGpioModeOutputPP = GPIO_MODE_OUTPUT_PP,
	kGpioModeOutputOD = GPIO_MODE_OUTPUT_OD,
	kGpioModeAFPP = GPIO_MODE_AF_PP,
	kGpioModeAFOD = GPIO_MODE_AF_OD,
	kGpioModeInput = GPIO_MODE_INPUT,
	kGpioModeAnalog = GPIO_MODE_ANALOG,
	kGpioModeITRising = GPIO_MODE_IT_RISING,
	kGpioModeITFalling = GPIO_MODE_IT_FALLING,
	kGpioModeITRisingFalling = GPIO_MODE_IT_RISING_FALLING
};

enum GpioType {
	kGpioTypeOutput = 0,
	kGpioTypeInput,
	kGpioAlternateFunction
};

enum GpioPull {
	kGpioPullOff = GPIO_NOPULL,
	kGpioPullUp = GPIO_PULLUP,
	kGpioPullDown = GPIO_PULLDOWN
};

enum GpioSpeed {
	kGpioSpeedLow = 0,
	kGpioSpeedMedium,
	kGpioSpeedHigh,
	kGpioSpeedVeryHigh
};

enum GpioState {
	kGpioStateLow = 0,
	kGpioStateHigh,
};

enum GpioIntType {
	kGpioFalling = 0,
	kGpioRising
};

enum GpioStatus {
	kNoError = 0,
	kExtiAssignedErr,
	kIntNotAssignedErr
};

typedef std::function<void()> gpio_callback_function_t;

class GpioPin {

public:
	// Default constructor
	GpioPin(void);
	// Constructor for GPO pins
	void Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode, GpioSpeed speed,
			GpioState initState, GpioPull pupdType);
	// Constructor for AF pins
	void Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode, GpioSpeed speed,
			GpioPull pupdType, uint8_t afSelection);
	// Constructor for input pins
	void Init(GPIO_TypeDef *port, uint16_t pin, GpioMode mode, GpioPull pupdType);

	virtual ~GpioPin();
	virtual void SetBit(bool value);
	void operator =(bool value);
	virtual bool GetBit(void);
	operator bool();

	GpioStatus RegisterCallback(gpio_callback_function_t callback, uint32_t preempt_proprity = 3, uint32_t subpriority = 0);

private:
	uint16_t pinNumber_;
	GPIO_TypeDef *portName_;
	uint32_t mode_;
	GpioType ioType_;

	void InitializeClocks(GPIO_TypeDef *port);

};

class Gpio {
private:

public:

	static void Init(void);
};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
// 	*Place HAL function constructors here*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H_ */
