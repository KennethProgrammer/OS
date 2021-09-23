#ifndef gdt_h
#define gdt_h

#include "util.h"

typedef struct{
	uint16_t segLimit;
	uint16_t lowbase;
	uint8_t midbase;
	uint8_t access;
	uint8_t granularity;
	uint8_t hibase;
}PACKED gdt_entry;

typedef struct{
	uint16_t limit;
	uint32_t base;
}PACKED gdtptr;

gdt_entry gdt[3];
gdtptr gdtp;

void setgdt(int i, uint16_t low, uint8_t mid, uint8_t hi, uint16_t limit, uint8_t access, uint8_t gran){
	gdt[i].segLimit = limit;
	gdt[i].lowbase = low;
	gdt[i].midbase = mid;
	gdt[i].access = access;
	gdt[i].granularity = gran;
	gdt[i].hibase = hi;
};

void load_gdt(){
	setgdt(0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);
	setgdt(1, 0x0, 0x0, 0x0, 0xffff, 0x9A, 0xCF);
	setgdt(2, 0x0, 0x0, 0x0, 0xffff, 0x92, 0xCF);

	gdtp.base = (uint32_t)&gdt[0];
	gdtp.limit = 3 * sizeof(gdt_entry) - 1;
	asm volatile("lgdtl (%0)" : : "r" (&gdtp));
};

#endif
