#ifndef _ROS_roadmap_msgs_MLPFeedback_h
#define _ROS_roadmap_msgs_MLPFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/Path.h"

namespace roadmap_msgs
{

  class MLPFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef nav_msgs::Path _path_type;
      _path_type path;
      typedef float _path_length_type;
      _path_length_type path_length;
      typedef float _total_reward_type;
      _total_reward_type total_reward;
      typedef bool _unknown_exploration_type;
      _unknown_exploration_type unknown_exploration;
      typedef bool _timeout_triggered_type;
      _timeout_triggered_type timeout_triggered;

    MLPFeedback():
      header(),
      path(),
      path_length(0),
      total_reward(0),
      unknown_exploration(0),
      timeout_triggered(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->path.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_path_length;
      u_path_length.real = this->path_length;
      *(outbuffer + offset + 0) = (u_path_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      union {
        float real;
        uint32_t base;
      } u_total_reward;
      u_total_reward.real = this->total_reward;
      *(outbuffer + offset + 0) = (u_total_reward.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_reward.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_reward.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_reward.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_reward);
      union {
        bool real;
        uint8_t base;
      } u_unknown_exploration;
      u_unknown_exploration.real = this->unknown_exploration;
      *(outbuffer + offset + 0) = (u_unknown_exploration.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->unknown_exploration);
      union {
        bool real;
        uint8_t base;
      } u_timeout_triggered;
      u_timeout_triggered.real = this->timeout_triggered;
      *(outbuffer + offset + 0) = (u_timeout_triggered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->timeout_triggered);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->path.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_path_length;
      u_path_length.base = 0;
      u_path_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_length = u_path_length.real;
      offset += sizeof(this->path_length);
      union {
        float real;
        uint32_t base;
      } u_total_reward;
      u_total_reward.base = 0;
      u_total_reward.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_reward.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_reward.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_reward.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_reward = u_total_reward.real;
      offset += sizeof(this->total_reward);
      union {
        bool real;
        uint8_t base;
      } u_unknown_exploration;
      u_unknown_exploration.base = 0;
      u_unknown_exploration.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->unknown_exploration = u_unknown_exploration.real;
      offset += sizeof(this->unknown_exploration);
      union {
        bool real;
        uint8_t base;
      } u_timeout_triggered;
      u_timeout_triggered.base = 0;
      u_timeout_triggered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->timeout_triggered = u_timeout_triggered.real;
      offset += sizeof(this->timeout_triggered);
     return offset;
    }

    virtual const char * getType() override { return "roadmap_msgs/MLPFeedback"; };
    virtual const char * getMD5() override { return "482b0d8041ffdf7fe5af27cba07a836a"; };

  };

}
#endif
