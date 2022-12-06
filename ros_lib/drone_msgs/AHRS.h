#ifndef _ROS_drone_msgs_AHRS_h
#define _ROS_drone_msgs_AHRS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class AHRS : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Quaternion _q_des_type;
      _q_des_type q_des;
      typedef geometry_msgs::Quaternion _q_act_type;
      _q_act_type q_act;
      typedef geometry_msgs::Quaternion _q_err_type;
      _q_err_type q_err;
      typedef geometry_msgs::Vector3 _w_des_type;
      _w_des_type w_des;
      typedef geometry_msgs::Vector3 _w_act_type;
      _w_act_type w_act;
      typedef geometry_msgs::Vector3 _w_err_type;
      _w_err_type w_err;
      typedef geometry_msgs::Vector3 _s_type;
      _s_type s;
      typedef geometry_msgs::Vector3 _integrators_type;
      _integrators_type integrators;

    AHRS():
      header(),
      q_des(),
      q_act(),
      q_err(),
      w_des(),
      w_act(),
      w_err(),
      s(),
      integrators()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->q_des.serialize(outbuffer + offset);
      offset += this->q_act.serialize(outbuffer + offset);
      offset += this->q_err.serialize(outbuffer + offset);
      offset += this->w_des.serialize(outbuffer + offset);
      offset += this->w_act.serialize(outbuffer + offset);
      offset += this->w_err.serialize(outbuffer + offset);
      offset += this->s.serialize(outbuffer + offset);
      offset += this->integrators.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->q_des.deserialize(inbuffer + offset);
      offset += this->q_act.deserialize(inbuffer + offset);
      offset += this->q_err.deserialize(inbuffer + offset);
      offset += this->w_des.deserialize(inbuffer + offset);
      offset += this->w_act.deserialize(inbuffer + offset);
      offset += this->w_err.deserialize(inbuffer + offset);
      offset += this->s.deserialize(inbuffer + offset);
      offset += this->integrators.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/AHRS"; };
    virtual const char * getMD5() override { return "e29a1c06743e6b71fac325c483d20ca6"; };

  };

}
#endif
