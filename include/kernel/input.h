/*
 *  File: input.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef _INPUT_
#define _INPUT_

#include <adamantine/aos-defs.h>
#include <adamantine/aos-types.h>

#if defined(__cplusplus)
extern "C" {
#endif

uint8_t read_portb(uint16_t port);					            /* read 8-bit port. */
uint16_t read_portw(uint16_t port);					            /* read 16-bit port. */
uint32_t read_portdw(uint16_t port);                            /* read 32-bit port. */

#if defined(__cplusplus)
}
#endif

#endif