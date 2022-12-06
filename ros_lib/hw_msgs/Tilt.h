#ifndef _ROS_hw_msgs_Tilt_h
#define _ROS_hw_msgs_Tilt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class Tilt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _tilt_x_type;
      _tilt_x_type tilt_x;
      typedef int16_t _tilt_y_type;
      _tilt_y_type tilt_y;

    Tilt():
      header(),
      tilt_x(0),
      tilt_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt_x;
      u_tilt_x.real = this->tilt_x;
      *(outbuffer + offset + 0) = (u_tilt_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tilt_x);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt_y;
      u_tilt_y.real = this->tilt_y;
      *(outbuffer + offset + 0) = (u_tilt_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tilt_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt_x;
      u_tilt_x.base = 0;
      u_tilt_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tilt_x = u_tilt_x.real;
      offset += sizeof(this->tilt_x);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt_y;
      u_tilt_y.base = 0;
      u_tilt_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tilt_y = u_tilt_y.real;
      offset += sizeof(this->tilt_y);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/Tilt"; };
    virtual const char * getMD5() override { return "3f0a3db2910f574aa2a726107bdc52bd"; };

  };

}
#endif
