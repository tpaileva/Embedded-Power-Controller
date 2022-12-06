#ifndef _ROS_SERVICE_UseYawGoal_h
#define _ROS_SERVICE_UseYawGoal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

static const char USEYAWGOAL[] = "mobility_msgs/UseYawGoal";

  class UseYawGoalRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;
      typedef double _yaw_tolerance_type;
      _yaw_tolerance_type yaw_tolerance;

    UseYawGoalRequest():
      enable(0),
      yaw_tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      union {
        double real;
        uint64_t base;
      } u_yaw_tolerance;
      u_yaw_tolerance.real = this->yaw_tolerance;
      *(outbuffer + offset + 0) = (u_yaw_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yaw_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yaw_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yaw_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yaw_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->yaw_tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
      union {
        double real;
        uint64_t base;
      } u_yaw_tolerance;
      u_yaw_tolerance.base = 0;
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->yaw_tolerance = u_yaw_tolerance.real;
      offset += sizeof(this->yaw_tolerance);
     return offset;
    }

    virtual const char * getType() override { return USEYAWGOAL; };
    virtual const char * getMD5() override { return "c8512f1374d04b7d1f8481bf59cb29ea"; };

  };

  class UseYawGoalResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    UseYawGoalResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return USEYAWGOAL; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class UseYawGoal {
    public:
    typedef UseYawGoalRequest Request;
    typedef UseYawGoalResponse Response;
  };

}
#endif
