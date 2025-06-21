#include "vector.h"

int	main()
{
	Vector*	v = init_vector();

	v->append(v, 'h');

	printf("\n--------------------in main()-----------------------\n");
	printf("vector: %p\n", v);
	printf("------------------------end---------------------------\n");
	return 0;
}
