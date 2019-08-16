/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:35:44 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/17 00:35:47 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void destroy_stack(t_stack *head)
{
	if (head->next)
		destroy_stack(head->next);
	free(head);
}

int cleanup(t_stacks *container)
{
	destroy_stack(*(container->a));
	destroy_stack(*(container->b));
	free(container);
	return (0);
}
