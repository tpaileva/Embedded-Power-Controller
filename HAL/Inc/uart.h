/*
 * uart.h
 *
 *  Created on: Jun 2021
 *      Author: t. pailevanian
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include "gpio.h"
#include "circular_buffer.h"
#include "util.h"

#include <stdarg.h>
#include <string>

// Forward declaration
class Uart;

// Extern Variables
extern Uart Serial;
extern Uart Xbee;
extern Uart Uart5;

// Definitions
#define SERIAL_BUFFER_SIZE	256

// Enumerations
enum UartWordLength {
	k8bLength = UART_WORDLENGTH_8B,
	k9bLength = UART_WORDLENGTH_9B
};

enum UartStopBits {
	kUartStopBits1 = UART_STOPBITS_1,
	kUartStopBits2 = UART_STOPBITS_2
};

enum UartParity {
	kUartParityNone = UART_PARITY_NONE,
	kUartParityEven = UART_PARITY_EVEN,
	kUartParityOdd = UART_PARITY_ODD
};

enum UartSwapRxTx {
	kUartNoSwap = 0,
	kUartSwapPins
};

enum UartType{
	kStandadUart,
	kRs485Uart
};

enum UartStatus{

	kUartSuccess = 0,
	kUartFailed,
	kRxBufEmpty,
	kTxBufFull,
	kUartTimeout
};

class Uart{

public:

	CircularBuffer rx_buffer = CircularBuffer(SERIAL_BUFFER_SIZE);
	CircularBuffer tx_buffer = CircularBuffer(SERIAL_BUFFER_SIZE);

	Uart(USART_TypeDef* usart, GPIO_TypeDef *tx_port, uint16_t tx_pin, uint8_t tx_alt_func,
			GPIO_TypeDef *rx_port, uint16_t rx_pin, uint8_t rx_alt_func);


	Uart(USART_TypeDef* usart, GPIO_TypeDef *tx_port, uint16_t tx_pin, uint8_t tx_alt_func,
			GPIO_TypeDef *rx_port, uint16_t rx_pin, uint8_t rx_alt_func,
			GPIO_TypeDef *rs485_dir_port, uint16_t rs485_dir_pin);

	virtual ~Uart();

	// Initializes the UART with the provided configuration
	bool Init(uint32_t baudrate, UartWordLength word_length, UartStopBits stop_bits, UartParity parity);
	bool Init(uint32_t baudrate);

	// Enables interrupts for the UART with the provided preemption priority and subpriority
	void EnableInterrupts(uint32_t preempt_priority, uint32_t subpriority);

	// Disables interrupts for the UART channel
	void DisableInterrupts();

	UART_HandleTypeDef * GetUartHandle();

	void TxCpltCallback();
	void RxCpltCallback();
	void ErrorCallback();

	UartStatus Write(uint8_t *data, uint8_t size);
	UartStatus Read(uint8_t *data);
	UartStatus Flush(void);
	uint8_t Available();

	bool WriteString(const char * c, ...);

	uint32_t GetBaudrate(void);

private:

	GPIO_TypeDef * tx_port_;
	uint16_t tx_pin_;
	uint8_t tx_alt_func_;

	GPIO_TypeDef * rx_port_;
	uint16_t rx_pin_;
	uint8_t rx_alt_func_;

	GPIO_TypeDef * rs485_dir_port_;
	uint16_t rs485_dir_pin_;

	GpioPin uart_tx_;
	GpioPin uart_rx_;
	GpioPin rs485_dir_;

	uint8_t tx_data_reg_;
	uint8_t rx_data_reg_;

	uint32_t baudrate_;

	uint32_t error_code_;

	USART_TypeDef* usart_;

	UartType uart_type_;

	UART_HandleTypeDef h_uart_;

	// Initialize clocks for the Uart
	void InitializeClocks(USART_TypeDef* usart);


};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif /* UART_H_ */
