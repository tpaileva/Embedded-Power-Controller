#ifndef _ROS_persistent_msgs_Wrsa_h
#define _ROS_persistent_msgs_Wrsa_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "persistent_msgs/WrsaNeighborSnr.h"
#include "persistent_msgs/WrsaBaseband.h"
#include "persistent_msgs/WrsaInterface.h"

namespace persistent_msgs
{

  class Wrsa : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _recv_from_ip_type;
      _recv_from_ip_type recv_from_ip;
      typedef const char* _recv_from_mac_type;
      _recv_from_mac_type recv_from_mac;
      typedef int32_t _packet_length_type;
      _packet_length_type packet_length;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef float _altitude_ft_type;
      _altitude_ft_type altitude_ft;
      typedef float _speed_mph_type;
      _speed_mph_type speed_mph;
      typedef int32_t _icon_type_type;
      _icon_type_type icon_type;
      typedef const char* _icon_type_text_type;
      _icon_type_text_type icon_type_text;
      typedef int32_t _gps_live_type;
      _gps_live_type gps_live;
      typedef int32_t _num_neighbors_type;
      _num_neighbors_type num_neighbors;
      typedef int32_t _recv_packets_type;
      _recv_packets_type recv_packets;
      typedef int32_t _sent_packets_type;
      _sent_packets_type sent_packets;
      typedef const char* _wr_node_name_type;
      _wr_node_name_type wr_node_name;
      typedef const char* _wr_node_ip_type;
      _wr_node_ip_type wr_node_ip;
      typedef int32_t _battery_percent_type;
      _battery_percent_type battery_percent;
      uint32_t neighbors_length;
      typedef persistent_msgs::WrsaNeighborSnr _neighbors_type;
      _neighbors_type st_neighbors;
      _neighbors_type * neighbors;
      uint32_t baseband_stats_length;
      typedef persistent_msgs::WrsaBaseband _baseband_stats_type;
      _baseband_stats_type st_baseband_stats;
      _baseband_stats_type * baseband_stats;
      uint32_t interface_info_length;
      typedef persistent_msgs::WrsaInterface _interface_info_type;
      _interface_info_type st_interface_info;
      _interface_info_type * interface_info;

    Wrsa():
      header(),
      recv_from_ip(""),
      recv_from_mac(""),
      packet_length(0),
      latitude(0),
      longitude(0),
      altitude_ft(0),
      speed_mph(0),
      icon_type(0),
      icon_type_text(""),
      gps_live(0),
      num_neighbors(0),
      recv_packets(0),
      sent_packets(0),
      wr_node_name(""),
      wr_node_ip(""),
      battery_percent(0),
      neighbors_length(0), st_neighbors(), neighbors(nullptr),
      baseband_stats_length(0), st_baseband_stats(), baseband_stats(nullptr),
      interface_info_length(0), st_interface_info(), interface_info(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_recv_from_ip = strlen(this->recv_from_ip);
      varToArr(outbuffer + offset, length_recv_from_ip);
      offset += 4;
      memcpy(outbuffer + offset, this->recv_from_ip, length_recv_from_ip);
      offset += length_recv_from_ip;
      uint32_t length_recv_from_mac = strlen(this->recv_from_mac);
      varToArr(outbuffer + offset, length_recv_from_mac);
      offset += 4;
      memcpy(outbuffer + offset, this->recv_from_mac, length_recv_from_mac);
      offset += length_recv_from_mac;
      union {
        int32_t real;
        uint32_t base;
      } u_packet_length;
      u_packet_length.real = this->packet_length;
      *(outbuffer + offset + 0) = (u_packet_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packet_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packet_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packet_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packet_length);
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_ft;
      u_altitude_ft.real = this->altitude_ft;
      *(outbuffer + offset + 0) = (u_altitude_ft.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_ft.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_ft.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_ft.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_ft);
      union {
        float real;
        uint32_t base;
      } u_speed_mph;
      u_speed_mph.real = this->speed_mph;
      *(outbuffer + offset + 0) = (u_speed_mph.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_mph.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_mph.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_mph.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_mph);
      union {
        int32_t real;
        uint32_t base;
      } u_icon_type;
      u_icon_type.real = this->icon_type;
      *(outbuffer + offset + 0) = (u_icon_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icon_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icon_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icon_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icon_type);
      uint32_t length_icon_type_text = strlen(this->icon_type_text);
      varToArr(outbuffer + offset, length_icon_type_text);
      offset += 4;
      memcpy(outbuffer + offset, this->icon_type_text, length_icon_type_text);
      offset += length_icon_type_text;
      union {
        int32_t real;
        uint32_t base;
      } u_gps_live;
      u_gps_live.real = this->gps_live;
      *(outbuffer + offset + 0) = (u_gps_live.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gps_live.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gps_live.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gps_live.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_live);
      union {
        int32_t real;
        uint32_t base;
      } u_num_neighbors;
      u_num_neighbors.real = this->num_neighbors;
      *(outbuffer + offset + 0) = (u_num_neighbors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_neighbors.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_neighbors.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_neighbors.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_neighbors);
      union {
        int32_t real;
        uint32_t base;
      } u_recv_packets;
      u_recv_packets.real = this->recv_packets;
      *(outbuffer + offset + 0) = (u_recv_packets.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recv_packets.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_recv_packets.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_recv_packets.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recv_packets);
      union {
        int32_t real;
        uint32_t base;
      } u_sent_packets;
      u_sent_packets.real = this->sent_packets;
      *(outbuffer + offset + 0) = (u_sent_packets.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sent_packets.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sent_packets.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sent_packets.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sent_packets);
      uint32_t length_wr_node_name = strlen(this->wr_node_name);
      varToArr(outbuffer + offset, length_wr_node_name);
      offset += 4;
      memcpy(outbuffer + offset, this->wr_node_name, length_wr_node_name);
      offset += length_wr_node_name;
      uint32_t length_wr_node_ip = strlen(this->wr_node_ip);
      varToArr(outbuffer + offset, length_wr_node_ip);
      offset += 4;
      memcpy(outbuffer + offset, this->wr_node_ip, length_wr_node_ip);
      offset += length_wr_node_ip;
      union {
        int32_t real;
        uint32_t base;
      } u_battery_percent;
      u_battery_percent.real = this->battery_percent;
      *(outbuffer + offset + 0) = (u_battery_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_percent);
      *(outbuffer + offset + 0) = (this->neighbors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighbors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighbors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighbors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbors_length);
      for( uint32_t i = 0; i < neighbors_length; i++){
      offset += this->neighbors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->baseband_stats_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->baseband_stats_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->baseband_stats_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->baseband_stats_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baseband_stats_length);
      for( uint32_t i = 0; i < baseband_stats_length; i++){
      offset += this->baseband_stats[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->interface_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->interface_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->interface_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->interface_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interface_info_length);
      for( uint32_t i = 0; i < interface_info_length; i++){
      offset += this->interface_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_recv_from_ip;
      arrToVar(length_recv_from_ip, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_recv_from_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_recv_from_ip-1]=0;
      this->recv_from_ip = (char *)(inbuffer + offset-1);
      offset += length_recv_from_ip;
      uint32_t length_recv_from_mac;
      arrToVar(length_recv_from_mac, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_recv_from_mac; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_recv_from_mac-1]=0;
      this->recv_from_mac = (char *)(inbuffer + offset-1);
      offset += length_recv_from_mac;
      union {
        int32_t real;
        uint32_t base;
      } u_packet_length;
      u_packet_length.base = 0;
      u_packet_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packet_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packet_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packet_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packet_length = u_packet_length.real;
      offset += sizeof(this->packet_length);
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_ft;
      u_altitude_ft.base = 0;
      u_altitude_ft.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_ft.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_ft.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_ft.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_ft = u_altitude_ft.real;
      offset += sizeof(this->altitude_ft);
      union {
        float real;
        uint32_t base;
      } u_speed_mph;
      u_speed_mph.base = 0;
      u_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_mph = u_speed_mph.real;
      offset += sizeof(this->speed_mph);
      union {
        int32_t real;
        uint32_t base;
      } u_icon_type;
      u_icon_type.base = 0;
      u_icon_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icon_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icon_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icon_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icon_type = u_icon_type.real;
      offset += sizeof(this->icon_type);
      uint32_t length_icon_type_text;
      arrToVar(length_icon_type_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_icon_type_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_icon_type_text-1]=0;
      this->icon_type_text = (char *)(inbuffer + offset-1);
      offset += length_icon_type_text;
      union {
        int32_t real;
        uint32_t base;
      } u_gps_live;
      u_gps_live.base = 0;
      u_gps_live.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gps_live.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gps_live.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gps_live.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gps_live = u_gps_live.real;
      offset += sizeof(this->gps_live);
      union {
        int32_t real;
        uint32_t base;
      } u_num_neighbors;
      u_num_neighbors.base = 0;
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_neighbors = u_num_neighbors.real;
      offset += sizeof(this->num_neighbors);
      union {
        int32_t real;
        uint32_t base;
      } u_recv_packets;
      u_recv_packets.base = 0;
      u_recv_packets.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recv_packets.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_recv_packets.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_recv_packets.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->recv_packets = u_recv_packets.real;
      offset += sizeof(this->recv_packets);
      union {
        int32_t real;
        uint32_t base;
      } u_sent_packets;
      u_sent_packets.base = 0;
      u_sent_packets.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sent_packets.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sent_packets.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sent_packets.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sent_packets = u_sent_packets.real;
      offset += sizeof(this->sent_packets);
      uint32_t length_wr_node_name;
      arrToVar(length_wr_node_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wr_node_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wr_node_name-1]=0;
      this->wr_node_name = (char *)(inbuffer + offset-1);
      offset += length_wr_node_name;
      uint32_t length_wr_node_ip;
      arrToVar(length_wr_node_ip, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wr_node_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wr_node_ip-1]=0;
      this->wr_node_ip = (char *)(inbuffer + offset-1);
      offset += length_wr_node_ip;
      union {
        int32_t real;
        uint32_t base;
      } u_battery_percent;
      u_battery_percent.base = 0;
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_percent = u_battery_percent.real;
      offset += sizeof(this->battery_percent);
      uint32_t neighbors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighbors_length);
      if(neighbors_lengthT > neighbors_length)
        this->neighbors = (persistent_msgs::WrsaNeighborSnr*)realloc(this->neighbors, neighbors_lengthT * sizeof(persistent_msgs::WrsaNeighborSnr));
      neighbors_length = neighbors_lengthT;
      for( uint32_t i = 0; i < neighbors_length; i++){
      offset += this->st_neighbors.deserialize(inbuffer + offset);
        memcpy( &(this->neighbors[i]), &(this->st_neighbors), sizeof(persistent_msgs::WrsaNeighborSnr));
      }
      uint32_t baseband_stats_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      baseband_stats_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      baseband_stats_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      baseband_stats_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->baseband_stats_length);
      if(baseband_stats_lengthT > baseband_stats_length)
        this->baseband_stats = (persistent_msgs::WrsaBaseband*)realloc(this->baseband_stats, baseband_stats_lengthT * sizeof(persistent_msgs::WrsaBaseband));
      baseband_stats_length = baseband_stats_lengthT;
      for( uint32_t i = 0; i < baseband_stats_length; i++){
      offset += this->st_baseband_stats.deserialize(inbuffer + offset);
        memcpy( &(this->baseband_stats[i]), &(this->st_baseband_stats), sizeof(persistent_msgs::WrsaBaseband));
      }
      uint32_t interface_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      interface_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      interface_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      interface_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->interface_info_length);
      if(interface_info_lengthT > interface_info_length)
        this->interface_info = (persistent_msgs::WrsaInterface*)realloc(this->interface_info, interface_info_lengthT * sizeof(persistent_msgs::WrsaInterface));
      interface_info_length = interface_info_lengthT;
      for( uint32_t i = 0; i < interface_info_length; i++){
      offset += this->st_interface_info.deserialize(inbuffer + offset);
        memcpy( &(this->interface_info[i]), &(this->st_interface_info), sizeof(persistent_msgs::WrsaInterface));
      }
     return offset;
    }

    virtual const char * getType() override { return "persistent_msgs/Wrsa"; };
    virtual const char * getMD5() override { return "1ab562c887ba1c5216614a8156e4ec31"; };

  };

}
#endif
