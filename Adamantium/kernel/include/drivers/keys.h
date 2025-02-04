/*
 *  File: keys.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef _ADAMANTINE_KEYS_H
#define _ADAMANTINE_KEYS_H

#define KERNEL_ONLY

/* Define the keys for down state */
#ifndef KEYBOARD_KEY_DOWN
#define KEYBOARD_KEY_DOWN_NONE					0x00
#define KEYBOARD_KEY_DOWN_ESCAPE				0x01
#define KEYBOARD_KEY_DOWN_1						0x02
#define KEYBOARD_KEY_DOWN_2						0x03
#define KEYBOARD_KEY_DOWN_3						0x04
#define KEYBOARD_KEY_DOWN_4						0x05
#define KEYBOARD_KEY_DOWN_5						0x06
#define KEYBOARD_KEY_DOWN_6						0x07
#define KEYBOARD_KEY_DOWN_7						0x08
#define KEYBOARD_KEY_DOWN_8						0x09
#define KEYBOARD_KEY_DOWN_9						0x0A
#define KEYBOARD_KEY_DOWN_0						0x0B
#define KEYBOARD_KEY_DOWN_MINUS					0x0C
#define KEYBOARD_KEY_DOWN_EQUAL					0x0D
#define KEYBOARD_KEY_DOWN_BACKSPACE				0x0E
#define KEYBOARD_KEY_DOWN_TAB					0x0F
#define KEYBOARD_KEY_DOWN_Q						0x10
#define KEYBOARD_KEY_DOWN_W						0x11
#define KEYBOARD_KEY_DOWN_E						0x12
#define KEYBOARD_KEY_DOWN_R						0x13
#define KEYBOARD_KEY_DOWN_T						0x14
#define KEYBOARD_KEY_DOWN_Y						0x15
#define KEYBOARD_KEY_DOWN_U						0x16
#define KEYBOARD_KEY_DOWN_I						0x17
#define KEYBOARD_KEY_DOWN_O						0x18
#define KEYBOARD_KEY_DOWN_P						0x19
#define KEYBOARD_KEY_DOWN_LEFT_SQUARE_BRACKET	0x1A
#define KEYBOARD_KEY_DOWN_RIGHT_SQUARE_BRACKET	0x1B
#define KEYBOARD_KEY_DOWN_ENTER					0x1C
#define KEYBOARD_KEY_DOWN_CONTROL				0x1D
#define KEYBOARD_KEY_DOWN_A						0x1E
#define KEYBOARD_KEY_DOWN_S						0x1F
#define KEYBOARD_KEY_DOWN_D						0x20
#define KEYBOARD_KEY_DOWN_F						0x21
#define KEYBOARD_KEY_DOWN_G						0x22
#define KEYBOARD_KEY_DOWN_H						0x23
#define KEYBOARD_KEY_DOWN_J						0x24
#define KEYBOARD_KEY_DOWN_K						0x25
#define KEYBOARD_KEY_DOWN_L						0x26
#define KEYBOARD_KEY_DOWN_SEMICOLON				0x27
#define KEYBOARD_KEY_DOWN_APOSTROPHE			0x28
#define KEYBOARD_KEY_DOWN_TILDE					0x29
#define KEYBOARD_KEY_DOWN_LEFT_SHIFT			0x2A
#define KEYBOARD_KEY_DOWN_BACKSLASH				0x2B
#define KEYBOARD_KEY_DOWN_Z						0x2C
#define KEYBOARD_KEY_DOWN_X						0x2D
#define KEYBOARD_KEY_DOWN_C						0x2E
#define KEYBOARD_KEY_DOWN_V						0x2F
#define KEYBOARD_KEY_DOWN_B						0x30
#define KEYBOARD_KEY_DOWN_N						0x31
#define KEYBOARD_KEY_DOWN_M						0x32
#define KEYBOARD_KEY_DOWN_COMMA					0x33
#define KEYBOARD_KEY_DOWN_PERIOD				0x34
#define KEYBOARD_KEY_DOWN_SLASH					0x35
#define KEYBOARD_KEY_DOWN_RIGHT_SHIFT			0x36
#define KEYBOARD_KEY_DOWN_PRINT_SCREEN			0x37
#define KEYBOARD_KEY_DOWN_ALT					0x38
#define KEYBOARD_KEY_DOWN_SPACE_BAR				0x39
#define KEYBOARD_KEY_DOWN_CAPS_LOCK				0x3A
#define KEYBOARD_KEY_DOWN_F1					0x3B
#define KEYBOARD_KEY_DOWN_F2					0x3C
#define KEYBOARD_KEY_DOWN_F3					0x3D
#define KEYBOARD_KEY_DOWN_F4					0x3E
#define KEYBOARD_KEY_DOWN_F5					0x3F
#define KEYBOARD_KEY_DOWN_F6					0x40
#define KEYBOARD_KEY_DOWN_F7					0x41
#define KEYBOARD_KEY_DOWN_F8					0x42
#define KEYBOARD_KEY_DOWN_F9					0x43
#define KEYBOARD_KEY_DOWN_F10					0x44
#define KEYBOARD_KEY_DOWN_NUM_LOCK				0x45
#define KEYBOARD_KEY_DOWN_SCROLL_LOCK			0x46
#define KEYBOARD_KEY_DOWN_NUMPAD_7				0x47
#define KEYBOARD_KEY_DOWN_NUMPAD_8				0x48	// Up Arrow/Numpad 6
#define KEYBOARD_KEY_DOWN_NUMPAD_9				0x49
#define KEYBOARD_KEY_DOWN_NUMPAD_MINUS			0x4A
#define KEYBOARD_KEY_DOWN_NUMPAD_4				0x4B	// Left Arrow/Numpad 6
#define KEYBOARD_KEY_DOWN_NUMPAD_5				0x4C
#define KEYBOARD_KEY_DOWN_NUMPAD_6				0x4D	// Right Arrow/Numpad 6
#define KEYBOARD_KEY_DOWN_NUMPAD_PLUS			0x4E
#define KEYBOARD_KEY_DOWN_NUMPAD_1				0x4F
#define KEYBOARD_KEY_DOWN_NUMPAD_2				0x50	// Down Arrow/Numpad 6
#define KEYBOARD_KEY_DOWN_NUMPAD_3				0x51
#define KEYBOARD_KEY_DOWN_NUMPAD_0				0x52
#define KEYBOARD_KEY_DOWN_DELETE			    0x53
#define KEYBOARD_KEY_DOWN_F11					0x57
#define KEYBOARD_KEY_DOWN_F12					0x58
#define KEYBOARD_KEY_DOWN_WINDOWS_KEY_LEFT		0x5B
#define KEYBOARD_KEY_DOWN_WINDOWS_KEY_RIGHT		0x5C
#endif	// !KEYBOARD_KEY_DOWN

// Define the keys for up state:
#ifndef KEYBOARD_KEY_UP
#define KEYBOARD_KEY_UP_NONE					0x00
#define KEYBOARD_KEY_UP_ESCAPE					0x81
#define KEYBOARD_KEY_UP_1						0x82
#define KEYBOARD_KEY_UP_2						0x83
#define KEYBOARD_KEY_UP_3						0x84
#define KEYBOARD_KEY_UP_4						0x85
#define KEYBOARD_KEY_UP_5						0x86
#define KEYBOARD_KEY_UP_6						0x87
#define KEYBOARD_KEY_UP_7						0x88
#define KEYBOARD_KEY_UP_8						0x89
#define KEYBOARD_KEY_UP_9						0x8A
#define KEYBOARD_KEY_UP_0						0x8B
#define KEYBOARD_KEY_UP_MINUS					0x8C
#define KEYBOARD_KEY_UP_EQUAL					0x8D
#define KEYBOARD_KEY_UP_BACKSPACE				0x8E
#define KEYBOARD_KEY_UP_TAB						0x8F
#define KEYBOARD_KEY_UP_Q						0x90
#define KEYBOARD_KEY_UP_W						0x91
#define KEYBOARD_KEY_UP_E						0x92
#define KEYBOARD_KEY_UP_R						0x93
#define KEYBOARD_KEY_UP_T						0x94
#define KEYBOARD_KEY_UP_Y						0x95
#define KEYBOARD_KEY_UP_U						0x96
#define KEYBOARD_KEY_UP_I						0x97
#define KEYBOARD_KEY_UP_O						0x98
#define KEYBOARD_KEY_UP_P						0x99
#define KEYBOARD_KEY_UP_LEFT_SQUARE_BRACKET		0x9A
#define KEYBOARD_KEY_UP_RIGHT_SQUARE_BRACKET	0x9B
#define KEYBOARD_KEY_UP_ENTER					0x9C
#define KEYBOARD_KEY_UP_CONTROL					0x9D
#define KEYBOARD_KEY_UP_A						0x9E
#define KEYBOARD_KEY_UP_S						0x9F
#define KEYBOARD_KEY_UP_D						0xA0
#define KEYBOARD_KEY_UP_F						0xA1
#define KEYBOARD_KEY_UP_G						0xA2
#define KEYBOARD_KEY_UP_H						0xA3
#define KEYBOARD_KEY_UP_J						0xA4
#define KEYBOARD_KEY_UP_K						0xA5
#define KEYBOARD_KEY_UP_L						0xA6
#define KEYBOARD_KEY_UP_SEMICOLON				0xA7
#define KEYBOARD_KEY_UP_APOSTROPHE				0xA8
#define KEYBOARD_KEY_UP_TILDE					0xA9
#define KEYBOARD_KEY_UP_LEFT_SHIFT				0xAA
#define KEYBOARD_KEY_UP_BACKSLASH				0xAB
#define KEYBOARD_KEY_UP_Z						0xAC
#define KEYBOARD_KEY_UP_X						0xAD
#define KEYBOARD_KEY_UP_C						0xAE
#define KEYBOARD_KEY_UP_V						0xAF
#define KEYBOARD_KEY_UP_B						0xB0
#define KEYBOARD_KEY_UP_N						0xB1
#define KEYBOARD_KEY_UP_M						0xB2
#define KEYBOARD_KEY_UP_COMMA					0xB3
#define KEYBOARD_KEY_UP_PERIOD					0xB4
#define KEYBOARD_KEY_UP_SLASH					0xB5
#define KEYBOARD_KEY_UP_RIGHT_SHIFT				0xB6
#define KEYBOARD_KEY_UP_PRINT_SCREEN			0xB7
#define KEYBOARD_KEY_UP_ALT						0xB8
#define KEYBOARD_KEY_UP_SPACE_BAR				0xB9
#define KEYBOARD_KEY_UP_CAPS_LOCK				0xBA
#define KEYBOARD_KEY_UP_F1						0xBB
#define KEYBOARD_KEY_UP_F2						0xBC
#define KEYBOARD_KEY_UP_F3						0xBD
#define KEYBOARD_KEY_UP_F4						0xBE
#define KEYBOARD_KEY_UP_F5						0xBF
#define KEYBOARD_KEY_UP_F6						0xC0
#define KEYBOARD_KEY_UP_F7						0xC1
#define KEYBOARD_KEY_UP_F8						0xC2
#define KEYBOARD_KEY_UP_F9						0xC3
#define KEYBOARD_KEY_UP_F10						0xC4
#define KEYBOARD_KEY_UP_NUM_LOCK				0xC5
#define KEYBOARD_KEY_UP_SCROLL_LOCK				0xC6
#define KEYBOARD_KEY_UP_NUMPAD_7				0xC7
#define KEYBOARD_KEY_UP_NUMPAD_8				0xC8
#define KEYBOARD_KEY_UP_NUMPAD_9				0xC9
#define KEYBOARD_KEY_UP_NUMPAD_MINUS			0xCA
#define KEYBOARD_KEY_UP_NUMPAD_4				0xCB
#define KEYBOARD_KEY_UP_NUMPAD_5				0xCC
#define KEYBOARD_KEY_UP_NUMPAD_6				0xCD
#define KEYBOARD_KEY_UP_NUMPAD_PLUS				0xCE
#define KEYBOARD_KEY_UP_NUMPAD_1				0xCF
#define KEYBOARD_KEY_UP_NUMPAD_2				0xD0
#define KEYBOARD_KEY_UP_NUMPAD_3				0xD1
#define KEYBOARD_KEY_UP_NUMPAD_0				0xD2
#define KEYBOARD_KEY_UP_DELETE			        0xD3
#define KEYBOARD_KEY_UP_F11						0xD7
#define KEYBOARD_KEY_UP_F12						0xD8
#define KEYBOARD_KEY_UP_WINDOWS_KEY_LEFT		0xDB
#define KEYBOARD_KEY_UP_WINDOWS_KEY_RIGHT		0xDC
#endif	// KEYBOARD_KEY_UP
#endif 	// !_ADAMANTINE_KEYS_H
