#include <push_swap.h>

int acount = 0;
bool debug = false;




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
	int group = 1;

	
	stacklen = ft_stacklengths(stacka);
	nodes_per_group = stacklen / group_count;
	int index = 1;
	int i = nodes_per_group;
	if (stacklen % group > 0)
		group_count++;

	while (stacklen)
	{
		cursor = get_item_by_index(stacka, index);
		cursor->group = group;
		if (!nodes_per_group)
		{
			group++;
			nodes_per_group = i;
		}
		nodes_per_group--;
		index++;
		stacklen--;
	}
}

bool print_usage(char *program)
{
	ft_putstr("\n" GRN "Usage:  " RESET);
	ft_putstr(program);
	ft_putstr(" 10 9 8 7 6 5 4 3 2 1 0 -1\n\n");
	return (false);
}

void	run_algorithm(int count, t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);

	if (count == 2)
		ft_sort_two(container);
	else if (count == 3)
		ft_sort_three(container);
	else if (count < 31)
		ft_sort_below_thirty(container);
	else if (count < 101)
	{
		group_nodes(a, 5);
		ft_gabbysort(container);
		//ft_anotherway(container);
	}
	else
	{
		group_nodes(a, 13);
		ft_gabbysort(container);
	}
}

void destroy_stack(t_stack *head)
{
	if (head->next)
		destroy_stack(head->next);
	free(head);
}


int cleanup(t_stacks *container)
{
	destroy_stack(*(container->a));
	destroy_stack(*(container->b));
	free(container);
	return (0);
}

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	*container;
	int			i;

	i = 1;
	if (!(preflight(argc, argv)))
		return print_usage(argv[0]);
	stack_a = ft_stackinit();
	stack_b = ft_stackinit();
	while (i < argc)
		ft_appendelem(&stack_a, atoi(argv[i++]));
	if ((ft_hasdupe(&stack_a)))
	{
		ft_putstr(RED "Error!" RESET "  (Duplicates found)\n");
		return print_usage(argv[0]);
	}
	normalise(stack_a, argc - 1);
	container = ft_containstacks(&stack_a, &stack_b, false);
	if (ft_sorted(&stack_a, &stack_b))
		return (0);
	run_algorithm(argc - 1, &container);
	return (cleanup(container));
}