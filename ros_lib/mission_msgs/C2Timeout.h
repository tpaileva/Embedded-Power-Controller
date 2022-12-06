#ifndef _ROS_SERVICE_C2Timeout_h
#define _ROS_SERVICE_C2Timeout_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mission_msgs
{

static const char C2TIMEOUT[] = "mission_msgs/C2Timeout";

  class C2TimeoutRequest : public ros::Msg
  {
    public:
      typedef int32_t _timeout_type;
      _timeout_type timeout;

    C2TimeoutRequest():
      timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
     return offset;
    }

    virtual const char * getType() override { return C2TIMEOUT; };
    virtual const char * getMD5() override { return "59c7c94880c7082d9353d4d0a3356213"; };

  };

  class C2TimeoutResponse : public ros::Msg
  {
    public:
      typedef bool _unused2_type;
      _unused2_type unused2;

    C2TimeoutResponse():
      unused2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_unused2;
      u_unused2.real = this->unused2;
      *(outbuffer + offset + 0) = (u_unused2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->unused2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_unused2;
      u_unused2.base = 0;
      u_unused2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->unused2 = u_unused2.real;
      offset += sizeof(this->unused2);
     return offset;
    }

    virtual const char * getType() override { return C2TIMEOUT; };
    virtual const char * getMD5() override { return "7f0173d802b36aa2d2e0720fe126a284"; };

  };

  class C2Timeout {
    public:
    typedef C2TimeoutRequest Request;
    typedef C2TimeoutResponse Response;
  };

}
#endif
