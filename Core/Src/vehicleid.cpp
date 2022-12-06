/*
 * vehicleid.cpp
 *
 *  Created on: Jun 29, 2021
 *      Author: akourchi
 */

#include "vehicleid.h"
#include "gpio.h"

VehicleID VehID;

VehicleID::VehicleID() {


}

// TODO: Destructor
VehicleID::~VehicleID(){}

void VehicleID::Init() {

	// Read Vehicle ID once on power up
	m_id_ = static_cast<vehicle_type>(ReadVehicleID());

}

uint8_t VehicleID::ReadVehicleID() {

	uint8_t bit0, bit1, bit2;
	uint8_t bit_id;

	bit2 = veh_id_2.GetBit() ? 1 : 0;
	bit1 = veh_id_1.GetBit() ? 1 : 0;
	bit0 = veh_id_0.GetBit() ? 1 : 0;

	bit_id = ((~bit0) & 0x1) + (((~bit1) & 0x1) << 1) + (((~bit2) & 0x1) << 2);

	return bit_id;
}

vehicle_type VehicleID::GetVehicleType() {

	return m_id_;
}

