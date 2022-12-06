#ifndef _ROS_copilot_msgs_DialogueResponse_h
#define _ROS_copilot_msgs_DialogueResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace copilot_msgs
{

  class DialogueResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _response_id_type;
      _response_id_type response_id;
      typedef const char* _response_origin_type;
      _response_origin_type response_origin;
      typedef bool _response_type;
      _response_type response;

    DialogueResponse():
      header(),
      response_id(""),
      response_origin(""),
      response(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_response_id = strlen(this->response_id);
      varToArr(outbuffer + offset, length_response_id);
      offset += 4;
      memcpy(outbuffer + offset, this->response_id, length_response_id);
      offset += length_response_id;
      uint32_t length_response_origin = strlen(this->response_origin);
      varToArr(outbuffer + offset, length_response_origin);
      offset += 4;
      memcpy(outbuffer + offset, this->response_origin, length_response_origin);
      offset += length_response_origin;
      union {
        bool real;
        uint8_t base;
      } u_response;
      u_response.real = this->response;
      *(outbuffer + offset + 0) = (u_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->response);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_response_id;
      arrToVar(length_response_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response_id-1]=0;
      this->response_id = (char *)(inbuffer + offset-1);
      offset += length_response_id;
      uint32_t length_response_origin;
      arrToVar(length_response_origin, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response_origin; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response_origin-1]=0;
      this->response_origin = (char *)(inbuffer + offset-1);
      offset += length_response_origin;
      union {
        bool real;
        uint8_t base;
      } u_response;
      u_response.base = 0;
      u_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->response = u_response.real;
      offset += sizeof(this->response);
     return offset;
    }

    virtual const char * getType() override { return "copilot_msgs/DialogueResponse"; };
    virtual const char * getMD5() override { return "2d302c29f4e987c5c698a6181e2449bc"; };

  };

}
#endif
