/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_back_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:59:19 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/16 20:59:21 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap(t_stack **stack)
{
	t_stack *elem1;
	t_stack *elem2;

	if (!(*stack)->next)
		return ;
	if ((*stack)->next && (*stack)->next->next)
	{
		elem1 = (*stack)->next;
		elem2 = elem1->next;
		elem1->next = elem2->next;
		elem2->prev = elem1->prev;
		elem1->prev = elem2;
		elem2->next = elem1;
		(*stack)->next = elem2;
	}
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*master;
	t_stack *first;
	t_stack *last;

	master = (*stack);
	first = master->next;
	if (!first)
		return ;
	last = first->next;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		if (first->next == last)
			return (ft_swap(stack));
		master->next = first->next;
		first->next->prev = master;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

void	ft_reverse(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	t_stack *second_last;

	first = (*stack)->next;
	if (!first)
		return ;
	if (!(last = first->next))
		return ;
	while (last->next)
		last = last->next;
	if (last == first->next)
		return (ft_swap(stack));
	if (!(second_last = first->next))
		return ;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next = NULL;
	(*stack)->next = last;
	last->next = first;
}

void	ft_push(t_stack **sender, t_stack **receiver)
{
	t_stack *s_first;
	t_stack *r_first;

	s_first = (*sender)->next;
	r_first = (*receiver)->next;
	if (!s_first)
		return ;
	(*sender)->next = s_first->next;
	if ((*sender)->next)
		(*sender)->next->prev = (*sender);
	(*receiver)->next = s_first;
	s_first->prev = (*receiver);
	if (!r_first)
		s_first->next = NULL;
	else
	{
		r_first->prev = s_first;
		s_first->next = r_first;
	}
}
