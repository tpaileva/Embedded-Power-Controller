#ifndef _ROS_hw_msgs_PowerBoardStatus_h
#define _ROS_hw_msgs_PowerBoardStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class PowerBoardStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _power_source_type;
      _power_source_type power_source;
      typedef bool _debug_mode_type;
      _debug_mode_type debug_mode;
      typedef float _batt_voltage_type;
      _batt_voltage_type batt_voltage;
      typedef float _batt_current_type;
      _batt_current_type batt_current;
      typedef float _batt_percentage_type;
      _batt_percentage_type batt_percentage;
      typedef int32_t _battery_soc_type;
      _battery_soc_type battery_soc;
      typedef bool _battery_soc_critical_type;
      _battery_soc_critical_type battery_soc_critical;
      typedef float _drive_voltage_type;
      _drive_voltage_type drive_voltage;
      typedef float _drive_current_type;
      _drive_current_type drive_current;
      typedef float _v5_voltage_type;
      _v5_voltage_type v5_voltage;
      typedef float _v12_voltage_type;
      _v12_voltage_type v12_voltage;
      typedef float _v18_1_voltage_type;
      _v18_1_voltage_type v18_1_voltage;
      typedef float _v18_2_voltage_type;
      _v18_2_voltage_type v18_2_voltage;
      typedef float _v36_voltage_type;
      _v36_voltage_type v36_voltage;
      typedef float _extra_1_voltage_type;
      _extra_1_voltage_type extra_1_voltage;
      typedef float _extra_2_voltage_type;
      _extra_2_voltage_type extra_2_voltage;
      typedef float _system_uptime_type;
      _system_uptime_type system_uptime;
      typedef float _arm_time_type;
      _arm_time_type arm_time;
      typedef float _drive_time_type;
      _drive_time_type drive_time;
      typedef float _fly_time_type;
      _fly_time_type fly_time;

    PowerBoardStatus():
      header(),
      power_source(0),
      debug_mode(0),
      batt_voltage(0),
      batt_current(0),
      batt_percentage(0),
      battery_soc(0),
      battery_soc_critical(0),
      drive_voltage(0),
      drive_current(0),
      v5_voltage(0),
      v12_voltage(0),
      v18_1_voltage(0),
      v18_2_voltage(0),
      v36_voltage(0),
      extra_1_voltage(0),
      extra_2_voltage(0),
      system_uptime(0),
      arm_time(0),
      drive_time(0),
      fly_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->power_source >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_source);
      union {
        bool real;
        uint8_t base;
      } u_debug_mode;
      u_debug_mode.real = this->debug_mode;
      *(outbuffer + offset + 0) = (u_debug_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->debug_mode);
      union {
        float real;
        uint32_t base;
      } u_batt_voltage;
      u_batt_voltage.real = this->batt_voltage;
      *(outbuffer + offset + 0) = (u_batt_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batt_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batt_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batt_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batt_voltage);
      union {
        float real;
        uint32_t base;
      } u_batt_current;
      u_batt_current.real = this->batt_current;
      *(outbuffer + offset + 0) = (u_batt_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batt_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batt_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batt_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batt_current);
      union {
        float real;
        uint32_t base;
      } u_batt_percentage;
      u_batt_percentage.real = this->batt_percentage;
      *(outbuffer + offset + 0) = (u_batt_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batt_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batt_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batt_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batt_percentage);
      union {
        int32_t real;
        uint32_t base;
      } u_battery_soc;
      u_battery_soc.real = this->battery_soc;
      *(outbuffer + offset + 0) = (u_battery_soc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_soc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_soc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_soc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_soc);
      union {
        bool real;
        uint8_t base;
      } u_battery_soc_critical;
      u_battery_soc_critical.real = this->battery_soc_critical;
      *(outbuffer + offset + 0) = (u_battery_soc_critical.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_soc_critical);
      union {
        float real;
        uint32_t base;
      } u_drive_voltage;
      u_drive_voltage.real = this->drive_voltage;
      *(outbuffer + offset + 0) = (u_drive_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drive_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drive_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drive_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drive_voltage);
      union {
        float real;
        uint32_t base;
      } u_drive_current;
      u_drive_current.real = this->drive_current;
      *(outbuffer + offset + 0) = (u_drive_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drive_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drive_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drive_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drive_current);
      union {
        float real;
        uint32_t base;
      } u_v5_voltage;
      u_v5_voltage.real = this->v5_voltage;
      *(outbuffer + offset + 0) = (u_v5_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v5_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v5_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v5_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v5_voltage);
      union {
        float real;
        uint32_t base;
      } u_v12_voltage;
      u_v12_voltage.real = this->v12_voltage;
      *(outbuffer + offset + 0) = (u_v12_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v12_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v12_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v12_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v12_voltage);
      union {
        float real;
        uint32_t base;
      } u_v18_1_voltage;
      u_v18_1_voltage.real = this->v18_1_voltage;
      *(outbuffer + offset + 0) = (u_v18_1_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v18_1_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v18_1_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v18_1_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v18_1_voltage);
      union {
        float real;
        uint32_t base;
      } u_v18_2_voltage;
      u_v18_2_voltage.real = this->v18_2_voltage;
      *(outbuffer + offset + 0) = (u_v18_2_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v18_2_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v18_2_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v18_2_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v18_2_voltage);
      union {
        float real;
        uint32_t base;
      } u_v36_voltage;
      u_v36_voltage.real = this->v36_voltage;
      *(outbuffer + offset + 0) = (u_v36_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v36_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v36_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v36_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v36_voltage);
      union {
        float real;
        uint32_t base;
      } u_extra_1_voltage;
      u_extra_1_voltage.real = this->extra_1_voltage;
      *(outbuffer + offset + 0) = (u_extra_1_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extra_1_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extra_1_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extra_1_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extra_1_voltage);
      union {
        float real;
        uint32_t base;
      } u_extra_2_voltage;
      u_extra_2_voltage.real = this->extra_2_voltage;
      *(outbuffer + offset + 0) = (u_extra_2_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extra_2_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extra_2_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extra_2_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extra_2_voltage);
      union {
        float real;
        uint32_t base;
      } u_system_uptime;
      u_system_uptime.real = this->system_uptime;
      *(outbuffer + offset + 0) = (u_system_uptime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_system_uptime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_system_uptime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_system_uptime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->system_uptime);
      union {
        float real;
        uint32_t base;
      } u_arm_time;
      u_arm_time.real = this->arm_time;
      *(outbuffer + offset + 0) = (u_arm_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arm_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arm_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arm_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arm_time);
      union {
        float real;
        uint32_t base;
      } u_drive_time;
      u_drive_time.real = this->drive_time;
      *(outbuffer + offset + 0) = (u_drive_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drive_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drive_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drive_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drive_time);
      union {
        float real;
        uint32_t base;
      } u_fly_time;
      u_fly_time.real = this->fly_time;
      *(outbuffer + offset + 0) = (u_fly_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fly_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fly_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fly_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fly_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->power_source =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->power_source);
      union {
        bool real;
        uint8_t base;
      } u_debug_mode;
      u_debug_mode.base = 0;
      u_debug_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->debug_mode = u_debug_mode.real;
      offset += sizeof(this->debug_mode);
      union {
        float real;
        uint32_t base;
      } u_batt_voltage;
      u_batt_voltage.base = 0;
      u_batt_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batt_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batt_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batt_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batt_voltage = u_batt_voltage.real;
      offset += sizeof(this->batt_voltage);
      union {
        float real;
        uint32_t base;
      } u_batt_current;
      u_batt_current.base = 0;
      u_batt_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batt_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batt_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batt_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batt_current = u_batt_current.real;
      offset += sizeof(this->batt_current);
      union {
        float real;
        uint32_t base;
      } u_batt_percentage;
      u_batt_percentage.base = 0;
      u_batt_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batt_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batt_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batt_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batt_percentage = u_batt_percentage.real;
      offset += sizeof(this->batt_percentage);
      union {
        int32_t real;
        uint32_t base;
      } u_battery_soc;
      u_battery_soc.base = 0;
      u_battery_soc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_soc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_soc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_soc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_soc = u_battery_soc.real;
      offset += sizeof(this->battery_soc);
      union {
        bool real;
        uint8_t base;
      } u_battery_soc_critical;
      u_battery_soc_critical.base = 0;
      u_battery_soc_critical.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_soc_critical = u_battery_soc_critical.real;
      offset += sizeof(this->battery_soc_critical);
      union {
        float real;
        uint32_t base;
      } u_drive_voltage;
      u_drive_voltage.base = 0;
      u_drive_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drive_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drive_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drive_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drive_voltage = u_drive_voltage.real;
      offset += sizeof(this->drive_voltage);
      union {
        float real;
        uint32_t base;
      } u_drive_current;
      u_drive_current.base = 0;
      u_drive_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drive_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drive_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drive_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drive_current = u_drive_current.real;
      offset += sizeof(this->drive_current);
      union {
        float real;
        uint32_t base;
      } u_v5_voltage;
      u_v5_voltage.base = 0;
      u_v5_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v5_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v5_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v5_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v5_voltage = u_v5_voltage.real;
      offset += sizeof(this->v5_voltage);
      union {
        float real;
        uint32_t base;
      } u_v12_voltage;
      u_v12_voltage.base = 0;
      u_v12_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v12_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v12_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v12_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v12_voltage = u_v12_voltage.real;
      offset += sizeof(this->v12_voltage);
      union {
        float real;
        uint32_t base;
      } u_v18_1_voltage;
      u_v18_1_voltage.base = 0;
      u_v18_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v18_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v18_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v18_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v18_1_voltage = u_v18_1_voltage.real;
      offset += sizeof(this->v18_1_voltage);
      union {
        float real;
        uint32_t base;
      } u_v18_2_voltage;
      u_v18_2_voltage.base = 0;
      u_v18_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v18_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v18_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v18_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v18_2_voltage = u_v18_2_voltage.real;
      offset += sizeof(this->v18_2_voltage);
      union {
        float real;
        uint32_t base;
      } u_v36_voltage;
      u_v36_voltage.base = 0;
      u_v36_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v36_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v36_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v36_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v36_voltage = u_v36_voltage.real;
      offset += sizeof(this->v36_voltage);
      union {
        float real;
        uint32_t base;
      } u_extra_1_voltage;
      u_extra_1_voltage.base = 0;
      u_extra_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_extra_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_extra_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_extra_1_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->extra_1_voltage = u_extra_1_voltage.real;
      offset += sizeof(this->extra_1_voltage);
      union {
        float real;
        uint32_t base;
      } u_extra_2_voltage;
      u_extra_2_voltage.base = 0;
      u_extra_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_extra_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_extra_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_extra_2_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->extra_2_voltage = u_extra_2_voltage.real;
      offset += sizeof(this->extra_2_voltage);
      union {
        float real;
        uint32_t base;
      } u_system_uptime;
      u_system_uptime.base = 0;
      u_system_uptime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_system_uptime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_system_uptime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_system_uptime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->system_uptime = u_system_uptime.real;
      offset += sizeof(this->system_uptime);
      union {
        float real;
        uint32_t base;
      } u_arm_time;
      u_arm_time.base = 0;
      u_arm_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arm_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arm_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arm_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->arm_time = u_arm_time.real;
      offset += sizeof(this->arm_time);
      union {
        float real;
        uint32_t base;
      } u_drive_time;
      u_drive_time.base = 0;
      u_drive_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drive_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drive_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drive_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drive_time = u_drive_time.real;
      offset += sizeof(this->drive_time);
      union {
        float real;
        uint32_t base;
      } u_fly_time;
      u_fly_time.base = 0;
      u_fly_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fly_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fly_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fly_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fly_time = u_fly_time.real;
      offset += sizeof(this->fly_time);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/PowerBoardStatus"; };
    virtual const char * getMD5() override { return "a11343adc5d061e4dc31229def1f5321"; };

  };

}
#endif
