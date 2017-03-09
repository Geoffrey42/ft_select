/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 07:55:02 by ggane             #+#    #+#             */
/*   Updated: 2017/03/09 09:10:38 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

void	print_err_msg(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	find_terminal_description(void)
{
	char	buffer[2048];
	char	*term_type;
	int		ret;

	if (!(term_type = getenv("TERM")))
		print_err_msg("Specify a terminal type with `setenv TERM '.");
	ret = tgetent(buffer, term_type);
	if (!ret)
		print_err_msg("Terminal entry not found.");
	else if (ret < 0)
		print_err_msg("Terminfo database could not be found");
	printf("terminal description is found\n");
}

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
	/* find_terminal_description(); */
	display_window_size();
	return (0);
}
