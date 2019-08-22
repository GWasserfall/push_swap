/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:34:22 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 13:38:07 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	largest_to_top(t_stacks **container)
{
	t_stack *b;
	t_stack *largest;
	t_stack *cursor;

	b = *(*container)->b;
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

void	push_back_to_a(t_stacks **container)
{
	t_stack *b;

	b = *(*container)->b;
	while (b->next)
		largest_to_top(container);
}

int		min_index(t_stack *stack)
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
	return (min);
}

int		max_index(t_stack *stack)
{
	int max;

	if (stack)
		max = stack->index;
	else
		return (0);
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
