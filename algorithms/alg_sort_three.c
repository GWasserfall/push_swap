/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:28:50 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 13:32:34 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_value_at_index(t_stack **stack, int index)
{
	t_stack	*cursor;
	int		i;

	i = 0;
	cursor = (*stack)->next;
	while (cursor)
	{
		if (i == index)
		{
			return (cursor->value);
		}
		i++;
		cursor = cursor->next;
	}
	return (-1);
}

void	ft_sort_three(t_stacks **container)
{
	t_stack	*a;
	int		one;
	int		two;
	int		thr;

	a = *(*container)->a;
	while (!(ft_single_sorted(a)))
	{
		one = get_value_at_index(&a, 0);
		two = get_value_at_index(&a, 1);
		thr = get_value_at_index(&a, 2);
		if (one > two && one < thr)
			sa(container);
		else if (one > two && one > thr)
			ra(container);
		else if (one < two && two > thr)
			rra(container);
		else if (one > two && one > thr)
			sa(container);
		else if (one < two && two > thr)
			sa(container);
	}
}
