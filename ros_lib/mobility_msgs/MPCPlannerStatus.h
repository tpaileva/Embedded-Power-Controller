#ifndef _ROS_mobility_msgs_MPCPlannerStatus_h
#define _ROS_mobility_msgs_MPCPlannerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"

namespace mobility_msgs
{

  class MPCPlannerStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _waiting_type;
      _waiting_type waiting;
      typedef bool _plan_start_state_reset_type;
      _plan_start_state_reset_type plan_start_state_reset;
      typedef bool _collision_type;
      _collision_type collision;
      typedef bool _stopping_type;
      _stopping_type stopping;
      typedef bool _stuck_type;
      _stuck_type stuck;
      typedef bool _use_yaw_goal_type;
      _use_yaw_goal_type use_yaw_goal;
      typedef float _path_risk_type;
      _path_risk_type path_risk;
      typedef float _path_max_risk_type;
      _path_max_risk_type path_max_risk;
      typedef float _path_cost_type;
      _path_cost_type path_cost;
      typedef float _path_final_distance_to_goal_type;
      _path_final_distance_to_goal_type path_final_distance_to_goal;
      typedef float _path_length_type;
      _path_length_type path_length;
      typedef int32_t _path_num_obstacles_type;
      _path_num_obstacles_type path_num_obstacles;
      typedef ros::Duration _duration_to_first_obstacle_type;
      _duration_to_first_obstacle_type duration_to_first_obstacle;
      typedef ros::Duration _duration_to_max_risk_type;
      _duration_to_max_risk_type duration_to_max_risk;
      typedef geometry_msgs::PoseStamped _future_pose_type;
      _future_pose_type future_pose;
      typedef geometry_msgs::TwistStamped _future_velocity_type;
      _future_velocity_type future_velocity;
      typedef geometry_msgs::PoseStamped _max_risk_pose_type;
      _max_risk_pose_type max_risk_pose;

    MPCPlannerStatus():
      header(),
      waiting(0),
      plan_start_state_reset(0),
      collision(0),
      stopping(0),
      stuck(0),
      use_yaw_goal(0),
      path_risk(0),
      path_max_risk(0),
      path_cost(0),
      path_final_distance_to_goal(0),
      path_length(0),
      path_num_obstacles(0),
      duration_to_first_obstacle(),
      duration_to_max_risk(),
      future_pose(),
      future_velocity(),
      max_risk_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_waiting;
      u_waiting.real = this->waiting;
      *(outbuffer + offset + 0) = (u_waiting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->waiting);
      union {
        bool real;
        uint8_t base;
      } u_plan_start_state_reset;
      u_plan_start_state_reset.real = this->plan_start_state_reset;
      *(outbuffer + offset + 0) = (u_plan_start_state_reset.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_start_state_reset);
      union {
        bool real;
        uint8_t base;
      } u_collision;
      u_collision.real = this->collision;
      *(outbuffer + offset + 0) = (u_collision.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->collision);
      union {
        bool real;
        uint8_t base;
      } u_stopping;
      u_stopping.real = this->stopping;
      *(outbuffer + offset + 0) = (u_stopping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stopping);
      union {
        bool real;
        uint8_t base;
      } u_stuck;
      u_stuck.real = this->stuck;
      *(outbuffer + offset + 0) = (u_stuck.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stuck);
      union {
        bool real;
        uint8_t base;
      } u_use_yaw_goal;
      u_use_yaw_goal.real = this->use_yaw_goal;
      *(outbuffer + offset + 0) = (u_use_yaw_goal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_yaw_goal);
      union {
        float real;
        uint32_t base;
      } u_path_risk;
      u_path_risk.real = this->path_risk;
      *(outbuffer + offset + 0) = (u_path_risk.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_risk.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_risk.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_risk.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_risk);
      union {
        float real;
        uint32_t base;
      } u_path_max_risk;
      u_path_max_risk.real = this->path_max_risk;
      *(outbuffer + offset + 0) = (u_path_max_risk.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_max_risk.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_max_risk.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_max_risk.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_max_risk);
      union {
        float real;
        uint32_t base;
      } u_path_cost;
      u_path_cost.real = this->path_cost;
      *(outbuffer + offset + 0) = (u_path_cost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_cost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_cost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_cost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_cost);
      union {
        float real;
        uint32_t base;
      } u_path_final_distance_to_goal;
      u_path_final_distance_to_goal.real = this->path_final_distance_to_goal;
      *(outbuffer + offset + 0) = (u_path_final_distance_to_goal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_final_distance_to_goal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_final_distance_to_goal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_final_distance_to_goal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_final_distance_to_goal);
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
        int32_t real;
        uint32_t base;
      } u_path_num_obstacles;
      u_path_num_obstacles.real = this->path_num_obstacles;
      *(outbuffer + offset + 0) = (u_path_num_obstacles.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_num_obstacles.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_num_obstacles.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_num_obstacles.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_num_obstacles);
      *(outbuffer + offset + 0) = (this->duration_to_first_obstacle.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration_to_first_obstacle.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration_to_first_obstacle.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration_to_first_obstacle.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_to_first_obstacle.sec);
      *(outbuffer + offset + 0) = (this->duration_to_first_obstacle.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration_to_first_obstacle.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration_to_first_obstacle.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration_to_first_obstacle.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_to_first_obstacle.nsec);
      *(outbuffer + offset + 0) = (this->duration_to_max_risk.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration_to_max_risk.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration_to_max_risk.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration_to_max_risk.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_to_max_risk.sec);
      *(outbuffer + offset + 0) = (this->duration_to_max_risk.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration_to_max_risk.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration_to_max_risk.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration_to_max_risk.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_to_max_risk.nsec);
      offset += this->future_pose.serialize(outbuffer + offset);
      offset += this->future_velocity.serialize(outbuffer + offset);
      offset += this->max_risk_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_waiting;
      u_waiting.base = 0;
      u_waiting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->waiting = u_waiting.real;
      offset += sizeof(this->waiting);
      union {
        bool real;
        uint8_t base;
      } u_plan_start_state_reset;
      u_plan_start_state_reset.base = 0;
      u_plan_start_state_reset.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_start_state_reset = u_plan_start_state_reset.real;
      offset += sizeof(this->plan_start_state_reset);
      union {
        bool real;
        uint8_t base;
      } u_collision;
      u_collision.base = 0;
      u_collision.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->collision = u_collision.real;
      offset += sizeof(this->collision);
      union {
        bool real;
        uint8_t base;
      } u_stopping;
      u_stopping.base = 0;
      u_stopping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stopping = u_stopping.real;
      offset += sizeof(this->stopping);
      union {
        bool real;
        uint8_t base;
      } u_stuck;
      u_stuck.base = 0;
      u_stuck.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stuck = u_stuck.real;
      offset += sizeof(this->stuck);
      union {
        bool real;
        uint8_t base;
      } u_use_yaw_goal;
      u_use_yaw_goal.base = 0;
      u_use_yaw_goal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_yaw_goal = u_use_yaw_goal.real;
      offset += sizeof(this->use_yaw_goal);
      union {
        float real;
        uint32_t base;
      } u_path_risk;
      u_path_risk.base = 0;
      u_path_risk.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_risk.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_risk.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_risk.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_risk = u_path_risk.real;
      offset += sizeof(this->path_risk);
      union {
        float real;
        uint32_t base;
      } u_path_max_risk;
      u_path_max_risk.base = 0;
      u_path_max_risk.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_max_risk.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_max_risk.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_max_risk.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_max_risk = u_path_max_risk.real;
      offset += sizeof(this->path_max_risk);
      union {
        float real;
        uint32_t base;
      } u_path_cost;
      u_path_cost.base = 0;
      u_path_cost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_cost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_cost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_cost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_cost = u_path_cost.real;
      offset += sizeof(this->path_cost);
      union {
        float real;
        uint32_t base;
      } u_path_final_distance_to_goal;
      u_path_final_distance_to_goal.base = 0;
      u_path_final_distance_to_goal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_final_distance_to_goal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_final_distance_to_goal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_final_distance_to_goal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_final_distance_to_goal = u_path_final_distance_to_goal.real;
      offset += sizeof(this->path_final_distance_to_goal);
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
        int32_t real;
        uint32_t base;
      } u_path_num_obstacles;
      u_path_num_obstacles.base = 0;
      u_path_num_obstacles.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_num_obstacles.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_num_obstacles.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_num_obstacles.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->path_num_obstacles = u_path_num_obstacles.real;
      offset += sizeof(this->path_num_obstacles);
      this->duration_to_first_obstacle.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration_to_first_obstacle.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration_to_first_obstacle.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration_to_first_obstacle.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration_to_first_obstacle.sec);
      this->duration_to_first_obstacle.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration_to_first_obstacle.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration_to_first_obstacle.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration_to_first_obstacle.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration_to_first_obstacle.nsec);
      this->duration_to_max_risk.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration_to_max_risk.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration_to_max_risk.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration_to_max_risk.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration_to_max_risk.sec);
      this->duration_to_max_risk.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration_to_max_risk.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration_to_max_risk.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration_to_max_risk.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration_to_max_risk.nsec);
      offset += this->future_pose.deserialize(inbuffer + offset);
      offset += this->future_velocity.deserialize(inbuffer + offset);
      offset += this->max_risk_pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/MPCPlannerStatus"; };
    virtual const char * getMD5() override { return "a91c6375aabb9d88938c67abe70b54ec"; };

  };

}
#endif
