/*
 * filter.cpp
 *
 *  Created on: Jun 1, 2020
 *      Author: t. pailevanian
 */

#include "filter.h"

LPF::LPF(){}

LPF::LPF(uint32_t tau, float initial_value){
	tau_ = tau;
	last_output_ = initial_value;
	last_tick_ = DwtGetMicrosecondTicks();
}

void LPF::SetTau(uint32_t tau){
	tau_ = tau;

	// If tau is changed then reset the last tick
	last_tick_ = DwtGetMicrosecondTicks();
}

uint32_t LPF::GetTau(){
	return tau_;
}

float LPF::FilterUpdate(float value){

	uint32_t current_tick;
	uint32_t t_sample;
	float a;

	current_tick = DwtGetMicrosecondTicks();

	// Get sample period in us
	t_sample = current_tick - last_tick_;

	// Calculate filter coefficient
	a = (tau_ / (float)(tau_ + t_sample));

	// Do the filter step
	last_output_ = a * (value - last_output_) + last_output_;

	last_tick_ = current_tick;

	// return result
	return last_output_;
}

