#include <push_swap.h>

void	push_smallest_to_b(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *smallest;
	t_stack *cursor;

	smallest = a->next;
	cursor = smallest;
	while (cursor)
	{
		if (cursor->index < smallest->index)
			smallest = cursor;
		cursor = cursor->next;
	}
	if (len_from_start(a, smallest) < len_to_end(a, smallest))
	{
		while (a->next != smallest)
			ra(container);
		pb(container);
	}
	else
	{
		while (a->next != smallest)
			rra(container);
		pb(container);
	}
}

void	ft_sort_five(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	int stacklen;
	while ((stacklen = stack_is_long(a) > 3))
		push_smallest_to_b(container);
	ft_sort_three(container);
	while (b->next)
		pa(container);
}