#ifndef _ROS_navigator_NavigatorStatus_h
#define _ROS_navigator_NavigatorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace navigator
{

  class NavigatorStatus : public ros::Msg
  {
    public:
      typedef const char* _mode_type;
      _mode_type mode;
      typedef double _fumarole_x_type;
      _fumarole_x_type fumarole_x;
      typedef double _fumarole_y_type;
      _fumarole_y_type fumarole_y;

    NavigatorStatus():
      mode(""),
      fumarole_x(0),
      fumarole_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_mode = strlen(this->mode);
      varToArr(outbuffer + offset, length_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      union {
        double real;
        uint64_t base;
      } u_fumarole_x;
      u_fumarole_x.real = this->fumarole_x;
      *(outbuffer + offset + 0) = (u_fumarole_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fumarole_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fumarole_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fumarole_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fumarole_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fumarole_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fumarole_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fumarole_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fumarole_x);
      union {
        double real;
        uint64_t base;
      } u_fumarole_y;
      u_fumarole_y.real = this->fumarole_y;
      *(outbuffer + offset + 0) = (u_fumarole_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fumarole_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fumarole_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fumarole_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fumarole_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fumarole_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fumarole_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fumarole_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fumarole_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_mode;
      arrToVar(length_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
      union {
        double real;
        uint64_t base;
      } u_fumarole_x;
      u_fumarole_x.base = 0;
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fumarole_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fumarole_x = u_fumarole_x.real;
      offset += sizeof(this->fumarole_x);
      union {
        double real;
        uint64_t base;
      } u_fumarole_y;
      u_fumarole_y.base = 0;
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fumarole_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fumarole_y = u_fumarole_y.real;
      offset += sizeof(this->fumarole_y);
     return offset;
    }

    virtual const char * getType() override { return "navigator/NavigatorStatus"; };
    virtual const char * getMD5() override { return "3aec6ab63048486a42c1533a0a6b9636"; };

  };

}
#endif
