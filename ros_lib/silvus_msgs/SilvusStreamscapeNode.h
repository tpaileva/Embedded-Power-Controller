#ifndef _ROS_silvus_msgs_SilvusStreamscapeNode_h
#define _ROS_silvus_msgs_SilvusStreamscapeNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "silvus_msgs/SilvusStreamscapeNeighbor.h"
#include "silvus_msgs/key_value_int32_int32.h"

namespace silvus_msgs
{

  class SilvusStreamscapeNode : public ros::Msg
  {
    public:
      typedef int32_t _node_id_type;
      _node_id_type node_id;
      typedef const char* _node_label_type;
      _node_label_type node_label;
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef uint64_t _pg_key_type;
      _pg_key_type pg_key;
      typedef int32_t _last_updated_s_type;
      _last_updated_s_type last_updated_s;
      typedef const char* _gateway_ip_type;
      _gateway_ip_type gateway_ip;
      typedef const char* _ipaddr_type;
      _ipaddr_type ipaddr;
      typedef const char* _netmask_type;
      _netmask_type netmask;
      uint32_t neighbors_length;
      typedef silvus_msgs::SilvusStreamscapeNeighbor _neighbors_type;
      _neighbors_type st_neighbors;
      _neighbors_type * neighbors;
      typedef int32_t _frag_thresh_bytes_type;
      _frag_thresh_bytes_type frag_thresh_bytes;
      typedef int32_t _beam_form_enable_type;
      _beam_form_enable_type beam_form_enable;
      typedef const char* _board_type_type;
      _board_type_type board_type;
      typedef float _burst_time_ms_type;
      _burst_time_ms_type burst_time_ms;
      typedef int32_t _bandwidth_MHz_type;
      _bandwidth_MHz_type bandwidth_MHz;
      typedef int32_t _contention_window_minimum_type;
      _contention_window_minimum_type contention_window_minimum;
      typedef int32_t _full_power_type;
      _full_power_type full_power;
      typedef int32_t _freq_MHz_type;
      _freq_MHz_type freq_MHz;
      typedef int32_t _gps_status_type;
      _gps_status_type gps_status;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef int32_t _max_link_distance_m_type;
      _max_link_distance_m_type max_link_distance_m;
      typedef int32_t _max_speed_mph_type;
      _max_speed_mph_type max_speed_mph;
      typedef const char* _mcast0_config_type;
      _mcast0_config_type mcast0_config;
      typedef const char* _mcast1_config_type;
      _mcast1_config_type mcast1_config;
      typedef const char* _mcast2_config_type;
      _mcast2_config_type mcast2_config;
      typedef const char* _mcast3_config_type;
      _mcast3_config_type mcast3_config;
      typedef const char* _mcast4_config_type;
      _mcast4_config_type mcast4_config;
      typedef int32_t _link_adaptation_mode_type;
      _link_adaptation_mode_type link_adaptation_mode;
      typedef int32_t _link_adaptation_disable_type;
      _link_adaptation_disable_type link_adaptation_disable;
      typedef int32_t _modulation_coding_scheme_type;
      _modulation_coding_scheme_type modulation_coding_scheme;
      typedef int32_t _guard_interval_mode_type;
      _guard_interval_mode_type guard_interval_mode;
      typedef int32_t _cyclic_prefix_length_type;
      _cyclic_prefix_length_type cyclic_prefix_length;
      typedef int32_t _noise_level_dBm_type;
      _noise_level_dBm_type noise_level_dBm;
      typedef int32_t _interference_dB_type;
      _interference_dB_type interference_dB;
      typedef int32_t _number_retries_type;
      _number_retries_type number_retries;
      typedef int32_t _rts_retries_type;
      _rts_retries_type rts_retries;
      typedef int32_t _queue_size_type;
      _queue_size_type queue_size;
      typedef int32_t _routing_beacon_mcs_type;
      _routing_beacon_mcs_type routing_beacon_mcs;
      typedef int32_t _routing_beacon_period_ms_type;
      _routing_beacon_period_ms_type routing_beacon_period_ms;
      uint32_t next_hop_length;
      typedef silvus_msgs::key_value_int32_int32 _next_hop_type;
      _next_hop_type st_next_hop;
      _next_hop_type * next_hop;
      typedef int32_t _txpw_requested_mW_type;
      _txpw_requested_mW_type txpw_requested_mW;
      typedef int32_t _txpw_actual_mW_type;
      _txpw_actual_mW_type txpw_actual_mW;
      typedef float _txpw_requested_dBm_type;
      _txpw_requested_dBm_type txpw_requested_dBm;
      typedef float _txpw_actual_dBm_type;
      _txpw_actual_dBm_type txpw_actual_dBm;
      typedef float _total_air_time_percent_type;
      _total_air_time_percent_type total_air_time_percent;
      typedef float _total_data_rate_Mbps_type;
      _total_data_rate_Mbps_type total_data_rate_Mbps;
      typedef float _loss_rate_percent_type;
      _loss_rate_percent_type loss_rate_percent;
      typedef float _input_unicast_rate_Mbps_type;
      _input_unicast_rate_Mbps_type input_unicast_rate_Mbps;
      typedef float _input_multicast_rate_Mbps_type;
      _input_multicast_rate_Mbps_type input_multicast_rate_Mbps;
      typedef float _input_dropped_rate_Mbps_type;
      _input_dropped_rate_Mbps_type input_dropped_rate_Mbps;
      typedef float _forward_unicast_rate_Mbps_type;
      _forward_unicast_rate_Mbps_type forward_unicast_rate_Mbps;
      typedef float _forward_multicast_rate_Mbps_type;
      _forward_multicast_rate_Mbps_type forward_multicast_rate_Mbps;

    SilvusStreamscapeNode():
      node_id(0),
      node_label(""),
      robot_name(""),
      pg_key(0),
      last_updated_s(0),
      gateway_ip(""),
      ipaddr(""),
      netmask(""),
      neighbors_length(0), st_neighbors(), neighbors(nullptr),
      frag_thresh_bytes(0),
      beam_form_enable(0),
      board_type(""),
      burst_time_ms(0),
      bandwidth_MHz(0),
      contention_window_minimum(0),
      full_power(0),
      freq_MHz(0),
      gps_status(0),
      latitude(0),
      longitude(0),
      max_link_distance_m(0),
      max_speed_mph(0),
      mcast0_config(""),
      mcast1_config(""),
      mcast2_config(""),
      mcast3_config(""),
      mcast4_config(""),
      link_adaptation_mode(0),
      link_adaptation_disable(0),
      modulation_coding_scheme(0),
      guard_interval_mode(0),
      cyclic_prefix_length(0),
      noise_level_dBm(0),
      interference_dB(0),
      number_retries(0),
      rts_retries(0),
      queue_size(0),
      routing_beacon_mcs(0),
      routing_beacon_period_ms(0),
      next_hop_length(0), st_next_hop(), next_hop(nullptr),
      txpw_requested_mW(0),
      txpw_actual_mW(0),
      txpw_requested_dBm(0),
      txpw_actual_dBm(0),
      total_air_time_percent(0),
      total_data_rate_Mbps(0),
      loss_rate_percent(0),
      input_unicast_rate_Mbps(0),
      input_multicast_rate_Mbps(0),
      input_dropped_rate_Mbps(0),
      forward_unicast_rate_Mbps(0),
      forward_multicast_rate_Mbps(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_id);
      uint32_t length_node_label = strlen(this->node_label);
      varToArr(outbuffer + offset, length_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->node_label, length_node_label);
      offset += length_node_label;
      uint32_t length_robot_name = strlen(this->robot_name);
      varToArr(outbuffer + offset, length_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_pg_key;
      u_pg_key.real = this->pg_key;
      *(outbuffer + offset + 0) = (u_pg_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pg_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pg_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pg_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pg_key);
      union {
        int32_t real;
        uint32_t base;
      } u_last_updated_s;
      u_last_updated_s.real = this->last_updated_s;
      *(outbuffer + offset + 0) = (u_last_updated_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_updated_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_updated_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_updated_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_updated_s);
      uint32_t length_gateway_ip = strlen(this->gateway_ip);
      varToArr(outbuffer + offset, length_gateway_ip);
      offset += 4;
      memcpy(outbuffer + offset, this->gateway_ip, length_gateway_ip);
      offset += length_gateway_ip;
      uint32_t length_ipaddr = strlen(this->ipaddr);
      varToArr(outbuffer + offset, length_ipaddr);
      offset += 4;
      memcpy(outbuffer + offset, this->ipaddr, length_ipaddr);
      offset += length_ipaddr;
      uint32_t length_netmask = strlen(this->netmask);
      varToArr(outbuffer + offset, length_netmask);
      offset += 4;
      memcpy(outbuffer + offset, this->netmask, length_netmask);
      offset += length_netmask;
      *(outbuffer + offset + 0) = (this->neighbors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighbors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighbors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighbors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbors_length);
      for( uint32_t i = 0; i < neighbors_length; i++){
      offset += this->neighbors[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_frag_thresh_bytes;
      u_frag_thresh_bytes.real = this->frag_thresh_bytes;
      *(outbuffer + offset + 0) = (u_frag_thresh_bytes.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frag_thresh_bytes.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frag_thresh_bytes.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frag_thresh_bytes.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frag_thresh_bytes);
      union {
        int32_t real;
        uint32_t base;
      } u_beam_form_enable;
      u_beam_form_enable.real = this->beam_form_enable;
      *(outbuffer + offset + 0) = (u_beam_form_enable.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beam_form_enable.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beam_form_enable.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beam_form_enable.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beam_form_enable);
      uint32_t length_board_type = strlen(this->board_type);
      varToArr(outbuffer + offset, length_board_type);
      offset += 4;
      memcpy(outbuffer + offset, this->board_type, length_board_type);
      offset += length_board_type;
      union {
        float real;
        uint32_t base;
      } u_burst_time_ms;
      u_burst_time_ms.real = this->burst_time_ms;
      *(outbuffer + offset + 0) = (u_burst_time_ms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_burst_time_ms.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_burst_time_ms.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_burst_time_ms.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->burst_time_ms);
      union {
        int32_t real;
        uint32_t base;
      } u_bandwidth_MHz;
      u_bandwidth_MHz.real = this->bandwidth_MHz;
      *(outbuffer + offset + 0) = (u_bandwidth_MHz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bandwidth_MHz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bandwidth_MHz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bandwidth_MHz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bandwidth_MHz);
      union {
        int32_t real;
        uint32_t base;
      } u_contention_window_minimum;
      u_contention_window_minimum.real = this->contention_window_minimum;
      *(outbuffer + offset + 0) = (u_contention_window_minimum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_contention_window_minimum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_contention_window_minimum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_contention_window_minimum.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contention_window_minimum);
      union {
        int32_t real;
        uint32_t base;
      } u_full_power;
      u_full_power.real = this->full_power;
      *(outbuffer + offset + 0) = (u_full_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_full_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_full_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_full_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->full_power);
      union {
        int32_t real;
        uint32_t base;
      } u_freq_MHz;
      u_freq_MHz.real = this->freq_MHz;
      *(outbuffer + offset + 0) = (u_freq_MHz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_freq_MHz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_freq_MHz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_freq_MHz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->freq_MHz);
      union {
        int32_t real;
        uint32_t base;
      } u_gps_status;
      u_gps_status.real = this->gps_status;
      *(outbuffer + offset + 0) = (u_gps_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gps_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gps_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gps_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_status);
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
        int32_t real;
        uint32_t base;
      } u_max_link_distance_m;
      u_max_link_distance_m.real = this->max_link_distance_m;
      *(outbuffer + offset + 0) = (u_max_link_distance_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_link_distance_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_link_distance_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_link_distance_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_link_distance_m);
      union {
        int32_t real;
        uint32_t base;
      } u_max_speed_mph;
      u_max_speed_mph.real = this->max_speed_mph;
      *(outbuffer + offset + 0) = (u_max_speed_mph.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_speed_mph.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_speed_mph.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_speed_mph.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_speed_mph);
      uint32_t length_mcast0_config = strlen(this->mcast0_config);
      varToArr(outbuffer + offset, length_mcast0_config);
      offset += 4;
      memcpy(outbuffer + offset, this->mcast0_config, length_mcast0_config);
      offset += length_mcast0_config;
      uint32_t length_mcast1_config = strlen(this->mcast1_config);
      varToArr(outbuffer + offset, length_mcast1_config);
      offset += 4;
      memcpy(outbuffer + offset, this->mcast1_config, length_mcast1_config);
      offset += length_mcast1_config;
      uint32_t length_mcast2_config = strlen(this->mcast2_config);
      varToArr(outbuffer + offset, length_mcast2_config);
      offset += 4;
      memcpy(outbuffer + offset, this->mcast2_config, length_mcast2_config);
      offset += length_mcast2_config;
      uint32_t length_mcast3_config = strlen(this->mcast3_config);
      varToArr(outbuffer + offset, length_mcast3_config);
      offset += 4;
      memcpy(outbuffer + offset, this->mcast3_config, length_mcast3_config);
      offset += length_mcast3_config;
      uint32_t length_mcast4_config = strlen(this->mcast4_config);
      varToArr(outbuffer + offset, length_mcast4_config);
      offset += 4;
      memcpy(outbuffer + offset, this->mcast4_config, length_mcast4_config);
      offset += length_mcast4_config;
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_mode;
      u_link_adaptation_mode.real = this->link_adaptation_mode;
      *(outbuffer + offset + 0) = (u_link_adaptation_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_link_adaptation_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_link_adaptation_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_link_adaptation_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_adaptation_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_disable;
      u_link_adaptation_disable.real = this->link_adaptation_disable;
      *(outbuffer + offset + 0) = (u_link_adaptation_disable.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_link_adaptation_disable.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_link_adaptation_disable.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_link_adaptation_disable.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_adaptation_disable);
      union {
        int32_t real;
        uint32_t base;
      } u_modulation_coding_scheme;
      u_modulation_coding_scheme.real = this->modulation_coding_scheme;
      *(outbuffer + offset + 0) = (u_modulation_coding_scheme.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_modulation_coding_scheme.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_modulation_coding_scheme.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_modulation_coding_scheme.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modulation_coding_scheme);
      union {
        int32_t real;
        uint32_t base;
      } u_guard_interval_mode;
      u_guard_interval_mode.real = this->guard_interval_mode;
      *(outbuffer + offset + 0) = (u_guard_interval_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_guard_interval_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_guard_interval_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_guard_interval_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->guard_interval_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_cyclic_prefix_length;
      u_cyclic_prefix_length.real = this->cyclic_prefix_length;
      *(outbuffer + offset + 0) = (u_cyclic_prefix_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cyclic_prefix_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cyclic_prefix_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cyclic_prefix_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cyclic_prefix_length);
      union {
        int32_t real;
        uint32_t base;
      } u_noise_level_dBm;
      u_noise_level_dBm.real = this->noise_level_dBm;
      *(outbuffer + offset + 0) = (u_noise_level_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_noise_level_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_noise_level_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_noise_level_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_interference_dB;
      u_interference_dB.real = this->interference_dB;
      *(outbuffer + offset + 0) = (u_interference_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_interference_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_interference_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_interference_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_number_retries;
      u_number_retries.real = this->number_retries;
      *(outbuffer + offset + 0) = (u_number_retries.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_retries.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_retries.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_retries.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_retries);
      union {
        int32_t real;
        uint32_t base;
      } u_rts_retries;
      u_rts_retries.real = this->rts_retries;
      *(outbuffer + offset + 0) = (u_rts_retries.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rts_retries.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rts_retries.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rts_retries.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rts_retries);
      union {
        int32_t real;
        uint32_t base;
      } u_queue_size;
      u_queue_size.real = this->queue_size;
      *(outbuffer + offset + 0) = (u_queue_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_queue_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_queue_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_queue_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->queue_size);
      union {
        int32_t real;
        uint32_t base;
      } u_routing_beacon_mcs;
      u_routing_beacon_mcs.real = this->routing_beacon_mcs;
      *(outbuffer + offset + 0) = (u_routing_beacon_mcs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_routing_beacon_mcs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_routing_beacon_mcs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_routing_beacon_mcs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routing_beacon_mcs);
      union {
        int32_t real;
        uint32_t base;
      } u_routing_beacon_period_ms;
      u_routing_beacon_period_ms.real = this->routing_beacon_period_ms;
      *(outbuffer + offset + 0) = (u_routing_beacon_period_ms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_routing_beacon_period_ms.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_routing_beacon_period_ms.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_routing_beacon_period_ms.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routing_beacon_period_ms);
      *(outbuffer + offset + 0) = (this->next_hop_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->next_hop_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->next_hop_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->next_hop_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->next_hop_length);
      for( uint32_t i = 0; i < next_hop_length; i++){
      offset += this->next_hop[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_txpw_requested_mW;
      u_txpw_requested_mW.real = this->txpw_requested_mW;
      *(outbuffer + offset + 0) = (u_txpw_requested_mW.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_txpw_requested_mW.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_txpw_requested_mW.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_txpw_requested_mW.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->txpw_requested_mW);
      union {
        int32_t real;
        uint32_t base;
      } u_txpw_actual_mW;
      u_txpw_actual_mW.real = this->txpw_actual_mW;
      *(outbuffer + offset + 0) = (u_txpw_actual_mW.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_txpw_actual_mW.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_txpw_actual_mW.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_txpw_actual_mW.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->txpw_actual_mW);
      union {
        float real;
        uint32_t base;
      } u_txpw_requested_dBm;
      u_txpw_requested_dBm.real = this->txpw_requested_dBm;
      *(outbuffer + offset + 0) = (u_txpw_requested_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_txpw_requested_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_txpw_requested_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_txpw_requested_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->txpw_requested_dBm);
      union {
        float real;
        uint32_t base;
      } u_txpw_actual_dBm;
      u_txpw_actual_dBm.real = this->txpw_actual_dBm;
      *(outbuffer + offset + 0) = (u_txpw_actual_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_txpw_actual_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_txpw_actual_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_txpw_actual_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->txpw_actual_dBm);
      union {
        float real;
        uint32_t base;
      } u_total_air_time_percent;
      u_total_air_time_percent.real = this->total_air_time_percent;
      *(outbuffer + offset + 0) = (u_total_air_time_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_air_time_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_air_time_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_air_time_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_air_time_percent);
      union {
        float real;
        uint32_t base;
      } u_total_data_rate_Mbps;
      u_total_data_rate_Mbps.real = this->total_data_rate_Mbps;
      *(outbuffer + offset + 0) = (u_total_data_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_data_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_data_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_data_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_loss_rate_percent;
      u_loss_rate_percent.real = this->loss_rate_percent;
      *(outbuffer + offset + 0) = (u_loss_rate_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loss_rate_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_loss_rate_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_loss_rate_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loss_rate_percent);
      union {
        float real;
        uint32_t base;
      } u_input_unicast_rate_Mbps;
      u_input_unicast_rate_Mbps.real = this->input_unicast_rate_Mbps;
      *(outbuffer + offset + 0) = (u_input_unicast_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_unicast_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_unicast_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_unicast_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_unicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_input_multicast_rate_Mbps;
      u_input_multicast_rate_Mbps.real = this->input_multicast_rate_Mbps;
      *(outbuffer + offset + 0) = (u_input_multicast_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_multicast_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_multicast_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_multicast_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_multicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_input_dropped_rate_Mbps;
      u_input_dropped_rate_Mbps.real = this->input_dropped_rate_Mbps;
      *(outbuffer + offset + 0) = (u_input_dropped_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_dropped_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_dropped_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_dropped_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_dropped_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_forward_unicast_rate_Mbps;
      u_forward_unicast_rate_Mbps.real = this->forward_unicast_rate_Mbps;
      *(outbuffer + offset + 0) = (u_forward_unicast_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forward_unicast_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forward_unicast_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forward_unicast_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->forward_unicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_forward_multicast_rate_Mbps;
      u_forward_multicast_rate_Mbps.real = this->forward_multicast_rate_Mbps;
      *(outbuffer + offset + 0) = (u_forward_multicast_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forward_multicast_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forward_multicast_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forward_multicast_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->forward_multicast_rate_Mbps);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
      uint32_t length_node_label;
      arrToVar(length_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_label-1]=0;
      this->node_label = (char *)(inbuffer + offset-1);
      offset += length_node_label;
      uint32_t length_robot_name;
      arrToVar(length_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_pg_key;
      u_pg_key.base = 0;
      u_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pg_key = u_pg_key.real;
      offset += sizeof(this->pg_key);
      union {
        int32_t real;
        uint32_t base;
      } u_last_updated_s;
      u_last_updated_s.base = 0;
      u_last_updated_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_updated_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_updated_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_updated_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->last_updated_s = u_last_updated_s.real;
      offset += sizeof(this->last_updated_s);
      uint32_t length_gateway_ip;
      arrToVar(length_gateway_ip, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gateway_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gateway_ip-1]=0;
      this->gateway_ip = (char *)(inbuffer + offset-1);
      offset += length_gateway_ip;
      uint32_t length_ipaddr;
      arrToVar(length_ipaddr, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ipaddr; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ipaddr-1]=0;
      this->ipaddr = (char *)(inbuffer + offset-1);
      offset += length_ipaddr;
      uint32_t length_netmask;
      arrToVar(length_netmask, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_netmask; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_netmask-1]=0;
      this->netmask = (char *)(inbuffer + offset-1);
      offset += length_netmask;
      uint32_t neighbors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighbors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighbors_length);
      if(neighbors_lengthT > neighbors_length)
        this->neighbors = (silvus_msgs::SilvusStreamscapeNeighbor*)realloc(this->neighbors, neighbors_lengthT * sizeof(silvus_msgs::SilvusStreamscapeNeighbor));
      neighbors_length = neighbors_lengthT;
      for( uint32_t i = 0; i < neighbors_length; i++){
      offset += this->st_neighbors.deserialize(inbuffer + offset);
        memcpy( &(this->neighbors[i]), &(this->st_neighbors), sizeof(silvus_msgs::SilvusStreamscapeNeighbor));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_frag_thresh_bytes;
      u_frag_thresh_bytes.base = 0;
      u_frag_thresh_bytes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frag_thresh_bytes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frag_thresh_bytes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frag_thresh_bytes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frag_thresh_bytes = u_frag_thresh_bytes.real;
      offset += sizeof(this->frag_thresh_bytes);
      union {
        int32_t real;
        uint32_t base;
      } u_beam_form_enable;
      u_beam_form_enable.base = 0;
      u_beam_form_enable.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_beam_form_enable.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_beam_form_enable.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_beam_form_enable.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->beam_form_enable = u_beam_form_enable.real;
      offset += sizeof(this->beam_form_enable);
      uint32_t length_board_type;
      arrToVar(length_board_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_board_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_board_type-1]=0;
      this->board_type = (char *)(inbuffer + offset-1);
      offset += length_board_type;
      union {
        float real;
        uint32_t base;
      } u_burst_time_ms;
      u_burst_time_ms.base = 0;
      u_burst_time_ms.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_burst_time_ms.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_burst_time_ms.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_burst_time_ms.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->burst_time_ms = u_burst_time_ms.real;
      offset += sizeof(this->burst_time_ms);
      union {
        int32_t real;
        uint32_t base;
      } u_bandwidth_MHz;
      u_bandwidth_MHz.base = 0;
      u_bandwidth_MHz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bandwidth_MHz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bandwidth_MHz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bandwidth_MHz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bandwidth_MHz = u_bandwidth_MHz.real;
      offset += sizeof(this->bandwidth_MHz);
      union {
        int32_t real;
        uint32_t base;
      } u_contention_window_minimum;
      u_contention_window_minimum.base = 0;
      u_contention_window_minimum.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_contention_window_minimum.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_contention_window_minimum.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_contention_window_minimum.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->contention_window_minimum = u_contention_window_minimum.real;
      offset += sizeof(this->contention_window_minimum);
      union {
        int32_t real;
        uint32_t base;
      } u_full_power;
      u_full_power.base = 0;
      u_full_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_full_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_full_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_full_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->full_power = u_full_power.real;
      offset += sizeof(this->full_power);
      union {
        int32_t real;
        uint32_t base;
      } u_freq_MHz;
      u_freq_MHz.base = 0;
      u_freq_MHz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_freq_MHz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_freq_MHz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_freq_MHz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->freq_MHz = u_freq_MHz.real;
      offset += sizeof(this->freq_MHz);
      union {
        int32_t real;
        uint32_t base;
      } u_gps_status;
      u_gps_status.base = 0;
      u_gps_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gps_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gps_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gps_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gps_status = u_gps_status.real;
      offset += sizeof(this->gps_status);
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
        int32_t real;
        uint32_t base;
      } u_max_link_distance_m;
      u_max_link_distance_m.base = 0;
      u_max_link_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_link_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_link_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_link_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_link_distance_m = u_max_link_distance_m.real;
      offset += sizeof(this->max_link_distance_m);
      union {
        int32_t real;
        uint32_t base;
      } u_max_speed_mph;
      u_max_speed_mph.base = 0;
      u_max_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_speed_mph.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_speed_mph = u_max_speed_mph.real;
      offset += sizeof(this->max_speed_mph);
      uint32_t length_mcast0_config;
      arrToVar(length_mcast0_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mcast0_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mcast0_config-1]=0;
      this->mcast0_config = (char *)(inbuffer + offset-1);
      offset += length_mcast0_config;
      uint32_t length_mcast1_config;
      arrToVar(length_mcast1_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mcast1_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mcast1_config-1]=0;
      this->mcast1_config = (char *)(inbuffer + offset-1);
      offset += length_mcast1_config;
      uint32_t length_mcast2_config;
      arrToVar(length_mcast2_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mcast2_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mcast2_config-1]=0;
      this->mcast2_config = (char *)(inbuffer + offset-1);
      offset += length_mcast2_config;
      uint32_t length_mcast3_config;
      arrToVar(length_mcast3_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mcast3_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mcast3_config-1]=0;
      this->mcast3_config = (char *)(inbuffer + offset-1);
      offset += length_mcast3_config;
      uint32_t length_mcast4_config;
      arrToVar(length_mcast4_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mcast4_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mcast4_config-1]=0;
      this->mcast4_config = (char *)(inbuffer + offset-1);
      offset += length_mcast4_config;
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_mode;
      u_link_adaptation_mode.base = 0;
      u_link_adaptation_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_link_adaptation_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_link_adaptation_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_link_adaptation_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->link_adaptation_mode = u_link_adaptation_mode.real;
      offset += sizeof(this->link_adaptation_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_disable;
      u_link_adaptation_disable.base = 0;
      u_link_adaptation_disable.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_link_adaptation_disable.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_link_adaptation_disable.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_link_adaptation_disable.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->link_adaptation_disable = u_link_adaptation_disable.real;
      offset += sizeof(this->link_adaptation_disable);
      union {
        int32_t real;
        uint32_t base;
      } u_modulation_coding_scheme;
      u_modulation_coding_scheme.base = 0;
      u_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->modulation_coding_scheme = u_modulation_coding_scheme.real;
      offset += sizeof(this->modulation_coding_scheme);
      union {
        int32_t real;
        uint32_t base;
      } u_guard_interval_mode;
      u_guard_interval_mode.base = 0;
      u_guard_interval_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_guard_interval_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_guard_interval_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_guard_interval_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->guard_interval_mode = u_guard_interval_mode.real;
      offset += sizeof(this->guard_interval_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_cyclic_prefix_length;
      u_cyclic_prefix_length.base = 0;
      u_cyclic_prefix_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cyclic_prefix_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cyclic_prefix_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cyclic_prefix_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cyclic_prefix_length = u_cyclic_prefix_length.real;
      offset += sizeof(this->cyclic_prefix_length);
      union {
        int32_t real;
        uint32_t base;
      } u_noise_level_dBm;
      u_noise_level_dBm.base = 0;
      u_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->noise_level_dBm = u_noise_level_dBm.real;
      offset += sizeof(this->noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_interference_dB;
      u_interference_dB.base = 0;
      u_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->interference_dB = u_interference_dB.real;
      offset += sizeof(this->interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_number_retries;
      u_number_retries.base = 0;
      u_number_retries.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_retries.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_retries.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_retries.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_retries = u_number_retries.real;
      offset += sizeof(this->number_retries);
      union {
        int32_t real;
        uint32_t base;
      } u_rts_retries;
      u_rts_retries.base = 0;
      u_rts_retries.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rts_retries.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rts_retries.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rts_retries.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rts_retries = u_rts_retries.real;
      offset += sizeof(this->rts_retries);
      union {
        int32_t real;
        uint32_t base;
      } u_queue_size;
      u_queue_size.base = 0;
      u_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->queue_size = u_queue_size.real;
      offset += sizeof(this->queue_size);
      union {
        int32_t real;
        uint32_t base;
      } u_routing_beacon_mcs;
      u_routing_beacon_mcs.base = 0;
      u_routing_beacon_mcs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_routing_beacon_mcs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_routing_beacon_mcs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_routing_beacon_mcs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->routing_beacon_mcs = u_routing_beacon_mcs.real;
      offset += sizeof(this->routing_beacon_mcs);
      union {
        int32_t real;
        uint32_t base;
      } u_routing_beacon_period_ms;
      u_routing_beacon_period_ms.base = 0;
      u_routing_beacon_period_ms.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_routing_beacon_period_ms.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_routing_beacon_period_ms.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_routing_beacon_period_ms.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->routing_beacon_period_ms = u_routing_beacon_period_ms.real;
      offset += sizeof(this->routing_beacon_period_ms);
      uint32_t next_hop_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      next_hop_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      next_hop_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      next_hop_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->next_hop_length);
      if(next_hop_lengthT > next_hop_length)
        this->next_hop = (silvus_msgs::key_value_int32_int32*)realloc(this->next_hop, next_hop_lengthT * sizeof(silvus_msgs::key_value_int32_int32));
      next_hop_length = next_hop_lengthT;
      for( uint32_t i = 0; i < next_hop_length; i++){
      offset += this->st_next_hop.deserialize(inbuffer + offset);
        memcpy( &(this->next_hop[i]), &(this->st_next_hop), sizeof(silvus_msgs::key_value_int32_int32));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_txpw_requested_mW;
      u_txpw_requested_mW.base = 0;
      u_txpw_requested_mW.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_txpw_requested_mW.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_txpw_requested_mW.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_txpw_requested_mW.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->txpw_requested_mW = u_txpw_requested_mW.real;
      offset += sizeof(this->txpw_requested_mW);
      union {
        int32_t real;
        uint32_t base;
      } u_txpw_actual_mW;
      u_txpw_actual_mW.base = 0;
      u_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->txpw_actual_mW = u_txpw_actual_mW.real;
      offset += sizeof(this->txpw_actual_mW);
      union {
        float real;
        uint32_t base;
      } u_txpw_requested_dBm;
      u_txpw_requested_dBm.base = 0;
      u_txpw_requested_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_txpw_requested_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_txpw_requested_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_txpw_requested_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->txpw_requested_dBm = u_txpw_requested_dBm.real;
      offset += sizeof(this->txpw_requested_dBm);
      union {
        float real;
        uint32_t base;
      } u_txpw_actual_dBm;
      u_txpw_actual_dBm.base = 0;
      u_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->txpw_actual_dBm = u_txpw_actual_dBm.real;
      offset += sizeof(this->txpw_actual_dBm);
      union {
        float real;
        uint32_t base;
      } u_total_air_time_percent;
      u_total_air_time_percent.base = 0;
      u_total_air_time_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_air_time_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_air_time_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_air_time_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_air_time_percent = u_total_air_time_percent.real;
      offset += sizeof(this->total_air_time_percent);
      union {
        float real;
        uint32_t base;
      } u_total_data_rate_Mbps;
      u_total_data_rate_Mbps.base = 0;
      u_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_data_rate_Mbps = u_total_data_rate_Mbps.real;
      offset += sizeof(this->total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_loss_rate_percent;
      u_loss_rate_percent.base = 0;
      u_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->loss_rate_percent = u_loss_rate_percent.real;
      offset += sizeof(this->loss_rate_percent);
      union {
        float real;
        uint32_t base;
      } u_input_unicast_rate_Mbps;
      u_input_unicast_rate_Mbps.base = 0;
      u_input_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_unicast_rate_Mbps = u_input_unicast_rate_Mbps.real;
      offset += sizeof(this->input_unicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_input_multicast_rate_Mbps;
      u_input_multicast_rate_Mbps.base = 0;
      u_input_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_multicast_rate_Mbps = u_input_multicast_rate_Mbps.real;
      offset += sizeof(this->input_multicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_input_dropped_rate_Mbps;
      u_input_dropped_rate_Mbps.base = 0;
      u_input_dropped_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_dropped_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_dropped_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_dropped_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_dropped_rate_Mbps = u_input_dropped_rate_Mbps.real;
      offset += sizeof(this->input_dropped_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_forward_unicast_rate_Mbps;
      u_forward_unicast_rate_Mbps.base = 0;
      u_forward_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forward_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forward_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forward_unicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->forward_unicast_rate_Mbps = u_forward_unicast_rate_Mbps.real;
      offset += sizeof(this->forward_unicast_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_forward_multicast_rate_Mbps;
      u_forward_multicast_rate_Mbps.base = 0;
      u_forward_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forward_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forward_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forward_multicast_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->forward_multicast_rate_Mbps = u_forward_multicast_rate_Mbps.real;
      offset += sizeof(this->forward_multicast_rate_Mbps);
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusStreamscapeNode"; };
    virtual const char * getMD5() override { return "159223d85c8602e3dad2c2e1394cdd04"; };

  };

}
#endif
