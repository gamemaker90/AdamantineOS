/*
 *  File: centrix.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef CENTRIX
#define CENTRIX

#include <adamantine/aos-defs.h>
#include <centrix/centrix-core.h>
#include <adamantine/aos-types.h>
#include <memory/mm.h>
#include <system/terminal.h>

#if CENTRIX_VERSION <= 100

EXTERN void *kernel_install(string name);
EXTERN dword kernel_verify(void);

#endif	/* !CENTRIX_VERSION */
#endif	/* !CENTRIX */