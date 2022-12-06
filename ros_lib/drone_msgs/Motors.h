#ifndef _ROS_drone_msgs_Motors_h
#define _ROS_drone_msgs_Motors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace drone_msgs
{

  class Motors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _m1_type;
      _m1_type m1;
      typedef double _m2_type;
      _m2_type m2;
      typedef double _m3_type;
      _m3_type m3;
      typedef double _m4_type;
      _m4_type m4;
      typedef double _m5_type;
      _m5_type m5;
      typedef double _m6_type;
      _m6_type m6;
      typedef double _m7_type;
      _m7_type m7;
      typedef double _m8_type;
      _m8_type m8;

    Motors():
      header(),
      m1(0),
      m2(0),
      m3(0),
      m4(0),
      m5(0),
      m6(0),
      m7(0),
      m8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_m1;
      u_m1.real = this->m1;
      *(outbuffer + offset + 0) = (u_m1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m1);
      union {
        double real;
        uint64_t base;
      } u_m2;
      u_m2.real = this->m2;
      *(outbuffer + offset + 0) = (u_m2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m2);
      union {
        double real;
        uint64_t base;
      } u_m3;
      u_m3.real = this->m3;
      *(outbuffer + offset + 0) = (u_m3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m3);
      union {
        double real;
        uint64_t base;
      } u_m4;
      u_m4.real = this->m4;
      *(outbuffer + offset + 0) = (u_m4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m4.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m4.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m4.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m4.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m4.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m4);
      union {
        double real;
        uint64_t base;
      } u_m5;
      u_m5.real = this->m5;
      *(outbuffer + offset + 0) = (u_m5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m5.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m5.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m5.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m5.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m5.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m5);
      union {
        double real;
        uint64_t base;
      } u_m6;
      u_m6.real = this->m6;
      *(outbuffer + offset + 0) = (u_m6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m6.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m6.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m6.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m6.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m6.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m6);
      union {
        double real;
        uint64_t base;
      } u_m7;
      u_m7.real = this->m7;
      *(outbuffer + offset + 0) = (u_m7.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m7.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m7.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m7.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m7.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m7.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m7.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m7.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m7);
      union {
        double real;
        uint64_t base;
      } u_m8;
      u_m8.real = this->m8;
      *(outbuffer + offset + 0) = (u_m8.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m8.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m8.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m8.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m8.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m8.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m8.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m8.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_m1;
      u_m1.base = 0;
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m1 = u_m1.real;
      offset += sizeof(this->m1);
      union {
        double real;
        uint64_t base;
      } u_m2;
      u_m2.base = 0;
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m2 = u_m2.real;
      offset += sizeof(this->m2);
      union {
        double real;
        uint64_t base;
      } u_m3;
      u_m3.base = 0;
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m3 = u_m3.real;
      offset += sizeof(this->m3);
      union {
        double real;
        uint64_t base;
      } u_m4;
      u_m4.base = 0;
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m4.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m4 = u_m4.real;
      offset += sizeof(this->m4);
      union {
        double real;
        uint64_t base;
      } u_m5;
      u_m5.base = 0;
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m5.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m5 = u_m5.real;
      offset += sizeof(this->m5);
      union {
        double real;
        uint64_t base;
      } u_m6;
      u_m6.base = 0;
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m6.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m6 = u_m6.real;
      offset += sizeof(this->m6);
      union {
        double real;
        uint64_t base;
      } u_m7;
      u_m7.base = 0;
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m7.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m7 = u_m7.real;
      offset += sizeof(this->m7);
      union {
        double real;
        uint64_t base;
      } u_m8;
      u_m8.base = 0;
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m8.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m8 = u_m8.real;
      offset += sizeof(this->m8);
     return offset;
    }

    virtual const char * getType() override { return "drone_msgs/Motors"; };
    virtual const char * getMD5() override { return "2f7b2f19c4fbfd9dffd8b02620937b0a"; };

  };

}
#endif
