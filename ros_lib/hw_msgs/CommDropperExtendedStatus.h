#ifndef _ROS_hw_msgs_CommDropperExtendedStatus_h
#define _ROS_hw_msgs_CommDropperExtendedStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "hw_msgs/CommSystemStatus.h"
#include "hw_msgs/CommPowerStatus.h"
#include "hw_msgs/CommNodeStatus.h"

namespace hw_msgs
{

  class CommDropperExtendedStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _uptime_type;
      _uptime_type uptime;
      typedef hw_msgs::CommSystemStatus _system_type;
      _system_type system;
      typedef hw_msgs::CommPowerStatus _power_type;
      _power_type power;
      hw_msgs::CommNodeStatus node[6];

    CommDropperExtendedStatus():
      header(),
      uptime(0),
      system(),
      power(),
      node()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->uptime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime);
      offset += this->system.serialize(outbuffer + offset);
      offset += this->power.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += this->node[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->uptime =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime);
      offset += this->system.deserialize(inbuffer + offset);
      offset += this->power.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += this->node[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommDropperExtendedStatus"; };
    virtual const char * getMD5() override { return "87cccec8eb55d91e2188bf5e7536208d"; };

  };

}
#endif
