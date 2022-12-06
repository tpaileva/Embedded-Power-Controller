#ifndef _ROS_spot_msgs_Feedback_h
#define _ROS_spot_msgs_Feedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

  class Feedback : public ros::Msg
  {
    public:
      typedef bool _standing_type;
      _standing_type standing;
      typedef bool _sitting_type;
      _sitting_type sitting;
      typedef bool _moving_type;
      _moving_type moving;
      typedef const char* _serial_number_type;
      _serial_number_type serial_number;
      typedef const char* _species_type;
      _species_type species;
      typedef const char* _version_type;
      _version_type version;
      typedef const char* _nickname_type;
      _nickname_type nickname;
      typedef const char* _computer_serial_number_type;
      _computer_serial_number_type computer_serial_number;

    Feedback():
      standing(0),
      sitting(0),
      moving(0),
      serial_number(""),
      species(""),
      version(""),
      nickname(""),
      computer_serial_number("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_standing;
      u_standing.real = this->standing;
      *(outbuffer + offset + 0) = (u_standing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->standing);
      union {
        bool real;
        uint8_t base;
      } u_sitting;
      u_sitting.real = this->sitting;
      *(outbuffer + offset + 0) = (u_sitting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sitting);
      union {
        bool real;
        uint8_t base;
      } u_moving;
      u_moving.real = this->moving;
      *(outbuffer + offset + 0) = (u_moving.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->moving);
      uint32_t length_serial_number = strlen(this->serial_number);
      varToArr(outbuffer + offset, length_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      uint32_t length_species = strlen(this->species);
      varToArr(outbuffer + offset, length_species);
      offset += 4;
      memcpy(outbuffer + offset, this->species, length_species);
      offset += length_species;
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      uint32_t length_nickname = strlen(this->nickname);
      varToArr(outbuffer + offset, length_nickname);
      offset += 4;
      memcpy(outbuffer + offset, this->nickname, length_nickname);
      offset += length_nickname;
      uint32_t length_computer_serial_number = strlen(this->computer_serial_number);
      varToArr(outbuffer + offset, length_computer_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->computer_serial_number, length_computer_serial_number);
      offset += length_computer_serial_number;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_standing;
      u_standing.base = 0;
      u_standing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->standing = u_standing.real;
      offset += sizeof(this->standing);
      union {
        bool real;
        uint8_t base;
      } u_sitting;
      u_sitting.base = 0;
      u_sitting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sitting = u_sitting.real;
      offset += sizeof(this->sitting);
      union {
        bool real;
        uint8_t base;
      } u_moving;
      u_moving.base = 0;
      u_moving.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->moving = u_moving.real;
      offset += sizeof(this->moving);
      uint32_t length_serial_number;
      arrToVar(length_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
      uint32_t length_species;
      arrToVar(length_species, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_species; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_species-1]=0;
      this->species = (char *)(inbuffer + offset-1);
      offset += length_species;
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      uint32_t length_nickname;
      arrToVar(length_nickname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nickname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nickname-1]=0;
      this->nickname = (char *)(inbuffer + offset-1);
      offset += length_nickname;
      uint32_t length_computer_serial_number;
      arrToVar(length_computer_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_computer_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_computer_serial_number-1]=0;
      this->computer_serial_number = (char *)(inbuffer + offset-1);
      offset += length_computer_serial_number;
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/Feedback"; };
    virtual const char * getMD5() override { return "16779e4df8e3f77c9ee8c1811559bd21"; };

  };

}
#endif
