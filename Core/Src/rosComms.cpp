/*
 * ros.cpp
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#include "rosComms.h"

rosComms ROS;

PowerBoard_struct TELEMETRY;
commands COMMAND = {};

// Hardware objects
extern Led led;
extern Power PowerSystem;
extern EmergencyStop Estop;
extern TIER1 Tier1;
extern TIER2 Tier2;

// Callbacks
void CB_light_command(const std_msgs::UInt8& msg_Light_Command) {
	led.setWhiteLEDS(msg_Light_Command.data);

	// do nothing
	return;
}

void CB_tier1(const std_msgs::Bool& msg_tier1) {
	// Set the tier1 E Stop state
	if (msg_tier1.data) {
		// Tier 1 E-Stop should be enabled to stop the vehicle.
		// The class handles not restarting the count-down.
		Tier1.StartCountdown();

	} else {
		// Data is FALSE, Tier1 will not stop the vehicle (disabled)
		Tier1.Disable();
	}

	// All done
	return;
}

/*
void CB_processor_commands(const hw_msgs::ProcessorBoardCommands& msg_processor_commands) {
	COMMAND.ARMED = msg_processor_commands.ARMED;
	COMMAND.V5_DCDC = msg_processor_commands.V5_DCDC;
	COMMAND.V12_DCDC = msg_processor_commands.V12_DCDC;
	COMMAND.V18_1_DCDC = msg_processor_commands.V18_1_DCDC;
	COMMAND.V18_2_DCDC = msg_processor_commands.V18_2_DCDC;
	COMMAND.V36_DCDC = msg_processor_commands.V36_DCDC;
	COMMAND.V5_LOAD = msg_processor_commands.V5_LOAD;
	COMMAND.V12_LOAD = msg_processor_commands.V12_LOAD;
	COMMAND.V18_1_LOAD = msg_processor_commands.V18_1_LOAD;
	COMMAND.V18_2_LOAD = msg_processor_commands.V18_2_LOAD;
	COMMAND.V24_1_LOAD = msg_processor_commands.V24_1_LOAD;
	COMMAND.V24_2_LOAD = msg_processor_commands.V24_2_LOAD;
	COMMAND.V36_LOAD = msg_processor_commands.V36_LOAD;
	COMMAND.WHITE_LED_1 = msg_processor_commands.WHITE_LED_1;
	COMMAND.WHITE_LED_2 = msg_processor_commands.WHITE_LED_2;
	COMMAND.WHITE_LED_3 = msg_processor_commands.WHITE_LED_3;
	COMMAND.WHITE_LED_4 = msg_processor_commands.WHITE_LED_4;
	COMMAND.LIDAR1_LOAD = msg_processor_commands.LIDAR1_LOAD;
	COMMAND.LIDAR2_LOAD = msg_processor_commands.LIDAR2_LOAD;
	COMMAND.LIDAR3_LOAD = msg_processor_commands.LIDAR3_LOAD;
	COMMAND.LIDAR4_LOAD = msg_processor_commands.LIDAR4_LOAD;
	COMMAND.FAN_1_CTRL = msg_processor_commands.FAN_1_CTRL;
	COMMAND.FAN_2_CTRL = msg_processor_commands.FAN_2_CTRL;
}
*/

// Constructor
rosComms::rosComms() :
	sub_light_command      ("led/request"          , &CB_light_command),
	sub_tier1              ("e_stop/tier1_request" , &CB_tier1),
	pub_PowerBoardStatus   ("power_board/status"   , &msg_PowerBoardStatus),
	pub_EStopStatus        ("e_stop/status"        , &msg_EStopStatus),
	pub_Msg                ("power_board/msg"      , &msg_Msg),
    pub_FaultState         ("power_board/fault_log", &msg_FaultState)
//	pub_DropperReset       ("comm_dropper/reset"  , &msg_DropperReset)
//	sub_calibration_command("ProcessorBoard/cmds", &CB_processor_commands)
{
	// do nothing
	return;
}

// Functions
void rosComms::init(void) {

	// Subscribers
	nh.subscribe(sub_light_command);
	nh.subscribe(sub_tier1);
	//nh.subscribe(sub_calibration_command);

	// Publishers
	nh.advertise(pub_PowerBoardStatus);
	nh.advertise(pub_EStopStatus);
	nh.advertise(pub_Msg);
    nh.advertise(pub_FaultState);
	//nh.advertise(pub_DropperReset);

	// All done
	return;
}

void rosComms::publishFaultState(void) {
    
    // Fill the fields
	msg_FaultState.header.stamp = nh.now();

	msg_FaultState.powerFault    = fault_status_.getFaultState();
	msg_FaultState.faultSeverity = fault_status_.getFaultSeverity();

	msg_FaultState.battAlarm = battery_alarm_status_;
    
    // Publish the message
	pub_FaultState.publish(&msg_FaultState);
    
    // All done
    return;
}


void rosComms::publishStatus(void) {


	static uint32_t            t_armed = 0;
	static uint32_t        t_last_call = GetTicks();
           uint32_t  t_since_last_call = GetTicks() - t_last_call;

	// Track the armed time
	t_last_call = GetTicks();
	if (Estop.isArmed()) { t_armed += t_since_last_call; }

	// hw_msgs::PowerBoardStatus

	// Header
	msg_PowerBoardStatus.header.stamp = nh.now();

	// Power Inputs
	msg_PowerBoardStatus.power_source      = PowerSystem.isGsePowered();   // uint8

    // Debug Mode
	msg_PowerBoardStatus.debug_mode        = Tier1.Ignore() || Tier2.Ignore();   // (bool)

	// Battery Stats
	msg_PowerBoardStatus.batt_voltage         = PowerSystem.GetVoltage(PowerRail::VinLogicSw); // float
	msg_PowerBoardStatus.batt_current         = PowerSystem.GetCurrent(PowerRail::VinLogicSw); // float
	msg_PowerBoardStatus.batt_percentage      = (float) battery.getRelativeSOC();              // float
    msg_PowerBoardStatus.battery_soc          = battery.getRelativeSOC();                      // int32_t
    msg_PowerBoardStatus.battery_soc_critical = battery.getRosAlarmStatus();                   // bool

    // Drive Stats
	msg_PowerBoardStatus.drive_voltage     = PowerSystem.GetVoltage(PowerRail::VinMotor);   // float
	msg_PowerBoardStatus.drive_current     = PowerSystem.GetCurrent(PowerRail::VinMotor);   // float

	// Regs Voltages
	msg_PowerBoardStatus.v5_voltage      = PowerSystem.GetVoltage(PowerRail::Reg_5v);     // float
	msg_PowerBoardStatus.v12_voltage     = PowerSystem.GetVoltage(PowerRail::Reg_12v);    // float
	msg_PowerBoardStatus.v18_1_voltage   = PowerSystem.GetVoltage(PowerRail::Reg_17v);    // float, 17 V is the new 18 V
	msg_PowerBoardStatus.v18_2_voltage   = (float) loopTracking.Count();                  // float
	msg_PowerBoardStatus.v36_voltage     = (float) loopTracking.Max();                    // float
	msg_PowerBoardStatus.extra_1_voltage = PowerSystem.GetVoltage(PowerRail::VinLogic);   // float
	msg_PowerBoardStatus.extra_2_voltage = PowerSystem.GetVoltage(PowerRail::VinLogicSw); // float

	// System-On Stats
	msg_PowerBoardStatus.system_uptime    = (float) GetTicks()/1000.0f;   // float
	msg_PowerBoardStatus.arm_time         = (float) t_armed/1000.0f;      // float

	// Publish the message
	pub_PowerBoardStatus.publish(&msg_PowerBoardStatus);

	// Reset loop tracking values
	loopTracking.Reset();

	// All done
	return;
}

void rosComms::publishEStop(void) {

	// hw_msgs::EStopStatus

	// Header
	msg_EStopStatus.header.stamp  = nh.now();

	// System Estop State
	msg_EStopStatus.armed         = Estop.isArmed();                // (bool) - Robot_Status.armed;

	// Individual E-Stop states
	msg_EStopStatus.tier1_enabled =  Tier1.Enabled();                                             // (bool)    - ROS Estop
	msg_EStopStatus.tier2_enabled =  Tier2.Enabled();                                             // (bool)    - DARPA Estop
	msg_EStopStatus.tier3_enabled =  Tier3.Enabled();											  // (bool)    - Physical Estop Button
	msg_EStopStatus.tier2_timer   =  Estop.TimeRemaining();                                       // (int32_t) - Time remaining before powerdown
	msg_EStopStatus.estop_mode    =  Estop.getSystemEstopState();                                 // (uint8_t) - safety_state.estop_mode;

	// Publish the message
	pub_EStopStatus.publish(&msg_EStopStatus);

	// All done
	return;
}

void rosComms::publishMsg(std::string msg) {

	// Fill the string field
	msg_Msg.data = msg.c_str();

	// Publish the message
	pub_Msg.publish(&msg_Msg);

	// All done

}

/*
void rosComms::publishDropperReset(void) {

	// TODO: I'm not sure what this is for anymore, the Dropper reset is now its own ROS topic published directly to the dropper

	// std_msgs::Bool
	msg_DropperReset.data = 0;//DropperReset;

	// Publish the message
	pub_DropperReset.publish(&msg_DropperReset);

	// All done
	return;
}
*/

