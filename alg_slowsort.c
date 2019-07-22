#include "push_swap.h"

void	ft_slowsort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	// find the lowest value and push it to stack b over and over and over again

	int min;
	int	stacklen;

	while (!(ft_sorted(&a, &b)))
	{
		stacklen = stack_len(a);
		min = get_min(&a);

		while (index_of(&a, min) != 0)
		{
			if (index_of(&a, min) > (stacklen / 2))
				rra(container);
			else
				ra(container);	
		}
		
		pb(container);
		if (stack_len(a) == 3)
			sort_three(container);
		if (!a->next)
			while (b->next)
				pa(container);
	}
}