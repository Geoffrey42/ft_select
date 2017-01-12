/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:15:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 15:58:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	resize(int i)
{
	char	str[2];

	(void)i;
	str[0] = -62;
	str[1] = '\0';
	ioctl(FD, TIOCSTI, str);
}

void	cont(int i)
{
	char	str[2];
	char	str2[2];

	(void)i;
	str[0] = -62;
	str[1] = '\0';
	str2[0] = 10;
	str2[1] = '\0';
	ioctl(FD, TIOCSTI, str);
	ioctl(FD, TIOCSTI, str2);
}

void	ft_signals(void)
{
	void	*res;
	void	*con;

	con = &cont;
	res = &resize;
	signal(SIGWINCH, res);
	signal(SIGCONT, con);
}
