/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:25:58 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 15:35:32 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (false);
		current = position->value;
		cursor = position->next;
		while (cursor)
		{
			if (current == cursor->value)
				return (true);
			cursor = cursor->next;
		}
		position = position->next;
	}
	return (false);
}

long	ft_atol(char *string)
{
	long	negative;
	long	result;

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

int		stack_is_long(t_stack *stack)
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
