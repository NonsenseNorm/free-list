typedef unsigned char byte;

typedef struct s_block {
	byte*			head;
	ssize_t			size;
	struct s_block*	next;
	struct s_block*	previous;
}	Block;

typedef struct {
	Block*	sentinel;
}	VirtualArray;

VirtualArray*	create_virtual_array();


VirtualArray*	create_virtual_array()
{
	VirtualArray*	v;
	Block *const	sentinel = malloc(sizeof(Block));

	if (!sentinel)
		return NULL;
		
	v = malloc(sizeof(VirtualArray));
	if (!VirtualArray)
	{
		free(sentinel);
		return NULL;
	}

	*sentinel = (Block) {
		.head = NULL;
		.size = -1;
		.next = sentinel;
		.previous = sentinel;
	}

	*v = (VirtualArray) {
		.sentinel = 
