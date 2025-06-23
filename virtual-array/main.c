#include "virtual_array.h"

int	main()
{
	VirtualArray* v;

	v = create_virtual_array(sizeof(char)*200);
	*virtual_array(v, 0) = (int)100;
	int i = (int)*virtual_array(v, 0);
	printf("%d", i);
	dispose_virtual_array(v);
	return 0;
}
