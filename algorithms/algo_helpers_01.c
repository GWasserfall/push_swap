#include <push_swap.h>

void largest_to_top(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);
	t_stack *largest;
	t_stack *cursor;
	
	largest = b->next;
	cursor = b->next;
	while (cursor)
	{
		if (cursor->index > largest->index)
			largest = cursor;
		cursor = cursor->next;
	}
	
	while (b->next != largest)
	{
		if (len_from_start(b, largest) < len_to_end(b, largest))
			rb(container);
		else
			rrb(container);
	}
	pa(container);
}

void push_back_to_a(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);

	while (b->next)
		largest_to_top(container);
}

int min_index(t_stack *stack)
{
	int min;

	stack = stack->next;
	if (!stack)
		return (0);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return min;
}

int max_index(t_stack *stack)
{
	int max;

	if (stack)
		max = stack->index;
	else
		return 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return max;
}

int stack_is_long(t_stack *stack)
{
	int count;

	count = 0;
	stack = stack->next;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}