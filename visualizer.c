#include <ncurses.h>
#include <push_swap.h>
#include <locale.h>








void print_stacks(t_stack *a, t_stack*b)
{
	int i;
	i = 2;
	int j;
	clear();
	mvprintw(1, 1, "Stack A");
	a = a->next;

	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	
	while (a)
	{	
		j = 0;
		
		attron(COLOR_PAIR(3));
		while (j < a->index)
		{
			mvprintw(i, j, " ");	
			j++;
		}
		attroff(COLOR_PAIR(3));

		i++;
		a=a->next;
	}

	if (!b->next)
	{
		refresh();
		return ;
	}
		
	b = b->next;
	i = 2;
	mvprintw(1, COLS - 10, "Stack B");
	while (b)
	{
		j = 0;
		if (b->next && b->index < b->next->index)
			attron(COLOR_PAIR(2));
		else
			attron(COLOR_PAIR(2));
		while (j < b->index)
		{
			mvprintw(i, (COLS - 1) - j, " ");
			j++;
		}
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

	initscr();
	curs_set(FALSE);
	cbreak();
	start_color();
	
	char *line;
	int ret;

	line = ft_strnew(0);
	while ((ret = get_next_line(0, &line)) > 0)
	{	
		usleep(10000);
		if (!(ft_act(&container, line)))
		{
			free(line);
		}
		refresh();
		print_stacks(a, b);
	}

	getch();
	sleep(10000);
	curs_set(TRUE);
	endwin();
	return 0;
}