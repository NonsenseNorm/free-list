#include "virtual_array.h"

int	main()
{
	VirtualArray v;

	v = *create_virtual_array();
	*virtual_array(&v, 0) = (byte)'h';
	return 0;
}
