#ifndef _ROS_SERVICE_SetLocomotion_h
#define _ROS_SERVICE_SetLocomotion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

static const char SETLOCOMOTION[] = "spot_msgs/SetLocomotion";

  class SetLocomotionRequest : public ros::Msg
  {
    public:
      typedef uint32_t _locomotion_mode_type;
      _locomotion_mode_type locomotion_mode;

    SetLocomotionRequest():
      locomotion_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->locomotion_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locomotion_mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locomotion_mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locomotion_mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locomotion_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->locomotion_mode =  ((uint32_t) (*(inbuffer + offset)));
      this->locomotion_mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->locomotion_mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->locomotion_mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->locomotion_mode);
     return offset;
    }

    virtual const char * getType() override { return SETLOCOMOTION; };
    virtual const char * getMD5() override { return "34619b15c78bbb66e36c8b47c34e7683"; };

  };

  class SetLocomotionResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetLocomotionResponse():
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

    virtual const char * getType() override { return SETLOCOMOTION; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetLocomotion {
    public:
    typedef SetLocomotionRequest Request;
    typedef SetLocomotionResponse Response;
  };

}
#endif
