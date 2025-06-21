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
	Block*	current;
	int		block_counter;
	size_t	i;

	current = vector->sentinel->next;
	block_counter = 0;
	while(current != vector->sentinel)
	{
		current = current->next;
		block_counter++;
	}

	if (vector->used >= vector->capacity)
	{
		status = resize(vector);
		if (status == SUCCEED)
		{
			current->array[0] = data;
			vector->used++;
		}
		else
		{
			printf("faild in append() with resize()");
			return FAILD;
		}
	}
	else
	{
		i = vector->used - (block_counter - 1)*CAPACITY;
		current->array[i] = data;
		vector->used++;
	}

	printf("vecotr->used: %d, current: %p\n", vector->used, current);
	printf("vector->used - (block_counter - 1)*CAPACITY: %d\n", i);
	printf("array[i] = %c\n", (char)current->array[vector->used - 1]);
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

	printf("\n---------------in init_vector()-------------------\n");
	printf("vector: %p\n", vector);
	printf("sentinel.next: %p\n", sentinel->next);
	printf("sentinel.prev: %p\n", sentinel->prev);
	printf("----------------------end---------------------------\n");

	resize(vector);
	printf("\n----after calling resize for create first block-----\n");
	printf("vector: %p\n", vector);
	printf("sentinel.next: %p\n", sentinel->next);
	printf("sentinel.prev: %p\n", sentinel->prev);
	printf("----------------------end---------------------------\n");

	return vector;
}
