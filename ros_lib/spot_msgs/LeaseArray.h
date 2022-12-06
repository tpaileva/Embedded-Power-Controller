#ifndef _ROS_spot_msgs_LeaseArray_h
#define _ROS_spot_msgs_LeaseArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/LeaseResource.h"

namespace spot_msgs
{

  class LeaseArray : public ros::Msg
  {
    public:
      uint32_t resources_length;
      typedef spot_msgs::LeaseResource _resources_type;
      _resources_type st_resources;
      _resources_type * resources;

    LeaseArray():
      resources_length(0), st_resources(), resources(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->resources_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resources_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->resources_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->resources_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resources_length);
      for( uint32_t i = 0; i < resources_length; i++){
      offset += this->resources[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t resources_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->resources_length);
      if(resources_lengthT > resources_length)
        this->resources = (spot_msgs::LeaseResource*)realloc(this->resources, resources_lengthT * sizeof(spot_msgs::LeaseResource));
      resources_length = resources_lengthT;
      for( uint32_t i = 0; i < resources_length; i++){
      offset += this->st_resources.deserialize(inbuffer + offset);
        memcpy( &(this->resources[i]), &(this->st_resources), sizeof(spot_msgs::LeaseResource));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/LeaseArray"; };
    virtual const char * getMD5() override { return "1e9c3bf77fbef8b5aa6a3bea6c733c8a"; };

  };

}
#endif
