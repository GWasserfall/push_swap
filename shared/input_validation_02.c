#include <push_swap.h>

bool	args_fit_int(int argc, char **argv)
{
	int		i;
	long	current;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && !(ft_isdigit(argv[i][1])))
			continue;
		current = ft_atol(argv[i]);
		if (current > INT_MAX)
		{
			ft_putstr(RED "Error" RESET " : (Value over INT_MAX [");
			ft_putstr(argv[i]);
			ft_putstr("])\n");
			return (false);
		}
		else if (current < INT_MIN)
		{
			ft_putstr(RED "Error" RESET " : (Value under INT_MIN [");
			ft_putstr(argv[i]);
			ft_putstr("])\n");
			return (false);
		}
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
		while (i < argc && argv[i][j])
		{
			if (argv[i][0] == '-' && !(ft_isdigit(argv[i++][1])))
				continue;
			if (!(ft_isdigit(argv[i][j])))
			{
				ft_putstr(RED "Error" RESET " : (Non-digit ");
				ft_putstr("found in arguments [");
				ft_putchar(argv[i][j]);
				ft_putstr("])\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	single_arg_is_valid(int argc, char **argv)
{
	if (!(args_are_digits(argc, argv)))
	{
		ft_putstr("Info: ");
		ft_putstr(argv[0]);
		ft_putstr(" does not support a single argument that");
		ft_putstr(" is not a digit.");
		ft_putstr(" If you are using zsh please expand args using ${=ARG}\n");
		return (false);
	}
	return (true);
}