#ifndef util_h
#define util_h

typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef uint32_t size_t;
typedef _Bool bool;
#define true 1
#define false 0
#define PACKED __attribute__((packed))
#include "util2.h"

uint8_t inb(uint16_t port) {
    	uint8_t result;
	asm volatile("inb %1, %0" : "=a" (result) : "d" (port));
 	return result;
};

void outb(uint16_t port, uint8_t data){
	asm volatile("outb %0, %1" : : "r" (data), "r" (port));
};

void outw(uint16_t port, uint16_t data){
	asm volatile("outw %0, %1" : : "r" (data), "r" (port));
};

#endif
