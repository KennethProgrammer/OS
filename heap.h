#ifndef heap_h
#define heap_h

#include "util.h"

#define HBP (0x1+(40*512)+1024)
#define heapSize (0xffffffff - HBP)

typedef struct memoryBlock{
	size_t length;
	bool used;
	struct memoryBlock *next;
	struct memoryBlock *prev;
}PACKED memBlock_t;

memBlock_t *first;

void initHeap(uint32_t addr, size_t size){
	first = (memBlock_t *)addr;
	if (size < sizeof(memBlock_t)){first = 0; return;};

	first->length = size - sizeof(memBlock_t);
	first->used = false;
	first->next = 0;
	first->prev = 0;
};

//Start of malloc
void *malloc(size_t size){
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
	newBlock->next = 0;
	newBlock->prev = result;

	result->length = size;
	result->used = true;
	result->next = newBlock;
	result->prev = 0;
	return (void *)result + sizeof(memBlock_t);
};
//End of malloc

void *merge_next(memBlock_t *current){
	if (current->next != 0 && !current->next->used){

	 current->length += current->next->length + sizeof(memBlock_t);
	 current->next = current->next->next;

	 if (current->next != 0){current->next->prev = current;};
	};
	return current;
};

void *merge_prev(memBlock_t *current){
	return merge_next(current->prev);
};


void free(void *ptr){
	if (ptr == 0){return;};

	memBlock_t *current = (void *)ptr - sizeof(memBlock_t);
	if (current == 0){return;};

	current->used = false;
	current = merge_next(current);
	merge_prev(current);
};

#endif
