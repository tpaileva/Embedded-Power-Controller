#ifndef _ROS_mission_msgs_BaseMissionState_h
#define _ROS_mission_msgs_BaseMissionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace mission_msgs
{

  class BaseMissionState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _num_detected_artifacts_type;
      _num_detected_artifacts_type num_detected_artifacts;
      typedef int32_t _num_submitted_artifacts_type;
      _num_submitted_artifacts_type num_submitted_artifacts;
      typedef int32_t _num_scored_artifacts_type;
      _num_scored_artifacts_type num_scored_artifacts;
      typedef int32_t _num_remaining_submissions_type;
      _num_remaining_submissions_type num_remaining_submissions;
      typedef int32_t _num_deployed_robots_type;
      _num_deployed_robots_type num_deployed_robots;
      typedef int32_t _num_operational_robots_type;
      _num_operational_robots_type num_operational_robots;
      typedef ros::Duration _total_mission_time_type;
      _total_mission_time_type total_mission_time;
      typedef ros::Duration _remaining_mission_time_type;
      _remaining_mission_time_type remaining_mission_time;

    BaseMissionState():
      header(),
      num_detected_artifacts(0),
      num_submitted_artifacts(0),
      num_scored_artifacts(0),
      num_remaining_submissions(0),
      num_deployed_robots(0),
      num_operational_robots(0),
      total_mission_time(),
      remaining_mission_time()
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
      } u_num_submitted_artifacts;
      u_num_submitted_artifacts.real = this->num_submitted_artifacts;
      *(outbuffer + offset + 0) = (u_num_submitted_artifacts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_submitted_artifacts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_submitted_artifacts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_submitted_artifacts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_submitted_artifacts);
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
        int32_t real;
        uint32_t base;
      } u_num_remaining_submissions;
      u_num_remaining_submissions.real = this->num_remaining_submissions;
      *(outbuffer + offset + 0) = (u_num_remaining_submissions.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_remaining_submissions.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_remaining_submissions.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_remaining_submissions.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_remaining_submissions);
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
      } u_num_submitted_artifacts;
      u_num_submitted_artifacts.base = 0;
      u_num_submitted_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_submitted_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_submitted_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_submitted_artifacts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_submitted_artifacts = u_num_submitted_artifacts.real;
      offset += sizeof(this->num_submitted_artifacts);
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
        int32_t real;
        uint32_t base;
      } u_num_remaining_submissions;
      u_num_remaining_submissions.base = 0;
      u_num_remaining_submissions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_remaining_submissions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_remaining_submissions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_remaining_submissions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_remaining_submissions = u_num_remaining_submissions.real;
      offset += sizeof(this->num_remaining_submissions);
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
     return offset;
    }

    virtual const char * getType() override { return "mission_msgs/BaseMissionState"; };
    virtual const char * getMD5() override { return "ed1a383affbddb4e31c0f5bd7d11070a"; };

  };

}
#endif
