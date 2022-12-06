#ifndef _ROS_SERVICE_SetPositionGoal_h
#define _ROS_SERVICE_SetPositionGoal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace mission_msgs
{

static const char SETPOSITIONGOAL[] = "mission_msgs/SetPositionGoal";

  class SetPositionGoalRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _goal_type;
      _goal_type goal;

    SetPositionGoalRequest():
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETPOSITIONGOAL; };
    virtual const char * getMD5() override { return "313b76aa4f010582b3257488c62ac366"; };

  };

  class SetPositionGoalResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SetPositionGoalResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return SETPOSITIONGOAL; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetPositionGoal {
    public:
    typedef SetPositionGoalRequest Request;
    typedef SetPositionGoalResponse Response;
  };

}
#endif
