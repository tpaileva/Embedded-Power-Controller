#ifndef _ROS_SERVICE_GetPathStatistics_h
#define _ROS_SERVICE_GetPathStatistics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"

namespace mobility_msgs
{

static const char GETPATHSTATISTICS[] = "mobility_msgs/GetPathStatistics";

  class GetPathStatisticsRequest : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;

    GetPathStatisticsRequest():
      path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPATHSTATISTICS; };
    virtual const char * getMD5() override { return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

  class GetPathStatisticsResponse : public ros::Msg
  {
    public:
      typedef float _mean_type;
      _mean_type mean;
      typedef float _stdev_type;
      _stdev_type stdev;
      typedef float _median_type;
      _median_type median;
      typedef float _max_type;
      _max_type max;
      typedef float _min_type;
      _min_type min;
      typedef float _cost_path_integral_type;
      _cost_path_integral_type cost_path_integral;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _distance_xy_type;
      _distance_xy_type distance_xy;

    GetPathStatisticsResponse():
      mean(0),
      stdev(0),
      median(0),
      max(0),
      min(0),
      cost_path_integral(0),
      distance(0),
      distance_xy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.real = this->mean;
      *(outbuffer + offset + 0) = (u_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_stdev;
      u_stdev.real = this->stdev;
      *(outbuffer + offset + 0) = (u_stdev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stdev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stdev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stdev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stdev);
      union {
        float real;
        uint32_t base;
      } u_median;
      u_median.real = this->median;
      *(outbuffer + offset + 0) = (u_median.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_median.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_median.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_median.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->median);
      union {
        float real;
        uint32_t base;
      } u_max;
      u_max.real = this->max;
      *(outbuffer + offset + 0) = (u_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max);
      union {
        float real;
        uint32_t base;
      } u_min;
      u_min.real = this->min;
      *(outbuffer + offset + 0) = (u_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min);
      union {
        float real;
        uint32_t base;
      } u_cost_path_integral;
      u_cost_path_integral.real = this->cost_path_integral;
      *(outbuffer + offset + 0) = (u_cost_path_integral.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cost_path_integral.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cost_path_integral.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cost_path_integral.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cost_path_integral);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_distance_xy;
      u_distance_xy.real = this->distance_xy;
      *(outbuffer + offset + 0) = (u_distance_xy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_xy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_xy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_xy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_xy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.base = 0;
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mean = u_mean.real;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_stdev;
      u_stdev.base = 0;
      u_stdev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stdev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stdev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stdev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stdev = u_stdev.real;
      offset += sizeof(this->stdev);
      union {
        float real;
        uint32_t base;
      } u_median;
      u_median.base = 0;
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->median = u_median.real;
      offset += sizeof(this->median);
      union {
        float real;
        uint32_t base;
      } u_max;
      u_max.base = 0;
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max = u_max.real;
      offset += sizeof(this->max);
      union {
        float real;
        uint32_t base;
      } u_min;
      u_min.base = 0;
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min = u_min.real;
      offset += sizeof(this->min);
      union {
        float real;
        uint32_t base;
      } u_cost_path_integral;
      u_cost_path_integral.base = 0;
      u_cost_path_integral.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cost_path_integral.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cost_path_integral.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cost_path_integral.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cost_path_integral = u_cost_path_integral.real;
      offset += sizeof(this->cost_path_integral);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_distance_xy;
      u_distance_xy.base = 0;
      u_distance_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_xy = u_distance_xy.real;
      offset += sizeof(this->distance_xy);
     return offset;
    }

    virtual const char * getType() override { return GETPATHSTATISTICS; };
    virtual const char * getMD5() override { return "0e7782455079c53d9fb94f93bb3d7f38"; };

  };

  class GetPathStatistics {
    public:
    typedef GetPathStatisticsRequest Request;
    typedef GetPathStatisticsResponse Response;
  };

}
#endif
