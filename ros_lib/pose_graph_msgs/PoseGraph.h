#ifndef _ROS_pose_graph_msgs_PoseGraph_h
#define _ROS_pose_graph_msgs_PoseGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pose_graph_msgs/PoseGraphNode.h"
#include "pose_graph_msgs/PoseGraphEdge.h"

namespace pose_graph_msgs
{

  class PoseGraph : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _incremental_type;
      _incremental_type incremental;
      uint32_t nodes_length;
      typedef pose_graph_msgs::PoseGraphNode _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;
      uint32_t edges_length;
      typedef pose_graph_msgs::PoseGraphEdge _edges_type;
      _edges_type st_edges;
      _edges_type * edges;

    PoseGraph():
      header(),
      incremental(0),
      nodes_length(0), st_nodes(), nodes(nullptr),
      edges_length(0), st_edges(), edges(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_incremental;
      u_incremental.real = this->incremental;
      *(outbuffer + offset + 0) = (u_incremental.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->incremental);
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->edges_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->edges_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->edges_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->edges_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_length);
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->edges[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_incremental;
      u_incremental.base = 0;
      u_incremental.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->incremental = u_incremental.real;
      offset += sizeof(this->incremental);
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (pose_graph_msgs::PoseGraphNode*)realloc(this->nodes, nodes_lengthT * sizeof(pose_graph_msgs::PoseGraphNode));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(pose_graph_msgs::PoseGraphNode));
      }
      uint32_t edges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->edges_length);
      if(edges_lengthT > edges_length)
        this->edges = (pose_graph_msgs::PoseGraphEdge*)realloc(this->edges, edges_lengthT * sizeof(pose_graph_msgs::PoseGraphEdge));
      edges_length = edges_lengthT;
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->st_edges.deserialize(inbuffer + offset);
        memcpy( &(this->edges[i]), &(this->st_edges), sizeof(pose_graph_msgs::PoseGraphEdge));
      }
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/PoseGraph"; };
    virtual const char * getMD5() override { return "7bcbcc6a764387d0d037d9ff4f38d1b9"; };

  };

}
#endif
