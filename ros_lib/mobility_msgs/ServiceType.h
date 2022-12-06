#ifndef _ROS_mobility_msgs_ServiceType_h
#define _ROS_mobility_msgs_ServiceType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mobility_msgs
{

  class ServiceType : public ros::Msg
  {
    public:
      typedef uint8_t _service_type;
      _service_type service;
      enum { IDLE =  0    };
      enum { DRIVE_TO =  10   };
      enum { DRIVE_FORWARD =  11   };
      enum { DRIVE_TO_BACKWARDS =  12   };
      enum { DRIVE_TO_RELATIVE =  13   };
      enum { DRIVE_TO_BACKWARDS_RELATIVE =  14   };
      enum { CLIMB_STAIRS =  15   };
      enum { DRIVE_TO_SINGLE_OVERRIDABLE =  16   };
      enum { DRIVE_ALONG_PATH =  17   };
      enum { TAKEOFF =  20   };
      enum { LAND =  21   };
      enum { EMERGENCY_LAND =  22   };
      enum { DISARM =  23   };
      enum { FLY_TO =  30   };
      enum { FLY_FORWARD =  31   };
      enum { HOVER =  40   };

    ServiceType():
      service(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->service >> (8 * 0)) & 0xFF;
      offset += sizeof(this->service);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->service =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->service);
     return offset;
    }

    virtual const char * getType() override { return "mobility_msgs/ServiceType"; };
    virtual const char * getMD5() override { return "43767c80a9179a4ead6c755865f3c047"; };

  };

}
#endif
