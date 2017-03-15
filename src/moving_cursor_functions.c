/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_cursor_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:15:48 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 16:28:22 by ggane            ###   ########.fr       */
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
	(*args)->cursor_position = cursor;
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
	(*args)->cursor_position = cursor;
}

void	select_or_unselect_word(t_dlist **args)
{
	t_cycle		*cursor;

	cursor = (*args)->cursor_position;
	if (cursor->is_select)
		cursor->is_select = 0;
	else
		cursor->is_select = 1;
}

void	place_cursor_at(int row, int col)
{
	tputs(tgoto(tgetstr("cm", NULL), col, row), 1, outputchar);
}
