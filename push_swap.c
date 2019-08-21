/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:35:59 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:02:29 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	if (!(pushswap_preflight(argc, argv)))
		return (1);
	stack_a = ft_stackinit();
	stack_b = ft_stackinit();
	while (i < argc)
		ft_appendelem(&stack_a, atoi(argv[i++]));
	if ((ft_hasdupe(&stack_a)))
	{
		ft_putstr(RED "Error" RESET " :  (Duplicates found)\n");
		return (1);
	}
	normalise(stack_a, argc - 1);
	container = ft_containstacks(&stack_a, &stack_b, false);
	if (!ft_sorted(&stack_a, &stack_b))
		run_algorithm(argc - 1, &container);
	return (cleanup(container));
}
