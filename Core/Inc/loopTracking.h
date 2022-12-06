/*
 * loopTracking.h
 */

// Header for the loopTracking Functions

#pragma once


#include "uart.h"
#include "util.h"

// Forward declaration
class LOOPTRACKING;

extern LOOPTRACKING loopTracking;

class LOOPTRACKING {
public:
	LOOPTRACKING(void);

	virtual ~LOOPTRACKING();

	void Init(void);

	void AddLoop(void);
	void Reset(void);

	uint32_t Average(void);
	uint32_t Max(void)   { return (t_max_     ); };
	uint32_t Count(void) { return (loop_count_); };

private:

	uint32_t loop_count_       = 0;  // Count the number of loops
	uint32_t t_last_call_      = 0;  // Time the function was last called
	uint32_t t_tracking_start_ = 0;  // Time we started counting at
	uint32_t t_max_            = 0;  // Max loop time seen

};
