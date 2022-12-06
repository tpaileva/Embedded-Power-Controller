#ifndef _ROS_spot_msgs_SystemFaultState_h
#define _ROS_spot_msgs_SystemFaultState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/SystemFault.h"

namespace spot_msgs
{

  class SystemFaultState : public ros::Msg
  {
    public:
      uint32_t faults_length;
      typedef spot_msgs::SystemFault _faults_type;
      _faults_type st_faults;
      _faults_type * faults;
      uint32_t historical_faults_length;
      typedef spot_msgs::SystemFault _historical_faults_type;
      _historical_faults_type st_historical_faults;
      _historical_faults_type * historical_faults;

    SystemFaultState():
      faults_length(0), st_faults(), faults(nullptr),
      historical_faults_length(0), st_historical_faults(), historical_faults(nullptr)
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
      *(outbuffer + offset + 0) = (this->historical_faults_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->historical_faults_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->historical_faults_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->historical_faults_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->historical_faults_length);
      for( uint32_t i = 0; i < historical_faults_length; i++){
      offset += this->historical_faults[i].serialize(outbuffer + offset);
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
        this->faults = (spot_msgs::SystemFault*)realloc(this->faults, faults_lengthT * sizeof(spot_msgs::SystemFault));
      faults_length = faults_lengthT;
      for( uint32_t i = 0; i < faults_length; i++){
      offset += this->st_faults.deserialize(inbuffer + offset);
        memcpy( &(this->faults[i]), &(this->st_faults), sizeof(spot_msgs::SystemFault));
      }
      uint32_t historical_faults_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      historical_faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      historical_faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      historical_faults_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->historical_faults_length);
      if(historical_faults_lengthT > historical_faults_length)
        this->historical_faults = (spot_msgs::SystemFault*)realloc(this->historical_faults, historical_faults_lengthT * sizeof(spot_msgs::SystemFault));
      historical_faults_length = historical_faults_lengthT;
      for( uint32_t i = 0; i < historical_faults_length; i++){
      offset += this->st_historical_faults.deserialize(inbuffer + offset);
        memcpy( &(this->historical_faults[i]), &(this->st_historical_faults), sizeof(spot_msgs::SystemFault));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/SystemFaultState"; };
    virtual const char * getMD5() override { return "3847105c5e3204fe63ad7caa31a33575"; };

  };

}
#endif
