flags = -Wall -Werror -Wextra

push_swap:
	@$(CC) $(flags) ./push_swap.c ./shared/*.c ./algorithms/*.c ./library/libft.a -I./includes -o push_swap

checker:
	gcc -g actions_backend.c actions.c alg_*.c checker.c libft.a debug.c helpers.c stack.c -o checker sanatise_input.c

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap

re: fclean push_swap checker
