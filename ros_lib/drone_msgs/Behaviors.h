#ifndef _ROS_drone_msgs_Behaviors_h
#define _ROS_drone_msgs_Behaviors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace drone_msgs
{

  class Behaviors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _mode_type;
      _mode_type mode;
      enum { IDLE =  0 };
      enum { TAKEOFF =  1 };
      enum { START =  2 };
      enum { STOP =  3 };
      enum { LAND =  4 };
      enum { ESTOP =  5 };
      enum { AUTO =  6 };
      enum { MANUAL =  7 };

    Behaviors():
      header(),
      mode(0)
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
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/Behaviors"; };
    virtual const char * getMD5() override { return "a9351934d0dc46289076f3e7085c6279"; };

  };

}
#endif
