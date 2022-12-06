#ifndef _ROS_mission_msgs_MissionStatus_h
#define _ROS_mission_msgs_MissionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mission_msgs/ActiveMission.h"
#include "mission_msgs/ActiveTaskUUIDs.h"

namespace mission_msgs
{

  class MissionStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef mission_msgs::ActiveMission _active_mission_type;
      _active_mission_type active_mission;
      typedef const char* _mission_status_json_type;
      _mission_status_json_type mission_status_json;
      typedef mission_msgs::ActiveTaskUUIDs _mission_active_tasks_type;
      _mission_active_tasks_type mission_active_tasks;
      typedef int32_t _watchdog_countdown_type;
      _watchdog_countdown_type watchdog_countdown;

    MissionStatus():
      header(),
      active_mission(),
      mission_status_json(""),
      mission_active_tasks(),
      watchdog_countdown(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->active_mission.serialize(outbuffer + offset);
      uint32_t length_mission_status_json = strlen(this->mission_status_json);
      varToArr(outbuffer + offset, length_mission_status_json);
      offset += 4;
      memcpy(outbuffer + offset, this->mission_status_json, length_mission_status_json);
      offset += length_mission_status_json;
      offset += this->mission_active_tasks.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_watchdog_countdown;
      u_watchdog_countdown.real = this->watchdog_countdown;
      *(outbuffer + offset + 0) = (u_watchdog_countdown.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_watchdog_countdown.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_watchdog_countdown.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_watchdog_countdown.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->watchdog_countdown);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->active_mission.deserialize(inbuffer + offset);
      uint32_t length_mission_status_json;
      arrToVar(length_mission_status_json, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mission_status_json; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mission_status_json-1]=0;
      this->mission_status_json = (char *)(inbuffer + offset-1);
      offset += length_mission_status_json;
      offset += this->mission_active_tasks.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_watchdog_countdown;
      u_watchdog_countdown.base = 0;
      u_watchdog_countdown.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_watchdog_countdown.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_watchdog_countdown.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_watchdog_countdown.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->watchdog_countdown = u_watchdog_countdown.real;
      offset += sizeof(this->watchdog_countdown);
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/MissionStatus"; };
    virtual const char * getMD5() override { return "07526c05bf8697e8b1e9a37eac103b38"; };

  };

}
#endif
