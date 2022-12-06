#ifndef _ROS_uwb_msgs_InterVehicleRange_h
#define _ROS_uwb_msgs_InterVehicleRange_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace uwb_msgs
{

  class InterVehicleRange : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _from_type;
      _from_type from;
      typedef const char* _to_type;
      _to_type to;
      typedef float _range_type;
      _range_type range;

    InterVehicleRange():
      header(),
      from(""),
      to(""),
      range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_from = strlen(this->from);
      varToArr(outbuffer + offset, length_from);
      offset += 4;
      memcpy(outbuffer + offset, this->from, length_from);
      offset += length_from;
      uint32_t length_to = strlen(this->to);
      varToArr(outbuffer + offset, length_to);
      offset += 4;
      memcpy(outbuffer + offset, this->to, length_to);
      offset += length_to;
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_from;
      arrToVar(length_from, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_from; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_from-1]=0;
      this->from = (char *)(inbuffer + offset-1);
      offset += length_from;
      uint32_t length_to;
      arrToVar(length_to, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_to; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_to-1]=0;
      this->to = (char *)(inbuffer + offset-1);
      offset += length_to;
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
     return offset;
    }

    virtual const char * getType() override { return "uwb_msgs/InterVehicleRange"; };
    virtual const char * getMD5() override { return "4edffd4781b110229d2864152a051b55"; };

  };

}
#endif
