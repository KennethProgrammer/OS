#ifndef multitasking_h
#define multitasking_h

#include "util.h"
bool started = 0;

typedef struct Task{
	uint32_t* eip, esp, ebp;
	struct Task *next;
	struct Task *prev;
}PACKED Task_t;

Task_t *first_task;
Task_t *current_task;
uint32_t* esp, ebp;

bool init_multitasking(uint32_t *eip){
	started = 1;
	first_task = malloc(sizeof(Task_t));
	if (first_task == 0){return false;};

	void *lebp = (void *)malloc(4096) + 4095;
	if (lebp == (void *)4095){
	 free(first_task);
	 started = 0;
	 return false;
	};
	void *lesp = lebp;
	first_task->esp = lesp;
	first_task->ebp = lebp;

	first_task->eip = eip;
	first_task->next = 0;
	first_task->prev = 0;
	current_task = first_task;
	return true;
};

bool add_task(uint32_t *eip){
	Task_t *temp = 0;
	for (temp = first_task; temp->next != 0; temp = temp->next){};
	temp->next = malloc(sizeof(Task_t));
	if (temp->next == 0){return false;};

	void *lebp = (void *)malloc(4096) + 4095;
	if (lebp == (void *)4095){
	 free(temp->next);
	 return false;
	};
	void *lesp = lebp;
	temp->next->esp = lesp;
	temp->next->ebp = lebp;

	temp->next->eip = eip;
	temp->next->next = 0;
	temp->next->prev = temp;
	return true;
};

void end_multitasking(){
	Task_t *temp = 0;
	for (temp = first_task; temp != 0; temp = temp->next){
	 free(temp);
	};
	outb(0x21, 0b11111111);
	outb(0xA1, 0b11111111);
};

void mul(){
	uint8_t code = inb(0x60);
	if (current_task == 0 &&  started == 1){end_multitasking(); started = 0; return;};

	register uint32_t *i asm("esp");
	register uint32_t *i2 asm("ebp");
	esp = i;
	ebp = i2;
	asm volatile("movl %0, %%esp" :: "r" (current_task->esp));
	asm volatile("movl %0, %%ebp" :: "r" (current_task->ebp));

	asm volatile("call *%0" :: "r" (current_task->eip));

	asm volatile("movl %0, %%esp" :: "r" (esp));
	asm volatile("movl %0, %%ebp" :: "r" (ebp));
	current_task->ebp -= 4095;
	free(current_task->ebp);
	current_task->ebp = 0;
	current_task->esp = 0;

	current_task = current_task->next;
};

#endif
