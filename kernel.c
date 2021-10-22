void kernel();

void entry(){
	kernel();
	while(1){};
};

#include "vga.h"
#include "gdt.h"
#include "isr.h"
#include "shell.h"
#include "keyboard.h"
#include "util.h"
#include "heap.h"
#include "multitasking.h"

void kernel(){
	clear();
	initBothHeaps();
	load_gdt();
	isr_install();
	print(">");
	asm volatile("sti");
	outb(0x21, 0b11111101);
	outb(0xA1, 0b11111111);
};
