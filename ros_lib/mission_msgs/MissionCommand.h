#ifndef _ROS_mission_msgs_MissionCommand_h
#define _ROS_mission_msgs_MissionCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mission_msgs
{

  class MissionCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _c2_start_cmd_type;
      _c2_start_cmd_type c2_start_cmd;
      typedef bool _c2_start_cmd_valid_type;
      _c2_start_cmd_valid_type c2_start_cmd_valid;
      typedef bool _c2_end_cmd_type;
      _c2_end_cmd_type c2_end_cmd;
      typedef bool _c2_end_cmd_valid_type;
      _c2_end_cmd_valid_type c2_end_cmd_valid;
      typedef const char* _load_mission_cmd_type;
      _load_mission_cmd_type load_mission_cmd;
      typedef bool _load_mission_cmd_valid_type;
      _load_mission_cmd_valid_type load_mission_cmd_valid;
      typedef int32_t _set_comm_timeout_cmd_type;
      _set_comm_timeout_cmd_type set_comm_timeout_cmd;
      typedef bool _set_comm_timeout_cmd_valid_type;
      _set_comm_timeout_cmd_valid_type set_comm_timeout_cmd_valid;
      typedef bool _c2_drop_comm_node_cmd_type;
      _c2_drop_comm_node_cmd_type c2_drop_comm_node_cmd;
      typedef bool _c2_drop_comm_node_cmd_valid_type;
      _c2_drop_comm_node_cmd_valid_type c2_drop_comm_node_cmd_valid;

    MissionCommand():
      header(),
      c2_start_cmd(0),
      c2_start_cmd_valid(0),
      c2_end_cmd(0),
      c2_end_cmd_valid(0),
      load_mission_cmd(""),
      load_mission_cmd_valid(0),
      set_comm_timeout_cmd(0),
      set_comm_timeout_cmd_valid(0),
      c2_drop_comm_node_cmd(0),
      c2_drop_comm_node_cmd_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_c2_start_cmd;
      u_c2_start_cmd.real = this->c2_start_cmd;
      *(outbuffer + offset + 0) = (u_c2_start_cmd.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_start_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_start_cmd_valid;
      u_c2_start_cmd_valid.real = this->c2_start_cmd_valid;
      *(outbuffer + offset + 0) = (u_c2_start_cmd_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_start_cmd_valid);
      union {
        bool real;
        uint8_t base;
      } u_c2_end_cmd;
      u_c2_end_cmd.real = this->c2_end_cmd;
      *(outbuffer + offset + 0) = (u_c2_end_cmd.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_end_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_end_cmd_valid;
      u_c2_end_cmd_valid.real = this->c2_end_cmd_valid;
      *(outbuffer + offset + 0) = (u_c2_end_cmd_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_end_cmd_valid);
      uint32_t length_load_mission_cmd = strlen(this->load_mission_cmd);
      varToArr(outbuffer + offset, length_load_mission_cmd);
      offset += 4;
      memcpy(outbuffer + offset, this->load_mission_cmd, length_load_mission_cmd);
      offset += length_load_mission_cmd;
      union {
        bool real;
        uint8_t base;
      } u_load_mission_cmd_valid;
      u_load_mission_cmd_valid.real = this->load_mission_cmd_valid;
      *(outbuffer + offset + 0) = (u_load_mission_cmd_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->load_mission_cmd_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_set_comm_timeout_cmd;
      u_set_comm_timeout_cmd.real = this->set_comm_timeout_cmd;
      *(outbuffer + offset + 0) = (u_set_comm_timeout_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_comm_timeout_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_comm_timeout_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_comm_timeout_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_comm_timeout_cmd);
      union {
        bool real;
        uint8_t base;
      } u_set_comm_timeout_cmd_valid;
      u_set_comm_timeout_cmd_valid.real = this->set_comm_timeout_cmd_valid;
      *(outbuffer + offset + 0) = (u_set_comm_timeout_cmd_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_comm_timeout_cmd_valid);
      union {
        bool real;
        uint8_t base;
      } u_c2_drop_comm_node_cmd;
      u_c2_drop_comm_node_cmd.real = this->c2_drop_comm_node_cmd;
      *(outbuffer + offset + 0) = (u_c2_drop_comm_node_cmd.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_drop_comm_node_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_drop_comm_node_cmd_valid;
      u_c2_drop_comm_node_cmd_valid.real = this->c2_drop_comm_node_cmd_valid;
      *(outbuffer + offset + 0) = (u_c2_drop_comm_node_cmd_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c2_drop_comm_node_cmd_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_c2_start_cmd;
      u_c2_start_cmd.base = 0;
      u_c2_start_cmd.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_start_cmd = u_c2_start_cmd.real;
      offset += sizeof(this->c2_start_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_start_cmd_valid;
      u_c2_start_cmd_valid.base = 0;
      u_c2_start_cmd_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_start_cmd_valid = u_c2_start_cmd_valid.real;
      offset += sizeof(this->c2_start_cmd_valid);
      union {
        bool real;
        uint8_t base;
      } u_c2_end_cmd;
      u_c2_end_cmd.base = 0;
      u_c2_end_cmd.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_end_cmd = u_c2_end_cmd.real;
      offset += sizeof(this->c2_end_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_end_cmd_valid;
      u_c2_end_cmd_valid.base = 0;
      u_c2_end_cmd_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_end_cmd_valid = u_c2_end_cmd_valid.real;
      offset += sizeof(this->c2_end_cmd_valid);
      uint32_t length_load_mission_cmd;
      arrToVar(length_load_mission_cmd, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_load_mission_cmd; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_load_mission_cmd-1]=0;
      this->load_mission_cmd = (char *)(inbuffer + offset-1);
      offset += length_load_mission_cmd;
      union {
        bool real;
        uint8_t base;
      } u_load_mission_cmd_valid;
      u_load_mission_cmd_valid.base = 0;
      u_load_mission_cmd_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->load_mission_cmd_valid = u_load_mission_cmd_valid.real;
      offset += sizeof(this->load_mission_cmd_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_set_comm_timeout_cmd;
      u_set_comm_timeout_cmd.base = 0;
      u_set_comm_timeout_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_comm_timeout_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_comm_timeout_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_comm_timeout_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_comm_timeout_cmd = u_set_comm_timeout_cmd.real;
      offset += sizeof(this->set_comm_timeout_cmd);
      union {
        bool real;
        uint8_t base;
      } u_set_comm_timeout_cmd_valid;
      u_set_comm_timeout_cmd_valid.base = 0;
      u_set_comm_timeout_cmd_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_comm_timeout_cmd_valid = u_set_comm_timeout_cmd_valid.real;
      offset += sizeof(this->set_comm_timeout_cmd_valid);
      union {
        bool real;
        uint8_t base;
      } u_c2_drop_comm_node_cmd;
      u_c2_drop_comm_node_cmd.base = 0;
      u_c2_drop_comm_node_cmd.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_drop_comm_node_cmd = u_c2_drop_comm_node_cmd.real;
      offset += sizeof(this->c2_drop_comm_node_cmd);
      union {
        bool real;
        uint8_t base;
      } u_c2_drop_comm_node_cmd_valid;
      u_c2_drop_comm_node_cmd_valid.base = 0;
      u_c2_drop_comm_node_cmd_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->c2_drop_comm_node_cmd_valid = u_c2_drop_comm_node_cmd_valid.real;
      offset += sizeof(this->c2_drop_comm_node_cmd_valid);
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/MissionCommand"; };
    virtual const char * getMD5() override { return "4c8b4316da1e5d0a66680e02480b0d8f"; };

  };

}
#endif
