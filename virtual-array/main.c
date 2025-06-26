#include "virtual_array.h"

int	main()
{
	VirtualArray* v;

	/*sizeof(char)*10でばぐる*/
	v = create_virtual_array(2);
	if (v == NULL)
		return 1;

	int i = 0;
	while (i < 100)
	{
		*((int *)virtual_array(v, i)) = i*10000;
		printf("varray[%d]: %d\n", i, *((int *)virtual_array(v, i)));
		i++;
	}

	dispose_virtual_array(v);
	return 0;
}
