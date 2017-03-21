/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:01:43 by ggane             #+#    #+#             */
/*   Updated: 2017/03/21 09:18:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_buffer_aside(char *buffer, size_t size, int col)
{
	size_t	i;
	int		row;

	i = 0;
	row = 0;
	while (i < size)
	{
		place_cursor_at(row++, col);
		ft_putnbr(buffer[i]);
		i++;
	}
}

void	putstr_aside(char *str, int row, int col)
{
	place_cursor_at(row, col);
	ft_putstr(str);
}

void	putnbr_aside(int nb, int row, int col)
{
	place_cursor_at(row, col);
	ft_putnbr(nb);
}

void	display_name_aside(t_cycle *element, int col)
{
	int		row;

	row = 0;
	place_cursor_at(row, col);
	ft_putstr(element->name);
}

void	display_info_aside(t_dlist *args, int col)
{
	t_cycle		*element;
	int			row;

	element = args->head;
	row = 0;
	while (element)
	{
		place_cursor_at(row++, col);
		if (element->hover)
			ft_putchar('^');
		else if (element->is_select)
			ft_putchar('*');
		else
			ft_putchar('-');
		element = element->next;
	}
}
