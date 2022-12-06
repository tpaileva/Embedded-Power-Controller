#ifndef _ROS_drone_msgs_DroneMissionCmd_h
#define _ROS_drone_msgs_DroneMissionCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace drone_msgs
{

  class DroneMissionCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _mode_type;
      _mode_type mode;
      typedef int8_t _risk_level_type;
      _risk_level_type risk_level;
      enum { END =  0 };
      enum { START =  1 };
      enum { ESTOP =  2 };
      enum { SAFE =  0 };
      enum { UNSAFE =  1 };

    DroneMissionCmd():
      header(),
      mode(0),
      risk_level(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        int8_t real;
        uint8_t base;
      } u_risk_level;
      u_risk_level.real = this->risk_level;
      *(outbuffer + offset + 0) = (u_risk_level.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->risk_level);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      union {
        int8_t real;
        uint8_t base;
      } u_risk_level;
      u_risk_level.base = 0;
      u_risk_level.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->risk_level = u_risk_level.real;
      offset += sizeof(this->risk_level);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/DroneMissionCmd"; };
    virtual const char * getMD5() override { return "f6ffeb5de8e844982160e8a55cf8c75f"; };

  };

}
#endif
