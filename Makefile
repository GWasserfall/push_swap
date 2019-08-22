FLAGS = -Wall -Werror -Wextra

all: random push_swap checker

push_swap:
	$(CC) $(FLAGS) ./push_swap.c ./shared/*.c ./algorithms/*.c ./includes/libft.a -I./includes  ./helpers/*.c -o push_swap
	@echo "\033[4;32m== push_swap compiled ==\033[0m"

checker:
	$(CC) $(FLAGS) ./visualiser/*.c ./checker.c ./shared/*.c ./includes/libft.a -I./includes  -lncurses -o checker
	@echo "\033[4;32m== checker compiled   ==\033[0m"

random:
	$(CC) $(FLAGS) random.c ./includes/libft.a -I./includes -o random
	@echo "\033[4;32m== random compiled    ==\033[0m"

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap
	@$(RM) ./random
	@$(RM) ./libft/libft.a

clean: fclean

re: fclean all