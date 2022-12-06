/*
 * statemachine.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#include "statemachine.h"

#define FSM_DELAY_MS 333

const uint8_t FSM_NUMBER_OF_STATES = 7;

uint32_t enter_time_ = 0;
uint32_t arm_start_time_ = 0;

uint32_t reporting_time = GetTicks();

uint32_t ticks_since_last_alarm_msg = 0;
uint32_t ticks_since_last_fault_msg = 0;

// State Machine Debugging
uint8_t _sm_debug = 1;

// Vehicle ID
uint8_t vehicle_id;

// Global Fault Status
Fault fault_status_;

// Global Battery Alarm Status
BatteryAlarm battery_alarm_status_;

// Boot +1
State FSMS_Boot = State(Enter_Boot, Update_Boot, NULL); // GPIO INITIALIZATION FOR POWER AND LIGHT CLASS

// Power Up
State FSMS_PowerUp = State(Enter_PowerUp, Update_PowerUp, NULL);

// Armed +1
State FSMS_OP = State(Enter_OP, Update_OP, NULL);

// Safety +3
State FSMS_Estop = State(Enter_Estop, Update_Estop, NULL);

State FSMS_Fault = State(Enter_Fault, Update_Fault, NULL);

// Power Down / Reset
State FSMS_PowerDown = State(Enter_PowerDown, Update_PowerDown, NULL);

// Tier2 EStop
extern TIER2 Tier2;

// Tier3 EStop
extern TIER3 Tier3;

/* the state machine controls which of the states get attention and execution time */
FSM FSM_stateMachine = FSM(FSMS_Boot); //initialize state machine, start in state: noop

void processStateMachine() {
	//THIS LINE IS CRITICAL
	//do not remove the FSM_stateMachine.update() call, it is what makes this program 'tick'
	FSM_stateMachine.update();
}

void Enter_Boot() {

	// Store enter time
	enter_time_ = GetTicks();

	// Clear previous faults
	fault_status_.Init(NoFault, Nominal);
	PowerSystem.ResetFaultState();

	// Reset the Tier3 E-Stop logic in case Tier3 E-Stop is pressed/released
	// when the robot is powered off
	Tier3.resetTier3Estop();

	// Enable Tier1 E-Stop Output, Deactivate Robot
	Estop.setEstopOutput(true);

	// SM Debug Message
	if (_sm_debug) { Serial.WriteString("[ STATE ] - Entering Boot\r\n"); }
}

void Update_Boot() {

	// Check for Power Switch Enabled (nominally pulled up when disabled)
	if (PowerSystem.getPowerSwitchState() == 0)
	{
		FSM_stateMachine.transitionTo(FSMS_PowerUp);
	}

	// Update the Xbee
	Estop.getSystemEstopState();

}

// POWER ON SEQUENCE
void Enter_PowerUp() {

	// Store Power Up enter time
	enter_time_ = GetTicks();

	// Update the display
	display.PrintString("Powering Up...");

	// SM Debug Message
	if (_sm_debug) { Serial.WriteString("[ STATE ] - Entering Power Up\r\n"); }

	// Update ROS Messages
	ROS.publishMsg("Powering Up");
	ROS.nh.spinOnce();

	// Power Up and check for faults
	fault_status_ = PowerSystem.PowerUp();

	// Check for faults, if fatal, go to fault state and shutdown
	if (fault_status_.getFaultSeverity() == Fatal) {
		FSM_stateMachine.immediateTransitionTo(FSMS_Fault);
		return;
	}
	else {
		updateFault();
	}

	// Set White LEDs to 1%
	led.setWhiteLEDS(1);

	// Set LEDs to Pre-Arm color
	led.setArmStatusLED(PreArmedLEDStatus);

	// Play pre-arm melody
	buzzer.PlayPreArmMelody();

	// Update ROS Message
	ROS.publishMsg("System Powered Up");

	// SM Debug Message
	if (_sm_debug) {
		Serial.WriteString("[ STATE ] - Power Up Complete\r\n");
		Serial.WriteString("[ STATE ] - Ready for OP\r\n");
		Serial.WriteString("[ STATE ] - Waiting for E-Stop to cycle...\r\n");
	}

}

void Update_PowerUp() {

	// Run main loop
	fault_status_ = loop();

	// Check for faults, if fatal, go to fault state and shutdown
	if (fault_status_.getFaultSeverity() == Fatal) {
		FSM_stateMachine.immediateTransitionTo(FSMS_Fault);
		return;
	}
	else {
		updateFault();
	}

	// Monitor the power switch
	if (PowerSystem.getPowerSwitchState() == 1)
	{
		FSM_stateMachine.immediateTransitionTo(FSMS_PowerDown);
		return;
	}


	// Check for E-STOP cycle
	if(Tier3.waitForEstopCycle() == true && Estop.getSystemEstopState() == EstopDisabled) {
		Tier3.clearEstopCycle();
		FSM_stateMachine.transitionTo(FSMS_OP);
	}

	// Check for Alarms
	updateAlarm();
}

// Operational State
void Enter_OP() {

	// Store OP enter time
	enter_time_ = GetTicks();

	// Store the arm start time
	arm_start_time_ = GetTicks();

	// SM Debug Message
	if (_sm_debug) { Serial.WriteString("[ STATE ] - Entering OP\r\n"); }

	// Disable Tier1 E-Stop Output, Activate Robot
	Estop.setEstopOutput(false);

	// Set White LEDs to 100%
	led.setWhiteLEDS(100);

	// Set LEDs to Armed color
	led.setArmStatusLED(ArmedLEDStatus);

	// Set the output relay to false (enable driving)
	Estop.setEstopOutput(false);

	// Play ENABLED melody once
	buzzer.PlayArmedMelody();

	// Send a ROS message
	ROS.publishMsg("Power System Ready");
}

void Update_OP() {

	// Run main loop
	fault_status_ = loop();

	// Check for faults, if fatal, go to fault state and shutdown
	if (fault_status_.getFaultSeverity() == Fatal) {
		FSM_stateMachine.immediateTransitionTo(FSMS_Fault);
		return;
	}
	else {
		updateFault();
	}

	// Monitor the power switch
	if (PowerSystem.getPowerSwitchState() == 1)
	{
		FSM_stateMachine.immediateTransitionTo(FSMS_PowerDown);
		return;
	}

	// Check E-STOP state
	EstopState estop_state = Estop.getSystemEstopState();
	if(estop_state == EstopEnabled) {
		FSM_stateMachine.immediateTransitionTo(FSMS_Estop);
	}

	// Check for Alarms
	updateAlarm();
}


// E-STOP
void Enter_Estop() {

	// Store Estop enter time
	enter_time_ = GetTicks();

	// SM Debug Message
	if (_sm_debug) {
		Serial.WriteString("[ STATE ] - Entering E-Stop\r\n");
		Estop.printEstopStatus();
	}

	// Dim lights to 1% Duty Cycle
	led.setWhiteLEDS(1);

	// Set the output relay to true (disabled)
	Estop.setEstopOutput(true);

	// Set LEDs to Armed color
	led.setArmStatusLED(DisarmedLEDStatus);

	// Update ROS
	ROS.publishMsg("Entering E-Stop");
}

void Update_Estop() {

	// Check if Tier2 EStop (Xbee) is alive.  If it times out, issue an immediate fault (which is probably bad)
	if( Tier2.Timeout()) {
        // This is immediate at the moment, do we want this to be a slow shutdown?
		Serial.WriteString("[ STATE ] - X-Bee not responding, stopping robot moving\r\n");
		fault_status_.setFaultState(XBeeTimedOut, Critical);

		return;
	}

	// Run main loop
	// Note: The status of all E-Stop states is sent every loop iteration.
	//		 Software is responsible for safeing the vehicle within 30 seconds
	fault_status_ = loop();

	// Check for faults, if fatal, go to fault state and shutdown
	if (fault_status_.getFaultSeverity() == Fatal) {
		FSM_stateMachine.immediateTransitionTo(FSMS_Fault);
		return;
	}
	else {
		updateFault();
	}

	// Monitor the power switch
	if (PowerSystem.getPowerSwitchState() == 1)
	{
		FSM_stateMachine.immediateTransitionTo(FSMS_PowerDown);
		ROS.publishMsg("Powering Down (Power Switch)");
		return;
	}

	// If E-STOP cycled, go back to OP
	if(Tier3.waitForEstopCycle() == true && Estop.getSystemEstopState() == EstopDisabled) {
		Tier3.clearEstopCycle();
		FSM_stateMachine.immediateTransitionTo(FSMS_OP);
	}

	// Check for Alarms
	updateAlarm();
}

// Alarm
void updateAlarm() {

	// Check for Alarms
	battery_alarm_status_ = battery.getBatteryAlarmStatus();
	if(battery_alarm_status_ != NoAlarm && BTU_FAULT_OVERIDE == 0) {

		// Throttle Alarm reporting messages
		if (GetTicks() > (ticks_since_last_alarm_msg + ALARM_MSG_DELAY) ) {
			// TODO: Send low battery alarm SW command (there is currently no ROS command to support this)

			// SM Debug Message
			if (_sm_debug) {
				Serial.WriteString("[ MSG ] - Alarm!\r\n");
				battery.printAlarmStatus();
			}

			ticks_since_last_alarm_msg = GetTicks();
		}

		// Run in Alarm state until SW E-STOP is issued
		buzzer.SoundAlarm();
	}
	else {
		buzzer.SilenceAlarm();
	}
}

// Fault
void updateFault() {

	// Check for fault
	if (fault_status_.isFaulted()) {

		// Throttle Fault reporting messages
		if (GetTicks() > (ticks_since_last_fault_msg + FAULT_MSG_DELAY) ) {
			// Update ROS

			// SM Debug Message
			if (_sm_debug) {
				Serial.WriteString("[ MSG ] - Fault!!\r\n");
				Serial.WriteString(fault_status_.faultString().c_str());
			}

			ticks_since_last_fault_msg = GetTicks();
		}

		// Run in Alarm state until fault clears
		buzzer.SoundFault();
	}
	else {
		buzzer.SilenceFault();
	}
}

// Fault
void Enter_Fault() {

	// Store Fault enter time
	enter_time_ = GetTicks();

	// Update ROS
	ROS.publishMsg("Entering Fault State");
	ROS.publishMsg(fault_status_.faultString());

	// SM Debug Message
	if (_sm_debug) {
		Serial.WriteString("[ STATE ] - Entering Fault State\r\n");
		Serial.WriteString(fault_status_.faultString().c_str());
	}
}

void Update_Fault() {

	// TODO: It's very likely the loop update won't be serviced by the ROS 1hz loop and that the
	// 		 fault message will be missed. Immediately publish/send a ROS fault message as a swan song.
	FSM_stateMachine.immediateTransitionTo(FSMS_PowerDown);

}

// Power Down
void Enter_PowerDown() {

	// SM Debug Message
	if (_sm_debug) {
		Serial.WriteString("[ STATE ] - Entering Power Down\r\n");
	}

	// 	Update ROS
	ROS.publishMsg("Entering powerdown");

	// Send the message before we loose the connection
	ROS.nh.spinOnce();

	// Store OP enter time
	enter_time_ = GetTicks();

	// Set White LEDs to 0%
	led.setWhiteLEDS(0);

	// Powering down, so cut the power to the robot
	Estop.setEstopOutput(true);

	// Reset the Tier3 E-Stop logic in case Tier3 E-Stop is pressed/released
	// when the robot is powered off
	Tier3.resetTier3Estop();

	// Power sequence off
	PowerSystem.PowerDown();

}

void Update_PowerDown() {

	// If there is a fatal fault, hold fault state till cleared
	if (fault_status_.getFaultSeverity() == Fatal) {
		// Fault was critical enough to warrant an external power cycle
	}
	// Else if, monitor the power switch for cycle
	else if (PowerSystem.getPowerSwitchState() == 0)
	{
		FSM_stateMachine.transitionTo(FSMS_Boot);
	}

	// Update the Xbee
	Estop.getSystemEstopState();

}
//END OF FSM STATES


