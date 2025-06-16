#include "vector.h"

int	get_element(const Vector* vector, size_t i)
{
	return 0;
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
