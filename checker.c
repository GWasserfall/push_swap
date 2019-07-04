#include "push_swap.h"
#include "libft/libft.h"

int acount;
bool debug = false;

void	ft_runactions(t_stacks **container)
{
	char *line;

	line = ft_strnew(0);
	while ((get_next_line(0, &line) > 0))
	{
		if (!(ft_strcmp(line, "sa")))
			sa(container);
		if (!(ft_strcmp(line, "sb")))
			sb(container);
		if (!(ft_strcmp(line, "ss")))
			ss(container);
		if (!(ft_strcmp(line, "pa")))
			pa(container);
		if (!(ft_strcmp(line, "pb")))
			pb(container);
		if (!(ft_strcmp(line, "ra")))
			ra(container);
		if (!(ft_strcmp(line, "rb")))
			rb(container);
		if (!(ft_strcmp(line, "rr")))
			rr(container);
		if (!(ft_strcmp(line, "rra")))
			rrb(container);
		if (!(ft_strcmp(line, "rrb")))
			rrb(container);
		if (!(ft_strcmp(line, "rrr")))
			rrr(container);
		//printf("Got action : %s\n", line);
	}
}

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	*container;
	int			i;

	if (argc < 2)
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

	ft_runactions(&container);

	if (ft_sorted(&stack_a, &stack_b))
		printf("OK\n");
	else
	{
		debug = true;
		printf("KO\n");
		db_delayprint("DEBUG", &container);
	}

	return (0);
}