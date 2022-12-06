#ifndef _ROS_roadmap_msgs_RoadmapAnchor_h
#define _ROS_roadmap_msgs_RoadmapAnchor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace roadmap_msgs
{

  class RoadmapAnchor : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_rel_type;
      _pose_rel_type pose_rel;
      typedef uint64_t _pg_node_id_type;
      _pg_node_id_type pg_node_id;
      typedef float _prob_type;
      _prob_type prob;

    RoadmapAnchor():
      pose_rel(),
      pg_node_id(0),
      prob(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose_rel.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_pg_node_id;
      u_pg_node_id.real = this->pg_node_id;
      *(outbuffer + offset + 0) = (u_pg_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pg_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pg_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pg_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pg_node_id);
      union {
        float real;
        uint32_t base;
      } u_prob;
      u_prob.real = this->prob;
      *(outbuffer + offset + 0) = (u_prob.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_prob.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_prob.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_prob.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prob);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose_rel.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_pg_node_id;
      u_pg_node_id.base = 0;
      u_pg_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pg_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pg_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pg_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pg_node_id = u_pg_node_id.real;
      offset += sizeof(this->pg_node_id);
      union {
        float real;
        uint32_t base;
      } u_prob;
      u_prob.base = 0;
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->prob = u_prob.real;
      offset += sizeof(this->prob);
     return offset;
    }

    virtual const char * getType() override { return "roadmap_msgs/RoadmapAnchor"; };
    virtual const char * getMD5() override { return "c25665784b7d5ddb015d3dc119483995"; };

  };

}
#endif
