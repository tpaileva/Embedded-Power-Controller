#ifndef _ROS_mission_msgs_ActiveMission_h
#define _ROS_mission_msgs_ActiveMission_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace mission_msgs
{

  class ActiveMission : public ros::Msg
  {
    public:
      typedef ros::Time _loaded_time_type;
      _loaded_time_type loaded_time;
      typedef const char* _loaded_mission_type;
      _loaded_mission_type loaded_mission;

    ActiveMission():
      loaded_time(),
      loaded_mission("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->loaded_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loaded_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loaded_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loaded_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loaded_time.sec);
      *(outbuffer + offset + 0) = (this->loaded_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loaded_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loaded_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loaded_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loaded_time.nsec);
      uint32_t length_loaded_mission = strlen(this->loaded_mission);
      varToArr(outbuffer + offset, length_loaded_mission);
      offset += 4;
      memcpy(outbuffer + offset, this->loaded_mission, length_loaded_mission);
      offset += length_loaded_mission;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->loaded_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->loaded_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loaded_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->loaded_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->loaded_time.sec);
      this->loaded_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->loaded_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loaded_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->loaded_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->loaded_time.nsec);
      uint32_t length_loaded_mission;
      arrToVar(length_loaded_mission, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_loaded_mission; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_loaded_mission-1]=0;
      this->loaded_mission = (char *)(inbuffer + offset-1);
      offset += length_loaded_mission;
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/ActiveMission"; };
    virtual const char * getMD5() override { return "bb4d269115b20382ee7b87ec3f6070a5"; };

  };

}
#endif
