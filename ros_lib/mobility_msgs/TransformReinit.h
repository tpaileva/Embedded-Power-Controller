#ifndef _ROS_mobility_msgs_TransformReinit_h
#define _ROS_mobility_msgs_TransformReinit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mobility_msgs
{

  class TransformReinit : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _type_type;
      _type_type type;
      enum { ERROR = 0 };
      enum { IMU = 1 };
      enum { FUSED = 2 };
      enum { LO = 3 };
      enum { VIO = 4 };

    TransformReinit():
      header(),
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/TransformReinit"; };
    virtual const char * getMD5() override { return "ff7aeaf8df5731593ba7838174002aff"; };

  };

}
#endif
