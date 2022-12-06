#ifndef _ROS_crm_msgs_MapDiagnosis_h
#define _ROS_crm_msgs_MapDiagnosis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace crm_msgs
{

  class MapDiagnosis : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _source_node_type;
      _source_node_type source_node;
      typedef ros::Duration _update_time_type;
      _update_time_type update_time;
      typedef uint32_t _update_measurements_type;
      _update_measurements_type update_measurements;
      uint32_t update_errors_length;
      typedef uint32_t _update_errors_type;
      _update_errors_type st_update_errors;
      _update_errors_type * update_errors;
      typedef uint32_t _update_voxels_type;
      _update_voxels_type update_voxels;

    MapDiagnosis():
      header(),
      source_node(""),
      update_time(),
      update_measurements(0),
      update_errors_length(0), st_update_errors(), update_errors(nullptr),
      update_voxels(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_source_node = strlen(this->source_node);
      varToArr(outbuffer + offset, length_source_node);
      offset += 4;
      memcpy(outbuffer + offset, this->source_node, length_source_node);
      offset += length_source_node;
      *(outbuffer + offset + 0) = (this->update_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_time.sec);
      *(outbuffer + offset + 0) = (this->update_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_time.nsec);
      *(outbuffer + offset + 0) = (this->update_measurements >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_measurements >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_measurements >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_measurements >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_measurements);
      *(outbuffer + offset + 0) = (this->update_errors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_errors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_errors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_errors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_errors_length);
      for( uint32_t i = 0; i < update_errors_length; i++){
      *(outbuffer + offset + 0) = (this->update_errors[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_errors[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_errors[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_errors[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_errors[i]);
      }
      *(outbuffer + offset + 0) = (this->update_voxels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_voxels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_voxels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_voxels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_voxels);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_source_node;
      arrToVar(length_source_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_node-1]=0;
      this->source_node = (char *)(inbuffer + offset-1);
      offset += length_source_node;
      this->update_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->update_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->update_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->update_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->update_time.sec);
      this->update_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->update_time.nsec);
      this->update_measurements =  ((uint32_t) (*(inbuffer + offset)));
      this->update_measurements |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->update_measurements |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->update_measurements |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->update_measurements);
      uint32_t update_errors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      update_errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      update_errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      update_errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->update_errors_length);
      if(update_errors_lengthT > update_errors_length)
        this->update_errors = (uint32_t*)realloc(this->update_errors, update_errors_lengthT * sizeof(uint32_t));
      update_errors_length = update_errors_lengthT;
      for( uint32_t i = 0; i < update_errors_length; i++){
      this->st_update_errors =  ((uint32_t) (*(inbuffer + offset)));
      this->st_update_errors |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_update_errors |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_update_errors |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_update_errors);
        memcpy( &(this->update_errors[i]), &(this->st_update_errors), sizeof(uint32_t));
      }
      this->update_voxels =  ((uint32_t) (*(inbuffer + offset)));
      this->update_voxels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->update_voxels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->update_voxels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->update_voxels);
     return offset;
    }

    virtual const char * getType() override { return "crm_msgs/MapDiagnosis"; };
    virtual const char * getMD5() override { return "a0ba4c6256134ed341b935186d84ccdb"; };

  };

}
#endif
