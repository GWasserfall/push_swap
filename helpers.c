#include "push_swap.h"

bool	ft_hasdupe(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*position;
	int		current;

	position = (*stack)->next;
	while (true)
	{
		if (!position)
			return false;
		current = position->value;
		cursor = position->next;
		while (cursor)
		{
			if (current == cursor->value)
				return true;
			cursor = cursor->next;
		}
		position = position->next;
	}
	return false;
}

int		ft_top(t_stack **stack)
{
	// Not safe to run on empty stack :(
	return ((*stack)->next->value);
}

int		ft_bottom(t_stack **stack)
{
	t_stack *cursor;
	cursor = (*stack)->next;
	while (cursor->next)
	{
		cursor = cursor->next;
	}
	return (cursor->value);
}

bool	ft_isempty(t_stack **stack)
{
	if ((*stack)->next)
		return (false);
	return (true);
}

long ft_atol(char *string)
{
	long negative;
	long result;

	while (ft_isspace(*string) || *string == '-')
		string++;
	negative = (*(string - 1) == '-') ? -1 : 1;
	result = 0;
	while (*string)
	{
		result = result + (*string - '0');
		if (*(++string))
			result *= 10;
	}
	return (result * negative);
}