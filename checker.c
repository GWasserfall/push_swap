#include "push_swap.h"
int acount;
bool debug = false;

bool	ft_act(t_stacks **container, char *str)
{
		if (!(ft_strcmp(str, "sa")))
			sa(container);
		else if (!(ft_strcmp(str, "sb")))
			sb(container);
		else if (!(ft_strcmp(str, "ss")))
			ss(container);
		else if (!(ft_strcmp(str, "pa")))
			pa(container);
		else if (!(ft_strcmp(str, "pb")))
			pb(container);
		else if (!(ft_strcmp(str, "ra")))
			ra(container);
		else if (!(ft_strcmp(str, "rb")))
			rb(container);
		else if (!(ft_strcmp(str, "rr")))
			rr(container);
		else if (!(ft_strcmp(str, "rra")))
			rra(container);
		else if (!(ft_strcmp(str, "rrb")))
			rrb(container);
		else if (!(ft_strcmp(str, "rrr")))
			rrr(container);
		else
			return (false);
		return (true);
}

void	ft_runactions(t_stacks **container)
{
	char *line;
	int ret;

	line = ft_strnew(0);
	while ((ret = get_next_line(0, &line)) >= 0)
	{
		if (!(ft_act(container, line)))
		{
			printf("Incorrect input :(\n");
			return ;
		}
	}
}

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	*container;
	int			i;

	if (!(input_sane(argc, argv)))
		return (1);
	i = 1;
	stack_a = ft_stackinit();
	stack_b = ft_stackinit();

	if (argc > 1)
	{
		while (i < argc)
			ft_appendelem(&stack_a, atoi(argv[i++]));
	}

	container = ft_containstacks(&stack_a, &stack_b, true);

	// whiel((ret = get_net_line()))
	ft_runactions(&container);

	if (ft_sorted(&stack_a, &stack_b))
		printf("OK\n");
	else
	{
		//debug = true;
		printf("KO\n");
		//db_delayprint("DEBUG", &container);
	}

	return (0);
}

