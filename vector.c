#include "vector.h"

Vector*	init_vector(size_t sizeof_data)
{
	Vector*	vector;

	vector = malloc(sizeof(Vector));
	vector->array = malloc(sizeof_data * CAPACITY);
	if (vector->array == NULL)
		return (NULL);
	vector->sizeof_data = sizeof_data;
	vector->size = 0;
	vector->capacity = CAPACITY;

	return (vector);
}

void	cleanup(Vector* v)
{
	if (v)
	{
		free(v->array);
		free(v);
	}
}

int	append(Vector* vector, const void* data)
{
	byte*	dest;

	if (vector->capacity - 1 < vector->size)
		vector->array = realloc(vector->array, vector->capacity * 2);
	
	dest = (byte*)vector->array + (vector->size * vector->sizeof_data);
	memcpy(dest, data, vector->sizeof_data);
	(vector->size)++;

	return (SUCCEED);
}

void*	get_element(Vector* vector, size_t i)
{
	if (!vector || i > vector->size)
		return (NULL);

	return (vector->array + (i * vector->sizeof_data));
}
