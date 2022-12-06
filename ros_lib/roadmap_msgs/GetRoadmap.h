#ifndef _ROS_SERVICE_GetRoadmap_h
#define _ROS_SERVICE_GetRoadmap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roadmap_msgs/Roadmap.h"

namespace roadmap_msgs
{

static const char GETROADMAP[] = "roadmap_msgs/GetRoadmap";

  class GetRoadmapRequest : public ros::Msg
  {
    public:

    GetRoadmapRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETROADMAP; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRoadmapResponse : public ros::Msg
  {
    public:
      typedef roadmap_msgs::Roadmap _roadmap_type;
      _roadmap_type roadmap;

    GetRoadmapResponse():
      roadmap()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->roadmap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->roadmap.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETROADMAP; };
    virtual const char * getMD5() override { return "2543f90d3563489940897a33fbef44b2"; };

  };

  class GetRoadmap {
    public:
    typedef GetRoadmapRequest Request;
    typedef GetRoadmapResponse Response;
  };

}
#endif
