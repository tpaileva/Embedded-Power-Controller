#ifndef _ROS_hw_msgs_Fptp_h
#define _ROS_hw_msgs_Fptp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hw_msgs
{

  class Fptp : public ros::Msg
  {
    public:
      typedef int16_t _flp_front_left_type;
      _flp_front_left_type flp_front_left;
      typedef int16_t _flp_front_right_type;
      _flp_front_right_type flp_front_right;
      typedef int16_t _flp_rear_left_type;
      _flp_rear_left_type flp_rear_left;
      typedef int16_t _flp_rear_right_type;
      _flp_rear_right_type flp_rear_right;

    Fptp():
      flp_front_left(0),
      flp_front_right(0),
      flp_rear_left(0),
      flp_rear_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_flp_front_left;
      u_flp_front_left.real = this->flp_front_left;
      *(outbuffer + offset + 0) = (u_flp_front_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flp_front_left.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flp_front_left);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_front_right;
      u_flp_front_right.real = this->flp_front_right;
      *(outbuffer + offset + 0) = (u_flp_front_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flp_front_right.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flp_front_right);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_rear_left;
      u_flp_rear_left.real = this->flp_rear_left;
      *(outbuffer + offset + 0) = (u_flp_rear_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flp_rear_left.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flp_rear_left);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_rear_right;
      u_flp_rear_right.real = this->flp_rear_right;
      *(outbuffer + offset + 0) = (u_flp_rear_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flp_rear_right.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flp_rear_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_flp_front_left;
      u_flp_front_left.base = 0;
      u_flp_front_left.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flp_front_left.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flp_front_left = u_flp_front_left.real;
      offset += sizeof(this->flp_front_left);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_front_right;
      u_flp_front_right.base = 0;
      u_flp_front_right.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flp_front_right.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flp_front_right = u_flp_front_right.real;
      offset += sizeof(this->flp_front_right);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_rear_left;
      u_flp_rear_left.base = 0;
      u_flp_rear_left.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flp_rear_left.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flp_rear_left = u_flp_rear_left.real;
      offset += sizeof(this->flp_rear_left);
      union {
        int16_t real;
        uint16_t base;
      } u_flp_rear_right;
      u_flp_rear_right.base = 0;
      u_flp_rear_right.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flp_rear_right.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flp_rear_right = u_flp_rear_right.real;
      offset += sizeof(this->flp_rear_right);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/Fptp"; };
    virtual const char * getMD5() override { return "5b269ffdc0fa012c7d43537d1a1cbab5"; };

  };

}
#endif
