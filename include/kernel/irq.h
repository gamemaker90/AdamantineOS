/*
 *  File: irq.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef _AOS_IRQ_H
#define _AOS_IRQ_H

#include <stdint.h>

uint8_t are_interrupts_enabled(void);
unsigned long irq_disable(void);
void irq_restore(unsigned long flags);
void clear_interrupts(void);

#endif  // !_AOS_IRQ_H
