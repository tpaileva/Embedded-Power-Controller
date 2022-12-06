#ifndef _ROS_pose_graph_msgs_LoopCandidate_h
#define _ROS_pose_graph_msgs_LoopCandidate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace pose_graph_msgs
{

  class LoopCandidate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _key_from_type;
      _key_from_type key_from;
      typedef uint64_t _key_to_type;
      _key_to_type key_to;
      typedef geometry_msgs::Pose _pose_from_type;
      _pose_from_type pose_from;
      typedef geometry_msgs::Pose _pose_to_type;
      _pose_to_type pose_to;
      typedef int32_t _type_type;
      _type_type type;
      typedef double _value_type;
      _value_type value;
      enum { PROXIMITY =  0 };
      enum { MANUAL =  1 };
      enum { JUNCTION =  2 };
      enum { VISUAL =  3 };

    LoopCandidate():
      header(),
      key_from(0),
      key_to(0),
      pose_from(),
      pose_to(),
      type(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_key_from;
      u_key_from.real = this->key_from;
      *(outbuffer + offset + 0) = (u_key_from.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key_from.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key_from.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key_from.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key_from);
      union {
        uint64_t real;
        uint32_t base;
      } u_key_to;
      u_key_to.real = this->key_to;
      *(outbuffer + offset + 0) = (u_key_to.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key_to.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key_to.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key_to.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key_to);
      offset += this->pose_from.serialize(outbuffer + offset);
      offset += this->pose_to.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        double real;
        uint64_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_key_from;
      u_key_from.base = 0;
      u_key_from.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key_from.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key_from.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key_from.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key_from = u_key_from.real;
      offset += sizeof(this->key_from);
      union {
        uint64_t real;
        uint32_t base;
      } u_key_to;
      u_key_to.base = 0;
      u_key_to.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key_to.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key_to.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key_to.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key_to = u_key_to.real;
      offset += sizeof(this->key_to);
      offset += this->pose_from.deserialize(inbuffer + offset);
      offset += this->pose_to.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        double real;
        uint64_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/LoopCandidate"; };
    virtual const char * getMD5() override { return "931aa62f1ad3fa7a808e71ad2a7b1ec9"; };

  };

}
#endif
