#include <ncurses.h>
#include <time.h>
#include <push_swap.h>

#define LMID(x) (x / 2 - 8)
#define RMID(x) (x / 2 + 8)
#define HEIGHT(x) (x -2 )

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
	mvwprintw(win, row, i + 1, "[%.2d]", current->index);
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

void	act_forward(t_stacks **container, t_action *position)
{
	if (position->action == PA)
		pa(container);
	else if (position->action == PB)
		pb(container);
	else if (position->action == RA)
		ra(container);
	else if (position->action == RB)
		rb(container);
	else if (position->action == RR)
		rr(container);
	else if (position->action == SA)
		sa(container);
	else if (position->action == SB)
		sb(container);
	else if (position->action == SS)
		ss(container);
	else if (position->action == RRA)
		rra(container);
	else if (position->action == RRB)
		rrb(container);
	else if (position->action == RRR)
		rrr(container);
}

void advance_action(t_stacks **container, t_vstate *state)
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

int count_actions(t_action *current)
{
	int i;

	i = 0;
	while (current->prev)
	{
		i++;
		current = current->prev;
	}
	return i;
}

void print_actions(WINDOW *win, t_action *position)
{
	int middle;
	int moves;

	middle = LINES / 2;
	werase(win);
	print_actions_down(win, position->next, middle + 1);;
	wattron(win, COLOR_PAIR(4));
	p_action(win, position->action, middle);
	wattroff(win, COLOR_PAIR(4));
	print_actions_up(win, position->prev, middle - 1);
	moves = count_actions(position);
	mvwprintw(win, 0, 8 - ft_intlen(moves) / 2, "%d", moves);
	wrefresh(win);
}


void clear_stacks(WINDOW *left, WINDOW *right)
{
	werase(left);
	werase(right);
	box(left, 0, 0);
	box(right, 0, 0);
}

void	init_colors()
{
	start_color();
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

t_vstate *initialise()
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

void	initial_draw(t_vstate *state, t_stacks *container)
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

bool is_valid_move(t_stacks *con, enum e_action a)
{
	int alen;
	int blen;

	alen = stack_is_long(*(con->a));
	blen = stack_is_long(*(con->b));
	if (a != INVALID)
	{
		if (a == PA && blen == 0)
			return false;
		if (a == PB && alen == 0)
			return false;
		if ((a == RA || a == RR || a == RRA || a == RRR) && alen < 2)
			return false;
		if ((a == RB || a == RR || a == RRB || a == RRR) && blen < 2)
			return false;
		if ((a == SA || a == SS) && alen < 2)
			return false;
		if ((a == SB || a == SS) && blen < 2)
			return false;
		return true;
	}
	return false;
}


void user_input(t_stacks *con, t_vstate *state, char **act)
{
	bool valid;

	valid = true;
	echo();
	curs_set(1);
	mvwprintw(state->middlew, 1, 4, ": ");
	wgetstr(state->middlew, *act);
	valid = is_valid_move(con, get_action(*act));
	if (valid)
	{
		append_new_action(&(con->v_actions), get_action(*act));
		advance_action(&con, state);
	}
	noecho();
	curs_set(0);
}

void	advance_to_end(t_vstate *state, t_stacks *container)
{
	while (container->v_actions->next)
	{
		usleep(50000);
		advance_action(&container, state);
		clear_stacks(state->leftw, state->rightw);
		print_actions(state->middlew, container->v_actions);
		draw_stackw(state->leftw, *(container->a), TRUE);
		draw_stackw(state->rightw, *(container->b), FALSE);
		refresh();
	}
}

void animation_loop(t_vstate *state, t_stacks *container, char **act)
{
	while (1)
	{
		state->input = wgetch(stdscr);
		if (state->input == KEY_LEFT)
			reverse_action(&container, state);
		else if (state->input == KEY_RIGHT)
			advance_action(&container, state);
		else if (state->input == 'q')
			break;
		else if (state->input == 10)
			advance_to_end(state, container);
		else if (state->input == 'a' && state->interactive)
			user_input(container, state, act);
		clear_stacks(state->leftw, state->rightw);
		print_actions(state->middlew, container->v_actions);
		draw_stackw(state->leftw, *(container->a), TRUE);
		draw_stackw(state->rightw, *(container->b), FALSE);
		refresh();
	}
}

int visi(t_stacks *container)
{
	t_vstate *state;
	char *act;

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
    return 0;
}