/*
 *  File: mem-util.c
 *  Author: Vincent Cupo
 *  
 * 	THIS FILE IS NOT TO BE VIEWED BY THE GENERAL PUBLIC WITHOUT 
 * 	WRITTEN CONSENT OF PSIONIX SOFTWORKS LLC.
 * 
 *  PROPERTY OF PSIONIX SOFTWORKS LLC.
 *  Copyright (c) 2018-2020, Psionix Softworks LLC.
 *
 */

// Includes go here:
#include <kernel/memory/mm.h>
#include <kernel/system/terminal.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PAGE_ALLOCS		32

static uint32_t last_alloc 	= 0;
static uint32_t heap_end	= 0;
static uint32_t heap_begin 	= 0;
static uint32_t pheap_begin = 0;
static uint32_t pheap_end 	= 0;
static uint32_t memory_used = 0;
static uint8_t *pheap_desc 	= 0;

extern uint32_t kernel_end;
uint32_t placement_address 	= (uint32_t)&kernel_end;

void 
mm_init(uint32_t kernel_end) 
{
	last_alloc = kernel_end + 0x1000;
	heap_begin = last_alloc;
	pheap_end = 0x400000;
	pheap_begin = pheap_end - (MAX_PAGE_ALLOCS * 4096);
	heap_end = pheap_begin;
	memset((char *)heap_begin, 0, heap_end - heap_begin);
	pheap_desc = (uint8_t *)malloc(MAX_PAGE_ALLOCS);

	terminal_printf("[INFO]: Memory Module is initialized!\n");
	terminal_printf("[INFO]: Kernel heap begins at 0x%x\n", last_alloc);
}

void *
malloc(size_t size) 
{
	if (!size) return 0;
	uint8_t *mem = (uint8_t *)heap_begin;
	while ((uint32_t)mem < last_alloc)
	{
		alloc_t *a = (alloc_t *)mem;
		if (!a->size)
			goto nalloc;
		if (a->status) 
		{
			mem += a->size;
			mem += sizeof(alloc_t);
			mem += 4;
			continue;
		}

		if (a->size >= size) 
		{
			a->status = 1;

			//terminal_printf("RE:Allocated %d bytes from %d to %d...\n", size, mem + sizeof(alloc_t), mem + sizeof(alloc_t) + size);

			memset(mem + sizeof(alloc_t), 0, size);
			memory_used += size + sizeof(alloc_t);
			return ((void *)(mem + sizeof(alloc_t)));
		}
		mem += a->size;
		mem += sizeof(alloc_t);
		mem += 4;
	}

	nalloc:;
	if (last_alloc + size + sizeof(alloc_t) >= heap_end) 
	{
		terminal_printf("Cannot allocate. Out of memory...\n");
	}
	alloc_t *alloc = (alloc_t *)last_alloc;
	alloc->status = 1;
	alloc->size = size;

	last_alloc += size;
	last_alloc += sizeof(alloc_t);
	last_alloc += 4;

	memory_used += size + 4 + sizeof(alloc_t);
	memset((void *)((uint32_t)alloc + sizeof(alloc_t)), 0, size);

	return ((void *)((uint32_t)alloc + sizeof(alloc_t)));
}

void 
free(void *mem) 
{
	alloc_t *alloc = (mem - sizeof(alloc_t));
	memory_used -= alloc->size + sizeof(alloc_t);
	alloc->status = 0;
}



/* James Molloy... */
uint32_t
kmalloc_int(uint32_t size, uint32_t align, uint32_t *physical_address)
{
	if ((align == 1) && (placement_address & 0xFFFFF000))
	{
		placement_address &= 0xFFFFF000;
		placement_address += 0x1000;
	}
	if (physical_address)
	{
		*physical_address = placement_address;
	}
	uint32_t temp = placement_address;
	placement_address += size;
	return (temp);
}

uint32_t
kmalloc_a(uint32_t size)
{
	return (kmalloc_int(size, 1, 0));
}

uint32_t
kmalloc_p(uint32_t size, uint32_t *physical_address)
{
	return (kmalloc_int(size, 0, physical_address));
}

uint32_t
kmalloc_ap(uint32_t size, uint32_t *physical_address)
{
	return (kmalloc_int(size, 1, physical_address));
}

uint32_t
kmalloc(uint32_t size)
{
	return (kmalloc_int(size, 0, 0));
}
