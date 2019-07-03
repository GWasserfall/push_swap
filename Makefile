all:
	gcc -g actions_backend.c actions.c alg_*.c debug.c libft/libft.a helpers.c push_swap.c stack.c -o push_swap

checker:
	gcc -g actions_backend.c actions.c alg_*.c checker.c libft/libft.a debug.c helpers.c stack.c -o checker