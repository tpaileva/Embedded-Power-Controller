#ifndef _ROS_hw_msgs_HuskyCustomStatus_h
#define _ROS_hw_msgs_HuskyCustomStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class HuskyCustomStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _uptime_type;
      _uptime_type uptime;
      typedef double _mcu_and_user_port_current_type;
      _mcu_and_user_port_current_type mcu_and_user_port_current;
      typedef double _left_driver_current_type;
      _left_driver_current_type left_driver_current;
      typedef double _right_driver_current_type;
      _right_driver_current_type right_driver_current;
      typedef double _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef double _left_driver_voltage_type;
      _left_driver_voltage_type left_driver_voltage;
      typedef double _right_driver_voltage_type;
      _right_driver_voltage_type right_driver_voltage;

    HuskyCustomStatus():
      header(),
      uptime(0),
      mcu_and_user_port_current(0),
      left_driver_current(0),
      right_driver_current(0),
      battery_voltage(0),
      left_driver_voltage(0),
      right_driver_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->uptime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime);
      union {
        double real;
        uint64_t base;
      } u_mcu_and_user_port_current;
      u_mcu_and_user_port_current.real = this->mcu_and_user_port_current;
      *(outbuffer + offset + 0) = (u_mcu_and_user_port_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mcu_and_user_port_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mcu_and_user_port_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mcu_and_user_port_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mcu_and_user_port_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mcu_and_user_port_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mcu_and_user_port_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mcu_and_user_port_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mcu_and_user_port_current);
      union {
        double real;
        uint64_t base;
      } u_left_driver_current;
      u_left_driver_current.real = this->left_driver_current;
      *(outbuffer + offset + 0) = (u_left_driver_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_driver_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_driver_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_driver_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_driver_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_driver_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_driver_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_driver_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_driver_current);
      union {
        double real;
        uint64_t base;
      } u_right_driver_current;
      u_right_driver_current.real = this->right_driver_current;
      *(outbuffer + offset + 0) = (u_right_driver_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_driver_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_driver_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_driver_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_driver_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_driver_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_driver_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_driver_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_driver_current);
      union {
        double real;
        uint64_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_battery_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_battery_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_battery_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_battery_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        double real;
        uint64_t base;
      } u_left_driver_voltage;
      u_left_driver_voltage.real = this->left_driver_voltage;
      *(outbuffer + offset + 0) = (u_left_driver_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_driver_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_driver_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_driver_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_driver_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_driver_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_driver_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_driver_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_driver_voltage);
      union {
        double real;
        uint64_t base;
      } u_right_driver_voltage;
      u_right_driver_voltage.real = this->right_driver_voltage;
      *(outbuffer + offset + 0) = (u_right_driver_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_driver_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_driver_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_driver_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_driver_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_driver_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_driver_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_driver_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_driver_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->uptime =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime);
      union {
        double real;
        uint64_t base;
      } u_mcu_and_user_port_current;
      u_mcu_and_user_port_current.base = 0;
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mcu_and_user_port_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mcu_and_user_port_current = u_mcu_and_user_port_current.real;
      offset += sizeof(this->mcu_and_user_port_current);
      union {
        double real;
        uint64_t base;
      } u_left_driver_current;
      u_left_driver_current.base = 0;
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_driver_current = u_left_driver_current.real;
      offset += sizeof(this->left_driver_current);
      union {
        double real;
        uint64_t base;
      } u_right_driver_current;
      u_right_driver_current.base = 0;
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_driver_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_driver_current = u_right_driver_current.real;
      offset += sizeof(this->right_driver_current);
      union {
        double real;
        uint64_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_battery_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        double real;
        uint64_t base;
      } u_left_driver_voltage;
      u_left_driver_voltage.base = 0;
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_driver_voltage = u_left_driver_voltage.real;
      offset += sizeof(this->left_driver_voltage);
      union {
        double real;
        uint64_t base;
      } u_right_driver_voltage;
      u_right_driver_voltage.base = 0;
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_driver_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_driver_voltage = u_right_driver_voltage.real;
      offset += sizeof(this->right_driver_voltage);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/HuskyCustomStatus"; };
    virtual const char * getMD5() override { return "3f98ce1b0a95e3dad916db5807adc58a"; };

  };

}
#endif
