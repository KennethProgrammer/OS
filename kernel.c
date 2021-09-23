void kernel();
void execute_cmd(char cmd[]);
void outw(unsigned short port, unsigned short data);
char close = 0;

void entry(){
	kernel();
	while(!close){};
	outw(0x604, 0x2000);
};

#include "vga.h"
#include "gdt.h"
#include "isr.h"
#include "keyboard.h"
#include "shell.h"
#include "util.h"
#include "heap.h"

void kernel(){
	clear();
	initHeap(HBP, heapSize);
	print(">");
	load_gdt();
	isr_install();
	asm volatile("sti");
	outb(0x21, 0b11111101);
	outb(0xA1, 0b11111111);
};
