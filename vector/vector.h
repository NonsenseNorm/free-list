#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 10 // 0とか負の数とかの時弾くようにしたい

typedef enum {
	SUCCEED, 
	FAILD,
}	STATUS;

typedef struct s_block {
	struct s_block*	next;
	struct s_block*	prev;
	int				array[CAPACITY];
}	Block;

typedef struct s_vector {
	Block* 	sentinel;
	size_t	used;
	size_t	capacity;
	int		(*get_element)(const struct s_vector* vector, size_t i);
	STATUS	(*append)(struct s_vector* vector, int data);
	void	(*pop)(struct s_vector* vector);
}	Vector;

Vector*	init_vector();
Vector*	dispose_vector();

#endif
