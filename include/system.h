/*
 *  File: system.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef ADAMANTINE_SYSTEM
#define ADAMANTINE_SYSTEM

// Includes go here:
#include "aos-defs.h"
#include "types.h"

// Declare global functions:
EXTERN VOID (SystemEnableCursor(UBYTE CurStart, UBYTE CurEnd));  // Enable the cursor in the terminal.
EXTERN VOID (SystemDisableCursor(VOID));							// Disable the terminal cursor.
EXTERN VOID (SystemUpdateCursor(UDWORD x, UDWORD y));			// Update the cursor position.
EXTERN VOID (SystemSetCursorType(UBYTE Type));					// Set the cursor type (UNUSED).
EXTERN UWORD (SystemGetCursorPosition(VOID));					// Get the cursor position.

#endif	// !ADAMANTINE_SYSTEM
