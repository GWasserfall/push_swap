/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:21:09 by gwasserf          #+#    #+#             */
/*   Updated: 2019/08/21 18:21:47 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_action	*new_action(enum e_action action)
{
	t_action *new;

	if (!(new = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->action = action;
	return (new);
}

void		append_new_action(t_action **previous, enum e_action a)
{
	t_action *cursor;
	t_action *this;

	cursor = *previous;
	while (cursor->next)
		cursor = cursor->next;
	this = new_action(a);
	cursor->next = this;
	this->prev = cursor;
}

int			actions_length(t_action *start)
{
	int i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}
