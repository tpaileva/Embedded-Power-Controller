#ifndef _ROS_drone_msgs_AttSetpoint_h
#define _ROS_drone_msgs_AttSetpoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class AttSetpoint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Quaternion _att_type;
      _att_type att;
      typedef geometry_msgs::Vector3 _rate_type;
      _rate_type rate;
      typedef double _throttle_type;
      _throttle_type throttle;
      typedef int16_t _att_status_type;
      _att_status_type att_status;

    AttSetpoint():
      header(),
      att(),
      rate(),
      throttle(0),
      att_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->att.serialize(outbuffer + offset);
      offset += this->rate.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_throttle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_throttle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_throttle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_throttle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_att_status;
      u_att_status.real = this->att_status;
      *(outbuffer + offset + 0) = (u_att_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_att_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->att_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->att.deserialize(inbuffer + offset);
      offset += this->rate.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_att_status;
      u_att_status.base = 0;
      u_att_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_att_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->att_status = u_att_status.real;
      offset += sizeof(this->att_status);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/AttSetpoint"; };
    virtual const char * getMD5() override { return "5849d441faf7e1cf53891f700914d00f"; };

  };

}
#endif
