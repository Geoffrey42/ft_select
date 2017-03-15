/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_cursor_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:15:48 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 13:44:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_up(t_dlist **args)
{
	t_cycle		*cursor;

	cursor = (*args)->cursor_position;
	cursor->hover = 0;
	if (cursor->prev)
		cursor = cursor->prev;
	else
		cursor = (*args)->tail;
	cursor->hover = 1;
}

void	move_down(t_dlist **args)
{
	t_cycle		*cursor;

	cursor = (*args)->cursor_position;
	cursor->hover = 0;
	if (cursor->next)
		cursor = cursor->next;
	else
		cursor = (*args)->head;
	cursor->hover = 1;
}

/* void	position_cursor_accordingly(t_dlist **args, t_cycle *element) */
/* { */
/* } */

void	place_cursor_at(int row, int col)
{
	tputs(tgoto(tgetstr("cm", NULL), col, row), 1, outputchar);
}
