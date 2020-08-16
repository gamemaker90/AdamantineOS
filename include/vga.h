#ifndef _VGA_
#define _VGA_

#include "types.h"
#include "aos-defs.h"

#if !defined(VGA_MODE)
#define VGA_GRAPHICS_MODE           0xA0000
#define VGA_TEXT_MODE_MONOCHROME    0xB0000
#define VGA_TEXT_MODE_COLOR         0xB8000
#endif

#define VGA_WIDTH                   80
#define VGA_HEIGHT                  25

enum vga_color 
{
    SYSTEM_COLOR_BLACK,
    SYSTEM_COLOR_BLUE,
    SYSTEM_COLOR_GREEN,
    SYSTEM_COLOR_CYAN,
    SYSTEM_COLOR_RED,
    SYSTEM_COLOR_MAGENTA,
    SYSTEM_COLOR_BROWN,
    SYSTEM_COLOR_GRAY,
    SYSTEM_COLOR_DK_GRAY,
    SYSTEM_COLOR_LT_BLUE,
    SYSTEM_COLOR_LT_GREEN,
    SYSTEM_COLOR_LT_CYAN,
    SYSTEM_COLOR_LT_RED,
    SYSTEM_COLOR_LT_MAGENTA,
    SYSTEM_COLOR_YELLOW,
    SYSTEM_COLOR_WHITE
};

#endif
