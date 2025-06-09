#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOCATION_LIMIT
#define CAPACITY 10
#define FAILD -1
#define SUCCEED 1

typedef unsigned char byte;

typedef struct {
	void*	array;
	size_t	sizeof_data;
	size_t	size;
	size_t	capacity;
}	Vector;

Vector*	init_vector(size_t sizeof_data);
void	cleanup(Vector* v);
int		append(Vector* v, const void* data);
void*	get_element(Vector* v, size_t i);

#endif
