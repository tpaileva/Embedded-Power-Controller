#ifndef _ROS_mobility_msgs_ResiliencyLogicStatus_h
#define _ROS_mobility_msgs_ResiliencyLogicStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mobility_msgs
{

  class ResiliencyLogicStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _imu_only_type;
      _imu_only_type imu_only;
      typedef int8_t _selected_channel_type;
      _selected_channel_type selected_channel;
      enum { CHANNEL_NONE =  0 };
      enum { CHANNEL_A =  1 };
      enum { CHANNEL_B =  2 };

    ResiliencyLogicStatus():
      header(),
      imu_only(0),
      selected_channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_imu_only;
      u_imu_only.real = this->imu_only;
      *(outbuffer + offset + 0) = (u_imu_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_only);
      union {
        int8_t real;
        uint8_t base;
      } u_selected_channel;
      u_selected_channel.real = this->selected_channel;
      *(outbuffer + offset + 0) = (u_selected_channel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->selected_channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_imu_only;
      u_imu_only.base = 0;
      u_imu_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->imu_only = u_imu_only.real;
      offset += sizeof(this->imu_only);
      union {
        int8_t real;
        uint8_t base;
      } u_selected_channel;
      u_selected_channel.base = 0;
      u_selected_channel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->selected_channel = u_selected_channel.real;
      offset += sizeof(this->selected_channel);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/ResiliencyLogicStatus"; };
    virtual const char * getMD5() override { return "e7513feff6a80f08f0ce4eea41f9f33f"; };

  };

}
#endif
