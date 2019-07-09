#include "push_swap.h"

int acount = 0;
bool debug = false;

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

	// Run algo here
	//sort_three(&container);
	ft_slowsort(&container);
	//ft_kaksort(&container);

	if (debug)
	{
		system("clear");
		db_printstacks(&stack_a, &stack_b);
		printf("Done? Maybe...  [%d] actions performed\n\n", acount);
	}
}