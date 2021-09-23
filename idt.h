#ifndef idt_h
#define idt_h

#include "util.h"

typedef struct{
	uint16_t base_low;
	uint16_t sel;
	uint8_t always0;
	uint8_t flags;
	uint16_t base_hi;

}PACKED idt_entry;

typedef struct{
	uint16_t limit;
	uint32_t base;

}PACKED idtptr;

idt_entry idt[256];
idtptr idtp;

void set_entry(int n, uint32_t handler){
	idt[n].base_low = (uint16_t)((handler) & 0xffff);
	idt[n].sel = 0x08;
	idt[n].always0 = 0;
	idt[n].flags = 0x8E;
	idt[n].base_hi = (uint16_t)((handler) >> 16);
};

void set_idt(){
	idtp.base = (uint32_t)(&idt);
	idtp.limit = 256 * sizeof(idt_entry) - 1;
	asm volatile("lidtl (%0)" : : "r" (&idtp));
};

#endif
