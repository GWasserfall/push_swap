#include <push_swap.h>

int		stack_length(t_stack *head)
{
	int  count;

	count = 0;
	head = head->next;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

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

void	ft_sort_below_thirty(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	int stacklen;

	while ((stacklen = stack_length(a) > 3))
		push_smallest_to_b(container);

	ft_sort_three(container);

	while (b->next)
		pa(container);
}