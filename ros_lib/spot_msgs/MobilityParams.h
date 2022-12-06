#ifndef _ROS_spot_msgs_MobilityParams_h
#define _ROS_spot_msgs_MobilityParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace spot_msgs
{

  class MobilityParams : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _body_control_type;
      _body_control_type body_control;
      typedef uint32_t _locomotion_hint_type;
      _locomotion_hint_type locomotion_hint;
      typedef bool _stair_hint_type;
      _stair_hint_type stair_hint;

    MobilityParams():
      body_control(),
      locomotion_hint(0),
      stair_hint(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->body_control.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->locomotion_hint >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locomotion_hint >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locomotion_hint >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locomotion_hint >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locomotion_hint);
      union {
        bool real;
        uint8_t base;
      } u_stair_hint;
      u_stair_hint.real = this->stair_hint;
      *(outbuffer + offset + 0) = (u_stair_hint.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stair_hint);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->body_control.deserialize(inbuffer + offset);
      this->locomotion_hint =  ((uint32_t) (*(inbuffer + offset)));
      this->locomotion_hint |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->locomotion_hint |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->locomotion_hint |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->locomotion_hint);
      union {
        bool real;
        uint8_t base;
      } u_stair_hint;
      u_stair_hint.base = 0;
      u_stair_hint.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stair_hint = u_stair_hint.real;
      offset += sizeof(this->stair_hint);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/MobilityParams"; };
    virtual const char * getMD5() override { return "87bda7c4fbd2a6b19bdc029effa9f715"; };

  };

}
#endif
