#ifndef _ROS_copilot_msgs_DialogueRequestList_h
#define _ROS_copilot_msgs_DialogueRequestList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "copilot_msgs/DialogueRequest.h"

namespace copilot_msgs
{

  class DialogueRequestList : public ros::Msg
  {
    public:
      uint32_t dialogue_request_list_length;
      typedef copilot_msgs::DialogueRequest _dialogue_request_list_type;
      _dialogue_request_list_type st_dialogue_request_list;
      _dialogue_request_list_type * dialogue_request_list;

    DialogueRequestList():
      dialogue_request_list_length(0), st_dialogue_request_list(), dialogue_request_list(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->dialogue_request_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dialogue_request_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dialogue_request_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dialogue_request_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dialogue_request_list_length);
      for( uint32_t i = 0; i < dialogue_request_list_length; i++){
      offset += this->dialogue_request_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t dialogue_request_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dialogue_request_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dialogue_request_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dialogue_request_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dialogue_request_list_length);
      if(dialogue_request_list_lengthT > dialogue_request_list_length)
        this->dialogue_request_list = (copilot_msgs::DialogueRequest*)realloc(this->dialogue_request_list, dialogue_request_list_lengthT * sizeof(copilot_msgs::DialogueRequest));
      dialogue_request_list_length = dialogue_request_list_lengthT;
      for( uint32_t i = 0; i < dialogue_request_list_length; i++){
      offset += this->st_dialogue_request_list.deserialize(inbuffer + offset);
        memcpy( &(this->dialogue_request_list[i]), &(this->st_dialogue_request_list), sizeof(copilot_msgs::DialogueRequest));
      }
     return offset;
    }

    virtual const char * getType() override { return "copilot_msgs/DialogueRequestList"; };
    virtual const char * getMD5() override { return "7281b1a1858f3eba1626f9ca075d15f7"; };

  };

}
#endif
