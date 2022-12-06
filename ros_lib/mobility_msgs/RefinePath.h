#ifndef _ROS_SERVICE_RefinePath_h
#define _ROS_SERVICE_RefinePath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"

namespace mobility_msgs
{

static const char REFINEPATH[] = "mobility_msgs/RefinePath";

  class RefinePathRequest : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;
      typedef bool _allow_extrapolation_type;
      _allow_extrapolation_type allow_extrapolation;

    RefinePathRequest():
      path(),
      allow_extrapolation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_allow_extrapolation;
      u_allow_extrapolation.real = this->allow_extrapolation;
      *(outbuffer + offset + 0) = (u_allow_extrapolation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_extrapolation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_allow_extrapolation;
      u_allow_extrapolation.base = 0;
      u_allow_extrapolation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_extrapolation = u_allow_extrapolation.real;
      offset += sizeof(this->allow_extrapolation);
     return offset;
    }

    virtual const char * getType() override { return REFINEPATH; };
    virtual const char * getMD5() override { return "03cdcd7c7701c8f7a41fed434a5a2d82"; };

  };

  class RefinePathResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;

    RefinePathResponse():
      path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return REFINEPATH; };
    virtual const char * getMD5() override { return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

  class RefinePath {
    public:
    typedef RefinePathRequest Request;
    typedef RefinePathResponse Response;
  };

}
#endif
