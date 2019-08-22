/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_below_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:46:32 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 13:49:07 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_smallest_to_b(t_stacks **container)
{
	t_stack *a;
	t_stack *smallest;
	t_stack *cursor;

	a = *(*container)->a;
	smallest = a->next;
	cursor = smallest;
	while (cursor)
	{
		if (cursor->index < smallest->index)
			smallest = cursor;
		cursor = cursor->next;
	}
	if (len_from_start(a, smallest) < len_to_end(a, smallest))
	{
		while (a->next != smallest)
			ra(container);
		pb(container);
	}
	else
	{
		while (a->next != smallest)
			rra(container);
		pb(container);
	}
}

void	ft_sort_five(t_stacks **container)
{
	t_stack *a;
	t_stack *b;
	int		stacklen;

	a = *(*container)->a;
	b = *(*container)->b;
	while ((stacklen = stack_is_long(a) > 3))
		push_smallest_to_b(container);
	ft_sort_three(container);
	while (b->next)
		pa(container);
}
