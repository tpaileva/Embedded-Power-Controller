/*
 * power.h
 *
 *	Author: T. Pailevanian
 */

#ifndef POWER_H_
#define POWER_H_

#include "gpio.h"
#include "adc.h"
#include "util.h"
#include "fault.h"
#include "switch.h"
#include "vehicleid.h"
#include <functional>


#define VLOGIC_VMIN	17.5f
#define VLOGIC_VMAX	35.0f

#define V5BUS_VMIN	5.0f * 0.9f		// Check that regulator range is within 10%
#define V5BUS_VMAX	5.0f * 1.1f

#define V12BUS_VMIN	12.0f * 0.9f	// Check that regulator range is within 10%
#define V12BUS_VMAX	12.0f * 1.1f

#define V17BUS_VMIN	15.0f			// 17V can dip if the input voltage gets too close to 18
#define V17BUS_VMAX	17.0f * 1.1f	// so we will be flexible on the lower range

#define VMOTOR_VMIN	17.5f
#define VMOTOR_VMAX	40.0f           // ADC on board is broken, so allow a high value

#define HUSKY_VGSE  28.0f
#define SPOT_VGSE	33.0f

#define HUSKY_VMAX	30.0f
#define SPOT_VMAX	36.0f

#define ILOGIC_IMIN	-0.3f
#define ILOGIC_IMAX	20.0f

#define IMOTOR_IMIN	-1.0f
#define IMOTOR_IMAX	20.0f

// Forward declaration
class Power;

extern Power PowerSystem;
extern Switch pwr_sw;

enum class PowerRail {
	VinLogic = 0,
	VinLogicSw,
	Reg_5v,
	Reg_12v,
	Reg_17v,
	VinMotor
};

class Power {
public:
	// Default constructor
	Power(void);

	virtual ~Power();

	void Init(void);

	float GetVoltage(PowerRail rail);
	Fault CheckVoltageRail(PowerRail rail);
	Fault CheckVoltageInRange(float range_min, float range_max, float measured_voltage, FaultState overvoltage, FaultState undervoltage);
	Fault CheckInputVoltageForVehicleType(void);

	float GetCurrent(PowerRail rail);
	Fault CheckCurrentRail(PowerRail rail);

	Fault CheckAllRails(void);

	bool isGsePowered(void);

	Fault PowerUp(void);
	Fault PowerDown(void);

	Fault MonitoredDelay(uint32_t Delay);

	void ResetFaultState(void);

	bool getPowerSwitchState(void);

private:
	Fault status_;

	AdcChannel vsense_logic_;
	AdcChannel vsense_logic_sw_;
	AdcChannel vsense_17v_;
	AdcChannel vsense_12v_;
	AdcChannel vsense_5v_;
	AdcChannel vsense_motor_;
	AdcChannel isense_logic_;
	AdcChannel isense_motor_;

	// Debugging
	uint8_t _power_debug = 1;
};

#endif /* POWER_H_ */
