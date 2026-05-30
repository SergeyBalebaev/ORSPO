	#include <stdio.h> 
	#include <unistd.h> 
	#include <assert.h>
	#include <string.h>
	#include <stdarg.h>
	#include "safe_printf_lib.h"

	//используем safe_printf т.к. обычный printf для выделения памяти под буфер использует malloc

	#ifdef DEBUG
		#define info(... ) safe_printf(__VA_ARGS__)
	#else
		#define info(... )
	#endif


	int has_initialized = 0;	//флаг инициализации malloc_init
	void* managed_memory_start; //указатель на начало выделенной памяти
	void* last_valid_address;	//указатель на последний доступный адрес

	typedef struct mem_control_block {
		int is_available;
		long size;
	} mem_control_block;

	static void malloc_init()
	{
		managed_memory_start = sbrk(0);
		has_initialized = 1;
		last_valid_address = managed_memory_start;
		
		info("current head end in address %p\n", managed_memory_start);
	}

	static mem_control_block* find_available(long numbytes) {
		void* current = managed_memory_start;
		while(current < last_valid_address) {
			mem_control_block* block = (mem_control_block*)current;
			if(block->is_available == 1 && block->size >= numbytes) {
				return block;
			}
			current = (char*)current + sizeof(mem_control_block) + block->size;
		}
		return NULL;
	}


	void* malloc(long numbytes) {
		if(numbytes <= 0) return NULL;
		if(has_initialized == 0) {
			malloc_init();
		}
		mem_control_block* block = find_available(numbytes);
		if(block != NULL) {
			block->is_available = 0;
			info("reusing block at address %p", block);
			return (void*)(block + 1);
		}
		else {
			block = sbrk(sizeof(mem_control_block) + numbytes);
			if(block == (void*)-1) {
				info("failed to request memory from os");
				return NULL;
			}
			block->is_available = 0;
			block->size = numbytes;
			last_valid_address = sbrk(0);
			info("new block allocated at %p\n", last_valid_address);
			return (void*)(block+1);
			}
			
	}
		


	void free(void* firstbyte) {
		if(firstbyte == NULL) return;
		mem_control_block* block = (mem_control_block*)firstbyte - 1;
		block->is_available = 1;
		info("freed");
	}

