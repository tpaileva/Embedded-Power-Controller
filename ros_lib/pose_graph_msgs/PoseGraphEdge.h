#ifndef _ROS_pose_graph_msgs_PoseGraphEdge_h
#define _ROS_pose_graph_msgs_PoseGraphEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace pose_graph_msgs
{

  class PoseGraphEdge : public ros::Msg
  {
    public:
      typedef uint64_t _key_from_type;
      _key_from_type key_from;
      typedef uint64_t _key_to_type;
      _key_to_type key_to;
      typedef int32_t _type_type;
      _type_type type;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      double covariance[36];
      typedef double _range_type;
      _range_type range;
      typedef double _range_error_type;
      _range_error_type range_error;
      enum { ODOM =  0 };
      enum { PRIOR =  1 };
      enum { IMU =  2 };
      enum { LOOPCLOSE =  3 };
      enum { ARTIFACT =  4 };
      enum { UWB_RANGE =  5 };
      enum { UWB_BETWEEN =  6 };
      enum { INTERROB_RANGE =  7 };
      enum { INTERROB_BETW =  8 };

    PoseGraphEdge():
      key_from(0),
      key_to(0),
      type(0),
      pose(),
      covariance(),
      range(0),
      range_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      offset += this->pose.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      union {
        double real;
        uint64_t base;
      } u_covariancei;
      u_covariancei.real = this->covariance[i];
      *(outbuffer + offset + 0) = (u_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->covariance[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_range.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_range.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_range.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_range.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->range);
      union {
        double real;
        uint64_t base;
      } u_range_error;
      u_range_error.real = this->range_error;
      *(outbuffer + offset + 0) = (u_range_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_range_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_range_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_range_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_range_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->range_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      union {
        double real;
        uint64_t base;
      } u_covariancei;
      u_covariancei.base = 0;
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->covariance[i] = u_covariancei.real;
      offset += sizeof(this->covariance[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->range = u_range.real;
      offset += sizeof(this->range);
      union {
        double real;
        uint64_t base;
      } u_range_error;
      u_range_error.base = 0;
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_range_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->range_error = u_range_error.real;
      offset += sizeof(this->range_error);
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/PoseGraphEdge"; };
    virtual const char * getMD5() override { return "cfc2854799a8a1ab8ac1f62511bb6216"; };

  };

}
#endif
