/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:35:59 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/17 00:36:03 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	print_usage(char *program)
{
	ft_putstr("\n" GRN "Usage:  " RESET);
	ft_putstr(program);
	ft_putstr(" 10 9 8 7 6 5 4 3 2 1 0 -1\n\n");
	return (false);
}

void	run_algorithm(int count, t_stacks **container)
{
	t_stack *a;
	t_moves *moves;

	a = (*(*container)->a);
	if (count == 2)
		ft_sort_two(container);
	else if (count == 3)
		ft_sort_three(container);
	else if (count < 6)
		ft_sort_five(container);
	else
	{
		moves = (t_moves *)malloc(sizeof(t_moves));
		gsort(container, &moves, stack_is_long(a));
		free(moves);
	}
}

int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	*container;
	int			i;

	i = 1;
	if (!(preflight(argc, argv)))
		return (print_usage(argv[0]));
	stack_a = ft_stackinit();
	stack_b = ft_stackinit();
	while (i < argc)
		ft_appendelem(&stack_a, atoi(argv[i++]));
	if ((ft_hasdupe(&stack_a)))
	{
		ft_putstr(RED "Error!" RESET "  (Duplicates found)\n");
		return (print_usage(argv[0]));
	}
	normalise(stack_a, argc - 1);
	container = ft_containstacks(&stack_a, &stack_b, false);
	if (!ft_sorted(&stack_a, &stack_b))
		run_algorithm(argc - 1, &container);
	return (cleanup(container));
}
