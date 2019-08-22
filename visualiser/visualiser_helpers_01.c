/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_helpers_01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:19:25 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:20:52 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ncurses.h>

void	p_action(WINDOW *win, enum e_action action, int row)
{
	if (action == PA)
		mvwprintw(win, row, 6, " pa ");
	else if (action == PB)
		mvwprintw(win, row, 6, " pb ");
	else if (action == SA)
		mvwprintw(win, row, 6, " sa ");
	else if (action == SB)
		mvwprintw(win, row, 6, " sb ");
	else if (action == SS)
		mvwprintw(win, row, 6, " ss ");
	else if (action == RA)
		mvwprintw(win, row, 6, " ra ");
	else if (action == RB)
		mvwprintw(win, row, 6, " rb ");
	else if (action == RR)
		mvwprintw(win, row, 6, " rr ");
	else if (action == RRA)
		mvwprintw(win, row, 6, " rra ");
	else if (action == RRB)
		mvwprintw(win, row, 6, " rrb ");
	else if (action == RRR)
		mvwprintw(win, row, 6, " rrr ");
	else if (action == START)
		mvwprintw(win, row, 5, " START ");
}

void	print_actions_down(WINDOW *win, t_action *action, int pos)
{
	while (action && pos < (LINES - 3))
	{
		p_action(win, action->action, pos++);
		action = action->next;
	}
}

void	print_actions_up(WINDOW *win, t_action *action, int pos)
{
	while (action && pos > 2)
	{
		p_action(win, action->action, pos--);
		action = action->prev;
	}
}

void	wprint_row(WINDOW *win, t_stack *current, int row, int dir)
{
	int i;

	i = 1;
	if (dir == 1)
	{
		if (current->next && current->index > current->next->index)
			wattron(win, COLOR_PAIR(2));
		else
			wattron(win, COLOR_PAIR(3));
	}
	else
	{
		if (current->next && current->index < current->next->index)
			wattron(win, COLOR_PAIR(2));
		else
			wattron(win, COLOR_PAIR(3));
	}
	while (i <= current->index)
		mvwprintw(win, row, i++, " ");
	wattroff(win, COLOR_PAIR(3));
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, row, i + 1, "[%d]", current->value);
}

void	draw_stackw(WINDOW *window, t_stack *stack, int dir)
{
	int row;

	stack = stack->next;
	row = 1;
	while (stack)
	{
		wprint_row(window, stack, row, dir);
		row++;
		stack = stack->next;
	}
	wrefresh(window);
}
