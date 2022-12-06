/*
 * ros.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

#pragma once

#include <string.h>

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Empty.h>
#include <ros/time.h>
#include <std_msgs/Header.h>

#include <hw_msgs/EStopStatus.h>
#include <hw_msgs/PowerBoardStatus.h>
#include <hw_msgs/PowerBoardFaults.h>
//#include <hw_msgs/ProcessorBoardCommands.h>

// Includes for interfacing with hardware
#include "btu.h"
#include "led.h"
#include "power.h"
#include "estop.h"
#include "fault.h"
#include "btu.h"
#include "loopTracking.h"


// Forward declaration
class rosComms;

extern rosComms ROS;

struct PowerBoard_struct {
	size_t power_source = 0;
	const size_t BATTERY = 0;
	const size_t AUX = 1;

	float batt_voltage = 0;
	float batt_current = 0;
	float batt_percentage = 0;
	float drive_voltage = 0;
	float drive_current = 0;
	float system_uptime = 0;
	float arm_time = 0;
	float drive_time = 0;
	float fly_time = 0;
};

struct commands {
	bool ARMED = false;
	bool V5_DCDC = false;
	bool V12_DCDC = false;
	bool V18_1_DCDC = false;
	bool V18_2_DCDC = false;
	bool V36_DCDC = false;
	bool V5_LOAD = false;
	bool V12_LOAD = false;
	bool V18_1_LOAD = false;
	bool V18_2_LOAD = false;
	bool V24_1_LOAD = false;
	bool V24_2_LOAD = false;
	bool V36_LOAD = false;
	double WHITE_LED_1 = 0.0;
	double WHITE_LED_2 = 0.0;
	double WHITE_LED_3 = 0.0;
	double WHITE_LED_4 = 0.0;
	bool LIDAR1_LOAD = false;
	bool LIDAR2_LOAD = false;
	bool LIDAR3_LOAD = false;
	bool LIDAR4_LOAD = false;
	bool FAN_1_CTRL = false;
	bool FAN_2_CTRL = false;
};

class rosComms {
public:

	rosComms(void);

	//virtual ~rosComms();

	void init(void);

	void publishStatus(void);
	void publishEStop(void);
	void publishDropperReset(void);
    void publishFaultState(void);
	void publishMsg(std::string msg);

	// Variables
	ros::NodeHandle  nh;

private:

	// Subscribers
	ros::Subscriber<std_msgs::UInt8>                 sub_light_command;
	ros::Subscriber<std_msgs::Bool>                  sub_tier1;
	//ros::Subscriber<hw_msgs::ProcessorBoardCommands> sub_calibration_command;

	// Messages
	hw_msgs::PowerBoardStatus msg_PowerBoardStatus;
	hw_msgs::EStopStatus      msg_EStopStatus;
    hw_msgs::PowerBoardFaults msg_FaultState;
	//std_msgs::Bool            msg_DropperReset;
	std_msgs::String          msg_Msg;

	// Publishers
	ros::Publisher pub_PowerBoardStatus;
	ros::Publisher pub_EStopStatus;
	ros::Publisher pub_Msg;
    ros::Publisher pub_FaultState;
	//ros::Publisher pub_DropperReset;

};



