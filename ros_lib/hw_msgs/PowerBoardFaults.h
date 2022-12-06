#ifndef _ROS_hw_msgs_PowerBoardFaults_h
#define _ROS_hw_msgs_PowerBoardFaults_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hw_msgs
{

  class PowerBoardFaults : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _powerFault_type;
      _powerFault_type powerFault;
      typedef uint8_t _faultSeverity_type;
      _faultSeverity_type faultSeverity;
      typedef uint8_t _battAlarm_type;
      _battAlarm_type battAlarm;

    PowerBoardFaults():
      header(),
      powerFault(0),
      faultSeverity(0),
      battAlarm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->powerFault >> (8 * 0)) & 0xFF;
      offset += sizeof(this->powerFault);
      *(outbuffer + offset + 0) = (this->faultSeverity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->faultSeverity);
      *(outbuffer + offset + 0) = (this->battAlarm >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battAlarm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->powerFault =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->powerFault);
      this->faultSeverity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->faultSeverity);
      this->battAlarm =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->battAlarm);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/PowerBoardFaults"; };
    virtual const char * getMD5() override { return "f41daebda8e10abf9b5c454c0620aadb"; };

  };

}
#endif
