#ifndef _ROS_crm_msgs_Voxel_h
#define _ROS_crm_msgs_Voxel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace crm_msgs
{

  class Voxel : public ros::Msg
  {
    public:
      typedef uint32_t _index_type;
      _index_type index;
      typedef float _mean_type;
      _mean_type mean;
      typedef float _std_type;
      _std_type std;

    Voxel():
      index(0),
      mean(0),
      std(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.real = this->mean;
      *(outbuffer + offset + 0) = (u_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_std;
      u_std.real = this->std;
      *(outbuffer + offset + 0) = (u_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->std);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->index =  ((uint32_t) (*(inbuffer + offset)));
      this->index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.base = 0;
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mean = u_mean.real;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_std;
      u_std.base = 0;
      u_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->std = u_std.real;
      offset += sizeof(this->std);
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/Voxel"; };
    virtual const char * getMD5() override { return "03805c6e894e8aff680b3aea38e9d01e"; };

  };

}
#endif
