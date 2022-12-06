#ifndef _ROS_spot_msgs_EStopState_h
#define _ROS_spot_msgs_EStopState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace spot_msgs
{

  class EStopState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _state_type;
      _state_type state;
      typedef const char* _state_description_type;
      _state_description_type state_description;
      enum { TYPE_UNKNOWN =  0 };
      enum { TYPE_HARDWARE =  1 };
      enum { TYPE_SOFTWARE =  2 };
      enum { STATE_UNKNOWN =  0 };
      enum { STATE_ESTOPPED =  1 };
      enum { STATE_NOT_ESTOPPED =  2 };

    EStopState():
      header(),
      name(""),
      type(0),
      state(0),
      state_description("")
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
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      uint32_t length_state_description = strlen(this->state_description);
      varToArr(outbuffer + offset, length_state_description);
      offset += 4;
      memcpy(outbuffer + offset, this->state_description, length_state_description);
      offset += length_state_description;
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
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      uint32_t length_state_description;
      arrToVar(length_state_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_description-1]=0;
      this->state_description = (char *)(inbuffer + offset-1);
      offset += length_state_description;
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/EStopState"; };
    virtual const char * getMD5() override { return "4e1a419eb9800cdac35ecfe372fcc725"; };

  };

}
#endif
