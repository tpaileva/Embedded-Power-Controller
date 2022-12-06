/*
 * it.cpp
 *
 *      Author: t. pailevanian
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "it.h"
#include "uart.h"
#include "tim.h"
#include "adc.h"
#include "spi.h"

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
void NMI_Handler(void) {}

void HardFault_Handler(void) {
	while (1) {}
}

void MemManage_Handler(void) {
	while (1) {}
}

void BusFault_Handler(void) {
	while (1) {}
}

void UsageFault_Handler(void) {
	while (1) {}
}

void SVC_Handler(void) {}

void DebugMon_Handler(void) {}

void PendSV_Handler(void) {}

void SysTick_Handler(void) {
	HAL_IncTick();
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/////////////////////////////////////////////
// 		TIMER INTERRUPT ROUTINES
/////////////////////////////////////////////

void TIM2_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim2.GetTimHandle());
}

void TIM3_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim3.GetTimHandle());
}

void TIM4_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim4.GetTimHandle());
}

void TIM5_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim5.GetTimHandle());
}

void TIM6_DAC_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim6.GetTimHandle());
}

void TIM7_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim7.GetTimHandle());
}

void TIM1_BRK_TIM9_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim9.GetTimHandle());
}

void TIM1_UP_TIM10_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim10.GetTimHandle());
}

void TIM1_TRG_COM_TIM11_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim11.GetTimHandle());
}

void TIM8_BRK_TIM12_IRQHandler(void) {
 HAL_TIM_IRQHandler(Tim12.GetTimHandle());
}

void TIM8_UP_TIM13_IRQHandler(void) {
 HAL_TIM_IRQHandler(Tim13.GetTimHandle());
}

void TIM8_TRG_COM_TIM14_IRQHandler(void) {
  HAL_TIM_IRQHandler(Tim14.GetTimHandle());
}

/////////////////////////////////////////////
// 		ADC INTERRUPT ROUTINES
/////////////////////////////////////////////

void ADC_IRQHandler(void) {

	if(__HAL_ADC_GET_IT_SOURCE(Adc::GetAdc1Handle(), ADC_IT_EOC)) {
		HAL_ADC_ConvCpltCallback(Adc::GetAdc1Handle());
	}
}

/////////////////////////////////////////////
// 		UART INTERRUPT ROUTINES
/////////////////////////////////////////////

void USART3_IRQHandler(void) {
	HAL_UART_IRQHandler(Serial.GetUartHandle());
}

void UART4_IRQHandler(void) {
  HAL_UART_IRQHandler(Xbee.GetUartHandle());
}

void UART5_IRQHandler(void) {
  HAL_UART_IRQHandler(Uart5.GetUartHandle());
}

/////////////////////////////////////////////
// 		USB INTERRUPT ROUTINES
/////////////////////////////////////////////

void OTG_FS_IRQHandler(void) {
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
}

/////////////////////////////////////////////
// 		SPI INTERRUPT ROUTINES
/////////////////////////////////////////////
void SPI1_IRQHandler(void) {
	HAL_SPI_IRQHandler(Spi1.GetSpiHandle());
}
void DMA2_Stream0_IRQHandler(void) {
	HAL_DMA_IRQHandler(Spi1.GetSpiDmaRxHandle());
}
void DMA2_Stream3_IRQHandler(void) {
	HAL_DMA_IRQHandler(Spi1.GetSpiDmaTxHandle());
}

/////////////////////////////////////////////
// 		EXTI INTERRUPT ROUTINES
/////////////////////////////////////////////

void EXTI0_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

void EXTI2_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI3_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

void EXTI4_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void EXTI9_5_IRQHandler(void) {
	uint32_t pin;
	for (pin = GPIO_PIN_5; pin <= GPIO_PIN_9; pin = pin << 1) {
		HAL_GPIO_EXTI_IRQHandler(pin);
	}
}

void EXTI15_10_IRQHandler(void) {
	uint32_t pin;
	for (pin = GPIO_PIN_10; pin <= GPIO_PIN_15; pin = pin << 1) {
		HAL_GPIO_EXTI_IRQHandler(pin);
	}
}
