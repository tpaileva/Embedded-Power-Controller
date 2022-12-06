/*
 * filter.h
 *
 *  Created on: Jun 1, 2020
 *      Author: t. pailevanian
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "util.h"
#include <stdint.h>

// Classic leaky integration
// Implemented with following equations
//	a = tau / (tau + Tsample)
//		- tau is filter constant
//		- Tsapmle is sample period
//
//	filtered output = a * last_value + (1-a) * current value

class LPF {
public:
	LPF(void);
	LPF(uint32_t tau, float initial_value = 0.0);

	// Gets/Sets the filter time constant
	void 		SetTau(uint32_t tau);
	uint32_t	GetTau();

	// Filters the input value based on the internal filter parameters
	float 	FilterUpdate(float value);

private:

	uint32_t tau_;
	uint32_t last_tick_;
	float last_output_;

};

#endif /* FILTER_H_ */
