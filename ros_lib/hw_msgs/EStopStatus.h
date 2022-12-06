#ifndef _ROS_hw_msgs_EStopStatus_h
#define _ROS_hw_msgs_EStopStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class EStopStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _armed_type;
      _armed_type armed;
      typedef bool _tier1_enabled_type;
      _tier1_enabled_type tier1_enabled;
      typedef bool _tier2_enabled_type;
      _tier2_enabled_type tier2_enabled;
      typedef bool _tier3_enabled_type;
      _tier3_enabled_type tier3_enabled;
      typedef int32_t _tier2_timer_type;
      _tier2_timer_type tier2_timer;
      typedef uint8_t _estop_mode_type;
      _estop_mode_type estop_mode;

    EStopStatus():
      header(),
      armed(0),
      tier1_enabled(0),
      tier2_enabled(0),
      tier3_enabled(0),
      tier2_timer(0),
      estop_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.real = this->armed;
      *(outbuffer + offset + 0) = (u_armed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armed);
      union {
        bool real;
        uint8_t base;
      } u_tier1_enabled;
      u_tier1_enabled.real = this->tier1_enabled;
      *(outbuffer + offset + 0) = (u_tier1_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tier1_enabled);
      union {
        bool real;
        uint8_t base;
      } u_tier2_enabled;
      u_tier2_enabled.real = this->tier2_enabled;
      *(outbuffer + offset + 0) = (u_tier2_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tier2_enabled);
      union {
        bool real;
        uint8_t base;
      } u_tier3_enabled;
      u_tier3_enabled.real = this->tier3_enabled;
      *(outbuffer + offset + 0) = (u_tier3_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tier3_enabled);
      union {
        int32_t real;
        uint32_t base;
      } u_tier2_timer;
      u_tier2_timer.real = this->tier2_timer;
      *(outbuffer + offset + 0) = (u_tier2_timer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tier2_timer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tier2_timer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tier2_timer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tier2_timer);
      *(outbuffer + offset + 0) = (this->estop_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.base = 0;
      u_armed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->armed = u_armed.real;
      offset += sizeof(this->armed);
      union {
        bool real;
        uint8_t base;
      } u_tier1_enabled;
      u_tier1_enabled.base = 0;
      u_tier1_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tier1_enabled = u_tier1_enabled.real;
      offset += sizeof(this->tier1_enabled);
      union {
        bool real;
        uint8_t base;
      } u_tier2_enabled;
      u_tier2_enabled.base = 0;
      u_tier2_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tier2_enabled = u_tier2_enabled.real;
      offset += sizeof(this->tier2_enabled);
      union {
        bool real;
        uint8_t base;
      } u_tier3_enabled;
      u_tier3_enabled.base = 0;
      u_tier3_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tier3_enabled = u_tier3_enabled.real;
      offset += sizeof(this->tier3_enabled);
      union {
        int32_t real;
        uint32_t base;
      } u_tier2_timer;
      u_tier2_timer.base = 0;
      u_tier2_timer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tier2_timer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tier2_timer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tier2_timer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tier2_timer = u_tier2_timer.real;
      offset += sizeof(this->tier2_timer);
      this->estop_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->estop_mode);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/EStopStatus"; };
    virtual const char * getMD5() override { return "a8ddf3432451585018dab86fbff13c69"; };

  };

}
#endif
