#include <ncurses.h>
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
	{
		mvwprintw(win, row, i, " ");
		i++;
	}
	wattroff(win, COLOR_PAIR(3));
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, row, i + 1, "[%.2d]", current->index);
}


void	draw_stackw(WINDOW *window, t_stack *stack, int dir)
{
	int row;
	int col;

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

enum e_action get_action(char *str)
{
	if (!(ft_strcmp(str, "sa")))
		return (SA);
	else if (!(ft_strcmp(str, "sb")))
		return (SB);
	else if (!(ft_strcmp(str, "ss")))
		return (SS);
	else if (!(ft_strcmp(str, "pa")))
		return (PA);
	else if (!(ft_strcmp(str, "pb")))
		return (PB);
	else if (!(ft_strcmp(str, "ra")))
		return (RA);
	else if (!(ft_strcmp(str, "rb")))
		return (RB);
	else if (!(ft_strcmp(str, "rr")))
		return (RR);
	else if (!(ft_strcmp(str, "rra")))
		return (RRA);
	else if (!(ft_strcmp(str, "rrb")))
		return (RRB);
	else if (!(ft_strcmp(str, "rrr")))
		return (RRR);
	return (INVALID);
}

void collect_actions(t_stacks *container)
{
	int ret;
	char *line;
	line = malloc(1);
	while ((ret = get_next_line(0, &line)) > 0)
		append_new_action(&(container->v_actions), get_action(line));
	free(line);
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



void advance_action(t_stacks **container)
{
	t_action *position;
	position = (*container)->v_actions->next;

	if (position)
	{
		act_forward(container, position);
		(*container)->v_actions = position;
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
	int up;
	int down;
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

int visi(t_stacks *container)
{
	FILE	*f = fopen("/dev/tty", "r+");
	SCREEN	*screen = newterm(NULL, f, f);
	WINDOW	*rightw;
	WINDOW	*leftw;
	WINDOW	*middlew;

	int		interactive;

	set_term(screen);
	curs_set(0);
	start_color();
	

	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);

	interactive = 0;
	if (!isatty(0))
	{	
		collect_actions(container);
	}
	else
	{
		// Interactive Mode
		interactive = 1;
	}

	int sizel = (COLS / 2 - 10) / 2;
	int sizer = COLS - sizel;

	noecho();

    mvprintw(0, sizel, "STACK A");
    mvprintw(0, sizer, "STACK B");
	refresh();


	leftw = newwin(HEIGHT(LINES), LMID(COLS), 1, 0);
	box(leftw, 0, 0);

	rightw = newwin(HEIGHT(LINES), (COLS / 2 - 8), 1, RMID(COLS));
	box(rightw, 0, 0);

	middlew = newwin(HEIGHT(LINES), 16, 1, COLS / 2 - 8);

	int input;
	keypad(stdscr, TRUE);
	print_actions(middlew, container->v_actions);
	draw_stackw(leftw, *(container->a), TRUE);
	draw_stackw(rightw, *(container->b), FALSE);	
	

	while (1)
	{
		char *act;
		input = wgetch(stdscr);
		if (input == KEY_LEFT)
			reverse_action(&container);
		else if (input == KEY_RIGHT)
			advance_action(&container);
		else if (input == 'q')
			break;
		else if (input == 'a')
		{
			getstr(act);
			append_new_action(&(container->v_actions), get_action(act));

		}


		clear_stacks(leftw, rightw);
		print_actions(middlew, container->v_actions);
		draw_stackw(leftw, *(container->a), TRUE);
		draw_stackw(rightw, *(container->b), FALSE);
		
	}
    delwin(leftw);
	delwin(rightw);
    endwin();
    return 0;

}