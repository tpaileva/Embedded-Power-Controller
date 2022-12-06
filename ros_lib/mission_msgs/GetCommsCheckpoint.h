#ifndef _ROS_SERVICE_GetCommsCheckpoint_h
#define _ROS_SERVICE_GetCommsCheckpoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roadmap_msgs/RoadmapNode.h"
#include "geometry_msgs/Pose.h"

namespace mission_msgs
{

static const char GETCOMMSCHECKPOINT[] = "mission_msgs/GetCommsCheckpoint";

  class GetCommsCheckpointRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef int32_t _level_id_type;
      _level_id_type level_id;

    GetCommsCheckpointRequest():
      pose(),
      level_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_level_id;
      u_level_id.real = this->level_id;
      *(outbuffer + offset + 0) = (u_level_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_level_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_level_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_level_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->level_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_level_id;
      u_level_id.base = 0;
      u_level_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_level_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_level_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_level_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->level_id = u_level_id.real;
      offset += sizeof(this->level_id);
     return offset;
    }

    virtual const char * getType() override { return GETCOMMSCHECKPOINT; };
    virtual const char * getMD5() override { return "c23adc57a50fb74c8088a9c070f618d8"; };

  };

  class GetCommsCheckpointResponse : public ros::Msg
  {
    public:
      typedef roadmap_msgs::RoadmapNode _node_type;
      _node_type node;
      typedef int32_t _num_remaining_checkpoints_type;
      _num_remaining_checkpoints_type num_remaining_checkpoints;

    GetCommsCheckpointResponse():
      node(),
      num_remaining_checkpoints(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->node.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_num_remaining_checkpoints;
      u_num_remaining_checkpoints.real = this->num_remaining_checkpoints;
      *(outbuffer + offset + 0) = (u_num_remaining_checkpoints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_remaining_checkpoints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_remaining_checkpoints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_remaining_checkpoints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_remaining_checkpoints);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->node.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_num_remaining_checkpoints;
      u_num_remaining_checkpoints.base = 0;
      u_num_remaining_checkpoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_remaining_checkpoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_remaining_checkpoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_remaining_checkpoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_remaining_checkpoints = u_num_remaining_checkpoints.real;
      offset += sizeof(this->num_remaining_checkpoints);
     return offset;
    }

    virtual const char * getType() override { return GETCOMMSCHECKPOINT; };
    virtual const char * getMD5() override { return "bcbbc7cfd0aa663b46bcefbbdbef700a"; };

  };

  class GetCommsCheckpoint {
    public:
    typedef GetCommsCheckpointRequest Request;
    typedef GetCommsCheckpointResponse Response;
  };

}
#endif
