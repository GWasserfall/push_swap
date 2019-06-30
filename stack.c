#include "push_swap.h"

t_stack	*ft_newelem(int value)
{
	t_stack *stack;
	
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return NULL;
	
	stack->value = value;
	stack->master = false;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

bool ft_appendelem(t_stack **stack, int value)
{
	t_stack *cursor;
	t_stack *new_elem;

	cursor = *stack;

	if ((new_elem = ft_newelem(value)))
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_elem;
		new_elem->prev = cursor;
		return (true);
	}
	return (false);
}


t_stack	*ft_stackinit()
{
	t_stack *stack;

	if (!(stack = ft_newelem(0)))
		return NULL;

	stack->master = true;

	return (stack);
}