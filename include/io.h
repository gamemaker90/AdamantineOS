/*
 *  File: io.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef ADAMANTINE_IO
#define ADAMANTINE_IO

// Include files go here:
#include "types.h"
#include "string.h"
#include "input.h"
#include "output.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Declare io functions:
extern void io_wait(void);

#if defined(__cplusplus)
}
#endif

#endif	// !ADAMANTINE_IO
