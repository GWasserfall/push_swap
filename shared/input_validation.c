#include <push_swap.h>

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
				printf("%d - %s\n", argc, argv[i]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	preflight(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!(args_are_digits(argc, argv)))
			return (false);
		if (!(args_fit_int(argc, argv)))
			return (false);
	}
	return (true);
}