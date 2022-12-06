#ifndef _ROS_mobility_msgs_Terapx64Mode_h
#define _ROS_mobility_msgs_Terapx64Mode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

  class Terapx64Mode : public ros::Msg
  {
    public:
      typedef float _mode_1_type;
      _mode_1_type mode_1;
      typedef float _mode_2_type;
      _mode_2_type mode_2;
      typedef float _mode_3_type;
      _mode_3_type mode_3;
      typedef float _mode_4_type;
      _mode_4_type mode_4;

    Terapx64Mode():
      mode_1(0),
      mode_2(0),
      mode_3(0),
      mode_4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mode_1;
      u_mode_1.real = this->mode_1;
      *(outbuffer + offset + 0) = (u_mode_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode_1);
      union {
        float real;
        uint32_t base;
      } u_mode_2;
      u_mode_2.real = this->mode_2;
      *(outbuffer + offset + 0) = (u_mode_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode_2);
      union {
        float real;
        uint32_t base;
      } u_mode_3;
      u_mode_3.real = this->mode_3;
      *(outbuffer + offset + 0) = (u_mode_3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode_3);
      union {
        float real;
        uint32_t base;
      } u_mode_4;
      u_mode_4.real = this->mode_4;
      *(outbuffer + offset + 0) = (u_mode_4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode_4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mode_1;
      u_mode_1.base = 0;
      u_mode_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode_1 = u_mode_1.real;
      offset += sizeof(this->mode_1);
      union {
        float real;
        uint32_t base;
      } u_mode_2;
      u_mode_2.base = 0;
      u_mode_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode_2 = u_mode_2.real;
      offset += sizeof(this->mode_2);
      union {
        float real;
        uint32_t base;
      } u_mode_3;
      u_mode_3.base = 0;
      u_mode_3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode_3 = u_mode_3.real;
      offset += sizeof(this->mode_3);
      union {
        float real;
        uint32_t base;
      } u_mode_4;
      u_mode_4.base = 0;
      u_mode_4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode_4 = u_mode_4.real;
      offset += sizeof(this->mode_4);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/Terapx64Mode"; };
    virtual const char * getMD5() override { return "aab13d50a0c8ccce84e5d66269b5ed06"; };

  };

}
#endif
