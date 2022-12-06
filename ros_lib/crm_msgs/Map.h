#ifndef _ROS_crm_msgs_Map_h
#define _ROS_crm_msgs_Map_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "crm_msgs/Voxel.h"

namespace crm_msgs
{

  class Map : public ros::Msg
  {
    public:
      typedef const char* _source_node_type;
      _source_node_type source_node;
      typedef int32_t _sensor_id_type;
      _sensor_id_type sensor_id;
      typedef float _xmin_type;
      _xmin_type xmin;
      typedef float _xmax_type;
      _xmax_type xmax;
      typedef float _ymin_type;
      _ymin_type ymin;
      typedef float _ymax_type;
      _ymax_type ymax;
      typedef float _zmin_type;
      _zmin_type zmin;
      typedef float _zmax_type;
      _zmax_type zmax;
      typedef float _voxel_size_type;
      _voxel_size_type voxel_size;
      uint32_t voxels_length;
      typedef crm_msgs::Voxel _voxels_type;
      _voxels_type st_voxels;
      _voxels_type * voxels;

    Map():
      source_node(""),
      sensor_id(0),
      xmin(0),
      xmax(0),
      ymin(0),
      ymax(0),
      zmin(0),
      zmax(0),
      voxel_size(0),
      voxels_length(0), st_voxels(), voxels(nullptr)
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
      union {
        int32_t real;
        uint32_t base;
      } u_sensor_id;
      u_sensor_id.real = this->sensor_id;
      *(outbuffer + offset + 0) = (u_sensor_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensor_id);
      union {
        float real;
        uint32_t base;
      } u_xmin;
      u_xmin.real = this->xmin;
      *(outbuffer + offset + 0) = (u_xmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xmin);
      union {
        float real;
        uint32_t base;
      } u_xmax;
      u_xmax.real = this->xmax;
      *(outbuffer + offset + 0) = (u_xmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xmax);
      union {
        float real;
        uint32_t base;
      } u_ymin;
      u_ymin.real = this->ymin;
      *(outbuffer + offset + 0) = (u_ymin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ymin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ymin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ymin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ymin);
      union {
        float real;
        uint32_t base;
      } u_ymax;
      u_ymax.real = this->ymax;
      *(outbuffer + offset + 0) = (u_ymax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ymax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ymax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ymax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ymax);
      union {
        float real;
        uint32_t base;
      } u_zmin;
      u_zmin.real = this->zmin;
      *(outbuffer + offset + 0) = (u_zmin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zmin);
      union {
        float real;
        uint32_t base;
      } u_zmax;
      u_zmax.real = this->zmax;
      *(outbuffer + offset + 0) = (u_zmax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zmax);
      union {
        float real;
        uint32_t base;
      } u_voxel_size;
      u_voxel_size.real = this->voxel_size;
      *(outbuffer + offset + 0) = (u_voxel_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voxel_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voxel_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voxel_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voxel_size);
      *(outbuffer + offset + 0) = (this->voxels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voxels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voxels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voxels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voxels_length);
      for( uint32_t i = 0; i < voxels_length; i++){
      offset += this->voxels[i].serialize(outbuffer + offset);
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
      union {
        int32_t real;
        uint32_t base;
      } u_sensor_id;
      u_sensor_id.base = 0;
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sensor_id = u_sensor_id.real;
      offset += sizeof(this->sensor_id);
      union {
        float real;
        uint32_t base;
      } u_xmin;
      u_xmin.base = 0;
      u_xmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xmin = u_xmin.real;
      offset += sizeof(this->xmin);
      union {
        float real;
        uint32_t base;
      } u_xmax;
      u_xmax.base = 0;
      u_xmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xmax = u_xmax.real;
      offset += sizeof(this->xmax);
      union {
        float real;
        uint32_t base;
      } u_ymin;
      u_ymin.base = 0;
      u_ymin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ymin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ymin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ymin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ymin = u_ymin.real;
      offset += sizeof(this->ymin);
      union {
        float real;
        uint32_t base;
      } u_ymax;
      u_ymax.base = 0;
      u_ymax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ymax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ymax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ymax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ymax = u_ymax.real;
      offset += sizeof(this->ymax);
      union {
        float real;
        uint32_t base;
      } u_zmin;
      u_zmin.base = 0;
      u_zmin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zmin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zmin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zmin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zmin = u_zmin.real;
      offset += sizeof(this->zmin);
      union {
        float real;
        uint32_t base;
      } u_zmax;
      u_zmax.base = 0;
      u_zmax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zmax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zmax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zmax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zmax = u_zmax.real;
      offset += sizeof(this->zmax);
      union {
        float real;
        uint32_t base;
      } u_voxel_size;
      u_voxel_size.base = 0;
      u_voxel_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voxel_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voxel_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voxel_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voxel_size = u_voxel_size.real;
      offset += sizeof(this->voxel_size);
      uint32_t voxels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      voxels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      voxels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      voxels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->voxels_length);
      if(voxels_lengthT > voxels_length)
        this->voxels = (crm_msgs::Voxel*)realloc(this->voxels, voxels_lengthT * sizeof(crm_msgs::Voxel));
      voxels_length = voxels_lengthT;
      for( uint32_t i = 0; i < voxels_length; i++){
      offset += this->st_voxels.deserialize(inbuffer + offset);
        memcpy( &(this->voxels[i]), &(this->st_voxels), sizeof(crm_msgs::Voxel));
      }
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/Map"; };
    virtual const char * getMD5() override { return "294db9faa62a5939246e2ef2613e700b"; };

  };

}
#endif
