#ifndef _ROS_silvus_msgs_SilvusRouteList_h
#define _ROS_silvus_msgs_SilvusRouteList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "silvus_msgs/SilvusRoute.h"

namespace silvus_msgs
{

  class SilvusRouteList : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _streamscape_sequence_number_type;
      _streamscape_sequence_number_type streamscape_sequence_number;
      uint32_t routes_length;
      typedef silvus_msgs::SilvusRoute _routes_type;
      _routes_type st_routes;
      _routes_type * routes;

    SilvusRouteList():
      header(),
      streamscape_sequence_number(0),
      routes_length(0), st_routes(), routes(nullptr)
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
      *(outbuffer + offset + 0) = (this->routes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routes_length);
      for( uint32_t i = 0; i < routes_length; i++){
      offset += this->routes[i].serialize(outbuffer + offset);
      }
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
      uint32_t routes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->routes_length);
      if(routes_lengthT > routes_length)
        this->routes = (silvus_msgs::SilvusRoute*)realloc(this->routes, routes_lengthT * sizeof(silvus_msgs::SilvusRoute));
      routes_length = routes_lengthT;
      for( uint32_t i = 0; i < routes_length; i++){
      offset += this->st_routes.deserialize(inbuffer + offset);
        memcpy( &(this->routes[i]), &(this->st_routes), sizeof(silvus_msgs::SilvusRoute));
      }
     return offset;
    }

    virtual const char * getType() override { return "silvus_msgs/SilvusRouteList"; };
    virtual const char * getMD5() override { return "2fe90ce38bf1691f4ca1b5886d9389e0"; };

  };

}
#endif
