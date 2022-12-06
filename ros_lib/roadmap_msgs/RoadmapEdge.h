#ifndef _ROS_roadmap_msgs_RoadmapEdge_h
#define _ROS_roadmap_msgs_RoadmapEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "roadmap_msgs/RoadmapProperty.h"

namespace roadmap_msgs
{

  class RoadmapEdge : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint32_t _u_type;
      _u_type u;
      typedef uint32_t _v_type;
      _v_type v;
      uint32_t properties_length;
      typedef roadmap_msgs::RoadmapProperty _properties_type;
      _properties_type st_properties;
      _properties_type * properties;

    RoadmapEdge():
      stamp(),
      u(0),
      v(0),
      properties_length(0), st_properties(), properties(nullptr)
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
      *(outbuffer + offset + 0) = (this->u >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->u >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->u >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->u >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      *(outbuffer + offset + 0) = (this->v >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->v >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->v >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->v >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      *(outbuffer + offset + 0) = (this->properties_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->properties_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->properties_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->properties_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->properties_length);
      for( uint32_t i = 0; i < properties_length; i++){
      offset += this->properties[i].serialize(outbuffer + offset);
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
      this->u =  ((uint32_t) (*(inbuffer + offset)));
      this->u |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->u |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->u |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->u);
      this->v =  ((uint32_t) (*(inbuffer + offset)));
      this->v |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->v |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->v |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->v);
      uint32_t properties_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->properties_length);
      if(properties_lengthT > properties_length)
        this->properties = (roadmap_msgs::RoadmapProperty*)realloc(this->properties, properties_lengthT * sizeof(roadmap_msgs::RoadmapProperty));
      properties_length = properties_lengthT;
      for( uint32_t i = 0; i < properties_length; i++){
      offset += this->st_properties.deserialize(inbuffer + offset);
        memcpy( &(this->properties[i]), &(this->st_properties), sizeof(roadmap_msgs::RoadmapProperty));
      }
     return offset;
    }

    virtual const char * getType() override { return "roadmap_msgs/RoadmapEdge"; };
    virtual const char * getMD5() override { return "77439b535b00e0be1e4866c0c66cc936"; };

  };

}
#endif
