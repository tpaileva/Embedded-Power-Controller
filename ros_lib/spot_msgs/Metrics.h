#ifndef _ROS_spot_msgs_Metrics_h
#define _ROS_spot_msgs_Metrics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace spot_msgs
{

  class Metrics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_type;
      _distance_type distance;
      typedef int32_t _gait_cycles_type;
      _gait_cycles_type gait_cycles;
      typedef ros::Duration _time_moving_type;
      _time_moving_type time_moving;
      typedef ros::Duration _electric_power_type;
      _electric_power_type electric_power;

    Metrics():
      header(),
      distance(0),
      gait_cycles(0),
      time_moving(),
      electric_power()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        int32_t real;
        uint32_t base;
      } u_gait_cycles;
      u_gait_cycles.real = this->gait_cycles;
      *(outbuffer + offset + 0) = (u_gait_cycles.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gait_cycles.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gait_cycles.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gait_cycles.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gait_cycles);
      *(outbuffer + offset + 0) = (this->time_moving.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_moving.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_moving.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_moving.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_moving.sec);
      *(outbuffer + offset + 0) = (this->time_moving.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_moving.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_moving.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_moving.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_moving.nsec);
      *(outbuffer + offset + 0) = (this->electric_power.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->electric_power.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->electric_power.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->electric_power.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->electric_power.sec);
      *(outbuffer + offset + 0) = (this->electric_power.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->electric_power.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->electric_power.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->electric_power.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->electric_power.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        int32_t real;
        uint32_t base;
      } u_gait_cycles;
      u_gait_cycles.base = 0;
      u_gait_cycles.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gait_cycles.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gait_cycles.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gait_cycles.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gait_cycles = u_gait_cycles.real;
      offset += sizeof(this->gait_cycles);
      this->time_moving.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_moving.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_moving.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_moving.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_moving.sec);
      this->time_moving.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_moving.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_moving.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_moving.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_moving.nsec);
      this->electric_power.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->electric_power.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->electric_power.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->electric_power.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->electric_power.sec);
      this->electric_power.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->electric_power.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->electric_power.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->electric_power.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->electric_power.nsec);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/Metrics"; };
    virtual const char * getMD5() override { return "493e599307ab2a6dbe49405e7b5a9b6d"; };

  };

}
#endif
