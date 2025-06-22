#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 200
typedef unsigned char byte;

enum status {
	ALLOCATING_NEW_FAILED,
	ALLOCATING_ARRAY_FAILED,
	SUCCEED,
};

typedef struct s_block {
	byte*			head;
	size_t			size;//sizeというよりtotal_size
	struct s_block*	next;
	struct s_block*	previous;
}	Block;

typedef struct {
	Block*	sentinel;
}	VirtualArray;

VirtualArray*			create_virtual_array();
static enum status		dispose_vitual_array(VirtualArray* v);
byte*					virtual_array(VirtualArray* v, size_t i);

static enum status		add_block(VirtualArray* v, Block* block);
static enum status		remove_block(VirtualArray* v, Block* block);

VirtualArray*	create_virtual_array()
{
	VirtualArray*	v;
	Block *const	sentinel = malloc(sizeof(Block));

	if (!sentinel)
		return NULL;
	v = malloc(sizeof(VirtualArray));
	if (!v)
	{
		free(sentinel);
		return NULL;
	}

	*sentinel = (Block) {
		.head = NULL,
		.size = 0,
		.next = sentinel,
		.previous = sentinel,
	}
	*v = (VirtualArray) {
		.sentinel = sentinel,
	}

	add_block(v, v->sentinel->previous);

	return v;
}

static
enum status		add_block(VirtualArray* v, Block* block)
{
	Block*	current = v->sentinel->next;
	Block*	new;
	byte*	array;

	new = malloc(sizeof(Block));
	if (!new)
		return ALLOCATING_NEW_FAILED;
	array = malloc(CAPACITY);
	if (!array)
	{
		free(new);
		return ALLOCATING_ARRAY_FAILED;
	}

	block->next = new;
	block->next->previous = new;
	*(new) = (Block) {
		.head = array,
		.size = block->capacity + CAPACITY,
		.next = block->next,
		.previous = block,
	};

	return SUCCEED;
}


