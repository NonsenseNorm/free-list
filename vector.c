#include "vector.h"

valgrind memcheck api, lldb backtrace

static void*	safe_malloc(size_t	size)
{
	static void*	allocated_array[ALLOCATION_LIMIT];
	static int		allocation_counter = 0;
	void*			ret;
	
	ret = malloc(size);
	if (ret)
	{
		if (!(allocation_counter > ALLOCATION_LIMIT - 1))
			return NULL;

		allocation_counter++;
		allocated_array[allocation_counter] = ret;
		return (ret);
	}

	while (allocation_counter)
	{
		free(allocated_array[allocation_counter]);
		allocation_counter--;
	}

	exit(EXIT_FAILURE);
}

Vector*	init_vector(size_t sizeof_data, size_t CAPACITY)
{
	Vector	vector;

	vector = malloc(sizeof(Vector));
	vector.array = malloc(sizeof_data * CAPACITY);
	if (vector.array == NULL)
		return (NULL);
	vector.sizeof_data = sizeof_data;
	vector.size = 0;
	vector.capacity = CAPACITY;

	return (&vector);
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
	int		code;
	byte*	dest;

	if (vector->capacity - 1 < vector->size)
	{
		code = resize(vector);
		if (code == FAILD)
			return (FAILD);
	}
	
	dest = (byte*)vector->array + (vector->size * vector->sizeof_data);
	memcpy(dest, data, vector->sizeof_data);
	(vector->size)++;

	return (SUCCEED);
}

void*	get_element(Vector* vector, size_t i)
{
	if (!vector || i > vector->size)
		return (NULL);

	return (vector->array + (vactor->size * vector->sizeof_data));
}
