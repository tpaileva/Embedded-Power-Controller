/*
 * usb.cpp
 *
 *  Created on: May 26, 2020
 *      Author: t. pailevanian
 */

#include "usb.h"

UsbDevice Usb;

// Define static members of class Usb
USBD_HandleTypeDef UsbDevice::h_usb_device_fs_;
UsbDevice *UsbDevice::p_usb_ = NULL;
uint8_t UsbDevice::rx_buffer_[USB_BUF_SIZE];
uint8_t UsbDevice::tx_buffer_[USB_BUF_SIZE];

//------------------------------------------------------------------//
//     					USB Device Class							//
//------------------------------------------------------------------//

UsbDevice::UsbDevice(){

	p_usb_ = this;
}

UsbDevice::~UsbDevice()
{

	p_usb_ = NULL;

    USBD_Stop(&h_usb_device_fs_);
    USBD_DeInit(&h_usb_device_fs_);

    // Disable clocks
    __HAL_RCC_USB_OTG_FS_CLK_DISABLE();

    HAL_GPIO_DeInit(USB_DP_GPIO_Port, USB_DP_Pin);
    HAL_GPIO_DeInit(USB_DN_GPIO_Port, USB_DN_Pin);
    HAL_GPIO_DeInit(USB_VBUS_GPIO_Port, USB_VBUS_Pin);

    HAL_NVIC_DisableIRQ(OTG_FS_IRQn);
}

void UsbDevice::Init(GpioPin * usb_dp_pullup_pin){

	usb_dp_pullup_pin_ = usb_dp_pullup_pin;

	if(usb_dp_pullup_pin_ != NULL) {
		usb_dp_pullup_pin_->SetBit(0);
	}

    // Initialize the USB GPIO Pins
	usb_dp_.Init(USB_DP_GPIO_Port, USB_DP_Pin,
						kGpioModeAFPP,
						kGpioSpeedHigh,
						kGpioPullOff,
						USB_DP_AF);

	usb_dn_.Init(USB_DN_GPIO_Port, USB_DN_Pin,
						kGpioModeAFPP,
						kGpioSpeedHigh,
						kGpioPullOff,
						USB_DN_AF);

	usb_vbus_.Init(USB_VBUS_GPIO_Port, USB_VBUS_Pin, kGpioModeInput, kGpioPullOff);

	// Initialize USB Clock
	__HAL_RCC_USB_OTG_FS_CLK_ENABLE();

	USBD_Init(&h_usb_device_fs_, &FS_Desc, DEVICE_FS);
    USBD_RegisterClass(&h_usb_device_fs_, &USBD_CDC);

    // Register the callback functions
    usb_cdc_cb_.Init = Usb_initCb;
    usb_cdc_cb_.DeInit = Usb_deInitCb;
    usb_cdc_cb_.Control = Usb_controlCb;
    usb_cdc_cb_.Receive = Usb_recieveCb;

    USBD_CDC_RegisterInterface(&h_usb_device_fs_, &usb_cdc_cb_);

    // Reset the buffer
    received_buffer_.Reset();

    // Initialize Interrupts
    HAL_NVIC_SetPriority(OTG_FS_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OTG_FS_IRQn);

    // Start USB interface
    USBD_Start(&h_usb_device_fs_);

}

void UsbDevice::SendByte(uint8_t byte){
	byte_ = byte;
	SendData(&byte_, 1);
}

uint8_t UsbDevice::GetByte(){

    // Pop the byte from the buffer
    uint8_t l_byte;

    if(!received_buffer_.IsEmpty()){
    	received_buffer_.Get(&l_byte);
    }

    return l_byte;
}

USBD_StatusTypeDef UsbDevice::SendData(uint8_t *data, uint16_t length) {

	uint16_t i = 0;

	USBD_StatusTypeDef status;

	// Create timepoint for timeouts
	uint32_t ticks = GetTicks();

	// TODO: add boolean return to indicate if send was successful

	// Wait while transmit is busy
	while (TxBusy()) {
		// 10ms timeout
		if(GetTicks() - ticks > 10) {
			status = USBD_BUSY;
			goto send_status;
		}
	}

	for (i = 0; length > CDC_DATA_FS_MAX_PACKET_SIZE; length -=
			CDC_DATA_FS_MAX_PACKET_SIZE, i += CDC_DATA_FS_MAX_PACKET_SIZE) {

		USBD_CDC_SetTxBuffer(&h_usb_device_fs_, data + i, CDC_DATA_FS_MAX_PACKET_SIZE);
		status = (USBD_StatusTypeDef) USBD_CDC_TransmitPacket (&h_usb_device_fs_);

		// Check for timeouts
		ticks = GetTicks();

		while (TxBusy()) {
			// 10ms timeout
			if(GetTicks() - ticks > 10) {
				status = USBD_BUSY;
				goto send_status;
			}
		}
	}
	if (length > 0) {
		USBD_CDC_SetTxBuffer(&h_usb_device_fs_, data + i, length);
		status = (USBD_StatusTypeDef) USBD_CDC_TransmitPacket (&h_usb_device_fs_);

		// Check for timeouts
		ticks = GetTicks();

		while (TxBusy()) {
			// 10ms timeout
			if(GetTicks() - ticks > 10) {
				status = USBD_BUSY;
				goto send_status;
			}
		}
	}

send_status:

	return status;
}

bool UsbDevice::ReadData(uint8_t* data, uint16_t length)
{

	if(length > USB_BUF_SIZE) return false;

    // Copy input data
    uint16_t cnt = 0;

    while(cnt < USB_BUF_SIZE && !received_buffer_.IsEmpty()) {

    	received_buffer_.Get(&data[cnt]);
    }

    return true;
}

bool UsbDevice::TxBusy(void)
{
	return (((USBD_CDC_HandleTypeDef*)h_usb_device_fs_.pClassData)->TxState) ? true : false;
}

size_t UsbDevice::GetCounterRX(void)
{
    return  received_buffer_.Available();
}


void UsbDevice::ResetCounterRx()
{
	received_buffer_.Reset();
}


void UsbDevice::operator << (char* pData)
{
    SendData((uint8_t*)pData, (uint16_t)strlen(pData));
}


USBD_HandleTypeDef * UsbDevice::GetUsbDeviceHandle(){
	return &h_usb_device_fs_;
}

void UsbDevice::SetPullup(uint8_t state){

	if(usb_dp_pullup_pin_ != NULL) {
		usb_dp_pullup_pin_->SetBit(state ? true : false);
	}
}


// Private Functions
//===========================================

int8_t UsbDevice::Usb_initCb(void)
{
    USBD_CDC_SetTxBuffer(&h_usb_device_fs_, tx_buffer_, 0);
    USBD_CDC_SetRxBuffer(&h_usb_device_fs_, rx_buffer_);
    return (USBD_OK);
}


int8_t UsbDevice::Usb_deInitCb(void)
{
    return (USBD_OK);
}


int8_t UsbDevice::Usb_controlCb(uint8_t cmd, uint8_t *pbuf, uint16_t length) {
	switch (cmd) {
	case CDC_SEND_ENCAPSULATED_COMMAND:

		break;

	case CDC_GET_ENCAPSULATED_RESPONSE:

		break;

	case CDC_SET_COMM_FEATURE:

		break;

	case CDC_GET_COMM_FEATURE:

		break;

	case CDC_CLEAR_COMM_FEATURE:

		break;


	/*******************************************************************************/
	/* Line Coding Structure                                                       */
	/*-----------------------------------------------------------------------------*/
	/* Offset | Field       | Size | Value  | Description                          */
	/* 0      | dwDTERate   |   4  | Number |Data terminal rate, in bits per second*/
	/* 4      | bCharFormat |   1  | Number | Stop bits                            */
	/*                                        0 - 1 Stop bit                       */
	/*                                        1 - 1.5 Stop bits                    */
	/*                                        2 - 2 Stop bits                      */
	/* 5      | bParityType |  1   | Number | Parity                               */
	/*                                        0 - None                             */
	/*                                        1 - Odd                              */
	/*                                        2 - Even                             */
	/*                                        3 - Mark                             */
	/*                                        4 - Space                            */
	/* 6      | bDataBits  |   1   | Number Data bits (5, 6, 7, 8 or 16).          */
	/*******************************************************************************/
	case CDC_SET_LINE_CODING:

		break;

	case CDC_GET_LINE_CODING:

		break;

	case CDC_SET_CONTROL_LINE_STATE:

		break;

	case CDC_SEND_BREAK:

		break;

	default:
		break;
	}

	return (USBD_OK);
}


int8_t UsbDevice::Usb_recieveCb(uint8_t *buff, uint32_t *len)
{
	for (uint16_t i = 0; i < *len; i++) {

		p_usb_->received_buffer_.PutOverwrite(buff[i]);
	}

    USBD_CDC_SetRxBuffer(&h_usb_device_fs_, &buff[0]);
    USBD_CDC_ReceivePacket(&h_usb_device_fs_);

    return (USBD_OK);
}


//------------------------------------------------------------------//
//     				HAL USB Callback Functions						//
//------------------------------------------------------------------//


void HAL_PCDEx_SetConnectionState(PCD_HandleTypeDef *hpcd, uint8_t state) {

	// Only needed for processors without an integrated pull-up
//	Usb.SetPullup(state);

}

