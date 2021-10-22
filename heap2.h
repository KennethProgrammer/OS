#ifndef heap_h
#define heap_h

#include "util.h"

#define HBP (0xb8000 + 4000)
#define heapSize2 ((0xffffffff - HBP)+1)

typedef struct memoryBlock{
	size_t length;
	bool used;
	struct memoryBlock *next;
	struct memoryBlock *prev;
}PACKED memBlock_t;

memBlock_t *first2;

void initHeap2(){
	first2 = (memBlock_t *)HBP;

	first2->length = heapSize2 - sizeof(memBlock_t);
	first2->used = false;
	first2->next = 0;
	first2->prev = 0;
};

//Start of malloc
void *mem_alloc2(size_t size){
	if (size == 0){return 0;};
	memBlock_t *result = 0;

	for(memBlock_t *current = first2; current != 0; current = current->next){
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
	newBlock->next = result->next;
	newBlock->prev = result;
	if (newBlock->next != 0){newBlock->next->prev = newBlock;};

	result->length = size;
	result->used = true;
	result->next = newBlock;
	return (void *)result + sizeof(memBlock_t);
};
//End of malloc
void *merge_next(memBlock_t *current){
	memBlock_t *next = current->next;
 	if (next != 0 && !next->used){
         current->length += current->next->length;
         current->length += (sizeof(memBlock_t));

         current->next = current->next->next;
         if (current->next != 0){current->next->prev = current;};
  	};
	return current;
};

void merge_prev(memBlock_t *current){
	memBlock_t *prev = current->prev;
	if (prev != 0 && !prev->used){
         prev->length += current->length;
         prev->length += (sizeof(memBlock_t));

         prev->next = current->next;
         if (current->next != 0){current->next->prev = prev;};
	};
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
