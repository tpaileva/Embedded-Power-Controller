#ifndef _ROS_silvus_msgs_SilvusDualEdgeList_h
#define _ROS_silvus_msgs_SilvusDualEdgeList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "silvus_msgs/SilvusDualEdge.h"

namespace silvus_msgs
{

  class SilvusDualEdgeList : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _streamscape_sequence_number_type;
      _streamscape_sequence_number_type streamscape_sequence_number;
      uint32_t edges_length;
      typedef silvus_msgs::SilvusDualEdge _edges_type;
      _edges_type st_edges;
      _edges_type * edges;

    SilvusDualEdgeList():
      header(),
      streamscape_sequence_number(0),
      edges_length(0), st_edges(), edges(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_streamscape_sequence_number;
      u_streamscape_sequence_number.real = this->streamscape_sequence_number;
      *(outbuffer + offset + 0) = (u_streamscape_sequence_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_streamscape_sequence_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_streamscape_sequence_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_streamscape_sequence_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->streamscape_sequence_number);
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
        int32_t real;
        uint32_t base;
      } u_streamscape_sequence_number;
      u_streamscape_sequence_number.base = 0;
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->streamscape_sequence_number = u_streamscape_sequence_number.real;
      offset += sizeof(this->streamscape_sequence_number);
      uint32_t edges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->edges_length);
      if(edges_lengthT > edges_length)
        this->edges = (silvus_msgs::SilvusDualEdge*)realloc(this->edges, edges_lengthT * sizeof(silvus_msgs::SilvusDualEdge));
      edges_length = edges_lengthT;
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->st_edges.deserialize(inbuffer + offset);
        memcpy( &(this->edges[i]), &(this->st_edges), sizeof(silvus_msgs::SilvusDualEdge));
      }
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusDualEdgeList"; };
    virtual const char * getMD5() override { return "6cfd940dd1029910947d298f3de9bcba"; };

  };

}
#endif
