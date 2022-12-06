#ifndef _ROS_persistent_msgs_WrsaNeighborSnr_h
#define _ROS_persistent_msgs_WrsaNeighborSnr_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace persistent_msgs
{

  class WrsaNeighborSnr : public ros::Msg
  {
    public:
      typedef int32_t _snr_type;
      _snr_type snr;
      typedef const char* _mac_address_type;
      _mac_address_type mac_address;
      typedef int32_t _send_interface_index_type;
      _send_interface_index_type send_interface_index;
      typedef int32_t _recv_interface_index_type;
      _recv_interface_index_type recv_interface_index;

    WrsaNeighborSnr():
      snr(0),
      mac_address(""),
      send_interface_index(0),
      recv_interface_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_snr;
      u_snr.real = this->snr;
      *(outbuffer + offset + 0) = (u_snr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_snr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_snr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_snr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->snr);
      uint32_t length_mac_address = strlen(this->mac_address);
      varToArr(outbuffer + offset, length_mac_address);
      offset += 4;
      memcpy(outbuffer + offset, this->mac_address, length_mac_address);
      offset += length_mac_address;
      union {
        int32_t real;
        uint32_t base;
      } u_send_interface_index;
      u_send_interface_index.real = this->send_interface_index;
      *(outbuffer + offset + 0) = (u_send_interface_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_send_interface_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_send_interface_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_send_interface_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->send_interface_index);
      union {
        int32_t real;
        uint32_t base;
      } u_recv_interface_index;
      u_recv_interface_index.real = this->recv_interface_index;
      *(outbuffer + offset + 0) = (u_recv_interface_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recv_interface_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_recv_interface_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_recv_interface_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recv_interface_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_snr;
      u_snr.base = 0;
      u_snr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_snr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_snr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_snr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->snr = u_snr.real;
      offset += sizeof(this->snr);
      uint32_t length_mac_address;
      arrToVar(length_mac_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mac_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mac_address-1]=0;
      this->mac_address = (char *)(inbuffer + offset-1);
      offset += length_mac_address;
      union {
        int32_t real;
        uint32_t base;
      } u_send_interface_index;
      u_send_interface_index.base = 0;
      u_send_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_send_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_send_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_send_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->send_interface_index = u_send_interface_index.real;
      offset += sizeof(this->send_interface_index);
      union {
        int32_t real;
        uint32_t base;
      } u_recv_interface_index;
      u_recv_interface_index.base = 0;
      u_recv_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recv_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_recv_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_recv_interface_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->recv_interface_index = u_recv_interface_index.real;
      offset += sizeof(this->recv_interface_index);
     return offset;
    }

    virtual const char * getType() override { return "persistent_msgs/WrsaNeighborSnr"; };
    virtual const char * getMD5() override { return "f1c72ff0264b954a7812750e70d616de"; };

  };

}
#endif
