FLAGS = -Wall -Werror -Wextra

all: depend push_swap checker

depend:
	@make -C libft

push_swap:
	@$(CC) $(FLAGS)  ./push_swap.c ./shared/*.c ./algorithms/*.c ./library/libft.a -I./includes -lncurses -o push_swap
	@echo "push_swap OK!"

checker:
	@$(CC) ./visualizer.c ./checker.c ./shared/*.c ./algorithms/*.c ./library/libft.a -I./includes -lncurses -o checker
	@echo "checker OK!"

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap

clean: fclean

re: fclean push_swap checker