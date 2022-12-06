/*
 * buzzer.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "tim.h"
#include "util.h"

#define ALARM_BEEP_WAIT_COUNTS 5000
#define ALARM_BEEP_DURATION_COUNTS 300

// Forward declaration
class Buzzer;

extern Buzzer buzzer;

class Buzzer {
public:
	Buzzer(void);

	virtual ~Buzzer();

	void Init(void);
	void PlayPowerUpMelody(void);
	void PlayPreArmMelody(void);
	void PlayArmedMelody(void);

	void SoundAlarm(void);
	void SilenceAlarm(void);

	void SoundFault(void);
	void SilenceFault(void);

	void BuzzerLoop(void);

private:

	uint32_t alarm_wait_counter_ = 0;
	uint32_t alarm_duration_counter_ = 0;

	uint8_t alarm_flag = 0;
	uint8_t fault_flag = 0;

};


#endif /* INC_BUZZER_H_ */
