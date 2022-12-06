#ifndef _ROS_silvus_msgs_SilvusRoute_h
#define _ROS_silvus_msgs_SilvusRoute_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "silvus_msgs/SilvusStreamscapeNeighbor.h"

namespace silvus_msgs
{

  class SilvusRoute : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _streamscape_sequence_number_type;
      _streamscape_sequence_number_type streamscape_sequence_number;
      typedef int32_t _source_node_id_type;
      _source_node_id_type source_node_id;
      typedef int32_t _target_node_id_type;
      _target_node_id_type target_node_id;
      typedef const char* _source_node_label_type;
      _source_node_label_type source_node_label;
      typedef const char* _target_node_label_type;
      _target_node_label_type target_node_label;
      typedef const char* _source_robot_type;
      _source_robot_type source_robot;
      typedef const char* _target_robot_type;
      _target_robot_type target_robot;
      uint32_t comm_node_name_hops_length;
      typedef char* _comm_node_name_hops_type;
      _comm_node_name_hops_type st_comm_node_name_hops;
      _comm_node_name_hops_type * comm_node_name_hops;
      uint32_t comm_node_id_hops_length;
      typedef int32_t _comm_node_id_hops_type;
      _comm_node_id_hops_type st_comm_node_id_hops;
      _comm_node_id_hops_type * comm_node_id_hops;
      uint32_t links_length;
      typedef silvus_msgs::SilvusStreamscapeNeighbor _links_type;
      _links_type st_links;
      _links_type * links;
      typedef int32_t _target_noise_level_dBm_type;
      _target_noise_level_dBm_type target_noise_level_dBm;
      typedef int32_t _target_interference_dB_type;
      _target_interference_dB_type target_interference_dB;
      typedef int32_t _max_queue_size_type;
      _max_queue_size_type max_queue_size;
      typedef int32_t _min_snr_dB_type;
      _min_snr_dB_type min_snr_dB;
      typedef float _min_data_rate_margin_Mbps_type;
      _min_data_rate_margin_Mbps_type min_data_rate_margin_Mbps;
      typedef float _max_total_data_rate_Mbps_type;
      _max_total_data_rate_Mbps_type max_total_data_rate_Mbps;
      typedef float _min_total_data_rate_Mbps_type;
      _min_total_data_rate_Mbps_type min_total_data_rate_Mbps;
      typedef float _max_loss_rate_percent_type;
      _max_loss_rate_percent_type max_loss_rate_percent;
      typedef float _min_estimated_udp_throughput_Mbps_type;
      _min_estimated_udp_throughput_Mbps_type min_estimated_udp_throughput_Mbps;
      typedef float _min_theoretical_udp_throughput_Mbps_type;
      _min_theoretical_udp_throughput_Mbps_type min_theoretical_udp_throughput_Mbps;
      typedef int32_t _min_num_spatial_streams_type;
      _min_num_spatial_streams_type min_num_spatial_streams;
      typedef int32_t _max_noise_level_dBm_type;
      _max_noise_level_dBm_type max_noise_level_dBm;
      typedef int32_t _max_interference_dB_type;
      _max_interference_dB_type max_interference_dB;

    SilvusRoute():
      header(),
      streamscape_sequence_number(0),
      source_node_id(0),
      target_node_id(0),
      source_node_label(""),
      target_node_label(""),
      source_robot(""),
      target_robot(""),
      comm_node_name_hops_length(0), st_comm_node_name_hops(), comm_node_name_hops(nullptr),
      comm_node_id_hops_length(0), st_comm_node_id_hops(), comm_node_id_hops(nullptr),
      links_length(0), st_links(), links(nullptr),
      target_noise_level_dBm(0),
      target_interference_dB(0),
      max_queue_size(0),
      min_snr_dB(0),
      min_data_rate_margin_Mbps(0),
      max_total_data_rate_Mbps(0),
      min_total_data_rate_Mbps(0),
      max_loss_rate_percent(0),
      min_estimated_udp_throughput_Mbps(0),
      min_theoretical_udp_throughput_Mbps(0),
      min_num_spatial_streams(0),
      max_noise_level_dBm(0),
      max_interference_dB(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_streamscape_sequence_number;
      u_streamscape_sequence_number.real = this->streamscape_sequence_number;
      *(outbuffer + offset + 0) = (u_streamscape_sequence_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_streamscape_sequence_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_streamscape_sequence_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_streamscape_sequence_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->streamscape_sequence_number);
      union {
        int32_t real;
        uint32_t base;
      } u_source_node_id;
      u_source_node_id.real = this->source_node_id;
      *(outbuffer + offset + 0) = (u_source_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_source_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_source_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_source_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->source_node_id);
      union {
        int32_t real;
        uint32_t base;
      } u_target_node_id;
      u_target_node_id.real = this->target_node_id;
      *(outbuffer + offset + 0) = (u_target_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_node_id);
      uint32_t length_source_node_label = strlen(this->source_node_label);
      varToArr(outbuffer + offset, length_source_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->source_node_label, length_source_node_label);
      offset += length_source_node_label;
      uint32_t length_target_node_label = strlen(this->target_node_label);
      varToArr(outbuffer + offset, length_target_node_label);
      offset += 4;
      memcpy(outbuffer + offset, this->target_node_label, length_target_node_label);
      offset += length_target_node_label;
      uint32_t length_source_robot = strlen(this->source_robot);
      varToArr(outbuffer + offset, length_source_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->source_robot, length_source_robot);
      offset += length_source_robot;
      uint32_t length_target_robot = strlen(this->target_robot);
      varToArr(outbuffer + offset, length_target_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->target_robot, length_target_robot);
      offset += length_target_robot;
      *(outbuffer + offset + 0) = (this->comm_node_name_hops_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->comm_node_name_hops_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->comm_node_name_hops_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->comm_node_name_hops_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->comm_node_name_hops_length);
      for( uint32_t i = 0; i < comm_node_name_hops_length; i++){
      uint32_t length_comm_node_name_hopsi = strlen(this->comm_node_name_hops[i]);
      varToArr(outbuffer + offset, length_comm_node_name_hopsi);
      offset += 4;
      memcpy(outbuffer + offset, this->comm_node_name_hops[i], length_comm_node_name_hopsi);
      offset += length_comm_node_name_hopsi;
      }
      *(outbuffer + offset + 0) = (this->comm_node_id_hops_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->comm_node_id_hops_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->comm_node_id_hops_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->comm_node_id_hops_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->comm_node_id_hops_length);
      for( uint32_t i = 0; i < comm_node_id_hops_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_comm_node_id_hopsi;
      u_comm_node_id_hopsi.real = this->comm_node_id_hops[i];
      *(outbuffer + offset + 0) = (u_comm_node_id_hopsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_comm_node_id_hopsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_comm_node_id_hopsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_comm_node_id_hopsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->comm_node_id_hops[i]);
      }
      *(outbuffer + offset + 0) = (this->links_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->links_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->links_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->links_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->links_length);
      for( uint32_t i = 0; i < links_length; i++){
      offset += this->links[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_target_noise_level_dBm;
      u_target_noise_level_dBm.real = this->target_noise_level_dBm;
      *(outbuffer + offset + 0) = (u_target_noise_level_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_noise_level_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_noise_level_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_noise_level_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_target_interference_dB;
      u_target_interference_dB.real = this->target_interference_dB;
      *(outbuffer + offset + 0) = (u_target_interference_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_interference_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_interference_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_interference_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_max_queue_size;
      u_max_queue_size.real = this->max_queue_size;
      *(outbuffer + offset + 0) = (u_max_queue_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_queue_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_queue_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_queue_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_queue_size);
      union {
        int32_t real;
        uint32_t base;
      } u_min_snr_dB;
      u_min_snr_dB.real = this->min_snr_dB;
      *(outbuffer + offset + 0) = (u_min_snr_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_snr_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_snr_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_snr_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_snr_dB);
      union {
        float real;
        uint32_t base;
      } u_min_data_rate_margin_Mbps;
      u_min_data_rate_margin_Mbps.real = this->min_data_rate_margin_Mbps;
      *(outbuffer + offset + 0) = (u_min_data_rate_margin_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_data_rate_margin_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_data_rate_margin_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_data_rate_margin_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_data_rate_margin_Mbps);
      union {
        float real;
        uint32_t base;
      } u_max_total_data_rate_Mbps;
      u_max_total_data_rate_Mbps.real = this->max_total_data_rate_Mbps;
      *(outbuffer + offset + 0) = (u_max_total_data_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_total_data_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_total_data_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_total_data_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_min_total_data_rate_Mbps;
      u_min_total_data_rate_Mbps.real = this->min_total_data_rate_Mbps;
      *(outbuffer + offset + 0) = (u_min_total_data_rate_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_total_data_rate_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_total_data_rate_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_total_data_rate_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_max_loss_rate_percent;
      u_max_loss_rate_percent.real = this->max_loss_rate_percent;
      *(outbuffer + offset + 0) = (u_max_loss_rate_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_loss_rate_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_loss_rate_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_loss_rate_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_loss_rate_percent);
      union {
        float real;
        uint32_t base;
      } u_min_estimated_udp_throughput_Mbps;
      u_min_estimated_udp_throughput_Mbps.real = this->min_estimated_udp_throughput_Mbps;
      *(outbuffer + offset + 0) = (u_min_estimated_udp_throughput_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_estimated_udp_throughput_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_estimated_udp_throughput_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_estimated_udp_throughput_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_estimated_udp_throughput_Mbps);
      union {
        float real;
        uint32_t base;
      } u_min_theoretical_udp_throughput_Mbps;
      u_min_theoretical_udp_throughput_Mbps.real = this->min_theoretical_udp_throughput_Mbps;
      *(outbuffer + offset + 0) = (u_min_theoretical_udp_throughput_Mbps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_theoretical_udp_throughput_Mbps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_theoretical_udp_throughput_Mbps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_theoretical_udp_throughput_Mbps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_theoretical_udp_throughput_Mbps);
      union {
        int32_t real;
        uint32_t base;
      } u_min_num_spatial_streams;
      u_min_num_spatial_streams.real = this->min_num_spatial_streams;
      *(outbuffer + offset + 0) = (u_min_num_spatial_streams.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_num_spatial_streams.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_num_spatial_streams.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_num_spatial_streams.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_num_spatial_streams);
      union {
        int32_t real;
        uint32_t base;
      } u_max_noise_level_dBm;
      u_max_noise_level_dBm.real = this->max_noise_level_dBm;
      *(outbuffer + offset + 0) = (u_max_noise_level_dBm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_noise_level_dBm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_noise_level_dBm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_noise_level_dBm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_max_interference_dB;
      u_max_interference_dB.real = this->max_interference_dB;
      *(outbuffer + offset + 0) = (u_max_interference_dB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_interference_dB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_interference_dB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_interference_dB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_interference_dB);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_streamscape_sequence_number;
      u_streamscape_sequence_number.base = 0;
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_streamscape_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->streamscape_sequence_number = u_streamscape_sequence_number.real;
      offset += sizeof(this->streamscape_sequence_number);
      union {
        int32_t real;
        uint32_t base;
      } u_source_node_id;
      u_source_node_id.base = 0;
      u_source_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_source_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_source_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_source_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->source_node_id = u_source_node_id.real;
      offset += sizeof(this->source_node_id);
      union {
        int32_t real;
        uint32_t base;
      } u_target_node_id;
      u_target_node_id.base = 0;
      u_target_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_node_id = u_target_node_id.real;
      offset += sizeof(this->target_node_id);
      uint32_t length_source_node_label;
      arrToVar(length_source_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_node_label-1]=0;
      this->source_node_label = (char *)(inbuffer + offset-1);
      offset += length_source_node_label;
      uint32_t length_target_node_label;
      arrToVar(length_target_node_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_node_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_node_label-1]=0;
      this->target_node_label = (char *)(inbuffer + offset-1);
      offset += length_target_node_label;
      uint32_t length_source_robot;
      arrToVar(length_source_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_robot-1]=0;
      this->source_robot = (char *)(inbuffer + offset-1);
      offset += length_source_robot;
      uint32_t length_target_robot;
      arrToVar(length_target_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_robot-1]=0;
      this->target_robot = (char *)(inbuffer + offset-1);
      offset += length_target_robot;
      uint32_t comm_node_name_hops_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      comm_node_name_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      comm_node_name_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      comm_node_name_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->comm_node_name_hops_length);
      if(comm_node_name_hops_lengthT > comm_node_name_hops_length)
        this->comm_node_name_hops = (char**)realloc(this->comm_node_name_hops, comm_node_name_hops_lengthT * sizeof(char*));
      comm_node_name_hops_length = comm_node_name_hops_lengthT;
      for( uint32_t i = 0; i < comm_node_name_hops_length; i++){
      uint32_t length_st_comm_node_name_hops;
      arrToVar(length_st_comm_node_name_hops, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_comm_node_name_hops; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_comm_node_name_hops-1]=0;
      this->st_comm_node_name_hops = (char *)(inbuffer + offset-1);
      offset += length_st_comm_node_name_hops;
        memcpy( &(this->comm_node_name_hops[i]), &(this->st_comm_node_name_hops), sizeof(char*));
      }
      uint32_t comm_node_id_hops_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      comm_node_id_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      comm_node_id_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      comm_node_id_hops_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->comm_node_id_hops_length);
      if(comm_node_id_hops_lengthT > comm_node_id_hops_length)
        this->comm_node_id_hops = (int32_t*)realloc(this->comm_node_id_hops, comm_node_id_hops_lengthT * sizeof(int32_t));
      comm_node_id_hops_length = comm_node_id_hops_lengthT;
      for( uint32_t i = 0; i < comm_node_id_hops_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_comm_node_id_hops;
      u_st_comm_node_id_hops.base = 0;
      u_st_comm_node_id_hops.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_comm_node_id_hops.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_comm_node_id_hops.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_comm_node_id_hops.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_comm_node_id_hops = u_st_comm_node_id_hops.real;
      offset += sizeof(this->st_comm_node_id_hops);
        memcpy( &(this->comm_node_id_hops[i]), &(this->st_comm_node_id_hops), sizeof(int32_t));
      }
      uint32_t links_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->links_length);
      if(links_lengthT > links_length)
        this->links = (silvus_msgs::SilvusStreamscapeNeighbor*)realloc(this->links, links_lengthT * sizeof(silvus_msgs::SilvusStreamscapeNeighbor));
      links_length = links_lengthT;
      for( uint32_t i = 0; i < links_length; i++){
      offset += this->st_links.deserialize(inbuffer + offset);
        memcpy( &(this->links[i]), &(this->st_links), sizeof(silvus_msgs::SilvusStreamscapeNeighbor));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_target_noise_level_dBm;
      u_target_noise_level_dBm.base = 0;
      u_target_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_noise_level_dBm = u_target_noise_level_dBm.real;
      offset += sizeof(this->target_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_target_interference_dB;
      u_target_interference_dB.base = 0;
      u_target_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_interference_dB = u_target_interference_dB.real;
      offset += sizeof(this->target_interference_dB);
      union {
        int32_t real;
        uint32_t base;
      } u_max_queue_size;
      u_max_queue_size.base = 0;
      u_max_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_queue_size = u_max_queue_size.real;
      offset += sizeof(this->max_queue_size);
      union {
        int32_t real;
        uint32_t base;
      } u_min_snr_dB;
      u_min_snr_dB.base = 0;
      u_min_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_snr_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_snr_dB = u_min_snr_dB.real;
      offset += sizeof(this->min_snr_dB);
      union {
        float real;
        uint32_t base;
      } u_min_data_rate_margin_Mbps;
      u_min_data_rate_margin_Mbps.base = 0;
      u_min_data_rate_margin_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_data_rate_margin_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_data_rate_margin_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_data_rate_margin_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_data_rate_margin_Mbps = u_min_data_rate_margin_Mbps.real;
      offset += sizeof(this->min_data_rate_margin_Mbps);
      union {
        float real;
        uint32_t base;
      } u_max_total_data_rate_Mbps;
      u_max_total_data_rate_Mbps.base = 0;
      u_max_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_total_data_rate_Mbps = u_max_total_data_rate_Mbps.real;
      offset += sizeof(this->max_total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_min_total_data_rate_Mbps;
      u_min_total_data_rate_Mbps.base = 0;
      u_min_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_total_data_rate_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_total_data_rate_Mbps = u_min_total_data_rate_Mbps.real;
      offset += sizeof(this->min_total_data_rate_Mbps);
      union {
        float real;
        uint32_t base;
      } u_max_loss_rate_percent;
      u_max_loss_rate_percent.base = 0;
      u_max_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_loss_rate_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_loss_rate_percent = u_max_loss_rate_percent.real;
      offset += sizeof(this->max_loss_rate_percent);
      union {
        float real;
        uint32_t base;
      } u_min_estimated_udp_throughput_Mbps;
      u_min_estimated_udp_throughput_Mbps.base = 0;
      u_min_estimated_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_estimated_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_estimated_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_estimated_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_estimated_udp_throughput_Mbps = u_min_estimated_udp_throughput_Mbps.real;
      offset += sizeof(this->min_estimated_udp_throughput_Mbps);
      union {
        float real;
        uint32_t base;
      } u_min_theoretical_udp_throughput_Mbps;
      u_min_theoretical_udp_throughput_Mbps.base = 0;
      u_min_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_theoretical_udp_throughput_Mbps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_theoretical_udp_throughput_Mbps = u_min_theoretical_udp_throughput_Mbps.real;
      offset += sizeof(this->min_theoretical_udp_throughput_Mbps);
      union {
        int32_t real;
        uint32_t base;
      } u_min_num_spatial_streams;
      u_min_num_spatial_streams.base = 0;
      u_min_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_num_spatial_streams.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_num_spatial_streams = u_min_num_spatial_streams.real;
      offset += sizeof(this->min_num_spatial_streams);
      union {
        int32_t real;
        uint32_t base;
      } u_max_noise_level_dBm;
      u_max_noise_level_dBm.base = 0;
      u_max_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_noise_level_dBm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_noise_level_dBm = u_max_noise_level_dBm.real;
      offset += sizeof(this->max_noise_level_dBm);
      union {
        int32_t real;
        uint32_t base;
      } u_max_interference_dB;
      u_max_interference_dB.base = 0;
      u_max_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_interference_dB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_interference_dB = u_max_interference_dB.real;
      offset += sizeof(this->max_interference_dB);
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusRoute"; };
    virtual const char * getMD5() override { return "0b9a294abccba4a33cf807f3f890ec33"; };

  };

}
#endif
