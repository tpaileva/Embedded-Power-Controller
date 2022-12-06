/*
 * uart.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: t. pailevanian
 */

#include "uart.h"

Uart Serial(USART3, DEBUG_SERIAL_TX_GPIO_Port, DEBUG_SERIAL_TX_Pin, DEBUG_SERIAL_TX_AF,
				DEBUG_SERIAL_RX_GPIO_Port, DEBUG_SERIAL_RX_Pin, DEBUG_SERIAL_RX_AF);

Uart Xbee(UART4, XBEE_TX_GPIO_Port, XBEE_TX_Pin, XBEE_TX_AF,
				XBEE_RX_GPIO_Port, XBEE_RX_Pin, XBEE_RX_AF);

Uart Uart5(UART5, UART5_TX_GPIO_Port, UART5_TX_Pin, UART5_TX_AF,
				UART5_RX_GPIO_Port, UART5_RX_Pin, UART5_RX_AF);

//------------------------------------------------------------------//
//     						UART Class								//
//------------------------------------------------------------------//

Uart::Uart(USART_TypeDef* usart, GPIO_TypeDef *tx_port, uint16_t tx_pin, uint8_t tx_alt_func,
		GPIO_TypeDef *rx_port, uint16_t rx_pin, uint8_t rx_alt_func)
{
	tx_port_ = tx_port;
	tx_pin_ = tx_pin;
	tx_alt_func_ = tx_alt_func;

	rx_port_ = rx_port;
	rx_pin_ = rx_pin;
	rx_alt_func_ = rx_alt_func;

	usart_ = usart;

	uart_type_ = kStandadUart;

}

Uart::Uart(USART_TypeDef* usart, GPIO_TypeDef *tx_port, uint16_t tx_pin, uint8_t tx_alt_func,
			GPIO_TypeDef *rx_port, uint16_t rx_pin, uint8_t rx_alt_func,
			GPIO_TypeDef *rs485_dir_port, uint16_t rs485_dir_pin) {

	tx_port_ = tx_port;
	tx_pin_ = tx_pin;
	tx_alt_func_ = tx_alt_func;

	rx_port_ = rx_port;
	rx_pin_ = rx_pin;
	rx_alt_func_ = rx_alt_func;

	rs485_dir_port_ = rs485_dir_port;
	rs485_dir_pin_ = rs485_dir_pin;

	usart_ = usart;

	uart_type_ = kRs485Uart;

}

Uart::~Uart(){}

UART_HandleTypeDef * Uart::GetUartHandle()
{
	return &h_uart_;
}

bool Uart::Init(uint32_t baudrate, UartWordLength word_length, UartStopBits stop_bits, UartParity parity)
{
	baudrate_ = baudrate;

	InitializeClocks(usart_);

	uart_tx_.Init(tx_port_, tx_pin_,
						kGpioModeAFPP,
						kGpioSpeedVeryHigh,
						kGpioPullUp,
						tx_alt_func_);

	uart_rx_.Init(rx_port_, rx_pin_,
						kGpioModeAFPP,
						kGpioSpeedVeryHigh,
						kGpioPullUp,
						rx_alt_func_);

	if(uart_type_ == kRs485Uart)
	{
		rs485_dir_.Init(rs485_dir_port_, rs485_dir_pin_,
								kGpioModeOutputPP,
								kGpioSpeedMedium,
								kGpioStateLow,
								kGpioPullOff);
	}

	h_uart_.Instance = usart_;
	h_uart_.Init.BaudRate = baudrate;
	h_uart_.Init.WordLength = word_length;
	h_uart_.Init.StopBits = stop_bits;
	h_uart_.Init.Parity = parity;
	h_uart_.Init.Mode = UART_MODE_TX_RX;
	h_uart_.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	h_uart_.Init.OverSampling = UART_OVERSAMPLING_16;

	// Initialize the serial port
	if (HAL_UART_Init(&h_uart_) != HAL_OK) {
		return false;
	}

	rx_buffer.Reset();
	tx_buffer.Reset();

	// Enable Interrupts
	EnableInterrupts(2,0);

	// Start Serial Receive
	HAL_UART_Receive_IT(&h_uart_, &rx_data_reg_, 1);

	return true;
}

bool Uart::Init(uint32_t baudrate)
{
	return Init(baudrate, k8bLength, kUartStopBits1, kUartParityNone);
}


void Uart::EnableInterrupts(uint32_t preempt_priority, uint32_t subpriority)
{
	if(h_uart_.Instance == USART3){
		HAL_NVIC_SetPriority(USART3_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(USART3_IRQn);
	}
	else if(h_uart_.Instance == UART4){
		HAL_NVIC_SetPriority(UART4_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(UART4_IRQn);
	}
	else if(h_uart_.Instance == UART5){
		HAL_NVIC_SetPriority(UART5_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(UART5_IRQn);
	}
}

void Uart::DisableInterrupts()
{
	if(h_uart_.Instance == USART3){
		HAL_NVIC_DisableIRQ(USART3_IRQn);
	}
	else if(h_uart_.Instance == UART4){
		HAL_NVIC_DisableIRQ(UART4_IRQn);
	}
	else if(h_uart_.Instance == UART5){
		HAL_NVIC_DisableIRQ(UART5_IRQn);
	}
}

UartStatus Uart::Write(uint8_t *data, uint8_t size)
{
	UartStatus status = kUartSuccess;

	for(uint8_t i = 0; i < size; i++)
	{
		if(!tx_buffer.Put(data[i]))
		{
			status = kTxBufFull;
			return status;
		}
	}

	// Check to see if the TX interrupt is enabled
	// 	if not re-enable uart sending with interrupt
	//if(READ_BIT(ser->uart_handle->Instance->CR1, USART_CR1_TXEIE) != 1)
	if (h_uart_.gState != HAL_UART_STATE_BUSY_TX) {

		if (!tx_buffer.IsEmpty()) {

			// If uart type is RS485 then toggle the direction pin between transfers
			if (uart_type_ == kRs485Uart) {
				rs485_dir_.SetBit(1);
			}

			// Get one byte from the buffer and place in the TX register
			tx_buffer.Get(&tx_data_reg_);

			// Transmit the data over the serial interface
			HAL_UART_Transmit_IT(&h_uart_, &tx_data_reg_, 1);
		}

	}

	return status;
}

bool Uart::WriteString(const char *c, ...)
{
	bool status;

	char buffer[500];
	uint16_t num_bytes;

	va_list args;
	va_start(args, c);

	num_bytes = vsprintf (buffer,c, args);

	status = (Write((uint8_t*) buffer, num_bytes) == kUartSuccess);

	va_end(args);

	return status;
}

UartStatus Uart::Read(uint8_t *data)
{
	UartStatus status;

	if (rx_buffer.Get(data)) {

		status = kUartSuccess;
	} else { // RX buffer was empty

		status = kRxBufEmpty;
	}

	return status;
}

UartStatus Uart::Flush() {

	UartStatus status = kUartSuccess;

	uint32_t start_tick = GetTicks();

	// (1000 ms/s * 1/ baudrate * 10 bits/packet) + 2ms margin
	uint32_t timeout = tx_buffer.Available() * (uint32_t)(1000.0 / (float)(baudrate_) * 10.0) + 2;

	while(!tx_buffer.IsEmpty()){
		if((start_tick + timeout) > GetTicks()) {
			status = kUartTimeout;
			break;
		}
	}

	return status;
}

uint8_t Uart::Available()
{
	return rx_buffer.Available();
}

uint32_t Uart::GetBaudrate() {
	return baudrate_;
}

void Uart::TxCpltCallback()
{
	// Check to see if data is available to send
	if (!tx_buffer.IsEmpty()) {
		// Pop next byte from buffer
		tx_buffer.Get(&tx_data_reg_);

		// Send the byte over the UART using interrupts (Non-blocking)
		HAL_UART_Transmit_IT(&h_uart_, &tx_data_reg_, 1);
	} else // TX buffer empty
	{
		// If uart type is RS485 then toggle the direction pin between transfers
		if (uart_type_ == kRs485Uart) {
			rs485_dir_.SetBit(0);
		}
	}
}

void Uart::RxCpltCallback()
{
	// Queue the data into the buffer
	rx_buffer.Put(rx_data_reg_);

	// Initiate another read of serial data
	HAL_UART_Receive_IT(&h_uart_, &rx_data_reg_, 1);
}

void Uart::ErrorCallback() {

	error_code_ = h_uart_.ErrorCode;

}

// Private Functions
//===========================================

void Uart::InitializeClocks(USART_TypeDef* usart)
{
	if(usart == USART1){
		__HAL_RCC_USART1_CLK_ENABLE();
	}
	else if(usart == USART2){
		__HAL_RCC_USART2_CLK_ENABLE();
	}
	else if(usart == USART3){
		__HAL_RCC_USART3_CLK_ENABLE();
	}
	else if(usart == UART4){
		__HAL_RCC_UART4_CLK_ENABLE();
	}
	else if(usart == UART5){
		__HAL_RCC_UART5_CLK_ENABLE();
	}
}

//------------------------------------------------------------------//
//     				HAL UART Callback Functions						//
//------------------------------------------------------------------//

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

	if (huart == Serial.GetUartHandle()) {
		Serial.TxCpltCallback();
	} else if (huart == Xbee.GetUartHandle()) {
		Xbee.TxCpltCallback();
	} else if (huart == Uart5.GetUartHandle()) {
		Uart5.TxCpltCallback();
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	if (huart == Serial.GetUartHandle()) {
		Serial.RxCpltCallback();
	} else if (huart == Xbee.GetUartHandle()) {
		Xbee.RxCpltCallback();
	} else if (huart == Uart5.GetUartHandle()) {
		Uart5.RxCpltCallback();
	}
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {
	if (huart == Serial.GetUartHandle()) {
		Serial.ErrorCallback();
	} else if (huart == Xbee.GetUartHandle()) {
		Xbee.ErrorCallback();
	} else if (huart == Uart5.GetUartHandle()) {
		Uart5.ErrorCallback();
	}
}

