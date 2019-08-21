/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cisualiser_helpers_04.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:22:40 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:22:54 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	user_input(t_stacks *con, t_vstate *state, char **act)
{
	bool valid;

	valid = true;
	echo();
	curs_set(1);
	mvwprintw(state->middlew, 1, 4, ": ");
	wgetstr(state->middlew, *act);
	valid = is_valid_move(con, get_action(*act));
	if (valid)
	{
		append_new_action(&(con->v_actions), get_action(*act));
		advance_action(&con, state);
	}
	noecho();
	curs_set(0);
}
