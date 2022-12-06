#ifndef _ROS_silvus_msgs_SilvusStreamscape_h
#define _ROS_silvus_msgs_SilvusStreamscape_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "silvus_msgs/SilvusStreamscapeNode.h"

namespace silvus_msgs
{

  class SilvusStreamscape : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _robot_namespace_type;
      _robot_namespace_type robot_namespace;
      typedef const char* _target_radio_type;
      _target_radio_type target_radio;
      typedef int32_t _streamscape_sequence_number_type;
      _streamscape_sequence_number_type streamscape_sequence_number;
      uint32_t nodes_length;
      typedef silvus_msgs::SilvusStreamscapeNode _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    SilvusStreamscape():
      header(),
      robot_namespace(""),
      target_radio(""),
      streamscape_sequence_number(0),
      nodes_length(0), st_nodes(), nodes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_robot_namespace = strlen(this->robot_namespace);
      varToArr(outbuffer + offset, length_robot_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_namespace, length_robot_namespace);
      offset += length_robot_namespace;
      uint32_t length_target_radio = strlen(this->target_radio);
      varToArr(outbuffer + offset, length_target_radio);
      offset += 4;
      memcpy(outbuffer + offset, this->target_radio, length_target_radio);
      offset += length_target_radio;
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
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_robot_namespace;
      arrToVar(length_robot_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_namespace-1]=0;
      this->robot_namespace = (char *)(inbuffer + offset-1);
      offset += length_robot_namespace;
      uint32_t length_target_radio;
      arrToVar(length_target_radio, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_radio; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_radio-1]=0;
      this->target_radio = (char *)(inbuffer + offset-1);
      offset += length_target_radio;
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
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (silvus_msgs::SilvusStreamscapeNode*)realloc(this->nodes, nodes_lengthT * sizeof(silvus_msgs::SilvusStreamscapeNode));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(silvus_msgs::SilvusStreamscapeNode));
      }
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusStreamscape"; };
    virtual const char * getMD5() override { return "c8cd62cccfb741652b0f51287a3b7904"; };

  };

}
#endif
