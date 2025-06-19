#include "vector.h"

int	main()
{
	Vector*	v = init_vector();

	printf("v: %p", v);
	v->append(v, 'h');
	int data = v->get_element(v, 0);
	printf("data: %d", data);
	v = dispose_vector(v);
	printf("v: %p", v);
	return 0;
}
