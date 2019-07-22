#include "push_swap.h"
#include <limits.h>

int acount = 0;
bool debug = false;

void normalise(t_stack *stacka, int count)
{
	t_stack *cursor;
	t_stack *maximum;

	if (count > 0)
	{
		maximum = stacka->next;
		cursor = stacka->next;
		while (maximum && maximum->index > -1)
			maximum = maximum->next;
		while (cursor)
		{
			if (cursor->index < 0)
			{
				if (cursor->value > maximum->value)
					maximum	 = cursor;
			}
			cursor = cursor->next;
		}
		maximum->index = count;
		normalise(stacka, --count);
	}
}


t_stack *get_item_by_index(t_stack *stack, int index)
{
	t_stack *cursor;

	cursor = stack->next;
	while (cursor)
	{
		if (cursor->index == index)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

int		ft_stacklengths(t_stack *stack)
{
	t_stack *cursor;
	int i;

	i = 0;
	cursor = stack->next;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}


void	group_nodes(t_stack *stacka, int group_count)
{
	int stacklen;
	int nodes_per_group;
	t_stack *cursor;

	stacklen = ft_stacklengths(stacka);

	while (stacklen)
	{

		stacklen--;
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
		if (!(strcmp("-d", argv[i])))
		{
			debug = true;
			i++;
		}
		while (i < argc)
			ft_appendelem(&stack_a, atoi(argv[i++]));
		normalise(stack_a, argc - 1);
		group_nodes(stack_a, 5);
	}
	else
	{
		printf("error (no args)\n");
	}
	

	container = ft_containstacks(&stack_a, &stack_b, false);
	
	if ((ft_hasdupe(&stack_a)))
	{
		printf("error (duplicates)\n");
		return (1);
	}

	if (debug)
	{
		system("clear");
		db_printstacks(&stack_a, &stack_b);
		printf("\nPress any key to start\n");
		getchar();
	}

	// Run algo herep
	// sort_three(&container);
	ft_slowsort(&container);
	// ft_kaksort(&container);

	t_stack *cursor = stack_a->next;
	while (cursor)
	{
		printf("[%d] [%d] = %d\n", cursor->index, cursor->group, cursor->value);
		cursor = cursor->next;
	}

	if (debug)
	{
		system("clear");
		db_printstacks(&stack_a, &stack_b);
		printf("Done? Maybe...  [%d] actions performed\n\n", acount);
	}
}