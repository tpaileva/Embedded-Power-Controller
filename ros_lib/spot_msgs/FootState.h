#ifndef _ROS_spot_msgs_FootState_h
#define _ROS_spot_msgs_FootState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace spot_msgs
{

  class FootState : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _foot_position_rt_body_type;
      _foot_position_rt_body_type foot_position_rt_body;
      typedef uint8_t _contact_type;
      _contact_type contact;
      enum { CONTACT_UNKNOWN =  0 };
      enum { CONTACT_MADE =  1 };
      enum { CONTACT_LOST =  2 };

    FootState():
      foot_position_rt_body(),
      contact(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->foot_position_rt_body.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contact >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->foot_position_rt_body.deserialize(inbuffer + offset);
      this->contact =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->contact);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/FootState"; };
    virtual const char * getMD5() override { return "524cf45b9d66134675b586174885a624"; };

  };

}
#endif
