/*
 * loop.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#include "loop.h"

Fault loop(void) {

	Fault loop_status;
	loop_status.Init(NoFault, Nominal);

	// Check for E-Stop faults
	EstopState estop_fault_status = Estop.getSystemEstopState();
	if(estop_fault_status == EstopFault) {
		loop_status.setFaultState(EstopSystemFault, Nominal);
		return loop_status;
	}

	// Check switch states - check for Power Switch Enabled (nominally pulled up when disabled)
	if (PowerSystem.getPowerSwitchState() == 1)
	{
		loop_status.setFaultState(PowerSwitchDisable, Nominal);
		return loop_status;
	}

	// Monitor Power System Sensors
	loop_status = PowerSystem.CheckAllRails();
	if (loop_status.getFaultState() != NoFault) {
		return loop_status;
	}

	// Check for battery fault (Exclude low SoC. that would be alarm. Not a fault.)
	loop_status = battery.getBatteryFaultStatus();
	if (loop_status.getFaultState() != NoFault) {
		return loop_status;
	}

	// Check momentary switch for white LED toggle and update
	led.updateWhiteLEDToggle();

	return loop_status;
}


