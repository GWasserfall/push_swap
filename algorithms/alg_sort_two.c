/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:40:24 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 13:46:27 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sort_two(t_stacks **container)
{
	t_stack *a;
	t_stack *b;

	a = *(*container)->a;
	b = *(*container)->b;
	while (!(ft_sorted(&a, &b)))
		sa(container);
}
