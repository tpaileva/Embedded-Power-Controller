#ifndef _ROS_crm_msgs_MapComplete_h
#define _ROS_crm_msgs_MapComplete_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace crm_msgs
{

  class MapComplete : public ros::Msg
  {
    public:
      typedef const char* _source_node_type;
      _source_node_type source_node;
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
      typedef float _noise_std_type;
      _noise_std_type noise_std;
      uint32_t means_length;
      typedef float _means_type;
      _means_type st_means;
      _means_type * means;
      uint32_t stds_length;
      typedef float _stds_type;
      _stds_type st_stds;
      _stds_type * stds;

    MapComplete():
      source_node(""),
      xmin(0),
      xmax(0),
      ymin(0),
      ymax(0),
      zmin(0),
      zmax(0),
      voxel_size(0),
      noise_std(0),
      means_length(0), st_means(), means(nullptr),
      stds_length(0), st_stds(), stds(nullptr)
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
      union {
        float real;
        uint32_t base;
      } u_noise_std;
      u_noise_std.real = this->noise_std;
      *(outbuffer + offset + 0) = (u_noise_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_noise_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_noise_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_noise_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->noise_std);
      *(outbuffer + offset + 0) = (this->means_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->means_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->means_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->means_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->means_length);
      for( uint32_t i = 0; i < means_length; i++){
      union {
        float real;
        uint32_t base;
      } u_meansi;
      u_meansi.real = this->means[i];
      *(outbuffer + offset + 0) = (u_meansi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_meansi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_meansi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_meansi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->means[i]);
      }
      *(outbuffer + offset + 0) = (this->stds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stds_length);
      for( uint32_t i = 0; i < stds_length; i++){
      union {
        float real;
        uint32_t base;
      } u_stdsi;
      u_stdsi.real = this->stds[i];
      *(outbuffer + offset + 0) = (u_stdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stds[i]);
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
      union {
        float real;
        uint32_t base;
      } u_noise_std;
      u_noise_std.base = 0;
      u_noise_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_noise_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_noise_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_noise_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->noise_std = u_noise_std.real;
      offset += sizeof(this->noise_std);
      uint32_t means_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      means_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      means_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      means_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->means_length);
      if(means_lengthT > means_length)
        this->means = (float*)realloc(this->means, means_lengthT * sizeof(float));
      means_length = means_lengthT;
      for( uint32_t i = 0; i < means_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_means;
      u_st_means.base = 0;
      u_st_means.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_means.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_means.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_means.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_means = u_st_means.real;
      offset += sizeof(this->st_means);
        memcpy( &(this->means[i]), &(this->st_means), sizeof(float));
      }
      uint32_t stds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stds_length);
      if(stds_lengthT > stds_length)
        this->stds = (float*)realloc(this->stds, stds_lengthT * sizeof(float));
      stds_length = stds_lengthT;
      for( uint32_t i = 0; i < stds_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_stds;
      u_st_stds.base = 0;
      u_st_stds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_stds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_stds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_stds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_stds = u_st_stds.real;
      offset += sizeof(this->st_stds);
        memcpy( &(this->stds[i]), &(this->st_stds), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/MapComplete"; };
    virtual const char * getMD5() override { return "bba4ad7ccb1c1aecf387bf83438e693c"; };

  };

}
#endif
