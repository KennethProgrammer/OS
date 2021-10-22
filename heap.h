#ifndef kernel_heap
#define kernel_heap

#include "heap2.h"

memBlock_t *first = 0;

void initHeap(){
	first = (memBlock_t *)21506;

	first->length = (0xb8000 - 21506) - sizeof(memBlock_t);
	first->used = false;
	first->next = 0;
	first->prev = 0;
};

void *mem_alloc(size_t size){
	if (size == 0){return 0;};
	memBlock_t *result = 0;

	for(memBlock_t *current = first; current != 0; current = current->next){
	 if (current->length == size && !current->used){
	  current->used = true;
	  return (void *)current + sizeof(memBlock_t);
	 };
	 if (current->length > size && !current->used){result = current; break;};
	};


	if (result == 0){return 0;};

	if (result->length < size + sizeof(memBlock_t) + 1){
	 result->used = true;
	 return (void *)result + sizeof(memBlock_t);
	};

	memBlock_t *newBlock = (void *)result + sizeof(memBlock_t) + size;
	newBlock->used = false;
	newBlock->length = result->length - size - sizeof(memBlock_t);
	newBlock->prev = result;
	newBlock->next = result->next;
	if (newBlock->next != 0){newBlock->next->prev = newBlock;};

	result->length = size;
	result->used = true;
	result->next = newBlock;
	return (void *)result + sizeof(memBlock_t);
};

void initBothHeaps(){
	initHeap();
	initHeap2();
};

void *malloc(size_t size){
	if (size == 0){return 0;};
	void *ptr = mem_alloc(size);
	if (ptr == 0){ptr = mem_alloc2(size);};
	return ptr;
};

void *realloc(void *addr, size_t size){
	char *ADDR = (char *)addr;
	memBlock_t *ptr_addr = (void *)addr - sizeof(memBlock_t);
	char *dst = malloc(size);
	size_t smaller_size = 0;

	if (ptr_addr->length < size){smaller_size = ptr_addr->length;}
	else {smaller_size = size;};
	for (int i = 0; i < smaller_size; i++){dst[i] = ADDR[i];};
	free(addr);
	return (void *)dst;
};

int no_of_blocks(){
	int i = 0;
	for (memBlock_t *temp = first; temp != 0; temp = temp->next){i++;};
	return i;
};

#endif
