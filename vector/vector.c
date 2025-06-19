#include "vector.h"

static
int	get_element(const Vector* vector, size_t i)
{
	Block*	current;
	int		block_number;

	current = vector->sentinel->next;
	block_number = i / CAPACITY;
	while(current != vector->sentinel)
	{
		current = current->next;
		block_number--;
	}

	return current->array[i % CAPACITY];
}

void*	dispose_vector(Vector* vector)
{
	Block*	current;

	current = vector->sentinel->next;
	while(current != vector->sentinel)
	{
		current = current->next;
		free(current->prev);
	}
	free(vector->sentinel);
	free(vector);

	return (vector = NULL, (void*)vector);
}

static
STATUS	resize(Vector*	vector)
{
	Block*	current;
	Block*	new_block;

	current = vector->sentinel->next;
	while(current != vector->sentinel)
		current = current->next;
	
	new_block = malloc(sizeof(Block));
	if (!new_block)
		return FAILD;

	current->next = new_block;
	new_block->next = vector->sentinel;
	new_block->prev = current;

	vector->capacity += CAPACITY;

	return SUCCEED;
}

static
STATUS	append(Vector* vector, int data)
{
	STATUS	status;
	Block* current;

	current = vector->sentinel->next;
	while(current != vector->sentinel)
		current = current->next;

	if (vector->used >= vector->capacity)
	{
		status = resize(vector);
		if (status == SUCCEED)
		{
			current->array[0] = data;
			vector->used++;
		}
		else
			return FAILD;
	}
	else
	{
		current->array[vector->used + 1] = data;
		vector->used++;
	}
	return SUCCEED;
}
	
static
void	pop(Vector* vector)
{
	vector->used--;
}

Vector*	init_vector()
{
	Vector	*vector;
	Block 	*const	sentinel = malloc(sizeof(Block));

	if (!sentinel)
		return NULL;
	sentinel->next = sentinel;
	sentinel->prev = sentinel;

	vector = malloc(sizeof(Vector));
	if (!vector)
	{
		free(sentinel);
		return NULL;
	}
	*vector = (Vector){
		.sentinel = sentinel,
		.get_element = &get_element,
		.append = &append,
		.pop = &pop,
		.used = 0,
		.capacity = CAPACITY,
	};

	return vector;
}
