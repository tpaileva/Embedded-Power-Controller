#ifndef _ROS_hw_msgs_CommPowerStatus_h
#define _ROS_hw_msgs_CommPowerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hw_msgs
{

  class CommPowerStatus : public ros::Msg
  {
    public:
      typedef const char* _PowerState_type;
      _PowerState_type PowerState;
      typedef uint32_t _PowerError_type;
      _PowerError_type PowerError;
      typedef float _V_IN_type;
      _V_IN_type V_IN;
      typedef float _V_12V_type;
      _V_12V_type V_12V;

    CommPowerStatus():
      PowerState(""),
      PowerError(0),
      V_IN(0),
      V_12V(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_PowerState = strlen(this->PowerState);
      varToArr(outbuffer + offset, length_PowerState);
      offset += 4;
      memcpy(outbuffer + offset, this->PowerState, length_PowerState);
      offset += length_PowerState;
      *(outbuffer + offset + 0) = (this->PowerError >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->PowerError >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->PowerError >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->PowerError >> (8 * 3)) & 0xFF;
      offset += sizeof(this->PowerError);
      union {
        float real;
        uint32_t base;
      } u_V_IN;
      u_V_IN.real = this->V_IN;
      *(outbuffer + offset + 0) = (u_V_IN.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_V_IN.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_V_IN.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_V_IN.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->V_IN);
      union {
        float real;
        uint32_t base;
      } u_V_12V;
      u_V_12V.real = this->V_12V;
      *(outbuffer + offset + 0) = (u_V_12V.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_V_12V.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_V_12V.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_V_12V.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->V_12V);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_PowerState;
      arrToVar(length_PowerState, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_PowerState; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_PowerState-1]=0;
      this->PowerState = (char *)(inbuffer + offset-1);
      offset += length_PowerState;
      this->PowerError =  ((uint32_t) (*(inbuffer + offset)));
      this->PowerError |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->PowerError |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->PowerError |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->PowerError);
      union {
        float real;
        uint32_t base;
      } u_V_IN;
      u_V_IN.base = 0;
      u_V_IN.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_V_IN.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_V_IN.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_V_IN.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->V_IN = u_V_IN.real;
      offset += sizeof(this->V_IN);
      union {
        float real;
        uint32_t base;
      } u_V_12V;
      u_V_12V.base = 0;
      u_V_12V.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_V_12V.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_V_12V.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_V_12V.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->V_12V = u_V_12V.real;
      offset += sizeof(this->V_12V);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommPowerStatus"; };
    virtual const char * getMD5() override { return "32dd2e43617e991f7fbcf207a9b86a5a"; };

  };

}
#endif
