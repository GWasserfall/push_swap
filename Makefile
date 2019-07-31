flags = -Wall -Werror -Wextra

push_swap:
	@$(CC) ./push_swap.c ./shared/*.c ./algorithms/*.c ./library/libft.a -I./includes -lncurses -o push_swap

checker:
	@$(CC) ./visualizer.c ./checker.c ./shared/*.c ./algorithms/*.c ./library/libft.a -I./includes -lncurses -o checker

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap

re: fclean push_swap checker
