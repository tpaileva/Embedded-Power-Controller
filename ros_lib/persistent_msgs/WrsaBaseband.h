#ifndef _ROS_persistent_msgs_WrsaBaseband_h
#define _ROS_persistent_msgs_WrsaBaseband_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace persistent_msgs
{

  class WrsaBaseband : public ros::Msg
  {
    public:
      typedef int32_t _radio_index_type;
      _radio_index_type radio_index;
      typedef int32_t _tx_percent_type;
      _tx_percent_type tx_percent;
      typedef int32_t _rx_percent_type;
      _rx_percent_type rx_percent;
      typedef int32_t _cs_percent_type;
      _cs_percent_type cs_percent;

    WrsaBaseband():
      radio_index(0),
      tx_percent(0),
      rx_percent(0),
      cs_percent(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_radio_index;
      u_radio_index.real = this->radio_index;
      *(outbuffer + offset + 0) = (u_radio_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radio_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radio_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radio_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radio_index);
      union {
        int32_t real;
        uint32_t base;
      } u_tx_percent;
      u_tx_percent.real = this->tx_percent;
      *(outbuffer + offset + 0) = (u_tx_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tx_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tx_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tx_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tx_percent);
      union {
        int32_t real;
        uint32_t base;
      } u_rx_percent;
      u_rx_percent.real = this->rx_percent;
      *(outbuffer + offset + 0) = (u_rx_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rx_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rx_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rx_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rx_percent);
      union {
        int32_t real;
        uint32_t base;
      } u_cs_percent;
      u_cs_percent.real = this->cs_percent;
      *(outbuffer + offset + 0) = (u_cs_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cs_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cs_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cs_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cs_percent);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_radio_index;
      u_radio_index.base = 0;
      u_radio_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radio_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radio_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radio_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radio_index = u_radio_index.real;
      offset += sizeof(this->radio_index);
      union {
        int32_t real;
        uint32_t base;
      } u_tx_percent;
      u_tx_percent.base = 0;
      u_tx_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tx_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tx_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tx_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tx_percent = u_tx_percent.real;
      offset += sizeof(this->tx_percent);
      union {
        int32_t real;
        uint32_t base;
      } u_rx_percent;
      u_rx_percent.base = 0;
      u_rx_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rx_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rx_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rx_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rx_percent = u_rx_percent.real;
      offset += sizeof(this->rx_percent);
      union {
        int32_t real;
        uint32_t base;
      } u_cs_percent;
      u_cs_percent.base = 0;
      u_cs_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cs_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cs_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cs_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cs_percent = u_cs_percent.real;
      offset += sizeof(this->cs_percent);
     return offset;
    }

    virtual const char * getType() override { return "persistent_msgs/WrsaBaseband"; };
    virtual const char * getMD5() override { return "aff44781ac7627e3e02b4a4247406770"; };

  };

}
#endif
