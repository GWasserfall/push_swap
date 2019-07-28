#include "push_swap.h"
#include <limits.h>

int acount = 0;
bool debug = false;

void normalise(t_stack *stacka, int count)
{
	t_stack *cursor;
	t_stack *maximum;

	if (count < 1)
		return ;
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

bool	args_fit_int(int argc, char **argv)
{
	int i;
	long current;

	i = 1;
	while (i < argc)
	{
		current = ft_atol(argv[i]);
		if (current > INT_MAX)
		{
			ft_putstr(RED "Error!" RESET "  (Value over INT_MAX [");
			ft_putstr(argv[i]);
			ft_putstr("])\n");
			return (false);
		}
		else if (current < INT_MIN)
		{
			ft_putstr(RED "Error!" RESET "  (Value under INT_MIN [");
			ft_putstr(argv[i]);
			ft_putstr("])\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	args_are_digits(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				if (argv[i][j++] == '-' && argv[i][j] != '-')
					continue;
				ft_putstr(RED "Error!" RESET "  (Non-digit found in arguments [");
				ft_putchar(argv[i][j - 1]);
				ft_putstr("])\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

// TODO create 2 functions here
bool	preflight(int argc, char **argv)
{
	if (argc > 2)
	{
		if (!(args_are_digits(argc, argv)))
			return (false);
		if (!(args_fit_int(argc, argv)))
			return (false);
	}
	else
	{
		ft_putstr(RED "Error!" RESET "  (Insufficient arguments [min 2])\n");
		return (false);
	}
	return (true);
}

void	run_algorithm(int count, t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	if (count == 2)
		ft_sort_two(container);
	else if (count == 3)
		ft_sort_three(container);
	else if (count == 4)
		ft_sort_four(container);
	else if (count == 5)
		ft_sort_five(container);
	else if (count < 70)
	{
		group_nodes(a, 5);
		ft_gabbysort(container);
	}
	else
	{
		group_nodes(a, 11);
		ft_gabbysort(container);
	}
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
	run_algorithm(argc - 1, &container);
}