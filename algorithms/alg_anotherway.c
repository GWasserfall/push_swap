#include <push_swap.h>
#include <curses.h>

void	ft_anotherway(t_stacks **container)
{
	/*
		repeat 2:
			take the first and last value of a
				push the biggest to b
		
		take the first and last number
	 */

	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	// find the first unsorted number and push to b
	t_stack *ca;
	t_stack *cb;

	pb(container);
	pb(container);

	ca = a;
	cb = b;

	ca = a->next;
	cb = b->next;
	while (a->next)
	{
		while (a->next->index < b->next->index)
		{
			//printf("%d - %d\n", a->next->index, b->next->index);
			rr(container);
		}
		rr(container);
		pb(container);
	}
}