/*
 * SubTCommDropHardware
 *
 *  Created on: Mar 8, 2021
 *      Author: T. Pailevanian
 */

#ifndef ROS_SUBTCOMMDROP_HARDWARE_H_
#define ROS_SUBTCOMMDROP_HARDWARE_H_

#include "usb.h"
#include "util.h"

class SubTCommDropHardware {
public:
    SubTCommDropHardware(){}

    void init(){}

    int read(){
      if (Usb.GetCounterRX()) {
          return Usb.GetByte();
      } else {
          return -1;
      }
    };
    void write(uint8_t* data, int length) {
      Usb.SendData(data, length);
    }

    unsigned long time(){
      return GetTicks();
    }
};


#endif /* ROS_MBED_HARDWARE_H_ */
