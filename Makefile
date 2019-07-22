push_swap:
	gcc -g actions_backend.c actions.c alg_*.c debug.c libft.a helpers.c push_swap.c stack.c -o push_swap

checker:
	gcc -g actions_backend.c actions.c alg_*.c checker.c libft.a debug.c helpers.c stack.c -o checker sanatise_input.c

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap

re: fclean push_swap checker
