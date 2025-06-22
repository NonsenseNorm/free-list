#include "virtual_array.h"

int	main()
{
	VirtualArray* v;

	v = create_virtual_array();
	*virtual_array(v, 0) = (byte)'h';
	dispose_virtual_array(v);
	return 0;
}
