
#include <push_swap.h>

void rra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);

	if (!is_checker)
		ft_putstr("rra\n");
}

void rrb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&b);
	
	if (!is_checker)
		ft_putstr("rrb\n");
}

void rrr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);
	ft_reverse(&b);

	if (!is_checker)
		ft_putstr("rrr\n");
}
