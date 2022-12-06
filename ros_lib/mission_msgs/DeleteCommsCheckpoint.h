#ifndef _ROS_SERVICE_DeleteCommsCheckpoint_h
#define _ROS_SERVICE_DeleteCommsCheckpoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roadmap_msgs/RoadmapNode.h"

namespace mission_msgs
{

static const char DELETECOMMSCHECKPOINT[] = "mission_msgs/DeleteCommsCheckpoint";

  class DeleteCommsCheckpointRequest : public ros::Msg
  {
    public:
      typedef roadmap_msgs::RoadmapNode _node_type;
      _node_type node;

    DeleteCommsCheckpointRequest():
      node()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->node.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->node.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return DELETECOMMSCHECKPOINT; };
    virtual const char * getMD5() override { return "94c052cf5fb0d339b20ac6732a63f47c"; };

  };

  class DeleteCommsCheckpointResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    DeleteCommsCheckpointResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return DELETECOMMSCHECKPOINT; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class DeleteCommsCheckpoint {
    public:
    typedef DeleteCommsCheckpointRequest Request;
    typedef DeleteCommsCheckpointResponse Response;
  };

}
#endif
