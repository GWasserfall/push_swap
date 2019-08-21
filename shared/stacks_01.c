/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:28:57 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:31:06 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		normalise(t_stack *stacka, int count)
{
	t_stack *cursor;
	t_stack *maximum;

	if (count < 1)
		return ;
	maximum = stacka->next;
	cursor = stacka->next;
	while (maximum && maximum->index > -1)
		maximum = maximum->next;
	while (cursor)
	{
		if (cursor->index < 0)
		{
			if (cursor->value > maximum->value)
				maximum = cursor;
		}
		cursor = cursor->next;
	}
	maximum->index = count;
	normalise(stacka, --count);
}

bool		ft_sorted(t_stack **stack, t_stack **helper)
{
	t_stack *start;

	start = (*stack)->next;
	if ((*helper)->next)
		return (false);
	while (start)
	{
		if (!start->next)
			return (true);
		if (start->index < start->next->index)
			start = start->next;
		else
			return (false);
	}
	return (true);
}

bool		ft_single_sorted(t_stack *head)
{
	head = head->next;
	while (head)
	{
		if (!head->next)
			break ;
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

t_stacks	*ft_containstacks(t_stack **a, t_stack **b, bool is_checker)
{
	t_stacks *container;

	if (!(container = (t_stacks *)malloc(sizeof(t_stacks))))
		return (NULL);
	container->a = a;
	container->b = b;
	container->is_checker = is_checker;
	container->visualise = false;
	container->v_actions = NULL;
	return (container);
}

t_stack		*ft_newelem(int value)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->value = value;
	stack->master = false;
	stack->index = -1;
	stack->group = -1;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}
