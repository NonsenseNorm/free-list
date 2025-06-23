#include "_virtual_array.h"

VirtualArray* create_virtual_array(size_t block_size)
{
	Block *const sentinel = malloc(sizeof(Block));
	if (!sentinel)
	{
		return NULL;
	}
	VirtualArray* v = malloc(sizeof(VirtualArray));
	if (!v)
	{
		free(sentinel);
		return NULL;
	}

	*sentinel = (Block)
	{
		.head = NULL,
		.size = 0,
		.next = sentinel,
		.previous = sentinel,
	};
	if (block_size == 0)
		return NULL;
	*v = (VirtualArray)
	{
		.sentinel = sentinel,
		.block_size = block_size,
		.total_capacity = 0,
	};

	if (insert_block(v, v->sentinel) != SUCCEED)
	{
		dispose_virtual_array(v);
		return NULL;
	}

	return v;
}

byte* virtual_array(VirtualArray* v, size_t i)
{
	if (!v)
		return NULL;

	if (i >= v->total_capacity)
	{
		if (insert_block(v, v->sentinel) != SUCCEED)
		{
			dispose_virtual_array(v);
			return NULL;
		}
	}

	Block* current = v->sentinel->next;
	size_t current_offset = 0;

	while (current != v->sentinel)
	{
		if (i < current_offset + current->size)
		{
			return current->head + (i - current_offset);
		}
		current_offset += current->size;
		current = current->next;
	}
	return NULL;
}
//上の関数自分が書いたvector.c内部のget_elementと比較すること,自分の何が悪かったのか

//The new block will inserted right after the position.
enum status insert_block(VirtualArray* v, Block* position)
{
	Block* new_block = malloc(sizeof(Block));
	if (!new_block)
	{
		return ALLOCATING_NEW_FAILED;
	}

	byte* array = malloc(v->block_size);
	if (!array)
	{
		free(new_block);
		return ALLOCATING_ARRAY_FAILED;
	}

	*new_block = (Block)
	{
		.head = array,
		.size = v->block_size,
		.next = position->next,
		.previous = position,
	};

	position->next->previous = new_block;
	position->next = new_block;

	v->total_capacity += v->block_size;

	return SUCCEED;
}

/*
static
enum status remove_block(VirtualArray* v, Block* block_to_remove)
{
	if (!v || !block_to_remove || block_to_remove == v->sentinel)
	{
		return INVALID_BLOCK_TO_REMOVE;
	}

	block_to_remove->previous->next = block_to_remove->next;
	block_to_remove->next->previous = block_to_remove->previous;

	free(block_to_remove->head);
	free(block_to_remove);

	v->total_capacity -= CAPACITY;

	return SUCCEED;
}
*/