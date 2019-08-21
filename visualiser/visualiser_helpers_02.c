#include <push_swap.h>

void act_reverse(t_stacks **container, enum e_action action)
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

void reverse_action(t_stacks **container, t_vstate *state)
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

enum e_action get_action(char *str)
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

void collect_actions(t_stacks *container)
{
	int ret;
	char *line;
	line = malloc(1);
	while ((ret = get_next_line(0, &line)) > 0)
		append_new_action(&(container->v_actions), get_action(line));
	free(line);
}