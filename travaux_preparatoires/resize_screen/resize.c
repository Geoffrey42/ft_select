/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 07:55:02 by ggane             #+#    #+#             */
/*   Updated: 2017/03/09 13:40:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

void	display_window_size(void)
{
	struct winsize	window_size;
	int				hauteur;
	int				largeur;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	hauteur = window_size.ws_row;
	largeur = window_size.ws_col;
	printf("lines nb : %d\n", hauteur);
	printf("columns nb : %d\n", largeur);
	while (1)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
		if (largeur != window_size.ws_col || hauteur != window_size.ws_row)
			display_window_size();
	}
}

int		main(void)
{
	display_window_size();
	return (0);
}
