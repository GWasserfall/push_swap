#include <push_swap.h>

void ft_rotate_a(t_stacks **container, t_moves **moves)
{
	if ((*moves)->a_moves > 0)
	{
		ra(container);
		(*moves)->a_moves--;
	}
	else
	{
		rra(container);
		(*moves)->a_moves++;
	}
}

void ft_dblrotate(t_stacks **container, t_moves **moves, int direction)
{
	if (direction  > 0)
	{
		rr(container);
		(*moves)->a_moves--;
		(*moves)->b_moves--;
	}
	else
	{
		rrr(container);
		(*moves)->a_moves++;
		(*moves)->b_moves++;
	}
}

void ft_rotate_b(t_stacks **container, t_moves **moves)
{
	if ((*moves)->b_moves > 0)
	{
		rb(container);
		(*moves)->b_moves--;
	}
	else
	{
		rrb(container);
		(*moves)->b_moves++;
	}
}


void ft_initial_push(t_stacks **container, int max)
{
	int count;
	t_stack *a;

	a = (*(*container)->a);
	count = 0;
	while (count < 3)
	{
		if (a->next->index > max - 3)
			ra(container);
		else
		{
			pb(container);
			count++;
		}
	}
	ft_reversesort_three(container, (*(*container)->b));
}