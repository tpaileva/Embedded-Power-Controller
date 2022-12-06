/*
 * estop.h
 *
 *  Created on: Jun 23, 2021
 *      Author: akourchi
 */

// A place for shared data structures

#pragma once

enum EstopState {
	EstopFault,
	EstopDisabled,  // Robot Go
	EstopEnabled    // Robot NO-GO
};

