#ifndef _ROS_SERVICE_SetFrontierNode_h
#define _ROS_SERVICE_SetFrontierNode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mission_msgs
{

static const char SETFRONTIERNODE[] = "mission_msgs/SetFrontierNode";

  class SetFrontierNodeRequest : public ros::Msg
  {
    public:
      typedef uint32_t _frontier_idx_type;
      _frontier_idx_type frontier_idx;

    SetFrontierNodeRequest():
      frontier_idx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->frontier_idx >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frontier_idx >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frontier_idx >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frontier_idx >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frontier_idx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->frontier_idx =  ((uint32_t) (*(inbuffer + offset)));
      this->frontier_idx |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->frontier_idx |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->frontier_idx |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->frontier_idx);
     return offset;
    }

    virtual const char * getType() override { return SETFRONTIERNODE; };
    virtual const char * getMD5() override { return "21c616216ce653775033eb99a16f2666"; };

  };

  class SetFrontierNodeResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SetFrontierNodeResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return SETFRONTIERNODE; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetFrontierNode {
    public:
    typedef SetFrontierNodeRequest Request;
    typedef SetFrontierNodeResponse Response;
  };

}
#endif
