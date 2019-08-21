/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_helpers_03.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:15:47 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:19:21 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	advance_action(t_stacks **container, t_vstate *state)
{
	t_action *position;

	position = (*container)->v_actions->next;
	if (position)
	{
		act_forward(container, position);
		(*container)->v_actions = position;
	}
	if (position && !position->next)
	{
		if (ft_sorted((*container)->a, (*container)->b))
			wbkgd(state->middlew, COLOR_PAIR(3));
		else
			wbkgd(state->middlew, COLOR_PAIR(2));
	}
}

int		count_actions(t_action *current)
{
	int i;

	i = 0;
	while (current->prev)
	{
		i++;
		current = current->prev;
	}
	return (i);
}

void	print_actions(WINDOW *win, t_action *position)
{
	int middle;
	int moves;

	middle = LINES / 2;
	werase(win);
	print_actions_down(win, position->next, middle + 1);
	wattron(win, COLOR_PAIR(4));
	p_action(win, position->action, middle);
	wattroff(win, COLOR_PAIR(4));
	print_actions_up(win, position->prev, middle - 1);
	moves = count_actions(position);
	mvwprintw(win, 0, 8 - ft_intlen(moves) / 2, "%d", moves);
	wrefresh(win);
}

void	clear_stacks(WINDOW *left, WINDOW *right)
{
	werase(left);
	werase(right);
	box(left, 0, 0);
	box(right, 0, 0);
}

void	init_colors(void)
{
	start_color();
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
}
