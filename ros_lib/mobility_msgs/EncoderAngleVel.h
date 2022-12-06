#ifndef _ROS_mobility_msgs_EncoderAngleVel_h
#define _ROS_mobility_msgs_EncoderAngleVel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

  class EncoderAngleVel : public ros::Msg
  {
    public:
      typedef float _angleLeft_type;
      _angleLeft_type angleLeft;
      typedef float _angleRight_type;
      _angleRight_type angleRight;
      typedef float _velocityLeft_type;
      _velocityLeft_type velocityLeft;
      typedef float _velocityRight_type;
      _velocityRight_type velocityRight;

    EncoderAngleVel():
      angleLeft(0),
      angleRight(0),
      velocityLeft(0),
      velocityRight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angleLeft;
      u_angleLeft.real = this->angleLeft;
      *(outbuffer + offset + 0) = (u_angleLeft.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angleLeft.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angleLeft.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angleLeft.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angleLeft);
      union {
        float real;
        uint32_t base;
      } u_angleRight;
      u_angleRight.real = this->angleRight;
      *(outbuffer + offset + 0) = (u_angleRight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angleRight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angleRight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angleRight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angleRight);
      union {
        float real;
        uint32_t base;
      } u_velocityLeft;
      u_velocityLeft.real = this->velocityLeft;
      *(outbuffer + offset + 0) = (u_velocityLeft.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityLeft.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityLeft.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityLeft.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocityLeft);
      union {
        float real;
        uint32_t base;
      } u_velocityRight;
      u_velocityRight.real = this->velocityRight;
      *(outbuffer + offset + 0) = (u_velocityRight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityRight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityRight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityRight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocityRight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angleLeft;
      u_angleLeft.base = 0;
      u_angleLeft.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angleLeft.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angleLeft.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angleLeft.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angleLeft = u_angleLeft.real;
      offset += sizeof(this->angleLeft);
      union {
        float real;
        uint32_t base;
      } u_angleRight;
      u_angleRight.base = 0;
      u_angleRight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angleRight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angleRight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angleRight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angleRight = u_angleRight.real;
      offset += sizeof(this->angleRight);
      union {
        float real;
        uint32_t base;
      } u_velocityLeft;
      u_velocityLeft.base = 0;
      u_velocityLeft.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocityLeft.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocityLeft.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocityLeft.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocityLeft = u_velocityLeft.real;
      offset += sizeof(this->velocityLeft);
      union {
        float real;
        uint32_t base;
      } u_velocityRight;
      u_velocityRight.base = 0;
      u_velocityRight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocityRight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocityRight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocityRight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocityRight = u_velocityRight.real;
      offset += sizeof(this->velocityRight);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/EncoderAngleVel"; };
    virtual const char * getMD5() override { return "eb76938de6f9cace223a42b6689342f0"; };

  };

}
#endif
