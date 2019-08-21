/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:04:17 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:10:22 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <time.h>
#include <push_swap.h>

t_vstate	*initialise(void)
{
	FILE		*f;
	t_vstate	*state;

	if (!(state = (t_vstate *)malloc(sizeof(t_vstate))))
		return (NULL);
	state->interactive = isatty(0);
	if (!state->interactive)
	{
		f = fopen("/dev/tty", "r+");
		state->screen = newterm(NULL, f, f);
	}
	else
		state->screen = newterm(NULL, stderr, stdin);
	set_term(state->screen);
	init_colors();
	curs_set(0);
	noecho();
	state->rightw = newwin(HEIGHT(LINES), (COLS / 2 - 8), 1, RMID(COLS));
	state->leftw = newwin(HEIGHT(LINES), LMID(COLS), 1, 0);
	state->middlew = newwin(HEIGHT(LINES), 16, 1, COLS / 2 - 8);
	box(state->leftw, 0, 0);
	box(state->rightw, 0, 0);
	keypad(stdscr, TRUE);
	return (state);
}

void		initial_draw(t_vstate *state, t_stacks *container)
{
	mvprintw(0, (COLS / 2 - 10) / 2, "STACK A");
	mvprintw(0, COLS - ((COLS / 2 - 10) / 2), "STACK B");
	mvprintw(LINES - 1, 0, "[KEY_LEFT] Step Back");
	mvprintw(LINES - 1, 32, "[KEY_RIGHT] Step Forward");
	mvprintw(LINES - 1, 68, "[ENTER] Run From Here");
	if (state->interactive)
		mvprintw(LINES - 1, 99, "[a] Append Action");
	mvprintw(LINES - 1, COLS - 20, "[q] Exit");
	refresh();
	print_actions(state->middlew, container->v_actions);
	draw_stackw(state->leftw, *(container->a), TRUE);
	draw_stackw(state->rightw, *(container->b), FALSE);
}

bool		is_valid_move(t_stacks *con, enum e_action a)
{
	int alen;
	int blen;

	alen = stack_is_long(*(con->a));
	blen = stack_is_long(*(con->b));
	if (a != INVALID)
	{
		if (a == PA && blen == 0)
			return (false);
		if (a == PB && alen == 0)
			return (false);
		if ((a == RA || a == RR || a == RRA || a == RRR) && alen < 2)
			return (false);
		if ((a == RB || a == RR || a == RRB || a == RRR) && blen < 2)
			return (false);
		if ((a == SA || a == SS) && alen < 2)
			return (false);
		if ((a == SB || a == SS) && blen < 2)
			return (false);
		return (true);
	}
	return (false);
}

void		advance_to_end(t_vstate *state, t_stacks *container)
{
	while (container->v_actions->next)
	{
		usleep(50000);
		advance_action(&container, state);
		clear_stacks(state->leftw, state->rightw);
		print_actions(state->middlew, container->v_actions);
		draw_stackw(state->leftw, *(container->a), true);
		draw_stackw(state->rightw, *(container->b), false);
		refresh();
	}
}

int			visi(t_stacks *container)
{
	t_vstate	*state;
	char		*act;

	state = initialise();
	if (!state->interactive)
		collect_actions(container);
	initial_draw(state, container);
	if (!(act = malloc(5)))
		return (1);
	animation_loop(state, container, &act);
	delwin(state->leftw);
	delwin(state->rightw);
	endwin();
	return (0);
}
