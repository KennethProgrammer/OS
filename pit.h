#ifndef pit_h
#define pit_h

uint8_t count = 0;
uint16_t Divisor = 65535;
#define base_freq 1193182

void set_divisor(uint16_t divisor){
	outb(0x40, (uint8_t)(divisor & 0xff));
	outb(0x40, (uint8_t)((divisor & 0xff00) >> 8));
};

uint8_t put_color = 0x00;

void handler0(){
	//if (count == 19){printf("T"); count = 0;return;};
	//count++;
	printf("T");
};

void timer_init(uint16_t Divisor){
	outb(0x43, 0x36);
	set_divisor(Divisor);
	change_maskInt(0);
};

#endif
