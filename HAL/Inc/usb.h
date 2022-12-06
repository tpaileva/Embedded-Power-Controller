/*
 * usb.h
 *
 *  Created on: May 26, 2020
 *      Author: t. pailevanian
 */

#ifndef USB_H_
#define USB_H_

#include "stm32f4xx_hal.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_cdc.h"
#include "gpio.h"
#include "circular_buffer.h"
#include "util.h"

#include <string.h>

// Forward declaration
class UsbDevice;

extern UsbDevice Usb;

#define USB_BUF_SIZE	500

enum UsbStatus{

	kUsbSuccess = 0,
	kUsbFailed,
	kUsbBusy

};


class UsbDevice {
public:
	UsbDevice();
	~UsbDevice();

	void Init(GpioPin * usb_dp_pullup_pin = NULL);

	uint8_t GetByte(void);
	void SendByte(uint8_t byte);
	USBD_StatusTypeDef SendData(uint8_t *data, uint16_t lenth);
	bool ReadData(uint8_t *data, uint16_t lenth);

	bool TxBusy(void);
	size_t GetCounterRX(void);
    void ResetCounterRx();
    void operator << (char *pData);

    USBD_HandleTypeDef * GetUsbDeviceHandle(void);

    void SetPullup(uint8_t state);

private:

	// USB Peripheral RX and TX buffers
	static uint8_t rx_buffer_[USB_BUF_SIZE];
	static uint8_t tx_buffer_[USB_BUF_SIZE];

	// Received data buffer
	CircularBuffer received_buffer_ = CircularBuffer(USB_BUF_SIZE);
	uint8_t byte_;

	// USB Device Core Handle
	static USBD_HandleTypeDef h_usb_device_fs_;

	// Callback functions structure
	USBD_CDC_ItfTypeDef usb_cdc_cb_;

	static UsbDevice * p_usb_;

	GpioPin usb_dp_;
	GpioPin usb_dn_;
	GpioPin usb_vbus_;

	GpioPin * usb_dp_pullup_pin_;

    // Callback functions
    static int8_t Usb_recieveCb(uint8_t *buff, uint32_t *len);
    static int8_t Usb_controlCb(uint8_t cmd, uint8_t *pbuf, uint16_t length);
    static int8_t Usb_deInitCb(void);
    static int8_t Usb_initCb(void);

protected:


};

#ifdef __cplusplus
extern "C" {
#endif

// HAL Library Callback Functions
void HAL_PCDEx_SetConnectionState(PCD_HandleTypeDef *hpcd, uint8_t state);

#ifdef __cplusplus
}
#endif

#endif /* USB_H_ */
