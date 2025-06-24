#include "virtual_array.h"

int	main()
{
	VirtualArray* v;

	/*sizeof(char)*10でばぐる*/
	v = create_virtual_array(1);
	if (v == NULL)
		return 1;

	size_t i = 0;
	while (i < 100 && virtual_array(v, i) != NULL)
	{
		*virtual_array(v, i) = (int)i;
		i++;
	}

	size_t n = 0;
	while (n < 100)
	{
		printf("v_array[%ld]: %d\n", n, (int)*virtual_array(v, n));
		n++;
	}
	dispose_virtual_array(v);
	return 0;
}
