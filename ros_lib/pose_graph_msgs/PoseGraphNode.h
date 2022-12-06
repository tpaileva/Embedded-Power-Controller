#ifndef _ROS_pose_graph_msgs_PoseGraphNode_h
#define _ROS_pose_graph_msgs_PoseGraphNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace pose_graph_msgs
{

  class PoseGraphNode : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _key_type;
      _key_type key;
      typedef const char* _ID_type;
      _ID_type ID;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      double covariance[36];

    PoseGraphNode():
      header(),
      key(0),
      ID(""),
      pose(),
      covariance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_key;
      u_key.real = this->key;
      *(outbuffer + offset + 0) = (u_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key);
      uint32_t length_ID = strlen(this->ID);
      varToArr(outbuffer + offset, length_ID);
      offset += 4;
      memcpy(outbuffer + offset, this->ID, length_ID);
      offset += length_ID;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_key;
      u_key.base = 0;
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key = u_key.real;
      offset += sizeof(this->key);
      uint32_t length_ID;
      arrToVar(length_ID, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ID; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ID-1]=0;
      this->ID = (char *)(inbuffer + offset-1);
      offset += length_ID;
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
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/PoseGraphNode"; };
    virtual const char * getMD5() override { return "d08a6b4b5d6e4c60e98685622f399a1e"; };

  };

}
#endif
