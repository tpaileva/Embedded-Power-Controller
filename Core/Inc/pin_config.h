#ifndef PIN_CONFIG_H_
#define PIN_CONFIG_H_

//------------------------------------------------------------------//
//     					Digital Output Pins							//
//------------------------------------------------------------------//

//-------------------------------------
//     OLED Display Output Pins
//-------------------------------------
#define OLED_RESET_Pin 					GPIO_PIN_11
#define OLED_RESET_GPIO_Port 			GPIOE

#define OLED_SA0_DC_Pin 				GPIO_PIN_12
#define OLED_SA0_DC_GPIO_Port 			GPIOE

#define OLED_CS_Pin 					GPIO_PIN_13
#define OLED_CS_GPIO_Port 				GPIOE

//-------------------------------------
//     Power Supply Enable Pins
//-------------------------------------

#define ENABLE_5V_Pin 					GPIO_PIN_7
#define ENABLE_5V_GPIO_Port 			GPIOG

#define ENABLE_12V_Pin 					GPIO_PIN_15
#define ENABLE_12V_GPIO_Port 			GPIOA

#define ENABLE_17V_Pin 					GPIO_PIN_15
#define ENABLE_17V_GPIO_Port 			GPIOE

//-------------------------------------
//     Load Switch Enable Pins
//-------------------------------------

#define LOAD_EN_LOGIC_PWR_Pin 			GPIO_PIN_0
#define LOAD_EN_LOGIC_PWR_GPIO_Port 	GPIOE

#define LOAD_EN_5V_Pin 					GPIO_PIN_11
#define LOAD_EN_5V_GPIO_Port 			GPIOG

#define LOAD_EN_12V_Pin 				GPIO_PIN_12
#define LOAD_EN_12V_GPIO_Port 			GPIOG

#define LOAD_EN_17V_Pin 				GPIO_PIN_9
#define LOAD_EN_17V_GPIO_Port 			GPIOG

#define LOAD_EN_LIDAR_1_Pin 			GPIO_PIN_8
#define LOAD_EN_LIDAR_1_GPIO_Port 		GPIOB

#define LOAD_EN_LIDAR_2_Pin 			GPIO_PIN_15
#define LOAD_EN_LIDAR_2_GPIO_Port 		GPIOG

#define LOAD_EN_LIDAR_3_Pin 			GPIO_PIN_13
#define LOAD_EN_LIDAR_3_GPIO_Port 		GPIOG

#define LOAD_EN_LIDAR_4_Pin 			GPIO_PIN_14
#define LOAD_EN_LIDAR_4_GPIO_Port 		GPIOG

#define LOAD_EN_24V_1_Pin 				GPIO_PIN_9
#define LOAD_EN_24V_1_GPIO_Port 		GPIOB

#define LOAD_EN_24V_2_Pin 				GPIO_PIN_10
#define LOAD_EN_24V_2_GPIO_Port 		GPIOG

#define LOAD_EN_24V_3_Pin 				GPIO_PIN_5
#define LOAD_EN_24V_3_GPIO_Port 		GPIOG

//-------------------------------------
//     		E-Stop Output Pins
//-------------------------------------

#define ESTOP_OUTPUT_Pin 				GPIO_PIN_8
#define ESTOP_OUTPUT_GPIO_Port 			GPIOG

//-------------------------------------
//     	    Auxiliary CS Pins
//-------------------------------------

#define SPI_CS1_Pin 					GPIO_PIN_1
#define SPI_CS1_GPIO_Port 				GPIOD


//------------------------------------------------------------------//
//     					Digital Input Pins							//
//------------------------------------------------------------------//

//-------------------------------------
//  		Vehicle ID switches
//-------------------------------------
#define ID0_Pin 						GPIO_PIN_2
#define ID0_GPIO_Port 					GPIOF

#define ID1_Pin	 						GPIO_PIN_5
#define ID1_GPIO_Port 					GPIOD

#define ID2_Pin 						GPIO_PIN_4
#define ID2_GPIO_Port 					GPIOD

//-------------------------------------
//  		Switch Inputs
//-------------------------------------

#define POWER_SWITCH_Pin 				GPIO_PIN_3
#define POWER_SWITCH_GPIO_Port 			GPIOD

#define USER_SWITCH_Pin 				GPIO_PIN_7
#define USER_SWITCH_GPIO_Port 			GPIOD

#define WHITE_LED_SW_Pin 				GPIO_PIN_6
#define WHITE_LED_SW_GPIO_Port 			GPIOG

//-------------------------------------
//  		E-Stop Inputs
//-------------------------------------

#define ESTOP1_Pin 						GPIO_PIN_8
#define ESTOP1_GPIO_Port 				GPIOA

#define ESTOP2_Pin 						GPIO_PIN_10
#define ESTOP2_GPIO_Port 				GPIOA

#define RF_KILL_Pin 					GPIO_PIN_6
#define RF_KILL_GPIO_Port 				GPIOD

//-------------------------------------
//   	Input Protection Fault Inputs
//-------------------------------------

#define FAULT_Pin 						GPIO_PIN_1
#define FAULT_GPIO_Port 				GPIOE


//------------------------------------------------------------------//
//     					Timer Channel Pins							//
//------------------------------------------------------------------//

//-------------------------------------
//     		Fan Control
//-------------------------------------

#define FAN_CONTROL_1_Pin 				GPIO_PIN_5
#define FAN_CONTROL_1_GPIO_Port 		GPIOE
#define FAN_CONTROL_1_AF				GPIO_AF3_TIM9
#define FAN_CONTROL_1_TIMER_CHANNEL		TIM_CHANNEL_1
#define FAN_CONTROL_1_TIMER				&Tim9

#define FAN_CONTROL_2_Pin 				GPIO_PIN_6
#define FAN_CONTROL_2_GPIO_Port 		GPIOE
#define FAN_CONTROL_2_AF				GPIO_AF3_TIM9
#define FAN_CONTROL_2_TIMER_CHANNEL		TIM_CHANNEL_2
#define FAN_CONTROL_2_TIMER				&Tim9

//-------------------------------------
//     		Buzzer
//-------------------------------------

#define BUZZER_Pin 						GPIO_PIN_6
#define BUZZER_GPIO_Port 				GPIOF
#define BUZZER_AF						GPIO_AF3_TIM10
#define BUZZER_TIMER_CHANNEL			TIM_CHANNEL_1
#define BUZZER_TIMER					&Tim10

//-------------------------------------
//     		Extra GPIO Channels
//-------------------------------------

#define GPIO_EXTRA_1_Pin 				GPIO_PIN_8
#define GPIO_EXTRA_1_GPIO_Port 			GPIOF
#define GPIO_EXTRA_1_AF					GPIO_AF9_TIM13
#define GPIO_EXTRA_1_TIMER_CHANNEL		TIM_CHANNEL_1
#define GPIO_EXTRA_1_TIMER				&Tim13

//-------------------------------------
//     		Debug LED On Board
//-------------------------------------

#define DEBUG_LED_R_Pin 				GPIO_PIN_0
#define DEBUG_LED_R_GPIO_Port 			GPIOA
#define DEBUG_LED_R_AF					GPIO_AF2_TIM5
#define DEBUG_LED_R_TIMER_CHANNEL		TIM_CHANNEL_1
#define DEBUG_LEG_R_TIMER				&Tim5

#define DEBUG_LED_G_Pin 				GPIO_PIN_1
#define DEBUG_LED_G_GPIO_Port 			GPIOA
#define DEBUG_LED_G_AF					GPIO_AF2_TIM5
#define DEBUG_LED_G_TIMER_CHANNEL		TIM_CHANNEL_2
#define DEBUG_LEG_G_TIMER				&Tim5

#define DEBUG_LED_B_Pin 				GPIO_PIN_2
#define DEBUG_LED_B_GPIO_Port 			GPIOA
#define DEBUG_LED_B_AF					GPIO_AF2_TIM5
#define DEBUG_LED_B_TIMER_CHANNEL		TIM_CHANNEL_3
#define DEBUG_LEG_B_TIMER				&Tim5

//-------------------------------------
//     		RGB Light Strips
//-------------------------------------

#define RGB_BATT_Pin 					GPIO_PIN_10
#define RGB_BATT_GPIO_Port 				GPIOB
#define RGB_BATT_AF						GPIO_AF1_TIM2
#define RGB_BATT_TIMER_CHANNEL			TIM_CHANNEL_3
#define RGB_BATT_TIMER					&Tim2

#define RGB_EXTRA_Pin 					GPIO_PIN_11
#define RGB_EXTRA_GPIO_Port 			GPIOB
#define RGB_EXTRA_AF					GPIO_AF1_TIM2
#define RGB_EXTRA_TIMER_CHANNEL			TIM_CHANNEL_4
#define RGB_EXTRA_TIMER					&Tim2

//-------------------------------------
//     		Traffic Status LED
//-------------------------------------

#define TRAFFIC_LED_Pin 				GPIO_PIN_14
#define TRAFFIC_LED_GPIO_Port 			GPIOB
#define TRAFFIC_LED_AF					GPIO_AF9_TIM12
#define TRAFFIC_LED_TIMER_CHANNEL		TIM_CHANNEL_1
#define TRAFFIC_LED_TIMER				&Tim12

//-------------------------------------
//     		Heartbeat Status LED
//-------------------------------------

#define HEARTBEAT_LED_Pin 				GPIO_PIN_15
#define HEARTBEAT_LED_GPIO_Port 		GPIOB
#define HEARTBEAT_LED_AF				GPIO_AF9_TIM12
#define HEARTBEAT_LED_TIMER_CHANNEL		TIM_CHANNEL_2
#define HEARTBEAT_LED_TIMER				&Tim12

//-------------------------------------
//     		Vehicle Arm Status LEDs
//-------------------------------------

#define ARM_LED_B_Pin 					GPIO_PIN_6
#define ARM_LED_B_GPIO_Port 			GPIOC
#define ARM_LED_B_AF					GPIO_AF2_TIM3
#define ARM_LED_B_TIMER_CHANNEL			TIM_CHANNEL_1
#define ARM_LED_B_TIMER					&Tim3

#define ARM_LED_R_Pin 					GPIO_PIN_7
#define ARM_LED_R_GPIO_Port 			GPIOC
#define ARM_LED_R_AF					GPIO_AF2_TIM3
#define ARM_LED_R_TIMER_CHANNEL			TIM_CHANNEL_2
#define ARM_LED_R_TIMER					&Tim3

#define ARM_LED_G_Pin 					GPIO_PIN_8
#define ARM_LED_G_GPIO_Port 			GPIOC
#define ARM_LED_G_AF					GPIO_AF2_TIM3
#define ARM_LED_G_TIMER_CHANNEL			TIM_CHANNEL_3
#define ARM_LED_G_TIMER					&Tim3

//-------------------------------------
//     	QR Code Illumination LED
//-------------------------------------

#define ILLUMINATION_LED_Pin 			GPIO_PIN_9
#define ILLUMINATION_LED_GPIO_Port 		GPIOC
#define ILLUMINATION_LED_G_AF			GPIO_AF2_TIM3
#define ILLUMINATION_LED_G_TIMER_CHANNEL TIM_CHANNEL_4
#define ILLUMINATION_LED_G_TIMER		&Tim3

//-------------------------------------
//     	Bright White LEDs
//-------------------------------------

#define WHITE_LED_1_Pin 				GPIO_PIN_15
#define WHITE_LED_1_GPIO_Port 			GPIOD
#define WHITE_LED_1_AF					GPIO_AF2_TIM4
#define WHITE_LED_1_TIMER_CHANNEL		TIM_CHANNEL_4
#define WHITE_LED_1_TIMER				&Tim4

#define WHITE_LED_2_Pin 				GPIO_PIN_14
#define WHITE_LED_2_GPIO_Port 			GPIOD
#define WHITE_LED_2_AF					GPIO_AF2_TIM4
#define WHITE_LED_2_TIMER_CHANNEL		TIM_CHANNEL_3
#define WHITE_LED_2_TIMER				&Tim4

#define WHITE_LED_3_Pin 				GPIO_PIN_13
#define WHITE_LED_3_GPIO_Port 			GPIOD
#define WHITE_LED_3_AF					GPIO_AF2_TIM4
#define WHITE_LED_3_TIMER_CHANNEL		TIM_CHANNEL_2
#define WHITE_LED_3_TIMER				&Tim4

#define WHITE_LED_4_Pin 				GPIO_PIN_12
#define WHITE_LED_4_GPIO_Port 			GPIOD
#define WHITE_LED_4_AF					GPIO_AF2_TIM4
#define WHITE_LED_4_TIMER_CHANNEL		TIM_CHANNEL_1
#define WHITE_LED_4_TIMER				&Tim4

//------------------------------------------------------------------//
//     				  Peripheral Specific Pins						//
//------------------------------------------------------------------//

// Digital Comm (Extra Pins)
#define CAN2_RX_Pin 					GPIO_PIN_12
#define CAN2_RX_GPIO_Port 				GPIOB
#define CAN2_AF							GPIO_AF9_CAN2

#define CAN2_TX_Pin 					GPIO_PIN_13
#define CAN2_TX_GPIO_Port 				GPIOB
#define CAN2_TX_AF						GPIO_AF9_CAN2

// USB Pins
#define USB_VBUS_Pin 					GPIO_PIN_9
#define USB_VBUS_GPIO_Port 				GPIOA

#define USB_DN_Pin 						GPIO_PIN_11
#define USB_DN_GPIO_Port 				GPIOA
#define USB_DN_AF						GPIO_AF10_OTG_FS

#define USB_DP_Pin 						GPIO_PIN_12
#define USB_DP_GPIO_Port 				GPIOA
#define USB_DP_AF						GPIO_AF10_OTG_FS

// Debug UART (USART 3)
#define DEBUG_SERIAL_TX_Pin 			GPIO_PIN_8
#define DEBUG_SERIAL_TX_GPIO_Port 		GPIOD
#define DEBUG_SERIAL_TX_AF				GPIO_AF7_USART3

#define DEBUG_SERIAL_RX_Pin 			GPIO_PIN_9
#define DEBUG_SERIAL_RX_GPIO_Port 		GPIOD
#define DEBUG_SERIAL_RX_AF				GPIO_AF7_USART3

// XBEE Wireless E-STOP UART (UART 4)
#define XBEE_TX_Pin 					GPIO_PIN_10
#define XBEE_TX_GPIO_Port 				GPIOC
#define XBEE_TX_AF						GPIO_AF8_UART4

#define XBEE_RX_Pin 					GPIO_PIN_11
#define XBEE_RX_GPIO_Port 				GPIOC
#define XBEE_RX_AF						GPIO_AF8_UART4

// Spare UART (UART 5)
#define UART5_TX_Pin 					GPIO_PIN_12
#define UART5_TX_GPIO_Port 				GPIOC
#define UART5_TX_AF						GPIO_AF8_UART5

#define UART5_RX_Pin 					GPIO_PIN_2
#define UART5_RX_GPIO_Port 				GPIOD
#define UART5_RX_AF						GPIO_AF8_UART5

// Display SPI
#define SPI1_SCK_Pin 					GPIO_PIN_3
#define SPI1_SCK_GPIO_Port 				GPIOB
#define SPI1_SCK_AF						GPIO_AF5_SPI1

#define SPI1_MISO_Pin 					GPIO_PIN_4
#define SPI1_MISO_GPIO_Port 			GPIOB
#define SPI1_MISO_AF					GPIO_AF5_SPI1

#define SPI1_MOSI_Pin 					GPIO_PIN_5
#define SPI1_MOSI_GPIO_Port 			GPIOB
#define SPI1_MOSI_AF					GPIO_AF5_SPI1

// Sensor I2C Bus
#define I2C1_SCL_Pin 					GPIO_PIN_6
#define I2C1_SCL_GPIO_Port 				GPIOB
#define I2C1_SCL_AF						GPIO_AF4_I2C1

#define I2C1_SDA_Pin 					GPIO_PIN_7
#define I2C1_SDA_GPIO_Port 				GPIOB
#define I2C1_SDA_AF						GPIO_AF4_I2C1

// Extra I2C Bus
#define I2C2_SDA_Pin 					GPIO_PIN_0
#define I2C2_SDA_GPIO_Port 				GPIOF
#define I2C2_SDA_AF						GPIO_AF4_I2C2

#define I2C2_SCL_Pin 					GPIO_PIN_1
#define I2C2_SCL_GPIO_Port 				GPIOF
#define I2C2_SCL_AF						GPIO_AF4_I2C2


//------------------------------------------------------------------//
//     					Analog Input Pins							//
//------------------------------------------------------------------//

// ADC
#define ADC_EXTRA_1_Pin 				GPIO_PIN_0
#define ADC_EXTRA_1_GPIO_Port 			GPIOC
#define ADC_EXTRA_1_Adc					ADC1
#define ADC_EXTRA_1_Adc_Channel			ADC_CHANNEL_10

#define ADC_EXTRA_0_Pin 				GPIO_PIN_1
#define ADC_EXTRA_0_GPIO_Port			GPIOC
#define ADC_EXTRA_0_Adc					ADC1
#define ADC_EXTRA_0_Adc_Channel			ADC_CHANNEL_11

#define VSENSE_LOGIC_Pin 				GPIO_PIN_4
#define VSENSE_LOGIC_GPIO_Port 			GPIOA
#define VSENSE_LOGIC_Adc				ADC1
#define VSENSE_LOGIC_Adc_Channel		ADC_CHANNEL_4

#define VSENSE_17V_Pin 					GPIO_PIN_5
#define VSENSE_17V_GPIO_Port 			GPIOA
#define VSENSE_17V_Adc					ADC1
#define VSENSE_17V_Adc_Channel			ADC_CHANNEL_5

#define VSENSE_12V_Pin 					GPIO_PIN_6
#define VSENSE_12V_GPIO_Port 			GPIOA
#define VSENSE_12V_Adc					ADC1
#define VSENSE_12V_Adc_Channel			ADC_CHANNEL_6

#define VSENSE_5V_Pin 					GPIO_PIN_7
#define VSENSE_5V_GPIO_Port 			GPIOA
#define VSENSE_5V_Adc					ADC1
#define VSENSE_5V_Adc_Channel			ADC_CHANNEL_7

#define VSENSE_MOTOR_Pin 				GPIO_PIN_4
#define VSENSE_MOTOR_GPIO_Port 			GPIOC
#define VSENSE_MOTOR_Adc				ADC1
#define VSENSE_MOTOR_Adc_Channel		ADC_CHANNEL_14

#define VSENSE_LOGIC_SW_Pin 			GPIO_PIN_5
#define VSENSE_LOGIC_SW_GPIO_Port 		GPIOC
#define VSENSE_LOGIC_SW_Adc				ADC1
#define VSENSE_LOGIC_SW_Adc_Channel		ADC_CHANNEL_15

#define ISENSE_MOTOR_Pin 				GPIO_PIN_0
#define ISENSE_MOTOR_GPIO_Port 			GPIOB
#define ISENSE_MOTOR_Adc				ADC1
#define ISENSE_MOTOR_Adc_Channel		ADC_CHANNEL_8

#define ISENSE_LOGIC_Pin 				GPIO_PIN_1
#define ISENSE_LOGIC_GPIO_Port 			GPIOB
#define ISENSE_LOGIC_Adc				ADC1
#define ISENSE_LOGIC_Adc_Channel		ADC_CHANNEL_9

#endif /* PIN_CONFIG_H_ */
