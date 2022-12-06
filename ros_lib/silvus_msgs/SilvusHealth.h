#ifndef _ROS_silvus_msgs_SilvusHealth_h
#define _ROS_silvus_msgs_SilvusHealth_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace silvus_msgs
{

  class SilvusHealth : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _node_id_type;
      _node_id_type node_id;
      typedef const char* _node_label_type;
      _node_label_type node_label;
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef int32_t _temperature_C_type;
      _temperature_C_type temperature_C;
      typedef float _input_voltage_V_type;
      _input_voltage_V_type input_voltage_V;
      typedef float _battery_percent_type;
      _battery_percent_type battery_percent;
      uint32_t attached_devices_length;
      typedef char* _attached_devices_type;
      _attached_devices_type st_attached_devices;
      _attached_devices_type * attached_devices;

    SilvusHealth():
      header(),
      node_id(0),
      node_label(""),
      robot_name(""),
      temperature_C(0),
      input_voltage_V(0),
      battery_percent(0),
      attached_devices_length(0), st_attached_devices(), attached_devices(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_id);
      uint32_t length_node_label = strlen(this->node_label);
      varToArr(outbuffer + offset, length_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->node_label, length_node_label);
      offset += length_node_label;
      uint32_t length_robot_name = strlen(this->robot_name);
      varToArr(outbuffer + offset, length_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      union {
        int32_t real;
        uint32_t base;
      } u_temperature_C;
      u_temperature_C.real = this->temperature_C;
      *(outbuffer + offset + 0) = (u_temperature_C.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature_C.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature_C.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature_C.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature_C);
      union {
        float real;
        uint32_t base;
      } u_input_voltage_V;
      u_input_voltage_V.real = this->input_voltage_V;
      *(outbuffer + offset + 0) = (u_input_voltage_V.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_voltage_V.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_voltage_V.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_voltage_V.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_voltage_V);
      union {
        float real;
        uint32_t base;
      } u_battery_percent;
      u_battery_percent.real = this->battery_percent;
      *(outbuffer + offset + 0) = (u_battery_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_percent);
      *(outbuffer + offset + 0) = (this->attached_devices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attached_devices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attached_devices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attached_devices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attached_devices_length);
      for( uint32_t i = 0; i < attached_devices_length; i++){
      uint32_t length_attached_devicesi = strlen(this->attached_devices[i]);
      varToArr(outbuffer + offset, length_attached_devicesi);
      offset += 4;
      memcpy(outbuffer + offset, this->attached_devices[i], length_attached_devicesi);
      offset += length_attached_devicesi;
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
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
      uint32_t length_node_label;
      arrToVar(length_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_label-1]=0;
      this->node_label = (char *)(inbuffer + offset-1);
      offset += length_node_label;
      uint32_t length_robot_name;
      arrToVar(length_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      union {
        int32_t real;
        uint32_t base;
      } u_temperature_C;
      u_temperature_C.base = 0;
      u_temperature_C.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature_C.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature_C.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature_C.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature_C = u_temperature_C.real;
      offset += sizeof(this->temperature_C);
      union {
        float real;
        uint32_t base;
      } u_input_voltage_V;
      u_input_voltage_V.base = 0;
      u_input_voltage_V.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_voltage_V.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_voltage_V.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_voltage_V.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_voltage_V = u_input_voltage_V.real;
      offset += sizeof(this->input_voltage_V);
      union {
        float real;
        uint32_t base;
      } u_battery_percent;
      u_battery_percent.base = 0;
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_percent = u_battery_percent.real;
      offset += sizeof(this->battery_percent);
      uint32_t attached_devices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attached_devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attached_devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attached_devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attached_devices_length);
      if(attached_devices_lengthT > attached_devices_length)
        this->attached_devices = (char**)realloc(this->attached_devices, attached_devices_lengthT * sizeof(char*));
      attached_devices_length = attached_devices_lengthT;
      for( uint32_t i = 0; i < attached_devices_length; i++){
      uint32_t length_st_attached_devices;
      arrToVar(length_st_attached_devices, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_attached_devices; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_attached_devices-1]=0;
      this->st_attached_devices = (char *)(inbuffer + offset-1);
      offset += length_st_attached_devices;
        memcpy( &(this->attached_devices[i]), &(this->st_attached_devices), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusHealth"; };
    virtual const char * getMD5() override { return "1295beb8eaefaede05db42cc694142b5"; };

  };

}
#endif
