#ifndef _ROS_hw_msgs_CommDropperDebug_h
#define _ROS_hw_msgs_CommDropperDebug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hw_msgs
{

  class CommDropperDebug : public ros::Msg
  {
    public:
      typedef const char* _debug_type;
      _debug_type debug;

    CommDropperDebug():
      debug("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_debug = strlen(this->debug);
      varToArr(outbuffer + offset, length_debug);
      offset += 4;
      memcpy(outbuffer + offset, this->debug, length_debug);
      offset += length_debug;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_debug;
      arrToVar(length_debug, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_debug; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_debug-1]=0;
      this->debug = (char *)(inbuffer + offset-1);
      offset += length_debug;
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommDropperDebug"; };
    virtual const char * getMD5() override { return "a0e10f44f30cc34df81536679a8b5c07"; };

  };

}
#endif
