#ifndef _ROS_spot_msgs_LeaseOwner_h
#define _ROS_spot_msgs_LeaseOwner_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

  class LeaseOwner : public ros::Msg
  {
    public:
      typedef const char* _client_name_type;
      _client_name_type client_name;
      typedef const char* _user_name_type;
      _user_name_type user_name;

    LeaseOwner():
      client_name(""),
      user_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_client_name = strlen(this->client_name);
      varToArr(outbuffer + offset, length_client_name);
      offset += 4;
      memcpy(outbuffer + offset, this->client_name, length_client_name);
      offset += length_client_name;
      uint32_t length_user_name = strlen(this->user_name);
      varToArr(outbuffer + offset, length_user_name);
      offset += 4;
      memcpy(outbuffer + offset, this->user_name, length_user_name);
      offset += length_user_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_client_name;
      arrToVar(length_client_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_client_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_client_name-1]=0;
      this->client_name = (char *)(inbuffer + offset-1);
      offset += length_client_name;
      uint32_t length_user_name;
      arrToVar(length_user_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_name-1]=0;
      this->user_name = (char *)(inbuffer + offset-1);
      offset += length_user_name;
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/LeaseOwner"; };
    virtual const char * getMD5() override { return "5cea27b2d1a89312b1101c1d985fe078"; };

  };

}
#endif
