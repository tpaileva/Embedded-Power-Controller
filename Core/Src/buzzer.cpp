/*
 * buzzer.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */



#include "buzzer.h"

Buzzer buzzer;

TimChannel buzzerTimChannel;

//------------------------------------------------------------------//
//     						  Buzzer Class							//
//------------------------------------------------------------------//

Buzzer::Buzzer() {

}


// TODO: Destructor
Buzzer::~Buzzer(){}

void Buzzer::Init() {

	alarm_flag = 0;
	fault_flag = 0;

	Tim10.Init(1000);
	buzzerTimChannel.Init(&Tim10, BUZZER_GPIO_Port, BUZZER_Pin, BUZZER_AF, BUZZER_TIMER_CHANNEL, kPwmOutput);

	Tim10.Start();
	buzzerTimChannel.SetDuty(0);
	buzzerTimChannel.Start();

}


// TODO: Write a better buzzer class that uses sine wave LUTs and DMA
//		 to keyout tones and melodies

void Buzzer::PlayPowerUpMelody(void) {

	buzzerTimChannel.SetDuty(40);
	Delay(2000);
	buzzerTimChannel.SetDuty(0);
}


void Buzzer::PlayPreArmMelody(void) {

	buzzerTimChannel.SetDuty(40);
	Delay(250);
	buzzerTimChannel.SetDuty(60);
	Delay(250);
	buzzerTimChannel.SetDuty(30);
	Delay(250);
	buzzerTimChannel.SetDuty(60);
	Delay(250);
	buzzerTimChannel.SetDuty(40);
	Delay(250);
	buzzerTimChannel.SetDuty(60);
	Delay(250);
	buzzerTimChannel.SetDuty(30);
	Delay(250);
	buzzerTimChannel.SetDuty(60);
	Delay(250);
	buzzerTimChannel.SetDuty(0);
}


void Buzzer::PlayArmedMelody(void) {

	buzzerTimChannel.SetDuty(20);
	Delay(50);
	buzzerTimChannel.SetDuty(100);
	Delay(200);
	buzzerTimChannel.SetDuty(20);
	Delay(50);
	buzzerTimChannel.SetDuty(100);
	Delay(200);
	buzzerTimChannel.SetDuty(0);
}

void Buzzer::SoundAlarm(void) {
	alarm_flag = 1;
	BuzzerLoop();
}

void Buzzer::SilenceAlarm(void) {
	alarm_flag = 0;
	BuzzerLoop();
}

void Buzzer::SoundFault(void) {
	fault_flag = 1;
	BuzzerLoop();
}

void Buzzer::SilenceFault(void) {
	fault_flag = 0;
	BuzzerLoop();
}


void Buzzer::BuzzerLoop(void) {

	if (fault_flag == 1) {
		buzzerTimChannel.SetDuty(100);
	}
	else if(alarm_flag == 1) {
		if(alarm_wait_counter_ < ALARM_BEEP_WAIT_COUNTS) {
			buzzerTimChannel.SetDuty(0);
			alarm_wait_counter_++;
		}
		else if (alarm_duration_counter_ < ALARM_BEEP_DURATION_COUNTS) {
			buzzerTimChannel.SetDuty(100);
			alarm_duration_counter_++;
		}
		else {
			alarm_wait_counter_ = 0;
			alarm_duration_counter_ = 0;
		}
	}
	else {
		buzzerTimChannel.SetDuty(0);
	}
}
