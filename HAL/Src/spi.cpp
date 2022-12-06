/*
 * spi.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: t. pailevanian
 */

#include "spi.h"


Spi Spi1(SPI1, SPI1_SCK_GPIO_Port, SPI1_SCK_Pin, SPI1_SCK_AF,
			SPI1_MISO_GPIO_Port, SPI1_MISO_Pin, SPI1_MISO_AF,
			SPI1_MOSI_GPIO_Port, SPI1_MOSI_Pin, SPI1_MOSI_AF);


//------------------------------------------------------------------//
//     						  SPI Class								//
//------------------------------------------------------------------//

Spi::Spi(SPI_TypeDef* spi_instance, GPIO_TypeDef *spi_clk_port, uint16_t spi_clk_pin, uint8_t spi_clk_alt_func,
		GPIO_TypeDef *spi_miso_port, uint16_t spi_miso_pin, uint8_t spi_miso_alt_func,
		GPIO_TypeDef *spi_mosi_port, uint16_t spi_mosi_pin, uint8_t spi_mosi_alt_func)
{

	spi_instance_ = spi_instance;

	spi_clk_port_ = spi_clk_port;
	spi_clk_pin_ = spi_clk_pin;
	spi_clk_alt_func_ = spi_clk_alt_func;

	spi_miso_port_ = spi_miso_port;
	spi_miso_pin_ = spi_miso_pin;
	spi_miso_alt_func_ = spi_miso_alt_func;

	spi_mosi_port_ = spi_mosi_port;
	spi_mosi_pin_ = spi_mosi_pin;
	spi_mosi_alt_func_ = spi_mosi_alt_func;

}

Spi::~Spi(){}

bool Spi::Init(SpiMode mode, SpiRate rate, SpiEndian endian)
{

	spi_rate_ = rate;

	// Initialize clocks
	InitializeClocks(spi_instance_);
	InitializeDmaClocks(spi_instance_);

	// Initialize the GPIO pins associated with the SPI peripheral
	spi_clk_.Init(spi_clk_port_, spi_clk_pin_,
						kGpioModeAFPP,
						kGpioSpeedVeryHigh,
						kGpioPullOff,
						spi_clk_alt_func_);

	spi_miso_.Init(spi_miso_port_, spi_miso_pin_,
						kGpioModeAFPP,
						kGpioSpeedVeryHigh,
						kGpioPullOff,
						spi_miso_alt_func_);

	spi_mosi_.Init(spi_mosi_port_, spi_mosi_pin_,
						kGpioModeAFPP,
						kGpioSpeedVeryHigh,
						kGpioPullOff,
						spi_mosi_alt_func_);

	// Initialize the DMA channels
    // 	SPI TX Init
    h_dma_spi_tx_.Instance = GetDmaStream(spi_instance_, kSpiDmaTxChannel);
    h_dma_spi_tx_.Init.Channel = GetDmaChannel(spi_instance_, kSpiDmaTxChannel);
    h_dma_spi_tx_.Init.Direction = DMA_MEMORY_TO_PERIPH;
    h_dma_spi_tx_.Init.PeriphInc = DMA_PINC_DISABLE;
    h_dma_spi_tx_.Init.MemInc = DMA_MINC_ENABLE;
    h_dma_spi_tx_.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    h_dma_spi_tx_.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    h_dma_spi_tx_.Init.Mode = DMA_NORMAL;
    h_dma_spi_tx_.Init.Priority = DMA_PRIORITY_LOW;
    h_dma_spi_tx_.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

    if (HAL_DMA_Init(&h_dma_spi_tx_) != HAL_OK)
    {
      return false;
    }

    // 	SPI RX Init
    h_dma_spi_rx_.Instance = GetDmaStream(spi_instance_, kSpiDmaRxChannel);
    h_dma_spi_rx_.Init.Channel = GetDmaChannel(spi_instance_, kSpiDmaRxChannel);
    h_dma_spi_rx_.Init.Direction = DMA_PERIPH_TO_MEMORY;
    h_dma_spi_rx_.Init.PeriphInc = DMA_PINC_DISABLE;
    h_dma_spi_rx_.Init.MemInc = DMA_MINC_ENABLE;
    h_dma_spi_rx_.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    h_dma_spi_rx_.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    h_dma_spi_rx_.Init.Mode = DMA_NORMAL;
    h_dma_spi_rx_.Init.Priority = DMA_PRIORITY_LOW;
    h_dma_spi_rx_.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

    if (HAL_DMA_Init(&h_dma_spi_rx_) != HAL_OK)
    {
      return false;
    }

	// Initialize the peripheral
	h_spi_.Instance = spi_instance_;
	h_spi_.Init.Mode = SPI_MODE_MASTER;
	h_spi_.Init.Direction = SPI_DIRECTION_2LINES;
	h_spi_.Init.DataSize = SPI_DATASIZE_8BIT;

	if (mode == kSpiMode0) {
		h_spi_.Init.CLKPolarity = SPI_POLARITY_LOW;
		h_spi_.Init.CLKPhase = SPI_PHASE_1EDGE;
	} else if (mode == kSpiMode1) {
		h_spi_.Init.CLKPolarity = SPI_POLARITY_LOW;
		h_spi_.Init.CLKPhase = SPI_PHASE_2EDGE;

	} else if (mode == kSpiMode2) {
		h_spi_.Init.CLKPolarity = SPI_POLARITY_HIGH;
		h_spi_.Init.CLKPhase = SPI_PHASE_1EDGE;

	} else if (mode == kSpiMode3) {
		h_spi_.Init.CLKPolarity = SPI_POLARITY_HIGH;
		h_spi_.Init.CLKPhase = SPI_PHASE_2EDGE;
	}

	h_spi_.Init.NSS = SPI_NSS_SOFT;
	h_spi_.Init.BaudRatePrescaler = GetBaudRatePrescaler(rate, spi_instance_);
	h_spi_.Init.FirstBit = endian;
	h_spi_.Init.TIMode = SPI_TIMODE_DISABLE;
	h_spi_.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	h_spi_.Init.CRCPolynomial = 7;

	if (HAL_SPI_Init(&h_spi_) != HAL_OK) {
		return false;
	}

	// Link DMAs
	__HAL_LINKDMA(&h_spi_, hdmatx, h_dma_spi_tx_);
	__HAL_LINKDMA(&h_spi_, hdmarx, h_dma_spi_rx_);

	// Enable DMA Interrupts
	EnableDmaInterrupts(0, 0);

	return true;
}

SPI_HandleTypeDef * Spi::GetSpiHandle()
{
	return &h_spi_;
}

DMA_HandleTypeDef * Spi::GetSpiDmaTxHandle()
{
	return &h_dma_spi_tx_;
}

DMA_HandleTypeDef * Spi::GetSpiDmaRxHandle()
{
	return &h_dma_spi_rx_;
}


void Spi::EnableInterrupts(uint32_t preempt_priority, uint32_t subpriority)
{
	if(spi_instance_ == SPI1){
		HAL_NVIC_SetPriority(SPI1_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(SPI1_IRQn);
	}
	else if(spi_instance_ == SPI2){
		HAL_NVIC_SetPriority(SPI2_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(SPI2_IRQn);
	}
	else if(spi_instance_ == SPI3){
		HAL_NVIC_SetPriority(SPI3_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(SPI3_IRQn);
	}
}

void Spi::DisableInterrupts()
{
	if(spi_instance_ == SPI1){
		HAL_NVIC_DisableIRQ(SPI1_IRQn);
	}
}

void Spi::EnableDmaInterrupts(uint32_t preempt_priority, uint32_t subpriority)
{
	if(spi_instance_ == SPI1){
		HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
		HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, preempt_priority, subpriority);
	    HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
	}
}

void Spi::DisableDmaInterrupts()
{
	if(spi_instance_ == SPI1){
		HAL_NVIC_DisableIRQ(DMA2_Stream0_IRQn);
		HAL_NVIC_DisableIRQ(DMA2_Stream3_IRQn);
	}
}


SpiStatus Spi::Write(uint8_t *data, uint8_t size, GpioPin *cs_pin)
{
	SpiStatus status = kSpiSuccess;

	// If the CS pin was passed as an argument, then handle the CS pin
	//	function for the SPI data transfer
	if (cs_pin != NULL) {
		cs_pin->SetBit(0);
	}

	// Compute timeout based on spi baud rate with 1ms margin
	uint32_t timeout = ((1 << spi_rate_) * size * 8 / 18000) + 1;

	// Transmit data in blocking mode
	if(HAL_SPI_Transmit(&h_spi_, data, size, timeout) != HAL_OK)
	{
		status = kSpiFailed;
	}


	if (cs_pin != NULL) {
		cs_pin->SetBit(1);
	}

	return status;
}

SpiStatus Spi::Read(uint8_t *data, uint8_t size, GpioPin *cs_pin)
{
	SpiStatus status = kSpiSuccess;

	// If the CS pin was passed as an argument, then handle the CS pin
	//	function for the SPI data transfer
	if (cs_pin != NULL) {
		cs_pin->SetBit(0);
	}

	// Compute timeout based on spi baud rate with 1ms margin
	uint32_t timeout = ((1 << spi_rate_) * size * 8 / 18000) + 1;

	// Receive data in blocking mode
	if(HAL_SPI_Receive(&h_spi_, data, size, timeout) != HAL_OK)
	{
		status = kSpiFailed;
	}

	if (cs_pin != NULL) {
		cs_pin->SetBit(1);
	}

	return status;
}

SpiStatus Spi::Transfer(uint8_t *tx_data, uint8_t *rx_data, uint16_t size, GpioPin *cs_pin)
{
	SpiStatus status = kSpiSuccess;

	// If the CS pin was passed as an argument, then handle the CS pin
	//	function for the SPI data transfer
	if (cs_pin != NULL) {
		cs_pin->SetBit(0);
	}

	// Compute timeout based on spi baud rate with 1ms margin
	uint32_t timeout = ((1 << spi_rate_) * size / 18000) + 1;

	// Transmit/Receive data in blocking mode
	if(HAL_SPI_TransmitReceive(&h_spi_, tx_data, rx_data, size, timeout) != HAL_OK)
	{
		status = kSpiFailed;
	}

	if (cs_pin != NULL) {
		cs_pin->SetBit(1);
	}

	return status;
}

SpiStatus Spi::WriteDMA(uint8_t *data, uint16_t size, GpioPin *cs_pin)
{
	SpiStatus status = kSpiSuccess;

	cs_pin_ = cs_pin;

	// Set the cs pin low to start the transfer
	cs_pin->SetBit(0);

	if(HAL_SPI_Transmit_DMA(&h_spi_, data, size) != HAL_OK)
	{
		// Set the cs pin high again since there was a failure
		cs_pin->SetBit(1);

		status = kSpiFailed;
	}

	return status;
}

SpiStatus Spi::ReadDMA(uint8_t *data, uint16_t size, GpioPin *cs_pin, void (*callback)())
{
	SpiStatus status = kSpiSuccess;

	cs_pin_ = cs_pin;
	rx_cplt_callback_ = callback;

	// Set the cs pin low to start the transfer
	cs_pin->SetBit(0);

	if(HAL_SPI_Receive_DMA(&h_spi_, data, size) != HAL_OK)
	{
		// Set the cs pin high again since there was a failure
		cs_pin->SetBit(1);

		status = kSpiFailed;
	}

	return status;
}

SpiStatus Spi::TransferDMA(uint8_t *tx_data, uint8_t *rx_data, uint16_t size, GpioPin *cs_pin, void (*callback)())
{
	SpiStatus status = kSpiSuccess;

	cs_pin_ = cs_pin;
	rx_cplt_callback_ = callback;

	// Set the cs pin low to start the transfer
	cs_pin->SetBit(0);

	if(HAL_SPI_TransmitReceive_DMA(&h_spi_, tx_data, rx_data, size) != HAL_OK)
	{
		// Set the cs pin high again since there was a failure
		cs_pin->SetBit(1);

		status = kSpiFailed;
	}

	return status;
}

SpiStatus Spi::Write8Bit(uint8_t data, GpioPin *cs_pin)
{
	uint8_t tx_data = data;

	return Write(&tx_data, 1, cs_pin);
}

SpiStatus Spi::Write16Bit(uint16_t data, GpioPin *cs_pin)
{
	uint8_t tx_data[2];

	tx_data[0] = (uint8_t)((data & 0xFF00) >> 8);
	tx_data[1] = (uint8_t)(data & 0xFF);

	return Write(tx_data, 2, cs_pin);
}

SpiStatus Spi::Write24Bit(uint32_t data, GpioPin *cs_pin)
{
	uint8_t tx_data[3];

	tx_data[0] = (uint8_t)((data & 0xFF0000) >> 16);
	tx_data[1] = (uint8_t)((data & 0xFF00) >> 8);
	tx_data[2] = (uint8_t)(data & 0xFF);

	return Write(tx_data, 3, cs_pin);
}

SpiStatus Spi::Write32Bit(uint32_t data, GpioPin *cs_pin)
{
	uint8_t tx_data[4];

	tx_data[0] = (uint8_t)((data & 0xFF000000) >> 24);
	tx_data[1] = (uint8_t)((data & 0xFF0000) >> 16);
	tx_data[2] = (uint8_t)((data & 0xFF00) >> 8);
	tx_data[3] = (uint8_t)(data & 0xFF);

	return Write(tx_data, 4, cs_pin);
}

SpiStatus Spi::Read8Bit(uint8_t* data, GpioPin *cs_pin)
{
	return Read(data, 1, cs_pin);
}

SpiStatus Spi::Read16Bit(uint16_t* data, GpioPin *cs_pin)
{
	SpiStatus status;

	uint8_t rx_data[2];

	status = Read(rx_data, 2, cs_pin);

	*data = (((uint16_t)rx_data[0]) << 8) | (uint16_t)rx_data[1];

	return status;

}

SpiStatus Spi::Read24Bit(uint32_t* data, GpioPin *cs_pin)
{
	SpiStatus status;

	uint8_t rx_data[3];

	status = Read(rx_data, 3, cs_pin);

	*data = (((uint32_t)rx_data[0]) << 16) | (((uint32_t)rx_data[1]) << 8) | (uint32_t)rx_data[2];

	return status;

}

SpiStatus Spi::Read32Bit(uint32_t* data, GpioPin *cs_pin)
{
	SpiStatus status;

	uint8_t rx_data[4];

	status = Read(rx_data, 4, cs_pin);

	*data = (((uint32_t)rx_data[0]) << 24) | (((uint32_t)rx_data[1]) << 16) | (((uint32_t)rx_data[2]) << 8) | (uint32_t)rx_data[3];

	return status;

}

void Spi::TxCpltCallback()
{
	// DMA finished transmitting data
	//	Set pin high
	cs_pin_->SetBit(1);
}

void Spi::RxCpltCallback()
{
	// DMA received or Transfering data
	// Set pin high
	cs_pin_ ->SetBit(1);

	// Call the callback function
	rx_cplt_callback_();
}

// Private Functions
//===========================================

void Spi::InitializeClocks(SPI_TypeDef* spi_instance)
{
	if(spi_instance == SPI1){
		__HAL_RCC_SPI1_CLK_ENABLE();
	}
	else if(spi_instance == SPI2){
		__HAL_RCC_SPI2_CLK_ENABLE();
	}
	else if(spi_instance == SPI3){
		__HAL_RCC_SPI3_CLK_ENABLE();
	}
}

void Spi::InitializeDmaClocks(SPI_TypeDef* spi_instance)
{
	if(spi_instance == SPI1){
		__HAL_RCC_DMA2_CLK_ENABLE();
	}
}

uint32_t Spi::GetBaudRatePrescaler(SpiRate rate, SPI_TypeDef* spi_instance)
{
	uint32_t prescaler;

	// If proper SPI Instance is not used, return a "safe" baudrate prescaler
	if((spi_instance != SPI1) && (spi_instance != SPI2) && (spi_instance != SPI3))
		return SPI_BAUDRATEPRESCALER_32;

	switch(rate)
	{
		case kSpi21Mbps:
		{
			if(spi_instance == SPI1)
				prescaler = SPI_BAUDRATEPRESCALER_4;
			break;
		}
		case kSpi10p5Mbps:
		{
			if(spi_instance == SPI1)
				prescaler = SPI_BAUDRATEPRESCALER_8;
			break;
		}
		case kSpi5p25Mbps:
		{
			if(spi_instance == SPI1)
				prescaler = SPI_BAUDRATEPRESCALER_16;
			break;
		}
		case kSpi2p625Mbps:
		{
			if(spi_instance == SPI1)
				prescaler = SPI_BAUDRATEPRESCALER_32;
			break;
		}
		case kSpi1p3125Mbps:
		{
			if(spi_instance == SPI1)
				prescaler = SPI_BAUDRATEPRESCALER_64;
			break;
		}
		default:
			prescaler = SPI_BAUDRATEPRESCALER_32;
	}

	return prescaler;
}

DMA_Stream_TypeDef * Spi::GetDmaStream(SPI_TypeDef *spi_instance, SpiDmaChannel channel) {

	// TODO check if spi instance is a valid instance

	DMA_Stream_TypeDef * p_channel;

	switch (channel) {
	case kSpiDmaTxChannel: {
		if (spi_instance == SPI1)
			p_channel = DMA2_Stream3;
		break;
	}
	case kSpiDmaRxChannel: {
		if (spi_instance == SPI1)
			p_channel = DMA2_Stream0;
		break;
	}
	}

	return p_channel;
}

uint32_t Spi::GetDmaChannel(SPI_TypeDef *spi_instance, SpiDmaChannel channel) {

	// TODO check if spi instance is a valid instance

	uint32_t dma_channel;

	switch (channel) {
	case kSpiDmaTxChannel: {
		if (spi_instance == SPI1)
			dma_channel = DMA_CHANNEL_3;
		break;
	}
	case kSpiDmaRxChannel: {
		if (spi_instance == SPI1)
			dma_channel = DMA_CHANNEL_3;
		break;
	}
	}

	return dma_channel;
}

//------------------------------------------------------------------//
//     				HAL SPI Callback Functions						//
//------------------------------------------------------------------//

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi) {

	if (hspi == Spi1.GetSpiHandle()) {
		Spi1.TxCpltCallback();
	}
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi) {

	if (hspi == Spi1.GetSpiHandle()) {
		Spi1.RxCpltCallback();
	}
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi == Spi1.GetSpiHandle()) {
		Spi1.RxCpltCallback();
	}
}
