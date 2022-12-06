#ifndef _ROS_drone_msgs_Carrot_h
#define _ROS_drone_msgs_Carrot_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace drone_msgs
{

  class Carrot : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef double _dyaw_type;
      _dyaw_type dyaw;
      typedef int8_t _mode_type;
      _mode_type mode;
      enum { SAFE = 0 };
      enum { UNSAFE = 1 };

    Carrot():
      header(),
      pose(),
      dyaw(0),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dyaw;
      u_dyaw.real = this->dyaw;
      *(outbuffer + offset + 0) = (u_dyaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dyaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dyaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dyaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dyaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dyaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dyaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dyaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dyaw);
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dyaw;
      u_dyaw.base = 0;
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dyaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dyaw = u_dyaw.real;
      offset += sizeof(this->dyaw);
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/Carrot"; };
    virtual const char * getMD5() override { return "84b87fb305d9860ddf87fec8afa9d920"; };

  };

}
#endif
