#ifndef _ROS_mobility_msgs_ErrorCode_h
#define _ROS_mobility_msgs_ErrorCode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

  class ErrorCode : public ros::Msg
  {
    public:
      typedef int32_t _data_type;
      _data_type data;
      enum { SUCCESS =  0 };
      enum { INVALID_TRANSITION =  1 };
      enum { TRANSITION_FAILED =  2 };
      enum { INVALID_GOAL =  11 };
      enum { GOAL_IN_COLLISION =  12 };
      enum { INTERNAL_ERROR =  21 };
      enum { FRAME_TRANSFORM_FAILED =  22 };
      enum { USER_PREEMPTED =  31 };

    ErrorCode():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/ErrorCode"; };
    virtual const char * getMD5() override { return "bc18e2b381665471b808b5617df05d1e"; };

  };

}
#endif
