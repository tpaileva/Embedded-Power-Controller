#ifndef _ROS_mission_msgs_MissionState_h
#define _ROS_mission_msgs_MissionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace mission_msgs
{

  class MissionState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _num_detected_artifacts_type;
      _num_detected_artifacts_type num_detected_artifacts;
      typedef int32_t _num_unreported_artifacts_type;
      _num_unreported_artifacts_type num_unreported_artifacts;
      typedef int32_t _num_scored_artifacts_type;
      _num_scored_artifacts_type num_scored_artifacts;
      typedef float _max_confidence_of_unreported_artifacts_type;
      _max_confidence_of_unreported_artifacts_type max_confidence_of_unreported_artifacts;
      typedef int8_t _comm_health_type;
      _comm_health_type comm_health;
      typedef int32_t _num_loaded_comm_nodes_type;
      _num_loaded_comm_nodes_type num_loaded_comm_nodes;
      typedef ros::Duration _time_since_last_connection_type;
      _time_since_last_connection_type time_since_last_connection;
      typedef bool _comm_drop_requested_type;
      _comm_drop_requested_type comm_drop_requested;
      typedef int8_t _mobility_health_type;
      _mobility_health_type mobility_health;
      typedef int8_t _tilt_health_type;
      _tilt_health_type tilt_health;
      typedef bool _stairs_requested_type;
      _stairs_requested_type stairs_requested;
      typedef bool _user_node_requested_type;
      _user_node_requested_type user_node_requested;
      typedef bool _mission_node_requested_type;
      _mission_node_requested_type mission_node_requested;
      typedef bool _is_exploring_type;
      _is_exploring_type is_exploring;
      typedef bool _is_returning_type;
      _is_returning_type is_returning;
      typedef bool _is_comm_dropping_type;
      _is_comm_dropping_type is_comm_dropping;
      typedef bool _is_climbing_type;
      _is_climbing_type is_climbing;
      typedef int8_t _battery_health_type;
      _battery_health_type battery_health;
      typedef int8_t _ros_node_health_type;
      _ros_node_health_type ros_node_health;
      typedef int8_t _sensor_health_type;
      _sensor_health_type sensor_health;
      typedef int32_t _num_deployed_robots_type;
      _num_deployed_robots_type num_deployed_robots;
      typedef int32_t _num_operational_robots_type;
      _num_operational_robots_type num_operational_robots;
      typedef ros::Duration _total_mission_time_type;
      _total_mission_time_type total_mission_time;
      typedef ros::Duration _remaining_mission_time_type;
      _remaining_mission_time_type remaining_mission_time;
      typedef bool _has_collision_risk_type;
      _has_collision_risk_type has_collision_risk;
      uint32_t nearby_robots_length;
      typedef char* _nearby_robots_type;
      _nearby_robots_type st_nearby_robots;
      _nearby_robots_type * nearby_robots;
      enum { OK =  0 };
      enum { WARN =  1 };
      enum { ERROR =  2 };
      enum { FATAL =  3 };

    MissionState():
      header(),
      num_detected_artifacts(0),
      num_unreported_artifacts(0),
      num_scored_artifacts(0),
      max_confidence_of_unreported_artifacts(0),
      comm_health(0),
      num_loaded_comm_nodes(0),
      time_since_last_connection(),
      comm_drop_requested(0),
      mobility_health(0),
      tilt_health(0),
      stairs_requested(0),
      user_node_requested(0),
      mission_node_requested(0),
      is_exploring(0),
      is_returning(0),
      is_comm_dropping(0),
      is_climbing(0),
      battery_health(0),
      ros_node_health(0),
      sensor_health(0),
      num_deployed_robots(0),
      num_operational_robots(0),
      total_mission_time(),
      remaining_mission_time(),
      has_collision_risk(0),
      nearby_robots_length(0), st_nearby_robots(), nearby_robots(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_num_detected_artifacts;
      u_num_detected_artifacts.real = this->num_detected_artifacts;
      *(outbuffer + offset + 0) = (u_num_detected_artifacts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_detected_artifacts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_detected_artifacts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_detected_artifacts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_detected_artifacts);
      union {
        int32_t real;
        uint32_t base;
      } u_num_unreported_artifacts;
      u_num_unreported_artifacts.real = this->num_unreported_artifacts;
      *(outbuffer + offset + 0) = (u_num_unreported_artifacts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_unreported_artifacts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_unreported_artifacts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_unreported_artifacts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_unreported_artifacts);
      union {
        int32_t real;
        uint32_t base;
      } u_num_scored_artifacts;
      u_num_scored_artifacts.real = this->num_scored_artifacts;
      *(outbuffer + offset + 0) = (u_num_scored_artifacts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_scored_artifacts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_scored_artifacts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_scored_artifacts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_scored_artifacts);
      union {
        float real;
        uint32_t base;
      } u_max_confidence_of_unreported_artifacts;
      u_max_confidence_of_unreported_artifacts.real = this->max_confidence_of_unreported_artifacts;
      *(outbuffer + offset + 0) = (u_max_confidence_of_unreported_artifacts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_confidence_of_unreported_artifacts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_confidence_of_unreported_artifacts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_confidence_of_unreported_artifacts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_confidence_of_unreported_artifacts);
      union {
        int8_t real;
        uint8_t base;
      } u_comm_health;
      u_comm_health.real = this->comm_health;
      *(outbuffer + offset + 0) = (u_comm_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->comm_health);
      union {
        int32_t real;
        uint32_t base;
      } u_num_loaded_comm_nodes;
      u_num_loaded_comm_nodes.real = this->num_loaded_comm_nodes;
      *(outbuffer + offset + 0) = (u_num_loaded_comm_nodes.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_loaded_comm_nodes.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_loaded_comm_nodes.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_loaded_comm_nodes.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_loaded_comm_nodes);
      *(outbuffer + offset + 0) = (this->time_since_last_connection.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_since_last_connection.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_since_last_connection.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_since_last_connection.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_since_last_connection.sec);
      *(outbuffer + offset + 0) = (this->time_since_last_connection.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_since_last_connection.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_since_last_connection.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_since_last_connection.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_since_last_connection.nsec);
      union {
        bool real;
        uint8_t base;
      } u_comm_drop_requested;
      u_comm_drop_requested.real = this->comm_drop_requested;
      *(outbuffer + offset + 0) = (u_comm_drop_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->comm_drop_requested);
      union {
        int8_t real;
        uint8_t base;
      } u_mobility_health;
      u_mobility_health.real = this->mobility_health;
      *(outbuffer + offset + 0) = (u_mobility_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mobility_health);
      union {
        int8_t real;
        uint8_t base;
      } u_tilt_health;
      u_tilt_health.real = this->tilt_health;
      *(outbuffer + offset + 0) = (u_tilt_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tilt_health);
      union {
        bool real;
        uint8_t base;
      } u_stairs_requested;
      u_stairs_requested.real = this->stairs_requested;
      *(outbuffer + offset + 0) = (u_stairs_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stairs_requested);
      union {
        bool real;
        uint8_t base;
      } u_user_node_requested;
      u_user_node_requested.real = this->user_node_requested;
      *(outbuffer + offset + 0) = (u_user_node_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_node_requested);
      union {
        bool real;
        uint8_t base;
      } u_mission_node_requested;
      u_mission_node_requested.real = this->mission_node_requested;
      *(outbuffer + offset + 0) = (u_mission_node_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_node_requested);
      union {
        bool real;
        uint8_t base;
      } u_is_exploring;
      u_is_exploring.real = this->is_exploring;
      *(outbuffer + offset + 0) = (u_is_exploring.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_exploring);
      union {
        bool real;
        uint8_t base;
      } u_is_returning;
      u_is_returning.real = this->is_returning;
      *(outbuffer + offset + 0) = (u_is_returning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_returning);
      union {
        bool real;
        uint8_t base;
      } u_is_comm_dropping;
      u_is_comm_dropping.real = this->is_comm_dropping;
      *(outbuffer + offset + 0) = (u_is_comm_dropping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_comm_dropping);
      union {
        bool real;
        uint8_t base;
      } u_is_climbing;
      u_is_climbing.real = this->is_climbing;
      *(outbuffer + offset + 0) = (u_is_climbing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_climbing);
      union {
        int8_t real;
        uint8_t base;
      } u_battery_health;
      u_battery_health.real = this->battery_health;
      *(outbuffer + offset + 0) = (u_battery_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_health);
      union {
        int8_t real;
        uint8_t base;
      } u_ros_node_health;
      u_ros_node_health.real = this->ros_node_health;
      *(outbuffer + offset + 0) = (u_ros_node_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ros_node_health);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor_health;
      u_sensor_health.real = this->sensor_health;
      *(outbuffer + offset + 0) = (u_sensor_health.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_health);
      union {
        int32_t real;
        uint32_t base;
      } u_num_deployed_robots;
      u_num_deployed_robots.real = this->num_deployed_robots;
      *(outbuffer + offset + 0) = (u_num_deployed_robots.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_deployed_robots.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_deployed_robots.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_deployed_robots.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_deployed_robots);
      union {
        int32_t real;
        uint32_t base;
      } u_num_operational_robots;
      u_num_operational_robots.real = this->num_operational_robots;
      *(outbuffer + offset + 0) = (u_num_operational_robots.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_operational_robots.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_operational_robots.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_operational_robots.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_operational_robots);
      *(outbuffer + offset + 0) = (this->total_mission_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->total_mission_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->total_mission_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->total_mission_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_mission_time.sec);
      *(outbuffer + offset + 0) = (this->total_mission_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->total_mission_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->total_mission_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->total_mission_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_mission_time.nsec);
      *(outbuffer + offset + 0) = (this->remaining_mission_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remaining_mission_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remaining_mission_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remaining_mission_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_mission_time.sec);
      *(outbuffer + offset + 0) = (this->remaining_mission_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remaining_mission_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remaining_mission_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remaining_mission_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_mission_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_collision_risk;
      u_has_collision_risk.real = this->has_collision_risk;
      *(outbuffer + offset + 0) = (u_has_collision_risk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_collision_risk);
      *(outbuffer + offset + 0) = (this->nearby_robots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nearby_robots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nearby_robots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nearby_robots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nearby_robots_length);
      for( uint32_t i = 0; i < nearby_robots_length; i++){
      uint32_t length_nearby_robotsi = strlen(this->nearby_robots[i]);
      varToArr(outbuffer + offset, length_nearby_robotsi);
      offset += 4;
      memcpy(outbuffer + offset, this->nearby_robots[i], length_nearby_robotsi);
      offset += length_nearby_robotsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_num_detected_artifacts;
      u_num_detected_artifacts.base = 0;
      u_num_detected_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_detected_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_detected_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_detected_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_detected_artifacts = u_num_detected_artifacts.real;
      offset += sizeof(this->num_detected_artifacts);
      union {
        int32_t real;
        uint32_t base;
      } u_num_unreported_artifacts;
      u_num_unreported_artifacts.base = 0;
      u_num_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_unreported_artifacts = u_num_unreported_artifacts.real;
      offset += sizeof(this->num_unreported_artifacts);
      union {
        int32_t real;
        uint32_t base;
      } u_num_scored_artifacts;
      u_num_scored_artifacts.base = 0;
      u_num_scored_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_scored_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_scored_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_scored_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_scored_artifacts = u_num_scored_artifacts.real;
      offset += sizeof(this->num_scored_artifacts);
      union {
        float real;
        uint32_t base;
      } u_max_confidence_of_unreported_artifacts;
      u_max_confidence_of_unreported_artifacts.base = 0;
      u_max_confidence_of_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_confidence_of_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_confidence_of_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_confidence_of_unreported_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_confidence_of_unreported_artifacts = u_max_confidence_of_unreported_artifacts.real;
      offset += sizeof(this->max_confidence_of_unreported_artifacts);
      union {
        int8_t real;
        uint8_t base;
      } u_comm_health;
      u_comm_health.base = 0;
      u_comm_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->comm_health = u_comm_health.real;
      offset += sizeof(this->comm_health);
      union {
        int32_t real;
        uint32_t base;
      } u_num_loaded_comm_nodes;
      u_num_loaded_comm_nodes.base = 0;
      u_num_loaded_comm_nodes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_loaded_comm_nodes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_loaded_comm_nodes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_loaded_comm_nodes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_loaded_comm_nodes = u_num_loaded_comm_nodes.real;
      offset += sizeof(this->num_loaded_comm_nodes);
      this->time_since_last_connection.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_since_last_connection.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_since_last_connection.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_since_last_connection.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_since_last_connection.sec);
      this->time_since_last_connection.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_since_last_connection.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_since_last_connection.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_since_last_connection.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_since_last_connection.nsec);
      union {
        bool real;
        uint8_t base;
      } u_comm_drop_requested;
      u_comm_drop_requested.base = 0;
      u_comm_drop_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->comm_drop_requested = u_comm_drop_requested.real;
      offset += sizeof(this->comm_drop_requested);
      union {
        int8_t real;
        uint8_t base;
      } u_mobility_health;
      u_mobility_health.base = 0;
      u_mobility_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mobility_health = u_mobility_health.real;
      offset += sizeof(this->mobility_health);
      union {
        int8_t real;
        uint8_t base;
      } u_tilt_health;
      u_tilt_health.base = 0;
      u_tilt_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tilt_health = u_tilt_health.real;
      offset += sizeof(this->tilt_health);
      union {
        bool real;
        uint8_t base;
      } u_stairs_requested;
      u_stairs_requested.base = 0;
      u_stairs_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stairs_requested = u_stairs_requested.real;
      offset += sizeof(this->stairs_requested);
      union {
        bool real;
        uint8_t base;
      } u_user_node_requested;
      u_user_node_requested.base = 0;
      u_user_node_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_node_requested = u_user_node_requested.real;
      offset += sizeof(this->user_node_requested);
      union {
        bool real;
        uint8_t base;
      } u_mission_node_requested;
      u_mission_node_requested.base = 0;
      u_mission_node_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mission_node_requested = u_mission_node_requested.real;
      offset += sizeof(this->mission_node_requested);
      union {
        bool real;
        uint8_t base;
      } u_is_exploring;
      u_is_exploring.base = 0;
      u_is_exploring.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_exploring = u_is_exploring.real;
      offset += sizeof(this->is_exploring);
      union {
        bool real;
        uint8_t base;
      } u_is_returning;
      u_is_returning.base = 0;
      u_is_returning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_returning = u_is_returning.real;
      offset += sizeof(this->is_returning);
      union {
        bool real;
        uint8_t base;
      } u_is_comm_dropping;
      u_is_comm_dropping.base = 0;
      u_is_comm_dropping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_comm_dropping = u_is_comm_dropping.real;
      offset += sizeof(this->is_comm_dropping);
      union {
        bool real;
        uint8_t base;
      } u_is_climbing;
      u_is_climbing.base = 0;
      u_is_climbing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_climbing = u_is_climbing.real;
      offset += sizeof(this->is_climbing);
      union {
        int8_t real;
        uint8_t base;
      } u_battery_health;
      u_battery_health.base = 0;
      u_battery_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_health = u_battery_health.real;
      offset += sizeof(this->battery_health);
      union {
        int8_t real;
        uint8_t base;
      } u_ros_node_health;
      u_ros_node_health.base = 0;
      u_ros_node_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ros_node_health = u_ros_node_health.real;
      offset += sizeof(this->ros_node_health);
      union {
        int8_t real;
        uint8_t base;
      } u_sensor_health;
      u_sensor_health.base = 0;
      u_sensor_health.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_health = u_sensor_health.real;
      offset += sizeof(this->sensor_health);
      union {
        int32_t real;
        uint32_t base;
      } u_num_deployed_robots;
      u_num_deployed_robots.base = 0;
      u_num_deployed_robots.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_deployed_robots.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_deployed_robots.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_deployed_robots.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_deployed_robots = u_num_deployed_robots.real;
      offset += sizeof(this->num_deployed_robots);
      union {
        int32_t real;
        uint32_t base;
      } u_num_operational_robots;
      u_num_operational_robots.base = 0;
      u_num_operational_robots.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_operational_robots.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_operational_robots.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_operational_robots.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_operational_robots = u_num_operational_robots.real;
      offset += sizeof(this->num_operational_robots);
      this->total_mission_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->total_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->total_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->total_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->total_mission_time.sec);
      this->total_mission_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->total_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->total_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->total_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->total_mission_time.nsec);
      this->remaining_mission_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->remaining_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->remaining_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->remaining_mission_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->remaining_mission_time.sec);
      this->remaining_mission_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->remaining_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->remaining_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->remaining_mission_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->remaining_mission_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_collision_risk;
      u_has_collision_risk.base = 0;
      u_has_collision_risk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_collision_risk = u_has_collision_risk.real;
      offset += sizeof(this->has_collision_risk);
      uint32_t nearby_robots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nearby_robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nearby_robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nearby_robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nearby_robots_length);
      if(nearby_robots_lengthT > nearby_robots_length)
        this->nearby_robots = (char**)realloc(this->nearby_robots, nearby_robots_lengthT * sizeof(char*));
      nearby_robots_length = nearby_robots_lengthT;
      for( uint32_t i = 0; i < nearby_robots_length; i++){
      uint32_t length_st_nearby_robots;
      arrToVar(length_st_nearby_robots, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_nearby_robots; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_nearby_robots-1]=0;
      this->st_nearby_robots = (char *)(inbuffer + offset-1);
      offset += length_st_nearby_robots;
        memcpy( &(this->nearby_robots[i]), &(this->st_nearby_robots), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/MissionState"; };
    virtual const char * getMD5() override { return "34ae17342a0cf202dc7af8f17a5d788d"; };

  };

}
#endif
