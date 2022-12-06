#ifndef _ROS_copilot_msgs_CopilotSchedulerPerformance_h
#define _ROS_copilot_msgs_CopilotSchedulerPerformance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace copilot_msgs
{

  class CopilotSchedulerPerformance : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _scheduler_input_type;
      _scheduler_input_type scheduler_input;
      typedef double _scheduler_clock_type;
      _scheduler_clock_type scheduler_clock;
      typedef double _scheduler_solve_start_time_type;
      _scheduler_solve_start_time_type scheduler_solve_start_time;
      typedef double _scheduler_solve_duration_type;
      _scheduler_solve_duration_type scheduler_solve_duration;

    CopilotSchedulerPerformance():
      header(),
      scheduler_input(""),
      scheduler_clock(0),
      scheduler_solve_start_time(0),
      scheduler_solve_duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_scheduler_input = strlen(this->scheduler_input);
      varToArr(outbuffer + offset, length_scheduler_input);
      offset += 4;
      memcpy(outbuffer + offset, this->scheduler_input, length_scheduler_input);
      offset += length_scheduler_input;
      union {
        double real;
        uint64_t base;
      } u_scheduler_clock;
      u_scheduler_clock.real = this->scheduler_clock;
      *(outbuffer + offset + 0) = (u_scheduler_clock.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scheduler_clock.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scheduler_clock.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scheduler_clock.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_scheduler_clock.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_scheduler_clock.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_scheduler_clock.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_scheduler_clock.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->scheduler_clock);
      union {
        double real;
        uint64_t base;
      } u_scheduler_solve_start_time;
      u_scheduler_solve_start_time.real = this->scheduler_solve_start_time;
      *(outbuffer + offset + 0) = (u_scheduler_solve_start_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scheduler_solve_start_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scheduler_solve_start_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scheduler_solve_start_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_scheduler_solve_start_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_scheduler_solve_start_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_scheduler_solve_start_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_scheduler_solve_start_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->scheduler_solve_start_time);
      union {
        double real;
        uint64_t base;
      } u_scheduler_solve_duration;
      u_scheduler_solve_duration.real = this->scheduler_solve_duration;
      *(outbuffer + offset + 0) = (u_scheduler_solve_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scheduler_solve_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scheduler_solve_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scheduler_solve_duration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_scheduler_solve_duration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_scheduler_solve_duration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_scheduler_solve_duration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_scheduler_solve_duration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->scheduler_solve_duration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_scheduler_input;
      arrToVar(length_scheduler_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_scheduler_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_scheduler_input-1]=0;
      this->scheduler_input = (char *)(inbuffer + offset-1);
      offset += length_scheduler_input;
      union {
        double real;
        uint64_t base;
      } u_scheduler_clock;
      u_scheduler_clock.base = 0;
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_scheduler_clock.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->scheduler_clock = u_scheduler_clock.real;
      offset += sizeof(this->scheduler_clock);
      union {
        double real;
        uint64_t base;
      } u_scheduler_solve_start_time;
      u_scheduler_solve_start_time.base = 0;
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_scheduler_solve_start_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->scheduler_solve_start_time = u_scheduler_solve_start_time.real;
      offset += sizeof(this->scheduler_solve_start_time);
      union {
        double real;
        uint64_t base;
      } u_scheduler_solve_duration;
      u_scheduler_solve_duration.base = 0;
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_scheduler_solve_duration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->scheduler_solve_duration = u_scheduler_solve_duration.real;
      offset += sizeof(this->scheduler_solve_duration);
     return offset;
    }

    virtual const char * getType() override { return "copilot_msgs/CopilotSchedulerPerformance"; };
    virtual const char * getMD5() override { return "1cdf9833585c5980c0ad79d112a0cf1d"; };

  };

}
#endif
