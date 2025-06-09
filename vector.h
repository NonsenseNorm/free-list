#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//配列は0から始まるので2としたら3番目
void*	get_element(Vector* v, size_t i);


//C言語ではテンプレート型などがないので型がわからないものにも対応するにはvoid*を受け取る
//そしてappendの第2引数がconst void* dataとなっているのも型がわからないのでデータを値渡しできないから
#endif
