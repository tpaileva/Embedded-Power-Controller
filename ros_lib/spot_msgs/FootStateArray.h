#ifndef _ROS_spot_msgs_FootStateArray_h
#define _ROS_spot_msgs_FootStateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/FootState.h"

namespace spot_msgs
{

  class FootStateArray : public ros::Msg
  {
    public:
      uint32_t states_length;
      typedef spot_msgs::FootState _states_type;
      _states_type st_states;
      _states_type * states;

    FootStateArray():
      states_length(0), st_states(), states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (spot_msgs::FootState*)realloc(this->states, states_lengthT * sizeof(spot_msgs::FootState));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(spot_msgs::FootState));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/FootStateArray"; };
    virtual const char * getMD5() override { return "6bad9df4582060c21e7bde863865e1cb"; };

  };

}
#endif
