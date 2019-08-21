/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:21:51 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:22:15 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	animation_loop(t_vstate *state, t_stacks *container, char **act)
{
	while (1)
	{
		state->input = wgetch(stdscr);
		if (state->input == KEY_LEFT)
			reverse_action(&container, state);
		else if (state->input == KEY_RIGHT)
			advance_action(&container, state);
		else if (state->input == 'q')
			break ;
		else if (state->input == 10)
			advance_to_end(state, container);
		else if (state->input == 'a' && state->interactive)
			user_input(container, state, act);
		clear_stacks(state->leftw, state->rightw);
		print_actions(state->middlew, container->v_actions);
		draw_stackw(state->leftw, *(container->a), true);
		draw_stackw(state->rightw, *(container->b), false);
		refresh();
	}
}
