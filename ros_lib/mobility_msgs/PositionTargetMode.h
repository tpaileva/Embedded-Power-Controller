#ifndef _ROS_mobility_msgs_PositionTargetMode_h
#define _ROS_mobility_msgs_PositionTargetMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace mobility_msgs
{

  class PositionTargetMode : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _frame_id_z_type;
      _frame_id_z_type frame_id_z;
      typedef uint16_t _type_mask_type;
      _type_mask_type type_mask;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_or_force_type;
      _acceleration_or_force_type acceleration_or_force;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef uint8_t _mode_type;
      _mode_type mode;
      enum { IGNORE_PX =  1   };
      enum { IGNORE_PY =  2 };
      enum { IGNORE_PZ =  4 };
      enum { IGNORE_VX =  8   };
      enum { IGNORE_VY =  16 };
      enum { IGNORE_VZ =  32 };
      enum { IGNORE_AFX =  64   };
      enum { IGNORE_AFY =  128 };
      enum { IGNORE_AFZ =  256 };
      enum { FORCE =  512   };
      enum { IGNORE_YAW =  1024 };
      enum { IGNORE_YAW_RATE =  2048 };
      enum { MODE_GROUND = 0 };
      enum { MODE_AIR = 1 };
      enum { MODE_GROUND_BOUNCING = 2 };
      enum { MODE_AIR_BOUNCING = 3 };
      enum { MODE_ROLLING = 0 };
      enum { MODE_FLYING = 1 };
      enum { MODE_ROLLING_BOUNCING = 2 };
      enum { MODE_FLYING_BOUNCING = 3 };

    PositionTargetMode():
      header(),
      frame_id_z(""),
      type_mask(0),
      position(),
      velocity(),
      acceleration_or_force(),
      yaw(0),
      yaw_rate(0),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_frame_id_z = strlen(this->frame_id_z);
      varToArr(outbuffer + offset, length_frame_id_z);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id_z, length_frame_id_z);
      offset += length_frame_id_z;
      *(outbuffer + offset + 0) = (this->type_mask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_mask >> (8 * 1)) & 0xFF;
      offset += sizeof(this->type_mask);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration_or_force.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate;
      u_yaw_rate.real = this->yaw_rate;
      *(outbuffer + offset + 0) = (u_yaw_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_rate);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_frame_id_z;
      arrToVar(length_frame_id_z, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id_z; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id_z-1]=0;
      this->frame_id_z = (char *)(inbuffer + offset-1);
      offset += length_frame_id_z;
      this->type_mask =  ((uint16_t) (*(inbuffer + offset)));
      this->type_mask |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->type_mask);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration_or_force.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate;
      u_yaw_rate.base = 0;
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_rate = u_yaw_rate.real;
      offset += sizeof(this->yaw_rate);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/PositionTargetMode"; };
    virtual const char * getMD5() override { return "8f249a07f89e161bee78664120dfe823"; };

  };

}
#endif
