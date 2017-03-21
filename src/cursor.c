/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:09:31 by ggane             #+#    #+#             */
/*   Updated: 2017/03/21 10:58:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	turn_cursor_invisible(void)
{
	ask_capability("vi");
}

void	turn_cursor_visible(void)
{
	ask_capability("ve");
}

void	position_cursor(t_dlist **args, t_cycle *element, int *row, int *col)
{
	if ((int)ft_strlen(element->name) > (*args)->biggest_word_len)
		(*args)->biggest_word_len = ft_strlen(element->name);
	if (*row > (*args)->screen_length)
	{
		*row = 0;
		*col = (*args)->biggest_word_len + SPACE;
	}
	element->line = *row;
	element->col = *col;
	place_cursor_at(element->line, element->col);
	*row = *row + 1;
}
