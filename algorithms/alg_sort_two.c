#include <push_swap.h>

void ft_sort_two(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	
	while (!(ft_sorted(&a, &b)))
        sa(container);
}