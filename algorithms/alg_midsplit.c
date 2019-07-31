#include <push_swap.h>
#include <ncurses.h>

void ft_midsplit(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	int pivot_index = slen(a) / 8;

	t_stack *pivot_point = a;
	while (pivot_point->index != pivot_index)
		pivot_point = pivot_point->next;

	while (a->next)
	{
		getchar();
		if (a->next->index % 2 == 0)
			pb(container);
		else
			ra(container);
	}

	





}