/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:26:30 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:28:54 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	ft_appendelem(t_stack **stack, int value)
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

t_stack	*ft_stackinit(void)
{
	t_stack *stack;

	if (!(stack = ft_newelem(0)))
		return (NULL);
	stack->master = true;
	return (stack);
}

int		get_min(t_stack **stack)
{
	int		min;
	t_stack	*cursor;

	cursor = (*stack)->next;
	min = cursor->value;
	while (cursor)
	{
		if (cursor->value < min)
			min = cursor->value;
		cursor = cursor->next;
	}
	return (min);
}

int		stack_len(t_stack *stack)
{
	t_stack	*cursor;
	int		i;

	i = 0;
	cursor = stack->next;
	while (cursor && i++)
		cursor = cursor->next;
	return (i);
}

int		index_of(t_stack **stack, int number)
{
	int		index;
	t_stack	*cursor;

	index = 0;
	cursor = (*stack)->next;
	while (cursor)
	{
		if (cursor->value == number)
			return (index);
		index++;
		cursor = cursor->next;
	}
	return (-1);
}
