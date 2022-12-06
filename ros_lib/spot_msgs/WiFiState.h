#ifndef _ROS_spot_msgs_WiFiState_h
#define _ROS_spot_msgs_WiFiState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

  class WiFiState : public ros::Msg
  {
    public:
      typedef uint8_t _current_mode_type;
      _current_mode_type current_mode;
      typedef const char* _essid_type;
      _essid_type essid;
      enum { MODE_UNKNOWN =  0 };
      enum { MODE_ACCESS_POINT =  1 };
      enum { MODE_CLIENT =  2 };

    WiFiState():
      current_mode(0),
      essid("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->current_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_mode);
      uint32_t length_essid = strlen(this->essid);
      varToArr(outbuffer + offset, length_essid);
      offset += 4;
      memcpy(outbuffer + offset, this->essid, length_essid);
      offset += length_essid;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->current_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_mode);
      uint32_t length_essid;
      arrToVar(length_essid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_essid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_essid-1]=0;
      this->essid = (char *)(inbuffer + offset-1);
      offset += length_essid;
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/WiFiState"; };
    virtual const char * getMD5() override { return "ba66be2de3368e3a5a22e1ccf928954a"; };

  };

}
#endif
