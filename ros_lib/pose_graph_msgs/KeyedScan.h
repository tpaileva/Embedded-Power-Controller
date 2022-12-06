#ifndef _ROS_pose_graph_msgs_KeyedScan_h
#define _ROS_pose_graph_msgs_KeyedScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace pose_graph_msgs
{

  class KeyedScan : public ros::Msg
  {
    public:
      typedef uint64_t _key_type;
      _key_type key;
      typedef sensor_msgs::PointCloud2 _scan_type;
      _scan_type scan;

    KeyedScan():
      key(0),
      scan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_key;
      u_key.real = this->key;
      *(outbuffer + offset + 0) = (u_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key);
      offset += this->scan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_key;
      u_key.base = 0;
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key = u_key.real;
      offset += sizeof(this->key);
      offset += this->scan.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "pose_graph_msgs/KeyedScan"; };
    virtual const char * getMD5() override { return "4038d31be231d130b6ea4e485e3d4e6a"; };

  };

}
#endif
