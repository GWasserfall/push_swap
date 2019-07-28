#include "libft.h"
#include <push_swap.h>

void    print_checker_usage()
{
    ft_putstr("ERROR!\nUsage: ");
    ft_putstr(" ./checker 3 2 1\n");
    ft_putstr("\nInput actions into stdin followed by [enter] to finish hit ctrl + D\n");
}

bool    more_than_one_arg(int argc, char **argv)
{
    if (argc < 3)
        return (false);
    return (true);
}

bool    all_args_digits(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				continue;
			if (!(ft_isdigit(argv[i][j])))
				return (false);
			j++;
		}
        i++;
    }
    return (true);
}

bool input_sane(int argc, char **argv)
{
	if (more_than_one_arg(argc, argv))
		if (all_args_digits(argc, argv))
			return (true);
	print_checker_usage();
    return (false);
}