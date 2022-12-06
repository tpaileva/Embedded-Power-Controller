#ifndef _ROS_SERVICE_ReplanCommDrop_h
#define _ROS_SERVICE_ReplanCommDrop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roadmap_msgs/RoadmapNode.h"

namespace mission_msgs
{

static const char REPLANCOMMDROP[] = "mission_msgs/ReplanCommDrop";

  class ReplanCommDropRequest : public ros::Msg
  {
    public:
      typedef roadmap_msgs::RoadmapNode _curret_node_type;
      _curret_node_type curret_node;

    ReplanCommDropRequest():
      curret_node()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->curret_node.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->curret_node.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return REPLANCOMMDROP; };
    virtual const char * getMD5() override { return "fcef33add6a86221e5c2e6e1639b0620"; };

  };

  class ReplanCommDropResponse : public ros::Msg
  {
    public:
      typedef bool _status_type;
      _status_type status;

    ReplanCommDropResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return REPLANCOMMDROP; };
    virtual const char * getMD5() override { return "3a1255d4d998bd4d6585c64639b5ee9a"; };

  };

  class ReplanCommDrop {
    public:
    typedef ReplanCommDropRequest Request;
    typedef ReplanCommDropResponse Response;
  };

}
#endif
