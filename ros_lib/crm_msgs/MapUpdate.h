#ifndef _ROS_crm_msgs_MapUpdate_h
#define _ROS_crm_msgs_MapUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "crm_msgs/VoxelUpdate.h"

namespace crm_msgs
{

  class MapUpdate : public ros::Msg
  {
    public:
      typedef const char* _source_node_type;
      _source_node_type source_node;
      uint32_t voxel_updates_length;
      typedef crm_msgs::VoxelUpdate _voxel_updates_type;
      _voxel_updates_type st_voxel_updates;
      _voxel_updates_type * voxel_updates;

    MapUpdate():
      source_node(""),
      voxel_updates_length(0), st_voxel_updates(), voxel_updates(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_source_node = strlen(this->source_node);
      varToArr(outbuffer + offset, length_source_node);
      offset += 4;
      memcpy(outbuffer + offset, this->source_node, length_source_node);
      offset += length_source_node;
      *(outbuffer + offset + 0) = (this->voxel_updates_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voxel_updates_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voxel_updates_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voxel_updates_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voxel_updates_length);
      for( uint32_t i = 0; i < voxel_updates_length; i++){
      offset += this->voxel_updates[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_source_node;
      arrToVar(length_source_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_node-1]=0;
      this->source_node = (char *)(inbuffer + offset-1);
      offset += length_source_node;
      uint32_t voxel_updates_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      voxel_updates_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      voxel_updates_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      voxel_updates_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->voxel_updates_length);
      if(voxel_updates_lengthT > voxel_updates_length)
        this->voxel_updates = (crm_msgs::VoxelUpdate*)realloc(this->voxel_updates, voxel_updates_lengthT * sizeof(crm_msgs::VoxelUpdate));
      voxel_updates_length = voxel_updates_lengthT;
      for( uint32_t i = 0; i < voxel_updates_length; i++){
      offset += this->st_voxel_updates.deserialize(inbuffer + offset);
        memcpy( &(this->voxel_updates[i]), &(this->st_voxel_updates), sizeof(crm_msgs::VoxelUpdate));
      }
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/MapUpdate"; };
    virtual const char * getMD5() override { return "874c708d916d13c6960a4a98b30270ac"; };

  };

}
#endif
