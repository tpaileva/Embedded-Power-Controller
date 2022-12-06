#ifndef _ROS_spot_msgs_BehaviorFault_h
#define _ROS_spot_msgs_BehaviorFault_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace spot_msgs
{

  class BehaviorFault : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _behavior_fault_id_type;
      _behavior_fault_id_type behavior_fault_id;
      typedef uint8_t _cause_type;
      _cause_type cause;
      typedef uint8_t _status_type;
      _status_type status;
      enum { CAUSE_UNKNOWN =  0 };
      enum { CAUSE_FALL =  1 };
      enum { CAUSE_HARDWARE =  2 };
      enum { STATUS_UNKNOWN =  0 };
      enum { STATUS_CLEARABLE =  1 };
      enum { STATUS_UNCLEARABLE =  2 };

    BehaviorFault():
      header(),
      behavior_fault_id(0),
      cause(0),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->behavior_fault_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->behavior_fault_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->behavior_fault_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->behavior_fault_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->behavior_fault_id);
      *(outbuffer + offset + 0) = (this->cause >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cause);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->behavior_fault_id =  ((uint32_t) (*(inbuffer + offset)));
      this->behavior_fault_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->behavior_fault_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->behavior_fault_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->behavior_fault_id);
      this->cause =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cause);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/BehaviorFault"; };
    virtual const char * getMD5() override { return "849048e719811a4f2cf68e276a235d76"; };

  };

}
#endif
