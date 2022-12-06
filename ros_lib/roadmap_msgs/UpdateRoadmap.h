#ifndef _ROS_SERVICE_UpdateRoadmap_h
#define _ROS_SERVICE_UpdateRoadmap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roadmap_msgs/Roadmap.h"

namespace roadmap_msgs
{

static const char UPDATEROADMAP[] = "roadmap_msgs/UpdateRoadmap";

  class UpdateRoadmapRequest : public ros::Msg
  {
    public:
      typedef roadmap_msgs::Roadmap _roadmap_type;
      _roadmap_type roadmap;

    UpdateRoadmapRequest():
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

    virtual const char * getType() override { return UPDATEROADMAP; };
    virtual const char * getMD5() override { return "2543f90d3563489940897a33fbef44b2"; };

  };

  class UpdateRoadmapResponse : public ros::Msg
  {
    public:
      typedef roadmap_msgs::Roadmap _roadmap_type;
      _roadmap_type roadmap;

    UpdateRoadmapResponse():
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

    virtual const char * getType() override { return UPDATEROADMAP; };
    virtual const char * getMD5() override { return "2543f90d3563489940897a33fbef44b2"; };

  };

  class UpdateRoadmap {
    public:
    typedef UpdateRoadmapRequest Request;
    typedef UpdateRoadmapResponse Response;
  };

}
#endif
