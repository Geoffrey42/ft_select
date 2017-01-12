/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:15:14 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 15:39:32 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_maxlen(t_clist **list)
{
	int		i;
	int		len;
	t_clist	*ls;

	len = 0;
	i = 0;
	ls = *list;
	while (ls->next != NULL)
	{
		while (ls->str[i] != '\0')
		{
			if (i > len)
				len = i;
			i++;
		}
		ls = ls->next;
		i = 0;
	}
	return (len + 1);
}

int		tputs_putchar(int c)
{
	write(2, &c, 1);
	return (1);
}

