/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_helpers_02.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:12:44 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:15:40 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			act_reverse(t_stacks **container, enum e_action action)
{
	if (action == PA)
		pb(container);
	if (action == PB)
		pa(container);
	if (action == RA)
		rra(container);
	if (action == RB)
		rrb(container);
	if (action == RR)
		rrr(container);
	if (action == SA)
		sa(container);
	if (action == SB)
		sb(container);
	if (action == SS)
		ss(container);
	if (action == RRA)
		ra(container);
	if (action == RRB)
		rb(container);
	if (action == RRR)
		rr(container);
}

void			reverse_action(t_stacks **container, t_vstate *state)
{
	t_action *position;

	position = (*container)->v_actions;
	if (!position->prev)
		return ;
	if (position)
	{
		act_reverse(container, position->action);
		(*container)->v_actions = position->prev;
	}
	wbkgd(state->middlew, COLOR_PAIR(5));
}

enum e_action	get_action(char *str)
{
	if (!(ft_strcmp(str, "sa")))
		return (SA);
	else if (!(ft_strcmp(str, "sb")))
		return (SB);
	else if (!(ft_strcmp(str, "ss")))
		return (SS);
	else if (!(ft_strcmp(str, "pa")))
		return (PA);
	else if (!(ft_strcmp(str, "pb")))
		return (PB);
	else if (!(ft_strcmp(str, "ra")))
		return (RA);
	else if (!(ft_strcmp(str, "rb")))
		return (RB);
	else if (!(ft_strcmp(str, "rr")))
		return (RR);
	else if (!(ft_strcmp(str, "rra")))
		return (RRA);
	else if (!(ft_strcmp(str, "rrb")))
		return (RRB);
	else if (!(ft_strcmp(str, "rrr")))
		return (RRR);
	return (INVALID);
}

void			collect_actions(t_stacks *container)
{
	int		ret;
	char	*line;

	line = malloc(1);
	while ((ret = get_next_line(0, &line)) > 0)
		append_new_action(&(container->v_actions), get_action(line));
	free(line);
}

void			act_forward(t_stacks **container, t_action *position)
{
	if (position->action == PA)
		pa(container);
	else if (position->action == PB)
		pb(container);
	else if (position->action == RA)
		ra(container);
	else if (position->action == RB)
		rb(container);
	else if (position->action == RR)
		rr(container);
	else if (position->action == SA)
		sa(container);
	else if (position->action == SB)
		sb(container);
	else if (position->action == SS)
		ss(container);
	else if (position->action == RRA)
		rra(container);
	else if (position->action == RRB)
		rrb(container);
	else if (position->action == RRR)
		rrr(container);
}
