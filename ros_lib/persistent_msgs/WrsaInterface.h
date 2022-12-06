#ifndef _ROS_persistent_msgs_WrsaInterface_h
#define _ROS_persistent_msgs_WrsaInterface_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace persistent_msgs
{

  class WrsaInterface : public ros::Msg
  {
    public:
      typedef uint8_t _interface_num_type;
      _interface_num_type interface_num;
      typedef uint8_t _interface_type_type;
      _interface_type_type interface_type;
      typedef const char* _interface_name_type;
      _interface_name_type interface_name;
      typedef const char* _interface_mac1_type;
      _interface_mac1_type interface_mac1;
      typedef const char* _interface_mac2_type;
      _interface_mac2_type interface_mac2;

    WrsaInterface():
      interface_num(0),
      interface_type(0),
      interface_name(""),
      interface_mac1(""),
      interface_mac2("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->interface_num >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interface_num);
      *(outbuffer + offset + 0) = (this->interface_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interface_type);
      uint32_t length_interface_name = strlen(this->interface_name);
      varToArr(outbuffer + offset, length_interface_name);
      offset += 4;
      memcpy(outbuffer + offset, this->interface_name, length_interface_name);
      offset += length_interface_name;
      uint32_t length_interface_mac1 = strlen(this->interface_mac1);
      varToArr(outbuffer + offset, length_interface_mac1);
      offset += 4;
      memcpy(outbuffer + offset, this->interface_mac1, length_interface_mac1);
      offset += length_interface_mac1;
      uint32_t length_interface_mac2 = strlen(this->interface_mac2);
      varToArr(outbuffer + offset, length_interface_mac2);
      offset += 4;
      memcpy(outbuffer + offset, this->interface_mac2, length_interface_mac2);
      offset += length_interface_mac2;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->interface_num =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interface_num);
      this->interface_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interface_type);
      uint32_t length_interface_name;
      arrToVar(length_interface_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interface_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interface_name-1]=0;
      this->interface_name = (char *)(inbuffer + offset-1);
      offset += length_interface_name;
      uint32_t length_interface_mac1;
      arrToVar(length_interface_mac1, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interface_mac1; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interface_mac1-1]=0;
      this->interface_mac1 = (char *)(inbuffer + offset-1);
      offset += length_interface_mac1;
      uint32_t length_interface_mac2;
      arrToVar(length_interface_mac2, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interface_mac2; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interface_mac2-1]=0;
      this->interface_mac2 = (char *)(inbuffer + offset-1);
      offset += length_interface_mac2;
     return offset;
    }

    virtual const char * getType() override { return "persistent_msgs/WrsaInterface"; };
    virtual const char * getMD5() override { return "70a8cf439f8bc623d459bc6e6915f692"; };

  };

}
#endif
