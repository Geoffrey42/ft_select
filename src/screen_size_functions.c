/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:32:26 by ggane             #+#    #+#             */
/*   Updated: 2017/03/21 09:25:53 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check_window_width(t_dlist *args, char *name, int col)
{
	int	largeur;

	largeur = col + ft_strlen(name);
	if (largeur <= args->screen_width) 
		return (1);
	return (0);
}

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
		(*args)->screen_length = screen_size.ws_row;
		(*args)->screen_width = screen_size.ws_col;
		return (1);
	}
	return (0);
}

void	get_screen_size(t_dlist **args)
{
	struct	winsize		screen_size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &screen_size);
	(*args)->screen_length = screen_size.ws_row;
	(*args)->screen_width = screen_size.ws_col;
}
