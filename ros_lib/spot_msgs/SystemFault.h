#ifndef _ROS_spot_msgs_SystemFault_h
#define _ROS_spot_msgs_SystemFault_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace spot_msgs
{

  class SystemFault : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef ros::Duration _duration_type;
      _duration_type duration;
      typedef int32_t _code_type;
      _code_type code;
      typedef uint64_t _uid_type;
      _uid_type uid;
      typedef const char* _error_message_type;
      _error_message_type error_message;
      uint32_t attributes_length;
      typedef char* _attributes_type;
      _attributes_type st_attributes;
      _attributes_type * attributes;
      typedef uint8_t _severity_type;
      _severity_type severity;
      enum { SEVERITY_UNKNOWN =  0 };
      enum { SEVERITY_INFO =  1 };
      enum { SEVERITY_WARN =  2 };
      enum { SEVERITY_CRITICAL =  3 };

    SystemFault():
      header(),
      name(""),
      duration(),
      code(0),
      uid(0),
      error_message(""),
      attributes_length(0), st_attributes(), attributes(nullptr),
      severity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_code;
      u_code.real = this->code;
      *(outbuffer + offset + 0) = (u_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->code);
      union {
        uint64_t real;
        uint32_t base;
      } u_uid;
      u_uid.real = this->uid;
      *(outbuffer + offset + 0) = (u_uid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uid);
      uint32_t length_error_message = strlen(this->error_message);
      varToArr(outbuffer + offset, length_error_message);
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      *(outbuffer + offset + 0) = (this->attributes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attributes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attributes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attributes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attributes_length);
      for( uint32_t i = 0; i < attributes_length; i++){
      uint32_t length_attributesi = strlen(this->attributes[i]);
      varToArr(outbuffer + offset, length_attributesi);
      offset += 4;
      memcpy(outbuffer + offset, this->attributes[i], length_attributesi);
      offset += length_attributesi;
      }
      *(outbuffer + offset + 0) = (this->severity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->severity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_code;
      u_code.base = 0;
      u_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->code = u_code.real;
      offset += sizeof(this->code);
      union {
        uint64_t real;
        uint32_t base;
      } u_uid;
      u_uid.base = 0;
      u_uid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->uid = u_uid.real;
      offset += sizeof(this->uid);
      uint32_t length_error_message;
      arrToVar(length_error_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
      uint32_t attributes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attributes_length);
      if(attributes_lengthT > attributes_length)
        this->attributes = (char**)realloc(this->attributes, attributes_lengthT * sizeof(char*));
      attributes_length = attributes_lengthT;
      for( uint32_t i = 0; i < attributes_length; i++){
      uint32_t length_st_attributes;
      arrToVar(length_st_attributes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_attributes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_attributes-1]=0;
      this->st_attributes = (char *)(inbuffer + offset-1);
      offset += length_st_attributes;
        memcpy( &(this->attributes[i]), &(this->st_attributes), sizeof(char*));
      }
      this->severity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->severity);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/SystemFault"; };
    virtual const char * getMD5() override { return "d4409a7e7087c0e4485ccf8e05022a5d"; };

  };

}
#endif
