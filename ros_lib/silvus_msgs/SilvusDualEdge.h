#ifndef _ROS_silvus_msgs_SilvusDualEdge_h
#define _ROS_silvus_msgs_SilvusDualEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "silvus_msgs/SilvusStreamscapeNeighbor.h"

namespace silvus_msgs
{

  class SilvusDualEdge : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      uint32_t neighbors_length;
      typedef silvus_msgs::SilvusStreamscapeNeighbor _neighbors_type;
      _neighbors_type st_neighbors;
      _neighbors_type * neighbors;

    SilvusDualEdge():
      stamp(),
      neighbors_length(0), st_neighbors(), neighbors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      *(outbuffer + offset + 0) = (this->neighbors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighbors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighbors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighbors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbors_length);
      for( uint32_t i = 0; i < neighbors_length; i++){
      offset += this->neighbors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
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
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusDualEdge"; };
    virtual const char * getMD5() override { return "601db5d557c10a370048e5f33cb5d770"; };

  };

}
#endif
