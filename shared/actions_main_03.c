
#include <push_swap.h>

void ra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);

	if (!is_checker)
		ft_putstr("ra\n");
}

void rb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&b);

	if (!is_checker)
		ft_putstr("rb\n");
}

void rr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);
	ft_rotate(&b);
	
	if (!is_checker)
		ft_putstr("rr\n");
}