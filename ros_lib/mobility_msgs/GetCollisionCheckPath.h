#ifndef _ROS_SERVICE_GetCollisionCheckPath_h
#define _ROS_SERVICE_GetCollisionCheckPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "nav_msgs/Path.h"

namespace mobility_msgs
{

static const char GETCOLLISIONCHECKPATH[] = "mobility_msgs/GetCollisionCheckPath";

  class GetCollisionCheckPathRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _from_type;
      _from_type from;
      typedef geometry_msgs::Point _to_type;
      _to_type to;

    GetCollisionCheckPathRequest():
      from(),
      to()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->from.serialize(outbuffer + offset);
      offset += this->to.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->from.deserialize(inbuffer + offset);
      offset += this->to.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETCOLLISIONCHECKPATH; };
    virtual const char * getMD5() override { return "862144dff3b6849a7e54510297b2ffc1"; };

  };

  class GetCollisionCheckPathResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;

    GetCollisionCheckPathResponse():
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

    virtual const char * getType() override { return GETCOLLISIONCHECKPATH; };
    virtual const char * getMD5() override { return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

  class GetCollisionCheckPath {
    public:
    typedef GetCollisionCheckPathRequest Request;
    typedef GetCollisionCheckPathResponse Response;
  };

}
#endif
