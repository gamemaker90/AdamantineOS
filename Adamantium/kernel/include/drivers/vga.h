/*
 *  File: vga.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef _DRIVERS_VGA_H
#define _DRIVERS_VGA_H

#include <compiler.h>
#include <stdint.h>

/* VGA Teletype Screen Macros */
#define VGA_WIDTH                               80      // Width is 80 characters
#define VGA_HEIGHT                              25      // Height is 25 characters

#if defined(GFX_MODE) && (GFX_MODE == 1)
#define VGA_ADDRESS     0xA0000
#else
#if defined(MONOCHROME)
#define VGA_ADDRESS     0xB0000
#else
#define VGA_ADDRESS     0xB8000
#endif
#endif

typedef unsigned short *vbuff_t;

/* Define the available VGA colors */
enum vga_color 
{
    SYSTEM_COLOR_BLACK,         // 0x00 | 0
    SYSTEM_COLOR_BLUE,          // 0x01 | 1
    SYSTEM_COLOR_GREEN,         // 0x02 | 2
    SYSTEM_COLOR_CYAN,          // 0x03 | 3
    SYSTEM_COLOR_RED,           // 0x04 | 4
    SYSTEM_COLOR_MAGENTA,       // 0x05 | 5
    SYSTEM_COLOR_BROWN,         // 0x06 | 6
    SYSTEM_COLOR_GRAY,          // 0x07 | 7
    SYSTEM_COLOR_DK_GRAY,       // 0x08 | 8
    SYSTEM_COLOR_LT_BLUE,       // 0x09 | 9
    SYSTEM_COLOR_LT_GREEN,      // 0x0A | 10
    SYSTEM_COLOR_LT_CYAN,       // 0x0B | 11
    SYSTEM_COLOR_LT_RED,        // 0x0C | 12
    SYSTEM_COLOR_LT_MAGENTA,    // 0x0D | 13
    SYSTEM_COLOR_YELLOW,        // 0x0E | 14
    SYSTEM_COLOR_WHITE,         // 0x0F | 15
};

struct vga {
    vbuff_t buffer;
    uint32_t length;
};

#endif  // !_ADAMANTINE_VGA_H
