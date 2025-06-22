#ifndef _VIRTUAL_ARRAY_H
#define _VIRTUAL_ARRAY_H

#include "virtual_array.h"

enum status insert_block(VirtualArray* v, Block* previous_block);
enum status remove_block(VirtualArray* v, Block* block_to_remove);
void	dealloc_blocks_except_sentinel(VirtualArray* v);

#endif
