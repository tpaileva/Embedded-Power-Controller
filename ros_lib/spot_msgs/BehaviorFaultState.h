#ifndef _ROS_spot_msgs_BehaviorFaultState_h
#define _ROS_spot_msgs_BehaviorFaultState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/BehaviorFault.h"

namespace spot_msgs
{

  class BehaviorFaultState : public ros::Msg
  {
    public:
      uint32_t faults_length;
      typedef spot_msgs::BehaviorFault _faults_type;
      _faults_type st_faults;
      _faults_type * faults;

    BehaviorFaultState():
      faults_length(0), st_faults(), faults(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->faults_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->faults_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->faults_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->faults_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->faults_length);
      for( uint32_t i = 0; i < faults_length; i++){
      offset += this->faults[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t faults_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->faults_length);
      if(faults_lengthT > faults_length)
        this->faults = (spot_msgs::BehaviorFault*)realloc(this->faults, faults_lengthT * sizeof(spot_msgs::BehaviorFault));
      faults_length = faults_lengthT;
      for( uint32_t i = 0; i < faults_length; i++){
      offset += this->st_faults.deserialize(inbuffer + offset);
        memcpy( &(this->faults[i]), &(this->st_faults), sizeof(spot_msgs::BehaviorFault));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/BehaviorFaultState"; };
    virtual const char * getMD5() override { return "59543c1c1ad10a39140a97dcfc78f876"; };

  };

}
#endif
