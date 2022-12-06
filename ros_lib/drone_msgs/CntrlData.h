#ifndef _ROS_drone_msgs_CntrlData_h
#define _ROS_drone_msgs_CntrlData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class CntrlData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _position_desired_type;
      _position_desired_type position_desired;
      typedef geometry_msgs::Vector3 _velocity_desired_type;
      _velocity_desired_type velocity_desired;
      typedef geometry_msgs::Vector3 _position_error_type;
      _position_error_type position_error;
      typedef geometry_msgs::Vector3 _velocity_error_type;
      _velocity_error_type velocity_error;
      typedef geometry_msgs::Vector3 _acceleration_desired_type;
      _acceleration_desired_type acceleration_desired;
      typedef geometry_msgs::Vector3 _acceleration_feedback_type;
      _acceleration_feedback_type acceleration_feedback;
      typedef geometry_msgs::Vector3 _jerk_desired_type;
      _jerk_desired_type jerk_desired;
      typedef geometry_msgs::Vector3 _jerk_feedback_type;
      _jerk_feedback_type jerk_feedback;
      typedef geometry_msgs::Vector3 _position_integrators_type;
      _position_integrators_type position_integrators;
      typedef double _throttle_type;
      _throttle_type throttle;
      typedef int8_t _tracking_mode_type;
      _tracking_mode_type tracking_mode;
      typedef int8_t _att_status_type;
      _att_status_type att_status;

    CntrlData():
      header(),
      position_desired(),
      velocity_desired(),
      position_error(),
      velocity_error(),
      acceleration_desired(),
      acceleration_feedback(),
      jerk_desired(),
      jerk_feedback(),
      position_integrators(),
      throttle(0),
      tracking_mode(0),
      att_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position_desired.serialize(outbuffer + offset);
      offset += this->velocity_desired.serialize(outbuffer + offset);
      offset += this->position_error.serialize(outbuffer + offset);
      offset += this->velocity_error.serialize(outbuffer + offset);
      offset += this->acceleration_desired.serialize(outbuffer + offset);
      offset += this->acceleration_feedback.serialize(outbuffer + offset);
      offset += this->jerk_desired.serialize(outbuffer + offset);
      offset += this->jerk_feedback.serialize(outbuffer + offset);
      offset += this->position_integrators.serialize(outbuffer + offset);
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
        int8_t real;
        uint8_t base;
      } u_tracking_mode;
      u_tracking_mode.real = this->tracking_mode;
      *(outbuffer + offset + 0) = (u_tracking_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_att_status;
      u_att_status.real = this->att_status;
      *(outbuffer + offset + 0) = (u_att_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->att_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position_desired.deserialize(inbuffer + offset);
      offset += this->velocity_desired.deserialize(inbuffer + offset);
      offset += this->position_error.deserialize(inbuffer + offset);
      offset += this->velocity_error.deserialize(inbuffer + offset);
      offset += this->acceleration_desired.deserialize(inbuffer + offset);
      offset += this->acceleration_feedback.deserialize(inbuffer + offset);
      offset += this->jerk_desired.deserialize(inbuffer + offset);
      offset += this->jerk_feedback.deserialize(inbuffer + offset);
      offset += this->position_integrators.deserialize(inbuffer + offset);
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
        int8_t real;
        uint8_t base;
      } u_tracking_mode;
      u_tracking_mode.base = 0;
      u_tracking_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_mode = u_tracking_mode.real;
      offset += sizeof(this->tracking_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_att_status;
      u_att_status.base = 0;
      u_att_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->att_status = u_att_status.real;
      offset += sizeof(this->att_status);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/CntrlData"; };
    virtual const char * getMD5() override { return "7c106fab3161174e341aaef1d7ec57f7"; };

  };

}
#endif
