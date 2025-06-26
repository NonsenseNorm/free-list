#include "virtual_array.h"

typedef struct 
{
	int x;
	char c;
} t_data;


int	main()
{
	VirtualArray* v;

	t_data data = {30, 's'};

	v = create_virtual_array(2);
	if (v == NULL)
		return 1;

	int i = 0;
	while (i < 100)
	{
		*((t_data *)virtual_array(v, i)) = data;	
		i++;
	}

	i = 0;
	while (i < 100)
	{
		printf("varray[%d]: %d\n", i, ((t_data *)virtual_array(v, i))->x);
		printf("varray[%d]: %c\n", i, ((t_data *)virtual_array(v, i))->c);	
		i++;
	}
	
	dispose_virtual_array(v);
	return 0;
}
