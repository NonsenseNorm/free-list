#include "vector.h"

static int	get_element(const Vector* vector, size_t i)
{
	return 0;
}


static STATUS	resize(Vector*	vector)
{
	STAUTS	status;
	Block*	current;
	Block*	new_block;

	current = vector->sentinel.next;
	while(current != sentinel)
		current = current->next;
	
	new_block = malloc(sizeof(Block));
	if (!new_block)
		reuturn FAILD;
	current->next = new_block;
	new_block->next = sentinel;
	new_block->prev = current;

	vector->capacity += CAPACITY;

staitc STATUS	append(Vector* vector, int data)
{
	STATUS	status;

	if (vector->used >= vector->capacity) {
		status = resize(vector);
		if (status == SUCCEED)
		{
			
		}
	block = malloc(sizeof(Block));
	if (!block)
		return (status = FAILD, status);

	
static STATUS	pop(Vector* vector)
{

Vector*	init_vector()
{
	Vector	*vector;
	Block 	*const	sentinel = malloc(sizeof(Block));

	if (!sentinel)
		return NULL;
	sentinel->next = sentinel;
	sentinel->prev = sentinel;

	vector = malloc(sizeof(Vector));
	if (!vector) {
		free(sentinel);
		return NULL;
	}
	*vector = (Vector){
		.sentinel = sentinel,
		.get_element = &get_element,
		.used = 0,
		.capacity = CAPACITY,
	};

	return vector;
}
