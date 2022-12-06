/*
 * statemachine.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_STATEMACHINE_H_
#define INC_STATEMACHINE_H_

#include "buzzer.h"
#include "btu.h"
#include "finitestatemachine.h"
#include "gpio.h"
#include "power.h"
#include "fault.h"
#include "estop.h"
#include "led.h"
#include "loop.h"
#include "tier1.h"
#include "util.h"
#include "vehicleid.h"
#include "display.h"
#include <stddef.h>
#include <tier2.h>

void Init(void);

void processStateMachine();

void Enter_Boot();
void Update_Boot();
void Enter_PowerUp();
void Update_PowerUp();
void Enter_OP();
void Update_OP();
void Enter_Estop();
void Update_Estop();
void Enter_Alarm();
void Update_Alarm();
void Enter_Fault();
void Update_Fault();
void Enter_PowerDown();
void Update_PowerDown();

void update_lights();
void SafetyHandler();
void printEstopState();

void updateAlarm();
void updateFault();

extern GpioPin power_switch;

extern Fault fault_status_;

extern BatteryAlarm battery_alarm_status_;

// Debugging
extern uint8_t _sm_debug;

#endif /* INC_STATEMACHINE_H_ */
