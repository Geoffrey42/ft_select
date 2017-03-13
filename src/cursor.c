/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:09:31 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 18:11:46 by ggane            ###   ########.fr       */
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

void	place_cursor_on_first(t_dlist **args)
{
	(*args)->head->hover = 1;
}
