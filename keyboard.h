#ifndef keyboard_h
#define keyboard_h

#include "vga.h"

char key_buffer[256];

uint8_t lookup_table[256] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,
	0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0, 0,
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
	'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, 0, 0, ' '
};

void backspace(char buffer[]){
	int len = strlen(buffer);
	if (len == 0) {return;};
	buffer[len-1] = 0;

	offset -= 2;
	printc(' ');
	offset -= 2;
	set_cursor(offset/2);
};

void handler1(){
	uint8_t code = inb(0x60);
	if (code == 14){backspace(key_buffer); return;};
	if (code == 28){print("\n"); execute_cmd(key_buffer); key_buffer[0] = 0; return;};

	append_to_buffer(key_buffer, lookup_table[code]);
	printc(lookup_table[code]);
};

#endif
