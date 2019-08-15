#include <ncurses.h>
#include <push_swap.h>
#include <locale.h>


void	draw_stackw(WINDOW *window)
{
	mvwprintw(window, 1, 1, "Firsta line");
    wrefresh(window);
}

int main()
{
	int ret;
	char *line;

	FILE *f = fopen("/dev/tty", "r+");
	SCREEN *screen = newterm(NULL, f, f);
	// initscr();
	// WINDOW *left_stack;
	set_term(screen);

	int i;
	i = 5;
	if (!isatty(0))
	{	
		while ((ret = get_next_line(0, &line)) > 0)
		{	
			i++;
			if (i < LINES - 2)
				mvprintw(i, COLS / 2 - 1, "%s", line);
		}
	}

	WINDOW* my_win;
    WINDOW* right_stack;
	WINDOW* left_stack;
    
    
	
	int height = 10;
    int width = 40;
    int srtheight = 1;
    int srtwidth = 1;

	int sizel = (COLS / 2 - 10) / 2;
	int sizer = COLS - sizel;

    mvprintw(0, sizel, "STACK A"); // added for relative positioning
    mvprintw(0, sizer, "STACK B");
	refresh();  //  need to draw the root window
                //  without this, apparently the children never draw
    //my_win = newwin(height, width, 5, 5);
    //box(my_win, 0, 0);  // added for easy viewing

	left_stack = newwin(LINES - 2, (COLS / 2 - 8), 1, 0);
	box(left_stack, 0, 0);

	right_stack = newwin(LINES - 2, (COLS / 2 - 8), 1, COLS / 2 + 8);
	box(right_stack, 0, 0);


	draw_stackw(left_stack);
    //mvwprintw(left_stack, 1, 1, "First line");
    //wrefresh(left_stack);


    mvwprintw(right_stack, 1, 1, "First line");
	wrefresh(right_stack);

    getch();
    delwin(left_stack);
	delwin(right_stack);
    endwin();



    return 0;

}