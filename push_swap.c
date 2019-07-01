


/*
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
	 is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
	 is only one or no elements).

ss : sa and sb at the same time.

***pa : push a - take the first element at the top of b and put it at the top of a. Do
	 nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do
	 nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes
	 the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes
	 the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
	  becomes the first one.

rrr : rra and rrb at the same time.
*/
#include "push_swap.h"

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


void ft_sort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	

	while (!(sorted(&a, &b)))
	{
		t_stack *ca = a->next;
		t_stack *cb = b->next;
		
		db_printstacks(&a, &b);
		printf("Press Any Key to Continue\n");
	
		getchar();
		//system("clear");

		if (!cb) 
		{
			printf("Nothing on CB\n");
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

		if (!ca)
		{
			printf("sorted!");
			break ;
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
	db_printstacks(&stack_a, &stack_b);
	printf("Before sort\n");
	ft_sort(&container);
	
	printf("\nAfter sort\n");
	db_printstacks(&stack_a, &stack_b);

}






 