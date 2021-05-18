#include <kernel/drivers/keyboard.h>
#include <kernel/drivers/keys.h>
#include <kernel/system/io.h>
#include <kernel/system/terminal.h>
#include <kernel/isr.h>
#include <kernel/pic.h>

#include <kernel/cmd-line.h>
#include <string.h>
#include <stdlib.h>

// Nested conditional statement= var = (expr1 == val ? expr2 : expr3);

// Define for normal keys:
static char *keys_normal[256] = 
{
	"", "", 															// <None>, <Escape>,
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "0",					// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
	"-", "=", "\b", "\t",												// -, =, <Backspace>, <Tab>,
	"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\n",	// Q, W, E, R, T, Y, U, I, O, P, [, ], <Enter>,
	"",																	// <Control>,
	"a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'",				// A, S, D, F, G, H, J, K, L, ;, ',
	"`", "", "\\",														// `, <Left Shift>, \,
	"z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "",				// Z, X, C, V, B, N, m, ',', ., /, <Right Shift>, <Alt>
	"*", "", " ", "",													// *, <Alt>, <Space Bar>, <Caps Lock>,
	"", "", "", "", "", "", "", "", "", "",								// F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
	"", 																// <Numlock (On?)>,
	"",																	// <Scroll Lock>,
	"", "", "",															// Numpad 7, Numpad 8, Numpad 9
	"-", 																// Numpad -,
	"", "", "",															// Numpad 4, Numpad 5, Numpad 6,
	"+",																// Numpad +,
	"", "", "",															// Numpad 1, Numpad 2, Numpad 3,
	"", "",																// Numpad 0, Numpad Del,
	"", "", "",															// <NONE>, <NONE>, "<NONE>"
	"", "",																// <Windows key>, <Windows key>,
};

// Define for keys when shift is held:
static char * keys_caps[256] = 
{
	"", "", 															// <None>, <Escape>,
	"!", "@", "#", "$", "%", "^", "&", "*", "(", ")",					// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
	"_", "+", "\b", "\t",												// -, =, <Backspace>, <Tab>,
	"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "\n",	// Q, W, E, R, T, Y, U, I, O, P, [, ], <Enter>,
	"",																	// <Control>,
	"A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"",				// A, S, D, F, G, H, J, K, L, ;, ',
	"~", "", "|",														// `, <Left Shift>, \,
	"Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "",				// Z, X, C, V, B, N, m, ',', ., /, <Right Shift>, <Alt>
	"*", "", " ", "",													// *, <Alt>, <Space Bar>, <Caps Lock>,
	"", "", "", "", "", "", "", "", "", "",								// F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
	"", 																// <Numlock (On?)>,
	"",																	// <Scroll Lock>,
	"7", "8", "9",														// Numpad 7, Numpad 8, Numpad 9
	"-", 																// Numpad -,
	"4", "5", "6",														// Numpad 4, Numpad 5, Numpad 6,
	"+",																// Numpad +,
	"1", "2", "3",														// Numpad 1, Numpad 2, Numpad 3,
	"0", ".",															// Numpad 0, Numpad Del,
	"", "", "",															// <NONE>, <NONE>, "<NONE>"
	"<ADM>", "<ADM>",													// <Windows key>, <Windows key>,
};

static inline void keyboard_handler(void);
static inline uint8_t keyboard_read(void);
static inline void keyboard_write_command(uint8_t cmd);
static inline char *keyboard_get_key(void);
static inline void keyboard_set_leds(bool num_lock, bool caps_lock, bool scroll_lock);
static inline char *keyboard_get_keylast(void);

static bool init = false;
static bool shift_press = false;
static bool ctrl_press = false;
static bool system_press = false;
static bool alt_press = false;
static bool numlock UNUSED;
static bool capslock UNUSED;
static bool scrllock UNUSED;
static char *key_last = NULL;

static volatile char *key_buffer;

void
keyboard_init(void)
{
    if (!init)
    {
        key_buffer = (char *)malloc(sizeof(char *));
        //memset(key_buffer, 0, sizeof(char) * 40);

        register_interrupt_handler(IRQ1, (isr_t)&keyboard_handler);
        //key_buffer = keyboard_get_keylast();

        terminal_printf("[INFO]: Keyboard is initialized!\n");
        terminal_printf("%s", "[ADAMANTINE]: ");

        init = true;
    }
}

unsigned char
keyboard_read_scancode(void)
{
    uint8_t status = keyboard_read();
    if ((status & 0x01) == 1)
        return (inb(KEYBOARD_DATA));
    return 0;
}

static void UNUSED
keyboard_set_typematic_byte(void)
{
    outb(KEYBOARD_DATA, 0xF3);
    outb(KEYBOARD_DATA, 0);
}

char keypresses;

static inline void
keyboard_handler(void)
{
    static unsigned char scancode;
    scancode = keyboard_read_scancode();

    if (scancode)
    {
        // Check for Escape:
        if (scancode == KEYBOARD_KEY_DOWN_ESCAPE)
            terminal_printf("Cannot exit from current mode!\n[ADAMANTINE]: ");
        if ((scancode == KEYBOARD_KEY_DOWN_WINDOWS_KEY_LEFT) || (scancode == KEYBOARD_KEY_DOWN_WINDOWS_KEY_RIGHT))
            terminal_printf("[WindowsKey]: ");

        // Check for Left Shift:
        if ((scancode == KEYBOARD_KEY_DOWN_LEFT_SHIFT) || (scancode == KEYBOARD_KEY_DOWN_RIGHT_SHIFT))
            shift_press = true;
        else if ((scancode == KEYBOARD_KEY_UP_LEFT_SHIFT) || (scancode == KEYBOARD_KEY_UP_RIGHT_SHIFT))
            shift_press = false;

        // Check for Control Key:
        if ((scancode == KEYBOARD_KEY_DOWN_CONTROL))
            ctrl_press = true;
        else if (scancode == KEYBOARD_KEY_UP_CONTROL)
            ctrl_press = false;

        // Check for Alt Key:
        if (scancode == KEYBOARD_KEY_DOWN_ALT)
            alt_press = true;
        else if (scancode == KEYBOARD_KEY_UP_ALT)
            alt_press = false;

        // Check for System Key:
        if ((scancode == KEYBOARD_KEY_DOWN_WINDOWS_KEY_LEFT) || (scancode == KEYBOARD_KEY_DOWN_WINDOWS_KEY_RIGHT))
            system_press = true;
        else if ((scancode == KEYBOARD_KEY_UP_WINDOWS_KEY_LEFT) || (scancode == KEYBOARD_KEY_UP_WINDOWS_KEY_RIGHT))
            system_press = false;

        // Check for Caps lock:
        if (scancode == KEYBOARD_KEY_DOWN_CAPS_LOCK)
            shift_press = !shift_press;
        
        if ((ctrl_press) && (scancode == KEYBOARD_KEY_DOWN_S))
            terminal_printf("Nothing to save!\n%s", "[ADAMANTINE]: ");
        else if ((system_press) && (scancode == KEYBOARD_KEY_DOWN_W))
            terminal_printf("System test...\n");
        else if (scancode == KEYBOARD_KEY_DOWN_ENTER)
        {
            terminal_printf("\n[ADAMANTINE]: ");
        }
        else if (shift_press)
        {
            terminal_printf("%s", keys_caps[scancode]);
        }
        else
        {
            terminal_printf("%s", keys_normal[scancode]);
        }
    }
}

static inline char *
keyboard_get_keylast(void)
{
    return (key_last);
}

static inline uint8_t
keyboard_read(void)
{
    if (init) {
        uint8_t status = inb(KEYBOARD_COMMAND);
        return (status);
    }
    return 0;
}

static inline void
keyboard_write_command(uint8_t cmd)
{
    if (init) {
        while (1)
            if (!(keyboard_read() & 0x2))
                break;
        outb(KEYBOARD_DATA, cmd);
    }
    else
    {
        terminal_printf("[ERROR]: Keyboard has not been init...\n");
    }
}

static inline char *
keyboard_get_key(void)
{
    if (init) {
        keyboard_read();
        if (key_last != KEYBOARD_KEY_DOWN_NONE)
            return (key_last);
        return (KEYBOARD_KEY_DOWN_NONE);
    }
}

static inline void
keyboard_set_leds(bool num_lock, bool caps_lock, bool scroll_lock)
{
    uint8_t data = 0;

    data = (scroll_lock) ? (data | 1) : (data & 1);
    data = (num_lock) ? (num_lock | 2) : (num_lock & 2);
    data = (caps_lock) ? (caps_lock | 4) : (caps_lock & 4);

    outb(KEYBOARD_DATA, 0xED);
    outb(KEYBOARD_DATA, data);
}
