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

VirtualArray*			create_virtual_array();
enum static				dispose_vitual_array(VirtualArray* v);
byte*					virtual_array(VirtualArray* v, size_t i);

static enum status		add_block(VirtualArray* v);
static enum status		remove_block(VirtualArray* v);

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
		.head = NULL,
		.size = -1,
		.next = sentinel,
		.previous = sentinel,
	}
	*v = (VirtualArray) {
		.sentinel = sentinel,
	}

	add_block(v);

	return v;
}

static
enum status		add_block(VirtualArray* v)
{
	Block*	current = v->sentinel->next;
	Block*	new;
	byte*	array;

	while(current != v->sentinel)
	{
		current = current->next;
	}

	new = malloc(sizeof(Block));
	if (!new)
		return NEW_MALLOC_FAILD;

	array = malloc(CAPACITY);
	if (!array)
		return ARRAY_MALLOC_FAILD;
	
	*(v->sentinel) = (Block) {
		.head = array;
		.size = CAPACITY;
		.next = v->sentinel;
		.previous = v->///ここsentinelじゃない

	}


}


