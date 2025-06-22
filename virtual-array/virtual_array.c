#include "virtual_array.h"

static enum status insert_block(VirtualArray* v, Block* previous_block);
enum status remove_block(VirtualArray* v, Block* block_to_remove);

VirtualArray* create_virtual_array()
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
	*v = (VirtualArray)
	{
		.sentinel = sentinel,
		.total_capacity = 0,
	};

	if (insert_block(v, v->sentinel) != SUCCEED)
	{
		/*dispose_virtual_array(v);*/
		return NULL;
	}

	return v;
}

/*
enum status dispose_virtual_array(VirtualArray* v)
{
	if (!v)
	{
		return REMOVE_FAILED;
	}

	Block* current = v->sentinel->next;
	while (current != v->sentinel)
	{
		Block* next_block = current->next;
		if (remove_block(v, current) != SUCCEED)
		{
			// エラーハンドリングが必要であればここに記述
			// 例えば、部分的に解放された状態で関数を終了するか、エラーを返すか
			return REMOVE_FAILED;
		}
		current = next_block;
	}

	free(v->sentinel);
	free(v);
	return SUCCEED;
}
*/

byte* virtual_array(VirtualArray* v, size_t i)
{
	if (!v || i >= v->total_capacity)
	{
		return NULL;
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

static
enum status insert_block(VirtualArray* v, Block* previous_block)
{
	Block* new_block = malloc(sizeof(Block));
	if (!new_block)
	{
		return ALLOCATING_NEW_FAILED;
	}

	byte* array = malloc(CAPACITY);
	if (!array)
	{
		free(new_block);
		return ALLOCATING_ARRAY_FAILED;
	}

	*new_block = (Block)
	{
		.head = array,
		.size = CAPACITY,
		.next = previous_block->next,
		.previous = previous_block,
	};

	previous_block->next->previous = new_block;
	previous_block->next = new_block;

	v->total_capacity += CAPACITY;

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