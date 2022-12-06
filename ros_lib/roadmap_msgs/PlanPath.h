#ifndef _ROS_SERVICE_PlanPath_h
#define _ROS_SERVICE_PlanPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roadmap_msgs
{

static const char PLANPATH[] = "roadmap_msgs/PlanPath";

  class PlanPathRequest : public ros::Msg
  {
    public:
      typedef uint32_t _target_node_id_type;
      _target_node_id_type target_node_id;

    PlanPathRequest():
      target_node_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->target_node_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_node_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_node_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_node_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_node_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->target_node_id =  ((uint32_t) (*(inbuffer + offset)));
      this->target_node_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_node_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->target_node_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->target_node_id);
     return offset;
    }

    virtual const char * getType() override { return PLANPATH; };
    virtual const char * getMD5() override { return "6aaa923d168665141f2f2fa1e33b7122"; };

  };

  class PlanPathResponse : public ros::Msg
  {
    public:
      uint32_t node_ids_on_path_length;
      typedef uint32_t _node_ids_on_path_type;
      _node_ids_on_path_type st_node_ids_on_path;
      _node_ids_on_path_type * node_ids_on_path;

    PlanPathResponse():
      node_ids_on_path_length(0), st_node_ids_on_path(), node_ids_on_path(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->node_ids_on_path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->node_ids_on_path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->node_ids_on_path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->node_ids_on_path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_ids_on_path_length);
      for( uint32_t i = 0; i < node_ids_on_path_length; i++){
      *(outbuffer + offset + 0) = (this->node_ids_on_path[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->node_ids_on_path[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->node_ids_on_path[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->node_ids_on_path[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_ids_on_path[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t node_ids_on_path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      node_ids_on_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      node_ids_on_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      node_ids_on_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->node_ids_on_path_length);
      if(node_ids_on_path_lengthT > node_ids_on_path_length)
        this->node_ids_on_path = (uint32_t*)realloc(this->node_ids_on_path, node_ids_on_path_lengthT * sizeof(uint32_t));
      node_ids_on_path_length = node_ids_on_path_lengthT;
      for( uint32_t i = 0; i < node_ids_on_path_length; i++){
      this->st_node_ids_on_path =  ((uint32_t) (*(inbuffer + offset)));
      this->st_node_ids_on_path |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_node_ids_on_path |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_node_ids_on_path |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_node_ids_on_path);
        memcpy( &(this->node_ids_on_path[i]), &(this->st_node_ids_on_path), sizeof(uint32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return PLANPATH; };
    virtual const char * getMD5() override { return "0d9e87a3d3ef1661686b284e328c7b4c"; };

  };

  class PlanPath {
    public:
    typedef PlanPathRequest Request;
    typedef PlanPathResponse Response;
  };

}
#endif
