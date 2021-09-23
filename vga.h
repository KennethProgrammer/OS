#ifndef vga_h
#define vga_h

#include "util.h"

uint16_t offset = 0;
uint8_t *vga = (uint8_t *)0xb8000;
void clear();
void print(char *string);

uint16_t get_row_from_offset(uint16_t off){
	return off / (2 * 80);
};

uint16_t get_offset(uint16_t col, uint16_t row){
	return 2 * (row * 80 + col);
};

uint16_t move_offset_to_new_line(uint16_t off){
	if (get_row_from_offset(off) == 24){clear(); return 0;};
	return get_offset(0, get_row_from_offset(off) + 1);
};

void set_cursor(uint16_t position){
	outb(0x3d4, 0xe);
	outb(0x3d5, (uint8_t)(position >> 8));
	outb(0x3d4, 0xf);
	outb(0x3d5, (uint8_t)(position & 0xff));
};

void clear(){
	for (int i = 0; i < 2000; i++){
	 vga[i*2] = ' ';
	 vga[i*2+1] = 0x0f;
	};
	offset = 0;
	set_cursor(offset);
};

void print_ln(){
	offset = move_offset_to_new_line(offset);
};

void print(char *string){
	if (offset == 4000){clear(); print(">"); return;};
	for (int i = 0; string[i] != 0; i++){
	 if (string[i] == '\n'){
	  print_ln();
	 }
	 else{
	  vga[offset] = string[i];
	  vga[offset+1] = 0x0f;
	  offset += 2;
	 };
	};
	set_cursor(offset/2);
};

void printc(char chr){
	char *string = &chr;
	string[1] = 0;
	print(string);
};

#endif
