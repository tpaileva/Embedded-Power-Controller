#ifndef _ROS_spot_msgs_PowerState_h
#define _ROS_spot_msgs_PowerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace spot_msgs
{

  class PowerState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _motor_power_state_type;
      _motor_power_state_type motor_power_state;
      typedef uint8_t _shore_power_state_type;
      _shore_power_state_type shore_power_state;
      typedef double _locomotion_charge_percentage_type;
      _locomotion_charge_percentage_type locomotion_charge_percentage;
      typedef ros::Duration _locomotion_estimated_runtime_type;
      _locomotion_estimated_runtime_type locomotion_estimated_runtime;
      enum { STATE_UNKNOWN =  0 };
      enum { STATE_OFF =  1 };
      enum { STATE_ON =  2 };
      enum { STATE_POWERING_ON =  3 };
      enum { STATE_POWERING_OFF =  4 };
      enum { STATE_ERROR =  5 };
      enum { STATE_UNKNOWN_SHORE_POWER =  0 };
      enum { STATE_ON_SHORE_POWER =  1 };
      enum { STATE_OFF_SHORE_POWER =  2 };

    PowerState():
      header(),
      motor_power_state(0),
      shore_power_state(0),
      locomotion_charge_percentage(0),
      locomotion_estimated_runtime()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->motor_power_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_power_state);
      *(outbuffer + offset + 0) = (this->shore_power_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shore_power_state);
      union {
        double real;
        uint64_t base;
      } u_locomotion_charge_percentage;
      u_locomotion_charge_percentage.real = this->locomotion_charge_percentage;
      *(outbuffer + offset + 0) = (u_locomotion_charge_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_locomotion_charge_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_locomotion_charge_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_locomotion_charge_percentage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_locomotion_charge_percentage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_locomotion_charge_percentage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_locomotion_charge_percentage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_locomotion_charge_percentage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->locomotion_charge_percentage);
      *(outbuffer + offset + 0) = (this->locomotion_estimated_runtime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locomotion_estimated_runtime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locomotion_estimated_runtime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locomotion_estimated_runtime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locomotion_estimated_runtime.sec);
      *(outbuffer + offset + 0) = (this->locomotion_estimated_runtime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locomotion_estimated_runtime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locomotion_estimated_runtime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locomotion_estimated_runtime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locomotion_estimated_runtime.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->motor_power_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_power_state);
      this->shore_power_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->shore_power_state);
      union {
        double real;
        uint64_t base;
      } u_locomotion_charge_percentage;
      u_locomotion_charge_percentage.base = 0;
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_locomotion_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->locomotion_charge_percentage = u_locomotion_charge_percentage.real;
      offset += sizeof(this->locomotion_charge_percentage);
      this->locomotion_estimated_runtime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->locomotion_estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->locomotion_estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->locomotion_estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->locomotion_estimated_runtime.sec);
      this->locomotion_estimated_runtime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->locomotion_estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->locomotion_estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->locomotion_estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->locomotion_estimated_runtime.nsec);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/PowerState"; };
    virtual const char * getMD5() override { return "1248df72d2f23288441e3a23d09bd4f0"; };

  };

}
#endif
