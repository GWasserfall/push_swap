#include "push_swap.h"

bool ft_sorted(t_stack **stack, t_stack **helper)
{
	if ((*helper)->next)
		return false;
	t_stack *start = (*stack)->next;
	while (start)
	{
		if (!start->next)
			return true;
		if (start->value < start->next->value)
		{
			start = start->next;
			continue;
		}
		else
			return false;		
	}
	return true;
}

t_stacks	*ft_containstacks(t_stack **a, t_stack **b, bool is_checker)
{
	t_stacks *container;

	if (!(container = (t_stacks *)malloc(sizeof(t_stacks))))
		return NULL;
	
	container->a = a;
	container->b = b;
	container->is_checker = is_checker;

	return (container);
}

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