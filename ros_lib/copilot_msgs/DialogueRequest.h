#ifndef _ROS_copilot_msgs_DialogueRequest_h
#define _ROS_copilot_msgs_DialogueRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace copilot_msgs
{

  class DialogueRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _request_id_type;
      _request_id_type request_id;
      typedef const char* _request_origin_type;
      _request_origin_type request_origin;
      typedef int16_t _request_priority_type;
      _request_priority_type request_priority;
      typedef const char* _request_type_type;
      _request_type_type request_type;
      typedef bool _response_needed_type;
      _response_needed_type response_needed;
      typedef int16_t _request_timeout_type;
      _request_timeout_type request_timeout;
      typedef bool _delete_previous_requests_type;
      _delete_previous_requests_type delete_previous_requests;
      typedef const char* _request_msg_type;
      _request_msg_type request_msg;

    DialogueRequest():
      header(),
      request_id(""),
      request_origin(""),
      request_priority(0),
      request_type(""),
      response_needed(0),
      request_timeout(0),
      delete_previous_requests(0),
      request_msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_request_id = strlen(this->request_id);
      varToArr(outbuffer + offset, length_request_id);
      offset += 4;
      memcpy(outbuffer + offset, this->request_id, length_request_id);
      offset += length_request_id;
      uint32_t length_request_origin = strlen(this->request_origin);
      varToArr(outbuffer + offset, length_request_origin);
      offset += 4;
      memcpy(outbuffer + offset, this->request_origin, length_request_origin);
      offset += length_request_origin;
      union {
        int16_t real;
        uint16_t base;
      } u_request_priority;
      u_request_priority.real = this->request_priority;
      *(outbuffer + offset + 0) = (u_request_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_request_priority.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->request_priority);
      uint32_t length_request_type = strlen(this->request_type);
      varToArr(outbuffer + offset, length_request_type);
      offset += 4;
      memcpy(outbuffer + offset, this->request_type, length_request_type);
      offset += length_request_type;
      union {
        bool real;
        uint8_t base;
      } u_response_needed;
      u_response_needed.real = this->response_needed;
      *(outbuffer + offset + 0) = (u_response_needed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->response_needed);
      union {
        int16_t real;
        uint16_t base;
      } u_request_timeout;
      u_request_timeout.real = this->request_timeout;
      *(outbuffer + offset + 0) = (u_request_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_request_timeout.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->request_timeout);
      union {
        bool real;
        uint8_t base;
      } u_delete_previous_requests;
      u_delete_previous_requests.real = this->delete_previous_requests;
      *(outbuffer + offset + 0) = (u_delete_previous_requests.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->delete_previous_requests);
      uint32_t length_request_msg = strlen(this->request_msg);
      varToArr(outbuffer + offset, length_request_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->request_msg, length_request_msg);
      offset += length_request_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_request_id;
      arrToVar(length_request_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_id-1]=0;
      this->request_id = (char *)(inbuffer + offset-1);
      offset += length_request_id;
      uint32_t length_request_origin;
      arrToVar(length_request_origin, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_origin; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_origin-1]=0;
      this->request_origin = (char *)(inbuffer + offset-1);
      offset += length_request_origin;
      union {
        int16_t real;
        uint16_t base;
      } u_request_priority;
      u_request_priority.base = 0;
      u_request_priority.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_request_priority.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->request_priority = u_request_priority.real;
      offset += sizeof(this->request_priority);
      uint32_t length_request_type;
      arrToVar(length_request_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_type-1]=0;
      this->request_type = (char *)(inbuffer + offset-1);
      offset += length_request_type;
      union {
        bool real;
        uint8_t base;
      } u_response_needed;
      u_response_needed.base = 0;
      u_response_needed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->response_needed = u_response_needed.real;
      offset += sizeof(this->response_needed);
      union {
        int16_t real;
        uint16_t base;
      } u_request_timeout;
      u_request_timeout.base = 0;
      u_request_timeout.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_request_timeout.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->request_timeout = u_request_timeout.real;
      offset += sizeof(this->request_timeout);
      union {
        bool real;
        uint8_t base;
      } u_delete_previous_requests;
      u_delete_previous_requests.base = 0;
      u_delete_previous_requests.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->delete_previous_requests = u_delete_previous_requests.real;
      offset += sizeof(this->delete_previous_requests);
      uint32_t length_request_msg;
      arrToVar(length_request_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_msg-1]=0;
      this->request_msg = (char *)(inbuffer + offset-1);
      offset += length_request_msg;
     return offset;
    }

    virtual const char * getType() override { return "copilot_msgs/DialogueRequest"; };
    virtual const char * getMD5() override { return "a6d2691f473c8419eddd1b4ac8fc0e55"; };

  };

}
#endif
