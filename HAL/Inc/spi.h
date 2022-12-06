/*
 * spi.h
 *
 *  Created on: Apr 29, 2020
 *      Author: t. pailevanian
 */

#ifndef SPI_H_
#define SPI_H_

#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include "gpio.h"
#include "logs.h"

// Forward declaration
class Spi;

extern Spi Spi1;
extern Spi Spi2;

// Enumerations

enum SpiStatus{

	kSpiSuccess = 0,
	kSpiFailed

};

// SPI Data Endian-ness
enum SpiEndian {
	kSpiMsbFirst = SPI_FIRSTBIT_MSB,
	kSpiLsbFirst = SPI_FIRSTBIT_LSB
};

// SPI Rate
enum SpiRate {
	kSpi21Mbps,
	kSpi10p5Mbps,
	kSpi5p25Mbps,
	kSpi2p625Mbps,
	kSpi1p3125Mbps
};

/*
 * Mode			Clock Polarity (CPOL)	Clock Phase (CPHA)
 * ==========================================================
 * kSpiMode0		low		(0)				first edge	(0)
 * kSpiMode1		low		(0)				second edge	(1)
 * kSpiMode2		high 	(1)				first edge	(0)
 * kSpiMode3		high	(1)				second edge	(1)
*/

enum SpiMode {
	kSpiMode0,
	kSpiMode1,
	kSpiMode2,
	kSpiMode3
};



class Spi{

public:


	Spi(SPI_TypeDef* spi_instance, GPIO_TypeDef *spi_clk_port, uint16_t spi_clk_pin, uint8_t spi_clk_alt_func,
			GPIO_TypeDef *spi_miso_port, uint16_t spi_miso_pin, uint8_t spi_miso_alt_func,
			GPIO_TypeDef *spi_mosi_port, uint16_t spi_mosi_pin, uint8_t spi_mosi_alt_func);

	virtual ~Spi();

	// Initializes the Spi peripheral with the provided configuration
	bool Init(SpiMode mode, SpiRate rate, SpiEndian endian = kSpiMsbFirst);

	// Enables interrupts for the SPI peripheral with the provided preemption priority and subpriority
	void EnableInterrupts(uint32_t preempt_priority, uint32_t subpriority);

	// Disables interrupts for the Spi peripheral
	void DisableInterrupts();

	// Enables interrupts for the DMA Channel for the SPI peripheral with the
	//	provided preemption priority and subpriority
	void EnableDmaInterrupts(uint32_t preempt_proprity, uint32_t subpriority);

	// Disables interrupts for the DMA channel for the SPI peripheral
	void DisableDmaInterrupts();

	SPI_HandleTypeDef * GetSpiHandle();
	DMA_HandleTypeDef * GetSpiDmaTxHandle();
	DMA_HandleTypeDef * GetSpiDmaRxHandle();

	void TxCpltCallback();
	void RxCpltCallback();

	SpiStatus Write(uint8_t *data, uint8_t size, GpioPin *cs_pin = NULL);
	SpiStatus Read(uint8_t *data, uint8_t size, GpioPin *cs_pin = NULL);
	SpiStatus Transfer(uint8_t *tx_data, uint8_t *rx_data, uint16_t size, GpioPin *cs_pin = NULL);

	SpiStatus WriteDMA(uint8_t *data, uint16_t size, GpioPin *cs_pin);
	SpiStatus ReadDMA(uint8_t *data, uint16_t size, GpioPin *cs_pin, void (*callback)());
	SpiStatus TransferDMA(uint8_t *tx_data, uint8_t *rx_data, uint16_t size, GpioPin *cs_pin, void (*callback)());

	// Register Read/Write functions
	SpiStatus Write8Bit(uint8_t data, GpioPin *cs_pin = NULL);
	SpiStatus Write16Bit(uint16_t data, GpioPin *cs_pin = NULL);
	SpiStatus Write24Bit(uint32_t data, GpioPin *cs_pin = NULL);
	SpiStatus Write32Bit(uint32_t data, GpioPin *cs_pin = NULL);

	SpiStatus Read8Bit(uint8_t* data, GpioPin *cs_pin = NULL);
	SpiStatus Read16Bit(uint16_t* data, GpioPin *cs_pin = NULL);
	SpiStatus Read24Bit(uint32_t* data, GpioPin *cs_pin = NULL);
	SpiStatus Read32Bit(uint32_t* data, GpioPin *cs_pin = NULL);

private:

	GPIO_TypeDef * spi_clk_port_;
	uint16_t spi_clk_pin_;
	uint8_t spi_clk_alt_func_;

	GPIO_TypeDef * spi_miso_port_;
	uint16_t spi_miso_pin_;
	uint8_t spi_miso_alt_func_;

	GPIO_TypeDef * spi_mosi_port_;
	uint16_t spi_mosi_pin_;
	uint8_t spi_mosi_alt_func_;

	GpioPin spi_clk_;
	GpioPin spi_mosi_;
	GpioPin spi_miso_;

	SpiRate spi_rate_;

	SPI_TypeDef* spi_instance_;

	SPI_HandleTypeDef h_spi_;

	DMA_HandleTypeDef h_dma_spi_tx_;
	DMA_HandleTypeDef h_dma_spi_rx_;

	GpioPin * cs_pin_;

	enum SpiDmaChannel {
		kSpiDmaTxChannel = 0,
		kSpiDmaRxChannel
	};

	void (*rx_cplt_callback_)(void);

	// Initialize clocks for the Spi peripheral
	void InitializeClocks(SPI_TypeDef* spi_instance);
	void InitializeDmaClocks(SPI_TypeDef* spi_instance);
	uint32_t GetBaudRatePrescaler(SpiRate rate, SPI_TypeDef* spi_instance);
	DMA_Stream_TypeDef  * GetDmaStream(SPI_TypeDef* spi_instance, SpiDmaChannel channel);
	uint32_t GetDmaChannel(SPI_TypeDef* spi_instance, SpiDmaChannel channel);

};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
// 	*Place HAL function constructors here*
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif

#endif /* SPI_H_ */
