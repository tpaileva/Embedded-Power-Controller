#ifndef _ROS_spot_msgs_BatteryState_h
#define _ROS_spot_msgs_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace spot_msgs
{

  class BatteryState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _identifier_type;
      _identifier_type identifier;
      typedef double _charge_percentage_type;
      _charge_percentage_type charge_percentage;
      typedef ros::Duration _estimated_runtime_type;
      _estimated_runtime_type estimated_runtime;
      typedef double _current_type;
      _current_type current;
      typedef double _voltage_type;
      _voltage_type voltage;
      uint32_t temperatures_length;
      typedef double _temperatures_type;
      _temperatures_type st_temperatures;
      _temperatures_type * temperatures;
      typedef uint8_t _status_type;
      _status_type status;
      enum { STATUS_UNKNOWN =  0 };
      enum { STATUS_MISSING =  1 };
      enum { STATUS_CHARGING =  2 };
      enum { STATUS_DISCHARGING =  3 };
      enum { STATUS_BOOTING =  4 };

    BatteryState():
      header(),
      identifier(""),
      charge_percentage(0),
      estimated_runtime(),
      current(0),
      voltage(0),
      temperatures_length(0), st_temperatures(), temperatures(nullptr),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_identifier = strlen(this->identifier);
      varToArr(outbuffer + offset, length_identifier);
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      union {
        double real;
        uint64_t base;
      } u_charge_percentage;
      u_charge_percentage.real = this->charge_percentage;
      *(outbuffer + offset + 0) = (u_charge_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_percentage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charge_percentage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charge_percentage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charge_percentage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charge_percentage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charge_percentage);
      *(outbuffer + offset + 0) = (this->estimated_runtime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimated_runtime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimated_runtime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimated_runtime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_runtime.sec);
      *(outbuffer + offset + 0) = (this->estimated_runtime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimated_runtime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimated_runtime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimated_runtime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_runtime.nsec);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->voltage);
      *(outbuffer + offset + 0) = (this->temperatures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperatures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperatures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperatures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperatures_length);
      for( uint32_t i = 0; i < temperatures_length; i++){
      union {
        double real;
        uint64_t base;
      } u_temperaturesi;
      u_temperaturesi.real = this->temperatures[i];
      *(outbuffer + offset + 0) = (u_temperaturesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperaturesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperaturesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperaturesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperaturesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperaturesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperaturesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperaturesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperatures[i]);
      }
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_identifier;
      arrToVar(length_identifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
      union {
        double real;
        uint64_t base;
      } u_charge_percentage;
      u_charge_percentage.base = 0;
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charge_percentage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charge_percentage = u_charge_percentage.real;
      offset += sizeof(this->charge_percentage);
      this->estimated_runtime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimated_runtime.sec);
      this->estimated_runtime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimated_runtime.nsec);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      uint32_t temperatures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temperatures_length);
      if(temperatures_lengthT > temperatures_length)
        this->temperatures = (double*)realloc(this->temperatures, temperatures_lengthT * sizeof(double));
      temperatures_length = temperatures_lengthT;
      for( uint32_t i = 0; i < temperatures_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_temperatures;
      u_st_temperatures.base = 0;
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_temperatures = u_st_temperatures.real;
      offset += sizeof(this->st_temperatures);
        memcpy( &(this->temperatures[i]), &(this->st_temperatures), sizeof(double));
      }
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/BatteryState"; };
    virtual const char * getMD5() override { return "d4f77065e2805bf6a288541cb5a848ce"; };

  };

}
#endif
