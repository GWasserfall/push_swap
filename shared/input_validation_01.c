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


bool	more_than_one_arg(int argc, char **argv)
{
	if (argc == 1)
	{
		// ft_putstr("Error : ");
		// ft_putstr(argv[0]);
		// ft_putstr(" requires atleast one argument\n");
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
			if (argv[i][1] != 'v')
			{
				ft_putstr("Error: Invalid option : [");
				ft_putchar(argv[i][1]);
				ft_putstr("]\n");
				return (false);
			}
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