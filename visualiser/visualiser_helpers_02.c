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


void reverse_action(t_stacks **container)
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
}