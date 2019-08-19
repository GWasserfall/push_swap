/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:18:27 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/16 20:18:29 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][++j])
		{
			if (argv[i][0] == '-' && !(ft_isdigit(argv[i][1])))
				continue;
			if (!(ft_isdigit(argv[i][j])))
			{
				ft_putstr(RED "Error :" RESET "  (Non-digit ");
				ft_putstr("found in arguments [");
				ft_putchar(argv[i][j - 1]);
				ft_putstr("])\n");
				return (false);
			}
		}
	}
	return (true);
}

bool	single_arg_is_valid(int argc, char **argv)
{
	if (!(args_are_digits(argc, argv)))
	{
		ft_putstr("\nInfo: push_swap does not support a single argument that");
		ft_putstr("is not a digit.");
		ft_putstr(" If you are using zsh please expand args using ${=ARG}\n");
	}
	return (true);
}

bool	more_than_one_arg(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("Error : ");
		ft_putstr(argv[0]);
		ft_putstr(" requires atleast one argument\n");
		return (false);
	}
	return (true);
}

bool	valid_flags(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		if (argv[i][0] == '-' && ft_strlen((const char *)argv[i]) > 1)
		{
			ft_putstr("Error: Invalid option : [");
			ft_putchar(argv[i][1]);
			ft_putstr("]\n");
			return (false);
		}
		if (argv[i][0] == '-' && ft_strlen((const char *)argv[i]) == 1)
		{
			ft_putstr("Error: Invalid option : [-]\n");
			return (false);
		}
		
		i++;
	}
	return (true);
}

bool	checker_preflight(int argc, char **argv)
{
	if (!(more_than_one_arg(argc, argv)))
		return (false);
	if (argc == 2 && !single_arg_is_valid(argc, argv))
		return (false);
	if (!(args_are_digits(argc, argv)))
		return (false);
	if (!(args_fit_int(argc, argv)))
		return (false);
	if (!(valid_flags(argc, argv)))
		return (false);
	return (true);
}

bool	pushswap_preflight(int argc, char **argv)
{
	if (!(more_than_one_arg(argc, argv)))
		return (false);
	if (argc == 2 && !single_arg_is_valid(argc, argv))
		return (false);
	if (!(args_are_digits(argc, argv)))
		return (false);
	if (!(args_fit_int(argc, argv)))
		return (false);
	if (!(valid_flags(argc, argv)))
		return (false);
	return (true);
}