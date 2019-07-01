#include "push_swap.h"

int acount = 0;

t_stacks	*ft_containstacks(t_stack **a, t_stack **b)
{
	t_stacks *container;

	if (!(container = (t_stacks *)malloc(sizeof(t_stacks))))
		return NULL;
	
	container->a = a;
	container->b = b;

	return (container);
}

bool sorted(t_stack **stack, t_stack **helper)
{
	if ((*helper)->next)
		return false;
	t_stack *start = (*stack)->next;
	while (start)
	{
		if (!start->next)
			return true;
		if (start->value < start->next->value)
		{
			start = start->next;
			continue;
		}
		else
			return false;		
	}
	return true;
}


void ft_kaksort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	while (!(sorted(&a, &b)))
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






int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	*container;
	int			i;

	i = 1;

	stack_a = ft_stackinit();
	stack_b = ft_stackinit();

	if (argc > 1)
	{
		while (i < argc)
			ft_appendelem(&stack_a, atoi(argv[i++]));
	}

	container = ft_containstacks(&stack_a, &stack_b);
	
	system("clear");
	db_printstacks(&stack_a, &stack_b);
	printf("\nPress any key to start\n");
	getchar();

	ft_kaksort(&container);
	
	system("clear");
	
	db_printstacks(&stack_a, &stack_b);


	printf("Done? Maybe...  [%d] actions performed\n\n", acount);
}






 