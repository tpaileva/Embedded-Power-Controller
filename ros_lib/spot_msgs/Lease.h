#ifndef _ROS_spot_msgs_Lease_h
#define _ROS_spot_msgs_Lease_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

  class Lease : public ros::Msg
  {
    public:
      typedef const char* _resource_type;
      _resource_type resource;
      typedef const char* _epoch_type;
      _epoch_type epoch;
      uint32_t sequence_length;
      typedef uint32_t _sequence_type;
      _sequence_type st_sequence;
      _sequence_type * sequence;

    Lease():
      resource(""),
      epoch(""),
      sequence_length(0), st_sequence(), sequence(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_resource = strlen(this->resource);
      varToArr(outbuffer + offset, length_resource);
      offset += 4;
      memcpy(outbuffer + offset, this->resource, length_resource);
      offset += length_resource;
      uint32_t length_epoch = strlen(this->epoch);
      varToArr(outbuffer + offset, length_epoch);
      offset += 4;
      memcpy(outbuffer + offset, this->epoch, length_epoch);
      offset += length_epoch;
      *(outbuffer + offset + 0) = (this->sequence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence_length);
      for( uint32_t i = 0; i < sequence_length; i++){
      *(outbuffer + offset + 0) = (this->sequence[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequence[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequence[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_resource;
      arrToVar(length_resource, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_resource; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_resource-1]=0;
      this->resource = (char *)(inbuffer + offset-1);
      offset += length_resource;
      uint32_t length_epoch;
      arrToVar(length_epoch, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_epoch; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_epoch-1]=0;
      this->epoch = (char *)(inbuffer + offset-1);
      offset += length_epoch;
      uint32_t sequence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sequence_length);
      if(sequence_lengthT > sequence_length)
        this->sequence = (uint32_t*)realloc(this->sequence, sequence_lengthT * sizeof(uint32_t));
      sequence_length = sequence_lengthT;
      for( uint32_t i = 0; i < sequence_length; i++){
      this->st_sequence =  ((uint32_t) (*(inbuffer + offset)));
      this->st_sequence |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_sequence |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_sequence |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_sequence);
        memcpy( &(this->sequence[i]), &(this->st_sequence), sizeof(uint32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/Lease"; };
    virtual const char * getMD5() override { return "268ed4f702e0ce57ac084653ad1ace93"; };

  };

}
#endif
