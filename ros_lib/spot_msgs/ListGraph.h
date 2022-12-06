#ifndef _ROS_SERVICE_ListGraph_h
#define _ROS_SERVICE_ListGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

static const char LISTGRAPH[] = "spot_msgs/ListGraph";

  class ListGraphRequest : public ros::Msg
  {
    public:
      typedef const char* _upload_filepath_type;
      _upload_filepath_type upload_filepath;

    ListGraphRequest():
      upload_filepath("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_upload_filepath = strlen(this->upload_filepath);
      varToArr(outbuffer + offset, length_upload_filepath);
      offset += 4;
      memcpy(outbuffer + offset, this->upload_filepath, length_upload_filepath);
      offset += length_upload_filepath;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_upload_filepath;
      arrToVar(length_upload_filepath, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_upload_filepath; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_upload_filepath-1]=0;
      this->upload_filepath = (char *)(inbuffer + offset-1);
      offset += length_upload_filepath;
     return offset;
    }

    virtual const char * getType() override { return LISTGRAPH; };
    virtual const char * getMD5() override { return "01555024216a394c0adb22a6e9118fe3"; };

  };

  class ListGraphResponse : public ros::Msg
  {
    public:
      uint32_t waypoint_ids_length;
      typedef char* _waypoint_ids_type;
      _waypoint_ids_type st_waypoint_ids;
      _waypoint_ids_type * waypoint_ids;

    ListGraphResponse():
      waypoint_ids_length(0), st_waypoint_ids(), waypoint_ids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->waypoint_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->waypoint_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->waypoint_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->waypoint_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoint_ids_length);
      for( uint32_t i = 0; i < waypoint_ids_length; i++){
      uint32_t length_waypoint_idsi = strlen(this->waypoint_ids[i]);
      varToArr(outbuffer + offset, length_waypoint_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->waypoint_ids[i], length_waypoint_idsi);
      offset += length_waypoint_idsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t waypoint_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      waypoint_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      waypoint_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      waypoint_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->waypoint_ids_length);
      if(waypoint_ids_lengthT > waypoint_ids_length)
        this->waypoint_ids = (char**)realloc(this->waypoint_ids, waypoint_ids_lengthT * sizeof(char*));
      waypoint_ids_length = waypoint_ids_lengthT;
      for( uint32_t i = 0; i < waypoint_ids_length; i++){
      uint32_t length_st_waypoint_ids;
      arrToVar(length_st_waypoint_ids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_waypoint_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_waypoint_ids-1]=0;
      this->st_waypoint_ids = (char *)(inbuffer + offset-1);
      offset += length_st_waypoint_ids;
        memcpy( &(this->waypoint_ids[i]), &(this->st_waypoint_ids), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return LISTGRAPH; };
    virtual const char * getMD5() override { return "118b8bcfd9aa792758857e91da4c7a89"; };

  };

  class ListGraph {
    public:
    typedef ListGraphRequest Request;
    typedef ListGraphResponse Response;
  };

}
#endif
