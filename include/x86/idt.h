/*
 *  File: idt.h
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

#ifndef ADAMANTINE_INTERRUPT_DESCRIPTOR_TABLE
#define ADAMANTINE_INTERRUPT_DESCRIPTOR_TABLE

// Includes go here:
#include "../aos-defs.h"
#include "../types.h"

#ifndef INTERRUPT_DESCRIPTOR
#define INTERRUPT_DESCRIPTOR
#endif

#if defined(__cplusplus)
extern "C" {
#endif

struct IDT_Entry 
{
	UWORD 				BaseLo;
	UWORD 				BaseHi;
	UWORD 				Selector;
	BYTE 				AlwaysZero;
	BYTE 				Flags;
} PACKED;
typedef struct IDT_Entry IDT_Entry_t;

struct PIDT 
{
	UDWORD 				Base;
	UWORD 				Limit;
} PACKED;
typedef struct PIDT PIDT_t;

EXTERN	SET_VOID(IDT_Load(UDWORD));
EXTERN	SET_VOID(ISR_0(VOID));
EXTERN	SET_VOID(ISR_1(VOID));
EXTERN	SET_VOID(ISR_2(VOID));
EXTERN	SET_VOID(ISR_3(VOID));
EXTERN	SET_VOID(ISR_4(VOID));
EXTERN	SET_VOID(ISR_5(VOID));
EXTERN	SET_VOID(ISR_6(VOID));
EXTERN	SET_VOID(ISR_7(VOID));
EXTERN	SET_VOID(ISR_8(VOID));
EXTERN	SET_VOID(ISR_9(VOID));
EXTERN	SET_VOID(ISR_10(VOID));
EXTERN	SET_VOID(ISR_11(VOID));
EXTERN	SET_VOID(ISR_12(VOID));
EXTERN	SET_VOID(ISR_13(VOID));
EXTERN	SET_VOID(ISR_14(VOID));
EXTERN	SET_VOID(ISR_15(VOID));
EXTERN	SET_VOID(ISR_16(VOID));
EXTERN	SET_VOID(ISR_17(VOID));
EXTERN	SET_VOID(ISR_18(VOID));
EXTERN	SET_VOID(ISR_19(VOID));
EXTERN	SET_VOID(ISR_20(VOID));
EXTERN	SET_VOID(ISR_21(VOID));
EXTERN	SET_VOID(ISR_22(VOID));
EXTERN	SET_VOID(ISR_23(VOID));
EXTERN	SET_VOID(ISR_24(VOID));
EXTERN	SET_VOID(ISR_25(VOID));
EXTERN	SET_VOID(ISR_26(VOID));
EXTERN	SET_VOID(ISR_27(VOID));
EXTERN	SET_VOID(ISR_28(VOID));
EXTERN	SET_VOID(ISR_29(VOID));
EXTERN	SET_VOID(ISR_30(VOID));
EXTERN	SET_VOID(ISR_31(VOID));

EXTERN	SET_VOID(IRQ_0(VOID));
EXTERN	SET_VOID(IRQ_1(VOID));
EXTERN	SET_VOID(IRQ_2(VOID));
EXTERN	SET_VOID(IRQ_3(VOID));
EXTERN	SET_VOID(IRQ_4(VOID));
EXTERN	SET_VOID(IRQ_5(VOID));
EXTERN	SET_VOID(IRQ_6(VOID));
EXTERN	SET_VOID(IRQ_7(VOID));
EXTERN	SET_VOID(IRQ_8(VOID));
EXTERN	SET_VOID(IRQ_9(VOID));
EXTERN	SET_VOID(IRQ_10(VOID));
EXTERN	SET_VOID(IRQ_11(VOID));
EXTERN	SET_VOID(IRQ_12(VOID));
EXTERN	SET_VOID(IRQ_13(VOID));
EXTERN	SET_VOID(IRQ_14(VOID));
EXTERN	SET_VOID(IRQ_15(VOID));

EXTERN 	SET_VOID(IDT_Init(VOID));
EXTERN 	SET_VOID(IDT_Free(VOID));

#if defined(__cplusplus)
}
#endif
#endif	// !ADAMANTINE_INTERRUPT_DESCRIPTOR_TABLE
