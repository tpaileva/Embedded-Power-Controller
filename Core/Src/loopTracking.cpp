/*
 * loopTracking.h
 */

#include "loopTracking.h"

LOOPTRACKING loopTracking;

LOOPTRACKING::LOOPTRACKING(void)
{

}

LOOPTRACKING::~LOOPTRACKING(){}

void LOOPTRACKING::Init() {

	// Reset all the counters
	Reset();

	// All done
	return;
}

void LOOPTRACKING::AddLoop(void) {

	// Increments the loop counter
	loop_count_++;

	// Look for a maximum loop time
	if (GetTicks()-t_last_call_ > t_max_) {
		t_max_ = GetTicks()-t_last_call_;
	}

	t_last_call_ = GetTicks();

	// All done
	return;
}

void LOOPTRACKING::Reset(void) {

	// Resets all the counters
	loop_count_       = 0;
	t_tracking_start_ = GetTicks();
	t_max_            = 0;
	t_last_call_      = GetTicks();

	// All done
	return;

}

uint32_t LOOPTRACKING::Average(void) {

	// Returns the average loop time since last reset

	uint32_t t_elapsed = GetTicks() - t_tracking_start_;
	if ( t_elapsed < 1 ) { t_elapsed = 1; };

	return (Count() / t_elapsed);

}
