#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 10
#define FAILD -1
#define SUCCEED 1

typedef struct s_block {
	struct s_block*	next;
	struct s_block*	prev;
	int				array[CAPACITY];
}	Block;

typedef struct s_vector {
	Block* 	sentinel;
	int		(*get_element)(const struct s_vector* vector, size_t i);
	size_t	used;
	size_t	capacity;
}	Vector;

Vector*	init_vector();
void	cleanup(Vector* vector);
int		append(Vector* vector,int data);
int		get_element(const Vector* vector, size_t i);

#endif
