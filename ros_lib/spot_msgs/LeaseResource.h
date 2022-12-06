#ifndef _ROS_spot_msgs_LeaseResource_h
#define _ROS_spot_msgs_LeaseResource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/Lease.h"
#include "spot_msgs/LeaseOwner.h"

namespace spot_msgs
{

  class LeaseResource : public ros::Msg
  {
    public:
      typedef const char* _resource_type;
      _resource_type resource;
      typedef spot_msgs::Lease _lease_type;
      _lease_type lease;
      typedef spot_msgs::LeaseOwner _lease_owner_type;
      _lease_owner_type lease_owner;

    LeaseResource():
      resource(""),
      lease(),
      lease_owner()
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
      offset += this->lease.serialize(outbuffer + offset);
      offset += this->lease_owner.serialize(outbuffer + offset);
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
      offset += this->lease.deserialize(inbuffer + offset);
      offset += this->lease_owner.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/LeaseResource"; };
    virtual const char * getMD5() override { return "e2b2b151bf21111e26403b0a4feba023"; };

  };

}
#endif
