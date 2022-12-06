#ifndef _ROS_drone_msgs_Goal_h
#define _ROS_drone_msgs_Goal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class Goal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _jerk_type;
      _jerk_type jerk;
      typedef double _yaw_type;
      _yaw_type yaw;
      typedef double _dyaw_type;
      _dyaw_type dyaw;
      typedef bool _power_motors_type;
      _power_motors_type power_motors;
      typedef bool _reset_xy_int_type;
      _reset_xy_int_type reset_xy_int;
      typedef bool _reset_z_int_type;
      _reset_z_int_type reset_z_int;
      typedef int8_t _xy_mode_type;
      _xy_mode_type xy_mode;
      typedef int8_t _z_mode_type;
      _z_mode_type z_mode;
      enum { MODE_POS = 0 };
      enum { MODE_VEL = 1 };
      enum { MODE_ACCEL = 2 };

    Goal():
      header(),
      position(),
      velocity(),
      acceleration(),
      jerk(),
      yaw(0),
      dyaw(0),
      power_motors(0),
      reset_xy_int(0),
      reset_z_int(0),
      xy_mode(0),
      z_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->jerk.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        double real;
        uint64_t base;
      } u_dyaw;
      u_dyaw.real = this->dyaw;
      *(outbuffer + offset + 0) = (u_dyaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dyaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dyaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dyaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dyaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dyaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dyaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dyaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dyaw);
      union {
        bool real;
        uint8_t base;
      } u_power_motors;
      u_power_motors.real = this->power_motors;
      *(outbuffer + offset + 0) = (u_power_motors.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_motors);
      union {
        bool real;
        uint8_t base;
      } u_reset_xy_int;
      u_reset_xy_int.real = this->reset_xy_int;
      *(outbuffer + offset + 0) = (u_reset_xy_int.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_xy_int);
      union {
        bool real;
        uint8_t base;
      } u_reset_z_int;
      u_reset_z_int.real = this->reset_z_int;
      *(outbuffer + offset + 0) = (u_reset_z_int.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_z_int);
      union {
        int8_t real;
        uint8_t base;
      } u_xy_mode;
      u_xy_mode.real = this->xy_mode;
      *(outbuffer + offset + 0) = (u_xy_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->xy_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_z_mode;
      u_z_mode.real = this->z_mode;
      *(outbuffer + offset + 0) = (u_z_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->jerk.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_yaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        double real;
        uint64_t base;
      } u_dyaw;
      u_dyaw.base = 0;
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dyaw = u_dyaw.real;
      offset += sizeof(this->dyaw);
      union {
        bool real;
        uint8_t base;
      } u_power_motors;
      u_power_motors.base = 0;
      u_power_motors.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_motors = u_power_motors.real;
      offset += sizeof(this->power_motors);
      union {
        bool real;
        uint8_t base;
      } u_reset_xy_int;
      u_reset_xy_int.base = 0;
      u_reset_xy_int.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_xy_int = u_reset_xy_int.real;
      offset += sizeof(this->reset_xy_int);
      union {
        bool real;
        uint8_t base;
      } u_reset_z_int;
      u_reset_z_int.base = 0;
      u_reset_z_int.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_z_int = u_reset_z_int.real;
      offset += sizeof(this->reset_z_int);
      union {
        int8_t real;
        uint8_t base;
      } u_xy_mode;
      u_xy_mode.base = 0;
      u_xy_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->xy_mode = u_xy_mode.real;
      offset += sizeof(this->xy_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_z_mode;
      u_z_mode.base = 0;
      u_z_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z_mode = u_z_mode.real;
      offset += sizeof(this->z_mode);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/Goal"; };
    virtual const char * getMD5() override { return "858830dff2fd01849da794e6a95f8bb3"; };

  };

}
#endif
