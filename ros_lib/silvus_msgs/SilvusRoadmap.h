#ifndef _ROS_silvus_msgs_SilvusRoadmap_h
#define _ROS_silvus_msgs_SilvusRoadmap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "silvus_msgs/SilvusStreamscape.h"
#include "roadmap_msgs/Roadmap.h"

namespace silvus_msgs
{

  class SilvusRoadmap : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef silvus_msgs::SilvusStreamscape _streamscape_type;
      _streamscape_type streamscape;
      typedef roadmap_msgs::Roadmap _roadmap_type;
      _roadmap_type roadmap;

    SilvusRoadmap():
      header(),
      streamscape(),
      roadmap()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->streamscape.serialize(outbuffer + offset);
      offset += this->roadmap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->streamscape.deserialize(inbuffer + offset);
      offset += this->roadmap.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusRoadmap"; };
    virtual const char * getMD5() override { return "0f81fa924283595d9c823521337858f3"; };

  };

}
#endif
