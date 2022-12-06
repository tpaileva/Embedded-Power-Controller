#ifndef _ROS_mission_msgs_ActiveTaskUUIDs_h
#define _ROS_mission_msgs_ActiveTaskUUIDs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mission_msgs
{

  class ActiveTaskUUIDs : public ros::Msg
  {
    public:
      uint32_t active_task_uuids_length;
      typedef char* _active_task_uuids_type;
      _active_task_uuids_type st_active_task_uuids;
      _active_task_uuids_type * active_task_uuids;

    ActiveTaskUUIDs():
      active_task_uuids_length(0), st_active_task_uuids(), active_task_uuids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_task_uuids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->active_task_uuids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->active_task_uuids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->active_task_uuids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->active_task_uuids_length);
      for( uint32_t i = 0; i < active_task_uuids_length; i++){
      uint32_t length_active_task_uuidsi = strlen(this->active_task_uuids[i]);
      varToArr(outbuffer + offset, length_active_task_uuidsi);
      offset += 4;
      memcpy(outbuffer + offset, this->active_task_uuids[i], length_active_task_uuidsi);
      offset += length_active_task_uuidsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t active_task_uuids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      active_task_uuids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      active_task_uuids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      active_task_uuids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->active_task_uuids_length);
      if(active_task_uuids_lengthT > active_task_uuids_length)
        this->active_task_uuids = (char**)realloc(this->active_task_uuids, active_task_uuids_lengthT * sizeof(char*));
      active_task_uuids_length = active_task_uuids_lengthT;
      for( uint32_t i = 0; i < active_task_uuids_length; i++){
      uint32_t length_st_active_task_uuids;
      arrToVar(length_st_active_task_uuids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_active_task_uuids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_active_task_uuids-1]=0;
      this->st_active_task_uuids = (char *)(inbuffer + offset-1);
      offset += length_st_active_task_uuids;
        memcpy( &(this->active_task_uuids[i]), &(this->st_active_task_uuids), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/ActiveTaskUUIDs"; };
    virtual const char * getMD5() override { return "ffd5a49e9331d93c34d53fb337cf02e5"; };

  };

}
#endif
