#ifndef VIRTUAL_ARRAY_H
#define VIRTUAL_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;

enum status
{
	ALLOCATING_NEW_FAILED,
	ALLOCATING_ARRAY_FAILED,
	SUCCEED,
	INVALID_INDEX,
	INVALID_BLOCK_TO_REMOVE,
	REMOVE_FAILED,
};

typedef struct s_block
{
	byte* head;
	size_t size;
	struct s_block* next;
	struct s_block* previous;
} Block;

typedef struct
{
	Block* sentinel;
	size_t block_size;
	size_t total_capacity;
} VirtualArray;

VirtualArray* create_virtual_array(size_t block_size);
VirtualArray* dispose_virtual_array(VirtualArray* v);
byte* virtual_array(VirtualArray* v, size_t i);

#endif
