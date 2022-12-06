#ifndef _ROS_silvus_msgs_key_value_int32_int32_h
#define _ROS_silvus_msgs_key_value_int32_int32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace silvus_msgs
{

  class key_value_int32_int32 : public ros::Msg
  {
    public:
      typedef int32_t _key_type;
      _key_type key;
      typedef int32_t _value_type;
      _value_type value;

    key_value_int32_int32():
      key(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_key;
      u_key.real = this->key;
      *(outbuffer + offset + 0) = (u_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key);
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_key;
      u_key.base = 0;
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key = u_key.real;
      offset += sizeof(this->key);
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/key_value_int32_int32"; };
    virtual const char * getMD5() override { return "baa6e7538896e2d534a92a129a69a1b7"; };

  };

}
#endif
