#ifndef _ROS_crm_msgs_VoxelUpdate_h
#define _ROS_crm_msgs_VoxelUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace crm_msgs
{

  class VoxelUpdate : public ros::Msg
  {
    public:
      typedef uint32_t _index_type;
      _index_type index;
      uint32_t as_length;
      typedef float _as_type;
      _as_type st_as;
      _as_type * as;
      uint32_t bs_length;
      typedef float _bs_type;
      _bs_type st_bs;
      _bs_type * bs;

    VoxelUpdate():
      index(0),
      as_length(0), st_as(), as(nullptr),
      bs_length(0), st_bs(), bs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->as_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->as_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->as_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->as_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->as_length);
      for( uint32_t i = 0; i < as_length; i++){
      union {
        float real;
        uint32_t base;
      } u_asi;
      u_asi.real = this->as[i];
      *(outbuffer + offset + 0) = (u_asi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_asi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_asi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_asi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->as[i]);
      }
      *(outbuffer + offset + 0) = (this->bs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bs_length);
      for( uint32_t i = 0; i < bs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_bsi;
      u_bsi.real = this->bs[i];
      *(outbuffer + offset + 0) = (u_bsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->index =  ((uint32_t) (*(inbuffer + offset)));
      this->index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->index);
      uint32_t as_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      as_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      as_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      as_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->as_length);
      if(as_lengthT > as_length)
        this->as = (float*)realloc(this->as, as_lengthT * sizeof(float));
      as_length = as_lengthT;
      for( uint32_t i = 0; i < as_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_as;
      u_st_as.base = 0;
      u_st_as.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_as.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_as.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_as.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_as = u_st_as.real;
      offset += sizeof(this->st_as);
        memcpy( &(this->as[i]), &(this->st_as), sizeof(float));
      }
      uint32_t bs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bs_length);
      if(bs_lengthT > bs_length)
        this->bs = (float*)realloc(this->bs, bs_lengthT * sizeof(float));
      bs_length = bs_lengthT;
      for( uint32_t i = 0; i < bs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_bs;
      u_st_bs.base = 0;
      u_st_bs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_bs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_bs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_bs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_bs = u_st_bs.real;
      offset += sizeof(this->st_bs);
        memcpy( &(this->bs[i]), &(this->st_bs), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/VoxelUpdate"; };
    virtual const char * getMD5() override { return "ab842307c9966bd0f5a8affe4f75befe"; };

  };

}
#endif
