#include <ncurses.h>
#include <push_swap.h>
#include <locale.h>

void print_header(char *action, int moves)
{
	mvprintw(1, 1, "Stack A");
	mvprintw(1, COLS - 8, "Stack B");
	mvprintw(5, COLS / 2, "%d", moves);
	mvprintw(1, COLS / 2, action);
	
}

void print_left_row(t_stack *current, int row)
{
	int col;
	col = 0;
	if (current->next && current->index > current->next->index)
		attron(COLOR_PAIR(2));
	else
		attron(COLOR_PAIR(3));
	while (col < current->index)
	{
		mvprintw(row, col + 1, " ");
		col++;
	}
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(2));
	
	mvprintw(row, col + 1, "[%d] %d", current->index, current->value);
}

void print_left_stack(t_stack *a)
{
	int col;
	int row;
	int stacklen;
	int color_pair;

	stacklen = stack_len(a);
	row = 2;
	a = a->next;
	while (a)
	{
		print_left_row(a, row);
		row++;
		a = a->next;
	}
}

void print_right_row(t_stack *current, int row)
{
	int col;
	col = 0;
	if (current->next && current->index < current->next->index)
		attron(COLOR_PAIR(2));
	else
		attron(COLOR_PAIR(3));
	while (col < current->index)
	{
		mvprintw(row, col, " ");
		col++;
	}
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(2));
	
	mvprintw(row, col + 1, "[%d] %d", current->index, current->value);
}

void print_right_stack(t_stack *a)
{
	int col;
	int row;
	int stacklen;
	int color_pair;

	stacklen = stack_len(a);
	row = 2;
	a = a->next;
	while (a)
	{
		print_left_row(a, row);
		row++;
		a = a->next;
	}
}


void print_stacks(t_stack *a, t_stack*b, char *action, int moves)
{
	int i;
	i = 3;
	int j;

	clear();
	
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	
	print_left_stack(a);
	print_header(action, moves);

	if (!b->next)
	{
		refresh();
		return ;
	}
		
	b = b->next;
	i = 3;
	while (b)
	{
		j = 1;
		if (b->next && b->index < b->next->index)
			attron(COLOR_PAIR(2));
		else
			attron(COLOR_PAIR(2));
		while (j < b->index)
		{
			mvprintw(i, (COLS - 1) - j, " ");
			j++;
		}
		mvprintw(i, (COLS - 1) - j, "%d", b->index);
		attroff(COLOR_PAIR(2));
		i++;
		b = b->next;
	}
	refresh();
}

int visualize_stacks(t_stacks *container) 
{
	t_stacks *stacks = container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	//initscr();
	newterm(NULL, stderr, stdin);
	//cbreak();
	start_color();
	
	char *line;
	int ret;
	int count;

	count = 0;
	line = ft_strnew(0);


	while ((ret = get_next_line(0, &line)) > 0)
	{	
		usleep(10000);
		if (!(ft_act(&container, line)))
		{
		 	free(line);
		}
		print_stacks(a, b, line, count++);
		refresh();
	}
	print_stacks(a, b, line, count++);
	while (1)
	;	

	curs_set(TRUE);
	endwin();
	
	return 0;
}