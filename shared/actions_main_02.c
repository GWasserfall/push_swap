#include <push_swap.h>

void sa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);

	if (!is_checker)
		ft_putstr("sa\n");
}

void sb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;

	a = *(*stacks)->a;
	b = *(*stacks)->b;
	ft_swap(&b);

	if (!is_checker)
		ft_putstr("sb\n");
}

void ss(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);
	ft_swap(&b);

	if (!is_checker)
		ft_putstr("ss\n");
}