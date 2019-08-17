#include <push_swap.h>
#include <ncurses.h>

void p_action(WINDOW *win, enum e_action action, int row)
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
	else if (action == INVALID)
		mvwprintw(win, row, 5, " INVLD ");
	else if (action == START)
		mvwprintw(win, row, 5, " START ");
}

void print_actions_down(WINDOW *win, t_action *action, int pos)
{
	while (action && pos < (LINES - 3))
	{
		p_action(win, action->action, pos++);
		action = action->next;
	}
}

void print_actions_up(WINDOW *win, t_action *action, int pos)
{
	while (action && pos > 2)
	{
		p_action(win, action->action, pos--);
		action = action->prev;
	}
}
