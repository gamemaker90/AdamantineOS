/*
 *  File: pic.c
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#include <adamantine/adamantine.h>

void 
pic_send_eoi(uint8_t irq) 
{
	if (irq >= 0x8) 
	{
		write_portb(PIC2_COMMAND, PIC_EOI);
	}
	write_portb(PIC1_COMMAND, PIC_EOI);
}

void 
pic_remap(void) 
{
	write_portb(0x20, 0x11);
	write_portb(0xA0, 0x11);
	write_portb(0x21, 0x20);
	write_portb(0xA1, 0x28);
	write_portb(0x21, 0x04);
	write_portb(0xA1, 0x02);
	write_portb(0x21, 0x01);
	write_portb(0xA1, 0x01);
	write_portb(0x21, 0x0);
	write_portb(0xA1, 0x0);
}

void 
irq_set_mask(uint8_t irq_Line) 
{
	uint16_t port;
	uint8_t value;
	
	if (irq_Line < 0x8) 
	{
		port = PIC1_DATA;
	} 
	else 
	{
		port = PIC2_DATA;
		irq_Line -= 0x8;
	}
	value = read_portb(port) | (1 << irq_Line);
	write_portb(port, value);
}

void 
irq_clear_mask(uint8_t irq_Line) 
{
	uint16_t port;
	uint8_t value;
	
	if (irq_Line < 0x8) 
	{
		port = PIC1_DATA;
	} 
	else 
	{
		port = PIC2_DATA;
		irq_Line -= 0x8;
	}
	value = read_portb(port) | ~(1 << irq_Line);
	write_portb(port, value);
}

uint16_t
pic_get_irr(void) 
{
	return (pic_get_irq_register(PIC_READ_IRR));
}

uint16_t
pic_get_isr(void) 
{
	return (pic_get_irq_register(PIC_READ_isr));
}

uint16_t pic_get_irq_register(int8_t ocw3) 
{
	write_portb(PIC1_COMMAND, ocw3);
	write_portb(PIC2_COMMAND, ocw3);
	
	return ((read_portb(PIC2_COMMAND) << 0x8) | read_portb(PIC1_COMMAND));
}
