/*
 * vehicleid.h
 *
 *  Created on: Jun 29, 2021
 *      Author: akourchi
 */

#ifndef INC_VEHICLEID_H_
#define INC_VEHICLEID_H_

#include "util.h"

// Forward declaration
class VehicleID;

extern VehicleID VehID;

// Vehicle Type
// Switch ON   -> Signal is LOW
// 000 Husky   -> 000 Husky
// 001 Telemax -> 001 Telemax
// 010 Spot    -> 010 Spot
enum vehicle_type {
	kHusky = 0,
	kTelemax = 1,
	kSpot = 2
};

class VehicleID
{
public:

	VehicleID(void);

	virtual ~VehicleID();

	void Init();

	// Returns the vehicle type
	vehicle_type GetVehicleType(void);

private:

	// Reads the ID for the vehicle
	uint8_t ReadVehicleID(void);

	vehicle_type m_id_;
};



#endif /* INC_VEHICLEID_H_ */
