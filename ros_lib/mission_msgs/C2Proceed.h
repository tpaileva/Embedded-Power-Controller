#ifndef _ROS_SERVICE_C2Proceed_h
#define _ROS_SERVICE_C2Proceed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mission_msgs
{

static const char C2PROCEED[] = "mission_msgs/C2Proceed";

  class C2ProceedRequest : public ros::Msg
  {
    public:
      typedef bool _unused1_type;
      _unused1_type unused1;

    C2ProceedRequest():
      unused1(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_unused1;
      u_unused1.real = this->unused1;
      *(outbuffer + offset + 0) = (u_unused1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->unused1);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_unused1;
      u_unused1.base = 0;
      u_unused1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->unused1 = u_unused1.real;
      offset += sizeof(this->unused1);
     return offset;
    }

    virtual const char * getType() override { return C2PROCEED; };
    virtual const char * getMD5() override { return "36a70214208bc1f2af83b3b7f637b67e"; };

  };

  class C2ProceedResponse : public ros::Msg
  {
    public:
      typedef bool _unused2_type;
      _unused2_type unused2;

    C2ProceedResponse():
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

    virtual const char * getType() override { return C2PROCEED; };
    virtual const char * getMD5() override { return "7f0173d802b36aa2d2e0720fe126a284"; };

  };

  class C2Proceed {
    public:
    typedef C2ProceedRequest Request;
    typedef C2ProceedResponse Response;
  };

}
#endif
