/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_gsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:21:41 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/22 15:34:41 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		move_count(t_stack *stack, int norm)
{
	int count;
	int next;
	int len;
	int max;
	int min;

	count = 0;
	len = stack_is_long(stack);
	max = max_index(stack);
	min = min_index(stack);
	next = closest_lower_index(stack, norm);
	stack = stack->next;
	if (norm < min)
		next = max;
	while (stack)
	{
		if (stack->index == next)
			break ;
		count++;
		stack = stack->next;
	}
	if (count > len / 2)
		return (count - len);
	else
		return (count);
}

void	calc_moves(t_moves **move, int *am, int *bm, int *total)
{
	t_moves	*m;

	m = *move;
	*am = (m->pos > m->lena / 2) ? m->pos - m->lena : m->pos;
	if (*bm > m->lenb / 2)
		*bm = *bm - m->lenb;
	if (*bm == *am)
		*total = (*bm > 0) ? *bm : *bm * -1;
	else if (*am > 0 && *bm > 0)
		*total = (*am > *bm ? *am : *bm);
	else if (*am < 0 && *bm < 0)
		*total = (*am < *bm) ? *am * -1 : *bm * -1;
	else
		*total = (*am - *bm > 0) ? *am - *bm : (*am - *bm) * -1;
}

void	best_move(t_moves **move, t_stack *a, t_stack *b)
{
	t_moves	*m;
	int		amoves;
	int		bmoves;
	int		total;

	m = *move;
	init_moves(move, a, b);
	a = a->next;
	while (a)
	{
		bmoves = move_count(b, a->index);
		calc_moves(move, &amoves, &bmoves, &total);
		if (a->index > m->maxa - 3)
			total += 200;
		if (total < m->total)
			set_best_move(move, amoves, bmoves, total);
		m->pos++;
		a = a->next;
	}
}

void	gsort(t_stacks **container, t_moves **moves, int a_max)
{
	t_stack	*a;
	t_stack	*b;

	a = *(*container)->a;
	b = *(*container)->b;
	ft_initial_push(container, a_max);
	while (a->next && !(stack_is_long(a) == 3))
	{
		best_move(moves, a, b);
		while ((*moves)->a_moves || (*moves)->b_moves)
		{
			if ((*moves)->b_moves > 0 && (*moves)->a_moves > 0)
				ft_dblrotate(container, moves, 1);
			else if ((*moves)->b_moves < 0 && (*moves)->a_moves < 0)
				ft_dblrotate(container, moves, -1);
			else if (!(*moves)->b_moves && (*moves)->a_moves)
				ft_rotate_a(container, moves);
			else
				ft_rotate_b(container, moves);
		}
		pb(container);
	}
	ft_sort_three(container);
	push_back_to_a(container);
}
