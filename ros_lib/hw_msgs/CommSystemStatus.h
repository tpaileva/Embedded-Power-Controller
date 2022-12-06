#ifndef _ROS_hw_msgs_CommSystemStatus_h
#define _ROS_hw_msgs_CommSystemStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hw_msgs
{

  class CommSystemStatus : public ros::Msg
  {
    public:
      typedef const char* _State_type;
      _State_type State;
      typedef uint32_t _Errors_type;
      _Errors_type Errors;

    CommSystemStatus():
      State(""),
      Errors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_State = strlen(this->State);
      varToArr(outbuffer + offset, length_State);
      offset += 4;
      memcpy(outbuffer + offset, this->State, length_State);
      offset += length_State;
      *(outbuffer + offset + 0) = (this->Errors >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Errors >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->Errors >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->Errors >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Errors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_State;
      arrToVar(length_State, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_State; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_State-1]=0;
      this->State = (char *)(inbuffer + offset-1);
      offset += length_State;
      this->Errors =  ((uint32_t) (*(inbuffer + offset)));
      this->Errors |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Errors |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->Errors |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->Errors);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommSystemStatus"; };
    virtual const char * getMD5() override { return "faf8740d3ccc85c6d631b4d18127239b"; };

  };

}
#endif
