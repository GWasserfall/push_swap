#include "push_swap.h"

int get_top_group(t_stack *stack)
{
	int group;
	t_stack *cursor;

	group = 0;
	cursor = stack->next;
	while (cursor)
	{
		if (cursor->group > group)
			group = cursor->group;
		cursor = cursor->next;
	}
	return (group);
}

bool	push_closest_to_b(t_stack *stack, int group)
{
	t_stack *cursor;

	cursor = stack->next;
	while (cursor)
	{
		
		cursor = cursor->next;
	}
}


void ft_gabbysort(t_stacks **container, int group)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	while (a->next)
	{
		
	}
}