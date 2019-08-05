#include <push_swap.h>

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