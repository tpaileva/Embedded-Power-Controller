#ifndef _ROS_drone_msgs_State_h
#define _ROS_drone_msgs_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class State : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ros::Time _state_stamp_type;
      _state_stamp_type state_stamp;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef geometry_msgs::Vector3 _abias_type;
      _abias_type abias;
      typedef geometry_msgs::Vector3 _gbias_type;
      _gbias_type gbias;

    State():
      header(),
      state_stamp(),
      pose(),
      twist(),
      abias(),
      gbias()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->state_stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_stamp.sec);
      *(outbuffer + offset + 0) = (this->state_stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_stamp.nsec);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->abias.serialize(outbuffer + offset);
      offset += this->gbias.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->state_stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->state_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->state_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->state_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->state_stamp.sec);
      this->state_stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->state_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->state_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->state_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->state_stamp.nsec);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->abias.deserialize(inbuffer + offset);
      offset += this->gbias.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/State"; };
    virtual const char * getMD5() override { return "fe98c2bd1795b5c79adf72d00f98b7cf"; };

  };

}
#endif
