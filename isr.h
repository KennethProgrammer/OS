#ifndef isr_h
#define isr_h

#include "util.h"
#include "idt.h"

#define pic1_cmd 0x20
#define pic1_data 0x21
#define pic2_cmd 0xA0
#define pic2_data 0xA1

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

void end(){
	outb(0x20, 0x20);
	outb(0xA0, 0x20);
};

void exceptions(){
	print("Exception Ocurred");
	while(1){};
};

void remap_pic(){
	outb(pic1_cmd, 0x11);
    	outb(pic2_cmd, 0x11);
    	outb(pic1_data, 0x20);
    	outb(pic2_data, 0x28);
    	outb(pic1_data, 0x04);
    	outb(pic2_data, 0x02);
    	outb(pic1_data, 0x01);
    	outb(pic2_data, 0x01);
    	outb(pic1_data, 0x0);
    	outb(pic2_data, 0x0);
};


void isr_install(){
	for (int i = 0; i < 32; i++){
	 set_entry(i, (uint32_t)exceptions);
	};
	set_entry(32, (uint32_t)irq0);
	set_entry(33, (uint32_t)irq1);
	set_entry(34, (uint32_t)irq2);
	set_entry(35, (uint32_t)irq3);
	set_entry(36, (uint32_t)irq4);
	set_entry(37, (uint32_t)irq5);
	set_entry(38, (uint32_t)irq6);
	set_entry(39, (uint32_t)irq7);
	set_entry(40, (uint32_t)irq8);
	set_entry(41, (uint32_t)irq9);
	set_entry(42, (uint32_t)irq10);
	set_entry(43, (uint32_t)irq11);
	set_entry(44, (uint32_t)irq12);
	set_entry(45, (uint32_t)irq13);
	set_entry(46, (uint32_t)irq14);
	set_entry(47, (uint32_t)irq15);
    	set_idt();
	remap_pic();
};

#endif
