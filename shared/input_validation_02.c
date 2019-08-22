/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:33:12 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:40:23 by gwasserf         ###   ########.fr       */
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

void	print_digit_error(char c)
{
	ft_putstr(RED "Error" RESET " : (Non-digit ");
	ft_putstr("found in arguments [");
	ft_putchar(c);
	ft_putstr("])\n");
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
			if (argv[i][0] == '-' && argv[i][1] == 'v')
				break ;
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!(ft_isdigit(argv[i][j])))
			{
				print_digit_error(argv[i][j]);
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
	if (argc == 2)
	{
		if (!argv[1][0])
			return (false);
	}
	return (true);
}

int		duplicate_error(void)
{
	ft_putstr(RED "Error : " RESET);
	ft_putstr("(Duplicates found)\n");
	return (1);
}
