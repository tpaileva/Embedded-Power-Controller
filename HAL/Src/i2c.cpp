/*
 * i2c.cpp
 *
 *  Created on: May 12, 2020
 *      Author: t. pailevanian
 */

#include "i2c.h"

I2C I2c1(I2C1, I2C1_SCL_GPIO_Port, I2C1_SCL_Pin, I2C1_SCL_AF,
		I2C1_SDA_GPIO_Port, I2C1_SDA_Pin, I2C1_SDA_AF);

I2C I2c2(I2C2, I2C2_SCL_GPIO_Port, I2C2_SCL_Pin, I2C2_SCL_AF,
		I2C2_SDA_GPIO_Port, I2C2_SDA_Pin, I2C2_SDA_AF);


//------------------------------------------------------------------//
//     						  I2C Class								//
//------------------------------------------------------------------//

I2C::I2C(I2C_TypeDef* i2c_instance, GPIO_TypeDef *i2c_scl_port, uint16_t i2c_scl_pin, uint8_t i2c_scl_alt_func,
			GPIO_TypeDef *i2c_sda_port, uint16_t i2c_sda_pin, uint8_t i2c_sda_alt_func){

	i2c_instance_ = i2c_instance;

	i2c_scl_port_ = i2c_scl_port;
	i2c_scl_pin_ = i2c_scl_pin;
	i2c_scl_alt_func_ = i2c_scl_alt_func;

	i2c_sda_port_ = i2c_sda_port;
	i2c_sda_pin_ = i2c_sda_pin;
	i2c_sda_alt_func_ = i2c_sda_alt_func;

}

bool I2C::Init(I2cRate rate) {

	InitializeClocks(i2c_instance_);

	i2c_rate_ = rate;

	// Initialize the GPIO pins associated with the SPI peripheral
	i2c_scl_.Init(i2c_scl_port_, i2c_scl_pin_,
						kGpioModeAFOD,
						kGpioSpeedHigh,
						kGpioPullUp,
						i2c_scl_alt_func_);

	i2c_sda_.Init(i2c_sda_port_, i2c_sda_pin_,
						kGpioModeAFOD,
						kGpioSpeedHigh,
						kGpioPullUp,
						i2c_sda_alt_func_);

	h_i2c_.Instance = i2c_instance_;

	if(rate == kI2c100Khz){
		h_i2c_.Init.ClockSpeed = 100000;
	}

	if(rate == kI2c400Khz){
		h_i2c_.Init.ClockSpeed = 400000;
	}

	if(rate == kI2c1000Khz){
		h_i2c_.Init.ClockSpeed = 1000000;
	}

	h_i2c_.Init.OwnAddress1 = 0;
	h_i2c_.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	h_i2c_.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	h_i2c_.Init.OwnAddress2 = 0;
	h_i2c_.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	h_i2c_.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&h_i2c_) != HAL_OK) {
		return false;
	}

	// Configure analog filter
	if (HAL_I2CEx_ConfigAnalogFilter(&h_i2c_, I2C_ANALOGFILTER_ENABLE) != HAL_OK) {
		return false;
	}

	// Configure digital filter
	if (HAL_I2CEx_ConfigDigitalFilter(&h_i2c_, 0) != HAL_OK) {
		return false;
	}

	return true;
}

void I2C::Reset(void) {

	I2C_SoftwareResetCmd(&h_i2c_);

}

I2cStatus I2C::Write(uint8_t *data, uint8_t slave8BitAddress, uint8_t size){

	I2cStatus status = kI2cSuccess;

	// Compute timeout based on i2c data rate with 1ms margin
	uint32_t timeout = ((size + 1) * 8 / ((uint32_t)i2c_rate_)) + 1;

	// Transmit data in blocking mode
	if(HAL_I2C_Master_Transmit(&h_i2c_, slave8BitAddress, data, size, timeout) != HAL_OK)
	{
		status = kI2cFailed;
	}

	return status;
}

I2cStatus I2C::Read(uint8_t *data, uint8_t slave8BitAddress, uint8_t size){

	I2cStatus status = kI2cSuccess;

	// Compute timeout based on i2c data rate with 1ms margin
	uint32_t timeout = ((size + 1) * 8 / ((uint32_t)i2c_rate_)) + 1;

	// Transmit data in blocking mode
	if(HAL_I2C_Master_Receive(&h_i2c_, slave8BitAddress, data, size, timeout) != HAL_OK)
	{
		status = kI2cFailed;
	}

	return status;
}

I2cStatus I2C::RegWrite(uint8_t slaveReg8BitAddress, uint8_t *data, uint8_t slave8BitAddress, uint8_t size){

	I2cStatus status = kI2cSuccess;

	// Compute timeout based on i2c data rate with 1ms margin
	uint32_t timeout = ((size + 1) * 8 / ((uint32_t)i2c_rate_)) + 1;

	// Transmit data in blocking mode
	if(HAL_I2C_Mem_Write(&h_i2c_, slave8BitAddress, slaveReg8BitAddress, 1, data, size, timeout) != HAL_OK)
	{
		status = kI2cFailed;
	}

	return status;
}

I2cStatus I2C::RegRead(uint8_t slaveReg8BitAddress, uint8_t *data, uint8_t slave8BitAddress, uint8_t size){

	I2cStatus status = kI2cSuccess;

	// Compute timeout based on i2c data rate with 1ms margin
	uint32_t timeout = ((size + 1) * 8 / ((uint32_t)i2c_rate_)) + 1;

	// Transmit data in blocking mode
	if(HAL_I2C_Mem_Read(&h_i2c_, slave8BitAddress, slaveReg8BitAddress, 1, data, size, timeout) != HAL_OK)
	{
		status = kI2cFailed;
	}

	return status;
}

// Private Functions
//===========================================

void I2C::InitializeClocks(I2C_TypeDef* i2c_instance)
{
	if(i2c_instance == I2C1){
		__HAL_RCC_I2C1_CLK_ENABLE();
	}
	else if(i2c_instance == I2C2){
		__HAL_RCC_I2C2_CLK_ENABLE();
	}
}
