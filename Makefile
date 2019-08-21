//FLAGS = -Wall -Werror -Wextra -g
FLAGS = -g

all: depend random push_swap checker

depend:
	@make re -C libft
	@echo "\033[4;32m== push_swap compiled ==\033[0m"

push_swap:
	$(CC) $(FLAGS) ./push_swap.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft ./helpers/*.c -o push_swap
	@echo "\033[4;32m== push_swap compiled ==\033[0m"

checker:
	$(CC) $(FLAGS) ./visualiser/*.c ./checker.c ./helpers/visual_actions.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft -lncurses -o checker
	@echo "\033[4;32m== checker compiled   ==\033[0m"

random:
	$(CC) $(FLAGS) random.c libft/libft.a -I./libft -o random
	@echo "\033[4;32m== random compiled    ==\033[0m"

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap
	@$(RM) ./random
	@$(RM) ./libft/libft.a

clean: fclean

re: fclean all