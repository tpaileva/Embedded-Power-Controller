#ifndef _ROS_mobility_msgs_LocalPlannerStatus_h
#define _ROS_mobility_msgs_LocalPlannerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mobility_msgs
{

  class LocalPlannerStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _status_type;
      _status_type status;
      typedef int8_t _moving_state_type;
      _moving_state_type moving_state;
      enum { ERROR = -1 };
      enum { WAITING = 0 };
      enum { RUNNING = 1 };
      enum { STUCK = 2 };
      enum { MOVING_FORWARD_DOWN = 0 };
      enum { MOVING_FORWARD_UP = 1 };
      enum { MOVING_DOWN = 2 };
      enum { MOVING_UP = 3 };
      enum { MOVING_STUCK = 4 };

    LocalPlannerStatus():
      header(),
      status(0),
      moving_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      union {
        int8_t real;
        uint8_t base;
      } u_moving_state;
      u_moving_state.real = this->moving_state;
      *(outbuffer + offset + 0) = (u_moving_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->moving_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      union {
        int8_t real;
        uint8_t base;
      } u_moving_state;
      u_moving_state.base = 0;
      u_moving_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->moving_state = u_moving_state.real;
      offset += sizeof(this->moving_state);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/LocalPlannerStatus"; };
    virtual const char * getMD5() override { return "0cb8d3fd79def8caec37712fb84e9267"; };

  };

}
#endif
