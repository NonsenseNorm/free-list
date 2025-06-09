#include "vector.h"

int	main()
{
	char	str[] = "Hello World!";

	Vector*	vector = init_vector(sizeof(char));
	int	i = 0;
	while (1)
	{
		append(vector, (const void*)str + i);
		if (str[i] == '\0')
			break;
		i++;
	}

	printf("\n%s\n", (char*)vector->array);
	printf("\n%s\n", (char*)get_element(vector, 2));
	return 1;
}	
