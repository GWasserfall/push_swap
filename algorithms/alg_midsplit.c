#include <push_swap.h>
#include <ncurses.h>

t_stack *get_by_index(t_stack *stack, int index)
{
	stack = stack->next;
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);

}

bool contains_index(t_stack *stack, int index)
{
	stack = stack->next;
	while (stack)
	{
		if (stack->index == index)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void ft_midsplit(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	int direction;

	direction = 1;

	int mid = slen(a) / 2;
	int total;

	t_stack *median;
	median = get_by_index(a, mid);

	total = slen(a);
	while (1)
	{
		if (a->next->index > mid)
		{
			pb(container);
		}
		ra(container);
		if (slen(a) <= mid)
			break;
	}

	t_stack *next;

	next = 

	if (len_from_start(a, median) < len_to_end(a, median))
	{
		while (a->next != median)
			ra(container);
	}
	else
	{
		while (a->next != median)
			rra(container);
	}
}