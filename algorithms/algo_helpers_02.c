/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:42:02 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 13:43:45 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		len_to_end(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head != item)
		head = head->next;
	while (item)
	{
		i++;
		item = item->next;
	}
	return (i);
}

int		len_from_start(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head->next)
	{
		if (head->next == item)
			return (i);
		i++;
		head = head->next;
	}
	return (i);
}

int		end_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int		closest_lower_index(t_stack *stack, int index)
{
	int i;

	i = 0;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > i && stack->index < index)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	ft_reversesort_three(t_stacks **container, t_stack *stack)
{
	int a;
	int b;
	int c;

	stack = stack->next;
	a = stack->index;
	b = stack->next->index;
	c = stack->next->next->index;
	if (a < b && b < c && c > a)
	{
		rb(container);
		sb(container);
	}
	else if (a < b && b > c && c > a)
		rb(container);
	else if (a < b && b > c && c < a)
		sb(container);
	else if (a > b && b < c && c > a)
		rrb(container);
	else if (a > b && b < c && c < a)
	{
		rrb(container);
		sb(container);
	}
}
