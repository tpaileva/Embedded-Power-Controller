#ifndef _ROS_hw_msgs_PointSourceDetection_h
#define _ROS_hw_msgs_PointSourceDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class PointSourceDetection : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef float _strength_type;
      _strength_type strength;

    PointSourceDetection():
      header(),
      id(""),
      strength(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.real = this->strength;
      *(outbuffer + offset + 0) = (u_strength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strength);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.base = 0;
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strength = u_strength.real;
      offset += sizeof(this->strength);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/PointSourceDetection"; };
    virtual const char * getMD5() override { return "ad271b550badb5ecc8b2941fc21dd5f1"; };

  };

}
#endif
