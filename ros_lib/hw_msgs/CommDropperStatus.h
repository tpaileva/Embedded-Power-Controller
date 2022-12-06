#ifndef _ROS_hw_msgs_CommDropperStatus_h
#define _ROS_hw_msgs_CommDropperStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class CommDropperStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint8_t status[6];
      enum { UNKNOWN =  0 };
      enum { EMPTY =  1 };
      enum { LOADED =  2 };
      enum { ERROR =  3 };

    CommDropperStatus():
      header(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->status[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      this->status[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommDropperStatus"; };
    virtual const char * getMD5() override { return "b11a988385d256ce125c26694a0d03f5"; };

  };

}
#endif
