#include "_virtual_array.h"

VirtualArray*	dispose_virtual_array(VirtualArray* v)
{
	if (!v)
		return NULL;

	dealloc_blocks_except_sentinel(v);

	free(v->sentinel);
	free(v);
	return (v = NULL);
}

void	dealloc_blocks_except_sentinel(VirtualArray* v)
{
	if (!v)
		return;

	//This is not necessary, but having this makes much easier to follow the flow.
	Block*	sentinel = v->sentinel;
	if (sentinel->next == sentinel && sentinel->previous == sentinel)
		return;

	Block*	current = sentinel->next;
	Block*	next;
	while (current != sentinel)
	{
		next = current->next;
		free(current->head);
		free(current);
		current = next;
	}

	sentinel->next = sentinel;
	sentinel->previous = sentinel;

	return;
}

//なぜ構造体VirtualArrayではなくsentinelポインタ変数自体がconst定数なのかというと,total_capacityが動くから
//である
//動かしたいものと動かしたくないものが混在しているからである

//なぜsentinelだけ別でfreeするのかというとsentinelだけarrayをmallocしていないからfreeする必要がない
//sentinelは他のblocksとは違いVirtualArray型変数の一生につきそうものだからだ
//よってVirtualArray型変数消滅とともに解放されるべきだと考えた
