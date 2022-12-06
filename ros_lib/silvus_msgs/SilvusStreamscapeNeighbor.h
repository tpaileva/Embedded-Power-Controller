#ifndef _ROS_silvus_msgs_SilvusStreamscapeNeighbor_h
#define _ROS_silvus_msgs_SilvusStreamscapeNeighbor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace silvus_msgs
{

  class SilvusStreamscapeNeighbor : public ros::Msg
  {
    public:
      typedef int32_t _my_node_id_type;
      _my_node_id_type my_node_id;
      typedef const char* _my_node_label_type;
      _my_node_label_type my_node_label;
      typedef const char* _my_robot_name_type;
      _my_robot_name_type my_robot_name;
      typedef uint64_t _my_pg_key_type;
      _my_pg_key_type my_pg_key;
      typedef int32_t _my_noise_level_dBm_type;
      _my_noise_level_dBm_type my_noise_level_dBm;
      typedef int32_t _my_interference_dB_type;
      _my_interference_dB_type my_interference_dB;
      typedef int32_t _my_txpw_actual_mW_type;
      _my_txpw_actual_mW_type my_txpw_actual_mW;
      typedef float _my_txpw_actual_dBm_type;
      _my_txpw_actual_dBm_type my_txpw_actual_dBm;
      typedef int32_t _neighbor_node_id_type;
      _neighbor_node_id_type neighbor_node_id;
      typedef const char* _neighbor_node_label_type;
      _neighbor_node_label_type neighbor_node_label;
      typedef uint64_t _neighbor_pg_key_type;
      _neighbor_pg_key_type neighbor_pg_key;
      typedef const char* _color_type;
      _color_type color;
      typedef int32_t _queue_size_type;
      _queue_size_type queue_size;
      typedef int32_t _snr_dB_type;
      _snr_dB_type snr_dB;
      typedef float _total_air_time_percent_type;
      _total_air_time_percent_type total_air_time_percent;
      typedef float _total_data_rate_Mbps_type;
      _total_data_rate_Mbps_type total_data_rate_Mbps;
      typedef float _loss_rate_percent_type;
      _loss_rate_percent_type loss_rate_percent;
      typedef float _theoretical_udp_throughput_Mbps_type;
      _theoretical_udp_throughput_Mbps_type theoretical_udp_throughput_Mbps;
      typedef int32_t _num_spatial_streams_type;
      _num_spatial_streams_type num_spatial_streams;
      uint32_t received_signal_power_dBm_length;
      typedef int32_t _received_signal_power_dBm_type;
      _received_signal_power_dBm_type st_received_signal_power_dBm;
      _received_signal_power_dBm_type * received_signal_power_dBm;
      typedef int32_t _link_adaptation_modulation_coding_scheme_type;
      _link_adaptation_modulation_coding_scheme_type link_adaptation_modulation_coding_scheme;
      typedef int32_t _guard_interval_mode_type;
      _guard_interval_mode_type guard_interval_mode;
      typedef int32_t _cyclic_prefix_length_type;
      _cyclic_prefix_length_type cyclic_prefix_length;

    SilvusStreamscapeNeighbor():
      my_node_id(0),
      my_node_label(""),
      my_robot_name(""),
      my_pg_key(0),
      my_noise_level_dBm(0),
      my_interference_dB(0),
      my_txpw_actual_mW(0),
      my_txpw_actual_dBm(0),
      neighbor_node_id(0),
      neighbor_node_label(""),
      neighbor_pg_key(0),
      color(""),
      queue_size(0),
      snr_dB(0),
      total_air_time_percent(0),
      total_data_rate_Mbps(0),
      loss_rate_percent(0),
      theoretical_udp_throughput_Mbps(0),
      num_spatial_streams(0),
      received_signal_power_dBm_length(0), st_received_signal_power_dBm(), received_signal_power_dBm(nullptr),
      link_adaptation_modulation_coding_scheme(0),
      guard_interval_mode(0),
      cyclic_prefix_length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_my_node_id;
      u_my_node_id.real = this->my_node_id;
      *(outbuffer + offset + 0) = (u_my_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_node_id);
      uint32_t length_my_node_label = strlen(this->my_node_label);
      varToArr(outbuffer + offset, length_my_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->my_node_label, length_my_node_label);
      offset += length_my_node_label;
      uint32_t length_my_robot_name = strlen(this->my_robot_name);
      varToArr(outbuffer + offset, length_my_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->my_robot_name, length_my_robot_name);
      offset += length_my_robot_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_my_pg_key;
      u_my_pg_key.real = this->my_pg_key;
      *(outbuffer + offset + 0) = (u_my_pg_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_pg_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_pg_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_pg_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_pg_key);
      union {
        int32_t real;
        uint32_t base;
      } u_my_noise_level_dBm;
      u_my_noise_level_dBm.real = this->my_noise_level_dBm;
      *(outbuffer + offset + 0) = (u_my_noise_level_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_noise_level_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_noise_level_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_noise_level_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_my_interference_dB;
      u_my_interference_dB.real = this->my_interference_dB;
      *(outbuffer + offset + 0) = (u_my_interference_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_interference_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_interference_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_interference_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_my_txpw_actual_mW;
      u_my_txpw_actual_mW.real = this->my_txpw_actual_mW;
      *(outbuffer + offset + 0) = (u_my_txpw_actual_mW.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_txpw_actual_mW.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_txpw_actual_mW.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_txpw_actual_mW.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_txpw_actual_mW);
      union {
        float real;
        uint32_t base;
      } u_my_txpw_actual_dBm;
      u_my_txpw_actual_dBm.real = this->my_txpw_actual_dBm;
      *(outbuffer + offset + 0) = (u_my_txpw_actual_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_my_txpw_actual_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_my_txpw_actual_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_my_txpw_actual_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->my_txpw_actual_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_neighbor_node_id;
      u_neighbor_node_id.real = this->neighbor_node_id;
      *(outbuffer + offset + 0) = (u_neighbor_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neighbor_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neighbor_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neighbor_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbor_node_id);
      uint32_t length_neighbor_node_label = strlen(this->neighbor_node_label);
      varToArr(outbuffer + offset, length_neighbor_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->neighbor_node_label, length_neighbor_node_label);
      offset += length_neighbor_node_label;
      union {
        uint64_t real;
        uint32_t base;
      } u_neighbor_pg_key;
      u_neighbor_pg_key.real = this->neighbor_pg_key;
      *(outbuffer + offset + 0) = (u_neighbor_pg_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neighbor_pg_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neighbor_pg_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neighbor_pg_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbor_pg_key);
      uint32_t length_color = strlen(this->color);
      varToArr(outbuffer + offset, length_color);
      offset += 4;
      memcpy(outbuffer + offset, this->color, length_color);
      offset += length_color;
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
      } u_snr_dB;
      u_snr_dB.real = this->snr_dB;
      *(outbuffer + offset + 0) = (u_snr_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_snr_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_snr_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_snr_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->snr_dB);
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
      } u_theoretical_udp_throughput_Mbps;
      u_theoretical_udp_throughput_Mbps.real = this->theoretical_udp_throughput_Mbps;
      *(outbuffer + offset + 0) = (u_theoretical_udp_throughput_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theoretical_udp_throughput_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theoretical_udp_throughput_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theoretical_udp_throughput_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theoretical_udp_throughput_Mbps);
      union {
        int32_t real;
        uint32_t base;
      } u_num_spatial_streams;
      u_num_spatial_streams.real = this->num_spatial_streams;
      *(outbuffer + offset + 0) = (u_num_spatial_streams.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_spatial_streams.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_spatial_streams.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_spatial_streams.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_spatial_streams);
      *(outbuffer + offset + 0) = (this->received_signal_power_dBm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->received_signal_power_dBm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->received_signal_power_dBm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->received_signal_power_dBm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->received_signal_power_dBm_length);
      for( uint32_t i = 0; i < received_signal_power_dBm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_received_signal_power_dBmi;
      u_received_signal_power_dBmi.real = this->received_signal_power_dBm[i];
      *(outbuffer + offset + 0) = (u_received_signal_power_dBmi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_received_signal_power_dBmi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_received_signal_power_dBmi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_received_signal_power_dBmi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->received_signal_power_dBm[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_modulation_coding_scheme;
      u_link_adaptation_modulation_coding_scheme.real = this->link_adaptation_modulation_coding_scheme;
      *(outbuffer + offset + 0) = (u_link_adaptation_modulation_coding_scheme.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_link_adaptation_modulation_coding_scheme.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_link_adaptation_modulation_coding_scheme.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_link_adaptation_modulation_coding_scheme.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_adaptation_modulation_coding_scheme);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_my_node_id;
      u_my_node_id.base = 0;
      u_my_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_node_id = u_my_node_id.real;
      offset += sizeof(this->my_node_id);
      uint32_t length_my_node_label;
      arrToVar(length_my_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_my_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_my_node_label-1]=0;
      this->my_node_label = (char *)(inbuffer + offset-1);
      offset += length_my_node_label;
      uint32_t length_my_robot_name;
      arrToVar(length_my_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_my_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_my_robot_name-1]=0;
      this->my_robot_name = (char *)(inbuffer + offset-1);
      offset += length_my_robot_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_my_pg_key;
      u_my_pg_key.base = 0;
      u_my_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_pg_key = u_my_pg_key.real;
      offset += sizeof(this->my_pg_key);
      union {
        int32_t real;
        uint32_t base;
      } u_my_noise_level_dBm;
      u_my_noise_level_dBm.base = 0;
      u_my_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_noise_level_dBm = u_my_noise_level_dBm.real;
      offset += sizeof(this->my_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_my_interference_dB;
      u_my_interference_dB.base = 0;
      u_my_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_interference_dB = u_my_interference_dB.real;
      offset += sizeof(this->my_interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_my_txpw_actual_mW;
      u_my_txpw_actual_mW.base = 0;
      u_my_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_txpw_actual_mW.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_txpw_actual_mW = u_my_txpw_actual_mW.real;
      offset += sizeof(this->my_txpw_actual_mW);
      union {
        float real;
        uint32_t base;
      } u_my_txpw_actual_dBm;
      u_my_txpw_actual_dBm.base = 0;
      u_my_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_my_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_my_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_my_txpw_actual_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->my_txpw_actual_dBm = u_my_txpw_actual_dBm.real;
      offset += sizeof(this->my_txpw_actual_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_neighbor_node_id;
      u_neighbor_node_id.base = 0;
      u_neighbor_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neighbor_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neighbor_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neighbor_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neighbor_node_id = u_neighbor_node_id.real;
      offset += sizeof(this->neighbor_node_id);
      uint32_t length_neighbor_node_label;
      arrToVar(length_neighbor_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_neighbor_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_neighbor_node_label-1]=0;
      this->neighbor_node_label = (char *)(inbuffer + offset-1);
      offset += length_neighbor_node_label;
      union {
        uint64_t real;
        uint32_t base;
      } u_neighbor_pg_key;
      u_neighbor_pg_key.base = 0;
      u_neighbor_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neighbor_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neighbor_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neighbor_pg_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neighbor_pg_key = u_neighbor_pg_key.real;
      offset += sizeof(this->neighbor_pg_key);
      uint32_t length_color;
      arrToVar(length_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color-1]=0;
      this->color = (char *)(inbuffer + offset-1);
      offset += length_color;
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
      } u_snr_dB;
      u_snr_dB.base = 0;
      u_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->snr_dB = u_snr_dB.real;
      offset += sizeof(this->snr_dB);
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
      } u_theoretical_udp_throughput_Mbps;
      u_theoretical_udp_throughput_Mbps.base = 0;
      u_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theoretical_udp_throughput_Mbps = u_theoretical_udp_throughput_Mbps.real;
      offset += sizeof(this->theoretical_udp_throughput_Mbps);
      union {
        int32_t real;
        uint32_t base;
      } u_num_spatial_streams;
      u_num_spatial_streams.base = 0;
      u_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_spatial_streams = u_num_spatial_streams.real;
      offset += sizeof(this->num_spatial_streams);
      uint32_t received_signal_power_dBm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      received_signal_power_dBm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      received_signal_power_dBm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      received_signal_power_dBm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->received_signal_power_dBm_length);
      if(received_signal_power_dBm_lengthT > received_signal_power_dBm_length)
        this->received_signal_power_dBm = (int32_t*)realloc(this->received_signal_power_dBm, received_signal_power_dBm_lengthT * sizeof(int32_t));
      received_signal_power_dBm_length = received_signal_power_dBm_lengthT;
      for( uint32_t i = 0; i < received_signal_power_dBm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_received_signal_power_dBm;
      u_st_received_signal_power_dBm.base = 0;
      u_st_received_signal_power_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_received_signal_power_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_received_signal_power_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_received_signal_power_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_received_signal_power_dBm = u_st_received_signal_power_dBm.real;
      offset += sizeof(this->st_received_signal_power_dBm);
        memcpy( &(this->received_signal_power_dBm[i]), &(this->st_received_signal_power_dBm), sizeof(int32_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_link_adaptation_modulation_coding_scheme;
      u_link_adaptation_modulation_coding_scheme.base = 0;
      u_link_adaptation_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_link_adaptation_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_link_adaptation_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_link_adaptation_modulation_coding_scheme.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->link_adaptation_modulation_coding_scheme = u_link_adaptation_modulation_coding_scheme.real;
      offset += sizeof(this->link_adaptation_modulation_coding_scheme);
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
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusStreamscapeNeighbor"; };
    virtual const char * getMD5() override { return "6587aa25a31507ea086a23f8e96e1ed2"; };

  };

}
#endif
