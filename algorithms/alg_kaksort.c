#include <push_swap.h>

void ft_kaksort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	while (!(ft_sorted(&a, &b)))
	{
		t_stack *ca = a->next;
		t_stack *cb = b->next;
		
		if (!ca)
		{
			// assume done
			// push all of B to A
			while (b->next)
				pa(&stacks);
			return ;
		}

		if (!cb) 
		{
			pb(&stacks);
			continue;
		}
		if (ca->value > cb->value)
			pb(&stacks);
		else
		{
			pa(&stacks);
			sa(&stacks);
		}
	}
}
