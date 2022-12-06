#ifndef _ROS_mobility_msgs_Terapx64Terrain_h
#define _ROS_mobility_msgs_Terapx64Terrain_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

  class Terapx64Terrain : public ros::Msg
  {
    public:
      typedef float _min_type;
      _min_type min;
      typedef float _max_type;
      _max_type max;
      typedef float _average_type;
      _average_type average;
      typedef float _variance_type;
      _variance_type variance;
      typedef int8_t _state_type;
      _state_type state;
      typedef const char* _state_def_type;
      _state_def_type state_def;

    Terapx64Terrain():
      min(0),
      max(0),
      average(0),
      variance(0),
      state(0),
      state_def("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min;
      u_min.real = this->min;
      *(outbuffer + offset + 0) = (u_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min);
      union {
        float real;
        uint32_t base;
      } u_max;
      u_max.real = this->max;
      *(outbuffer + offset + 0) = (u_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max);
      union {
        float real;
        uint32_t base;
      } u_average;
      u_average.real = this->average;
      *(outbuffer + offset + 0) = (u_average.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average);
      union {
        float real;
        uint32_t base;
      } u_variance;
      u_variance.real = this->variance;
      *(outbuffer + offset + 0) = (u_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variance);
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      uint32_t length_state_def = strlen(this->state_def);
      varToArr(outbuffer + offset, length_state_def);
      offset += 4;
      memcpy(outbuffer + offset, this->state_def, length_state_def);
      offset += length_state_def;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min;
      u_min.base = 0;
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min = u_min.real;
      offset += sizeof(this->min);
      union {
        float real;
        uint32_t base;
      } u_max;
      u_max.base = 0;
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max = u_max.real;
      offset += sizeof(this->max);
      union {
        float real;
        uint32_t base;
      } u_average;
      u_average.base = 0;
      u_average.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average = u_average.real;
      offset += sizeof(this->average);
      union {
        float real;
        uint32_t base;
      } u_variance;
      u_variance.base = 0;
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variance = u_variance.real;
      offset += sizeof(this->variance);
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      uint32_t length_state_def;
      arrToVar(length_state_def, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_def; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_def-1]=0;
      this->state_def = (char *)(inbuffer + offset-1);
      offset += length_state_def;
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/Terapx64Terrain"; };
    virtual const char * getMD5() override { return "8cc80231260c423de758d7bc24a6e3ca"; };

  };

}
#endif
