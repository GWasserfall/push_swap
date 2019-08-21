/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_gsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:21:41 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/15 17:21:42 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>




int b_not_sorted(t_stacks **container)
{
	t_stack *b = (*(*container)->b);
	int min = min_index(b);

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
	return 0;
}


int move_count(t_stack *stack, int norm)
{
	t_stack *starts;
	int count;
	//int start;
	int next;
	int len;
	int max;
	int min;

	count = 0;
	len = stack_is_long(stack);
	max = max_index(stack);
	min = min_index(stack);
	starts = stack->next;
	next = closest_lower_index(stack, norm);
	stack = stack->next;
	// if (norm > max && start == max) TODO
	// 	return (0);
	if (norm < min)
		next = max;
	while (stack)
	{
		if (stack->index == next)
			break;
		count++;
		stack = stack->next;
	}
	if (count > len / 2)
		return count - len;
	else
		return count;
}

void	best_move(t_moves **move, t_stack *a, t_stack *b)
{
	t_moves *m;
	int position;
	int len;
	int lenb;
	int amoves;
	int bmoves;
	int total;

	int big;

	big = max_index(a);


	len = stack_is_long(a);
	lenb = stack_is_long(b);
	m = *move;
	a = a->next;

	m->total = INT_MAX;

	position = 0;	
	while (a)
	{
		amoves = (position > len / 2) ? position - len : position;
		bmoves = move_count(b, a->index);
		if (bmoves > lenb / 2)
			bmoves = bmoves - lenb;
		if (bmoves == amoves)
			total = (bmoves > 0) ? bmoves : bmoves * -1;
		else if (amoves > 0 && bmoves > 0)
			total = (amoves > bmoves ? amoves : bmoves);
		else if (amoves < 0 && bmoves < 0)
			total = (amoves < bmoves) ? amoves * -1 : bmoves * -1;
		else
			total = (amoves - bmoves > 0) ? amoves - bmoves : (amoves - bmoves) * -1;
		
		if (a->index > big - 3)
			total += 200;

		if (total < m->total)
		{
			m->a_moves = amoves;
			m->b_moves = bmoves;
			m->total = total;
		}
		position++;
		a = a->next;
	}
}

void gsort(t_stacks **container, t_moves **moves, int a_max)
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
