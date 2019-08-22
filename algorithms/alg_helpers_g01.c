/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_helpers_g01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:27 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 15:34:22 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_best_move(t_moves **move, int a, int b, int t)
{
	t_moves *m;

	m = *move;
	m->a_moves = a;
	m->b_moves = b;
	m->total = t;
}

void	init_moves(t_moves **move, t_stack *a, t_stack *b)
{
	t_moves *m;

	m = *move;
	m->maxa = max_index(a);
	m->lena = stack_is_long(a);
	m->total = INT_MAX;
	m->lenb = stack_is_long(b);
	m->pos = 0;
}

int		b_not_sorted(t_stacks **container)
{
	t_stack *b;
	int		min;

	b = *(*container)->b;
	min = min_index(b);
	b = b->next;
	while (b)
	{
		if (b->next)
		{
			if ((b->index < b->next->index) && b->index != min)
				return (1);
		}
		b = b->next;
	}
	return (0);
}
