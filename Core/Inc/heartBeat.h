/*
 * heratBeat.h
 *
 * Header for running the heartbeat LED
 */

#pragma once

#include "util.h"
#include "gpio.h"
#include "pin_config.h"

// Forward declaration
class HEARTBEAT;

extern HEARTBEAT heartBeat;

class HEARTBEAT {

public :
    HEARTBEAT();

	void Init();
	void Update();
	void InvertLevel();

private :

	GpioPin heartBeatGPIO;

	const uint16_t heartBeatArray [4] = { 70, 245, 70, 1015 };
	uint8_t heartBeatIndex = 0;
	uint32_t heartBeatTimer = 0;
	bool LED_state = 1;

};

