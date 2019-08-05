#include <push_swap.h>

void pa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&b, &a);

	if (!is_checker)
		ft_putstr("pa\n");
}

void pb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&a, &b);

	if (!is_checker)
		ft_putstr("pb\n");
}