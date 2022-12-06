/*
 * i2c.h
 *
 *  Created on: May 12, 2020
 *      Author: t. pailevanian
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx_hal.h"
#include "pin_config.h"
#include "gpio.h"

// Forward declaration
class I2C;

extern I2C I2c1;
extern I2C I2c2;

// Enumerations

enum I2cStatus{

	kI2cSuccess = 0,
	kI2cFailed

};


enum I2cRate {
	kI2c100Khz = 100,
	kI2c400Khz = 400,
	kI2c1000Khz = 1000
};


class I2C{

public:


	I2C(I2C_TypeDef* i2c_instance, GPIO_TypeDef *i2c_scl_port, uint16_t i2c_scl_pin, uint8_t i2c_scl_alt_func,
			GPIO_TypeDef *i2c_sda_port, uint16_t i2c_sda_pin, uint8_t i2c_sda_alt_func);

	virtual ~I2C(){};

	// Initializes the I2C peripheral with the provided configuration
	bool Init(I2cRate rate = kI2c100Khz);

	void Reset(void);

	I2cStatus Write(uint8_t *data, uint8_t slave8BitAddress, uint8_t size);
	I2cStatus Read(uint8_t *data, uint8_t slave8BitAddress, uint8_t size);

	I2cStatus RegWrite(uint8_t slaveReg8BitAddress, uint8_t *data, uint8_t slave8BitAddress, uint8_t size);
	I2cStatus RegRead(uint8_t slaveReg8BitAddress, uint8_t *data, uint8_t slave8BitAddress, uint8_t size);

private:

	GPIO_TypeDef * i2c_scl_port_;
	uint16_t i2c_scl_pin_;
	uint8_t i2c_scl_alt_func_;

	GPIO_TypeDef * i2c_sda_port_;
	uint16_t i2c_sda_pin_;
	uint8_t i2c_sda_alt_func_;

	GpioPin i2c_scl_;
	GpioPin i2c_sda_;

	I2cRate i2c_rate_;

	I2C_TypeDef* i2c_instance_;

	I2C_HandleTypeDef h_i2c_;

	// Initialize clocks for the I2C peripheral
	void InitializeClocks(I2C_TypeDef* i2c_instance);


};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
// 	*Place HAL function constructors here*


#ifdef __cplusplus
}
#endif

#endif /* I2C_H_ */
