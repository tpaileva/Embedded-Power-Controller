#ifndef _ROS_spot_msgs_BatteryStateArray_h
#define _ROS_spot_msgs_BatteryStateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/BatteryState.h"

namespace spot_msgs
{

  class BatteryStateArray : public ros::Msg
  {
    public:
      uint32_t battery_states_length;
      typedef spot_msgs::BatteryState _battery_states_type;
      _battery_states_type st_battery_states;
      _battery_states_type * battery_states;

    BatteryStateArray():
      battery_states_length(0), st_battery_states(), battery_states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->battery_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->battery_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->battery_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->battery_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_states_length);
      for( uint32_t i = 0; i < battery_states_length; i++){
      offset += this->battery_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t battery_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      battery_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      battery_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      battery_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->battery_states_length);
      if(battery_states_lengthT > battery_states_length)
        this->battery_states = (spot_msgs::BatteryState*)realloc(this->battery_states, battery_states_lengthT * sizeof(spot_msgs::BatteryState));
      battery_states_length = battery_states_lengthT;
      for( uint32_t i = 0; i < battery_states_length; i++){
      offset += this->st_battery_states.deserialize(inbuffer + offset);
        memcpy( &(this->battery_states[i]), &(this->st_battery_states), sizeof(spot_msgs::BatteryState));
      }
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/BatteryStateArray"; };
    virtual const char * getMD5() override { return "5be00bcb9a392f14ba6707e020a94106"; };

  };

}
#endif
