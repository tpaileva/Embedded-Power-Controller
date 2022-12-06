#ifndef _ROS_spot_msgs_EStopStateArray_h
#define _ROS_spot_msgs_EStopStateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/EStopState.h"

namespace spot_msgs
{

  class EStopStateArray : public ros::Msg
  {
    public:
      uint32_t estop_states_length;
      typedef spot_msgs::EStopState _estop_states_type;
      _estop_states_type st_estop_states;
      _estop_states_type * estop_states;

    EStopStateArray():
      estop_states_length(0), st_estop_states(), estop_states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->estop_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estop_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estop_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estop_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estop_states_length);
      for( uint32_t i = 0; i < estop_states_length; i++){
      offset += this->estop_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t estop_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      estop_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      estop_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      estop_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->estop_states_length);
      if(estop_states_lengthT > estop_states_length)
        this->estop_states = (spot_msgs::EStopState*)realloc(this->estop_states, estop_states_lengthT * sizeof(spot_msgs::EStopState));
      estop_states_length = estop_states_lengthT;
      for( uint32_t i = 0; i < estop_states_length; i++){
      offset += this->st_estop_states.deserialize(inbuffer + offset);
        memcpy( &(this->estop_states[i]), &(this->st_estop_states), sizeof(spot_msgs::EStopState));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/EStopStateArray"; };
    virtual const char * getMD5() override { return "9a14a6b761f26c00c5613f0dc614f084"; };

  };

}
#endif
