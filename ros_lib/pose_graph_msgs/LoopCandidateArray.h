#ifndef _ROS_pose_graph_msgs_LoopCandidateArray_h
#define _ROS_pose_graph_msgs_LoopCandidateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pose_graph_msgs/LoopCandidate.h"

namespace pose_graph_msgs
{

  class LoopCandidateArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _originator_type;
      _originator_type originator;
      uint32_t candidates_length;
      typedef pose_graph_msgs::LoopCandidate _candidates_type;
      _candidates_type st_candidates;
      _candidates_type * candidates;

    LoopCandidateArray():
      header(),
      originator(0),
      candidates_length(0), st_candidates(), candidates(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_originator;
      u_originator.real = this->originator;
      *(outbuffer + offset + 0) = (u_originator.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_originator.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_originator.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_originator.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->originator);
      *(outbuffer + offset + 0) = (this->candidates_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->candidates_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->candidates_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->candidates_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->candidates_length);
      for( uint32_t i = 0; i < candidates_length; i++){
      offset += this->candidates[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_originator;
      u_originator.base = 0;
      u_originator.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_originator.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_originator.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_originator.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->originator = u_originator.real;
      offset += sizeof(this->originator);
      uint32_t candidates_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->candidates_length);
      if(candidates_lengthT > candidates_length)
        this->candidates = (pose_graph_msgs::LoopCandidate*)realloc(this->candidates, candidates_lengthT * sizeof(pose_graph_msgs::LoopCandidate));
      candidates_length = candidates_lengthT;
      for( uint32_t i = 0; i < candidates_length; i++){
      offset += this->st_candidates.deserialize(inbuffer + offset);
        memcpy( &(this->candidates[i]), &(this->st_candidates), sizeof(pose_graph_msgs::LoopCandidate));
      }
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/LoopCandidateArray"; };
    virtual const char * getMD5() override { return "5c1cd1f2249ac6780517474ddc7d33a3"; };

  };

}
#endif
