/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:32:26 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 20:48:18 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		user_resizes_his_screen(t_dlist **args)
{
	struct	winsize		screen_size;
	int					length;
	int					width;	

	length = (*args)->screen_length;
	width = (*args)->screen_width;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &screen_size);
	if (length != screen_size.ws_row && width != screen_size.ws_col)
	{
		(*args)->screen_length = window_size.ws_row;
		(*args)->screen_width = window_size.ws_col;
		return (1);
	}
	return (0);
}

void	get_screen_size(t_dlist **args)
{
	struct	winsize		screen_size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &screen_size);
	(*args)->screen_length = window_size.ws_row;
	(*args)->screen_width = window_size.ws_col;
}
