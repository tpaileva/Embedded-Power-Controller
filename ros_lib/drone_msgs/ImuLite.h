#ifndef _ROS_drone_msgs_ImuLite_h
#define _ROS_drone_msgs_ImuLite_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace drone_msgs
{

  class ImuLite : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _imu_time_stamp_type;
      _imu_time_stamp_type imu_time_stamp;
      typedef geometry_msgs::Vector3 _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      typedef geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;

    ImuLite():
      header(),
      imu_time_stamp(0),
      linear_acceleration(),
      angular_velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_imu_time_stamp;
      u_imu_time_stamp.real = this->imu_time_stamp;
      *(outbuffer + offset + 0) = (u_imu_time_stamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_time_stamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_time_stamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_time_stamp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_imu_time_stamp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_imu_time_stamp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_imu_time_stamp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_imu_time_stamp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->imu_time_stamp);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_imu_time_stamp;
      u_imu_time_stamp.base = 0;
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_imu_time_stamp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->imu_time_stamp = u_imu_time_stamp.real;
      offset += sizeof(this->imu_time_stamp);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/ImuLite"; };
    virtual const char * getMD5() override { return "c658e78489d9836f65be3b8ad9e6f10f"; };

  };

}
#endif
