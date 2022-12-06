#ifndef _ROS_hw_msgs_CommNodeStatus_h
#define _ROS_hw_msgs_CommNodeStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hw_msgs
{

  class CommNodeStatus : public ros::Msg
  {
    public:
      typedef const char* _NodeState_type;
      _NodeState_type NodeState;
      typedef uint32_t _NodeErrors_type;
      _NodeErrors_type NodeErrors;
      typedef uint16_t _ServoState_type;
      _ServoState_type ServoState;
      typedef uint16_t _DropState_type;
      _DropState_type DropState;
      typedef uint16_t _SwitchState_type;
      _SwitchState_type SwitchState;

    CommNodeStatus():
      NodeState(""),
      NodeErrors(0),
      ServoState(0),
      DropState(0),
      SwitchState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_NodeState = strlen(this->NodeState);
      varToArr(outbuffer + offset, length_NodeState);
      offset += 4;
      memcpy(outbuffer + offset, this->NodeState, length_NodeState);
      offset += length_NodeState;
      *(outbuffer + offset + 0) = (this->NodeErrors >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->NodeErrors >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->NodeErrors >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->NodeErrors >> (8 * 3)) & 0xFF;
      offset += sizeof(this->NodeErrors);
      *(outbuffer + offset + 0) = (this->ServoState >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ServoState >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ServoState);
      *(outbuffer + offset + 0) = (this->DropState >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->DropState >> (8 * 1)) & 0xFF;
      offset += sizeof(this->DropState);
      *(outbuffer + offset + 0) = (this->SwitchState >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->SwitchState >> (8 * 1)) & 0xFF;
      offset += sizeof(this->SwitchState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_NodeState;
      arrToVar(length_NodeState, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_NodeState; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_NodeState-1]=0;
      this->NodeState = (char *)(inbuffer + offset-1);
      offset += length_NodeState;
      this->NodeErrors =  ((uint32_t) (*(inbuffer + offset)));
      this->NodeErrors |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->NodeErrors |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->NodeErrors |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->NodeErrors);
      this->ServoState =  ((uint16_t) (*(inbuffer + offset)));
      this->ServoState |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ServoState);
      this->DropState =  ((uint16_t) (*(inbuffer + offset)));
      this->DropState |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->DropState);
      this->SwitchState =  ((uint16_t) (*(inbuffer + offset)));
      this->SwitchState |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->SwitchState);
     return offset;
    }

    virtual const char * getType() override { return "hw_msgs/CommNodeStatus"; };
    virtual const char * getMD5() override { return "ae574f170c3d1053095c4d2a81541f9a"; };

  };

}
#endif
