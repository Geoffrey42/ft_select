/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:32:26 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 15:46:15 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_size(t_window *size)
{
	struct winsize	ws;

	ioctl(FD, TIOCGWINSZ, &ws);
	if ((size->co = (int)ws.ws_col) < 0)
		return (-1);
	if ((size->li = ws.ws_row) < 0)
		return (-1);
	return (1);
}

int		ft_set_stage(struct termios *term)
{
	char			buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	return (1);
}

t_clist	*ft_get_list(char **argv)
{
	t_clist	*ret;
	int		i;

	i = 1;
	ret = ft_clstnew(argv[i]);
	i++;
	while (argv[i] != '\0')
	{
		ft_clstaddend(&ret, ft_clstnew(argv[i]));
		i++;
	}
	ret->is_cursor = 1;
	return (ret);
}
