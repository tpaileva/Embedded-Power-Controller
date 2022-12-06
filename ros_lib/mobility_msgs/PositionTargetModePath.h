#ifndef _ROS_mobility_msgs_PositionTargetModePath_h
#define _ROS_mobility_msgs_PositionTargetModePath_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mobility_msgs/PositionTargetMode.h"
#include "ros/time.h"

namespace mobility_msgs
{

  class PositionTargetModePath : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _frame_id_z_type;
      _frame_id_z_type frame_id_z;
      typedef uint8_t _control_mode_z_type;
      _control_mode_z_type control_mode_z;
      uint32_t path_length;
      typedef mobility_msgs::PositionTargetMode _path_type;
      _path_type st_path;
      _path_type * path;
      uint32_t target_time_length;
      typedef ros::Time _target_time_type;
      _target_time_type st_target_time;
      _target_time_type * target_time;

    PositionTargetModePath():
      header(),
      frame_id_z(""),
      control_mode_z(0),
      path_length(0), st_path(), path(nullptr),
      target_time_length(0), st_target_time(), target_time(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_frame_id_z = strlen(this->frame_id_z);
      varToArr(outbuffer + offset, length_frame_id_z);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id_z, length_frame_id_z);
      offset += length_frame_id_z;
      *(outbuffer + offset + 0) = (this->control_mode_z >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode_z);
      *(outbuffer + offset + 0) = (this->path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->target_time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_time_length);
      for( uint32_t i = 0; i < target_time_length; i++){
      *(outbuffer + offset + 0) = (this->target_time[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_time[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_time[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_time[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_time[i].sec);
      *(outbuffer + offset + 0) = (this->target_time[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_time[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_time[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_time[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_time[i].nsec);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_frame_id_z;
      arrToVar(length_frame_id_z, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id_z; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id_z-1]=0;
      this->frame_id_z = (char *)(inbuffer + offset-1);
      offset += length_frame_id_z;
      this->control_mode_z =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode_z);
      uint32_t path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->path_length);
      if(path_lengthT > path_length)
        this->path = (mobility_msgs::PositionTargetMode*)realloc(this->path, path_lengthT * sizeof(mobility_msgs::PositionTargetMode));
      path_length = path_lengthT;
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(mobility_msgs::PositionTargetMode));
      }
      uint32_t target_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      target_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      target_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      target_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->target_time_length);
      if(target_time_lengthT > target_time_length)
        this->target_time = (ros::Time*)realloc(this->target_time, target_time_lengthT * sizeof(ros::Time));
      target_time_length = target_time_lengthT;
      for( uint32_t i = 0; i < target_time_length; i++){
      this->st_target_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_target_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_target_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_target_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_target_time.sec);
      this->st_target_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_target_time.nsec);
        memcpy( &(this->target_time[i]), &(this->st_target_time), sizeof(ros::Time));
      }
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/PositionTargetModePath"; };
    virtual const char * getMD5() override { return "c7699d581fee478da9d08bf25792a51b"; };

  };

}
#endif
