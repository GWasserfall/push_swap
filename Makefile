FLAGS = -Wall -Werror -Wextra -g

all: depend randints push_swap checker

depend:
	@make re -C libft

push_swap:
	@$(CC) -g ./push_swap.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft -o push_swap
	@echo "push_swap OK!"

checker:
	@$(CC) ./visualizer.c ./checker.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft -lncurses -o checker
	@echo "checker OK!"

randints:
	$(CC) randints.c libft/libft.a -I./libft -o random

random:
	@echo `./randints $(c)`

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap
	@$(RM) ./random
	@$(RM) ./libft/libft.a

clean: fclean

re: fclean all