/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:15:20 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 16:49:11 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		num_tab_needed(t_window *size, t_clist **list)
{
	int	i;

	size->listcount = ft_clistcount(list);
	i = 1;
	while (size->li < size->listcount / i)
		i++;
	return (i);
}

void	ft_fill_struct_window(t_window *size, t_clist **list)
{
	size->tab_counter = 1;
	size->arg_printed = 0;
	size->num_tab = num_tab_needed(size, list);
	size->max_len = ft_maxlen(list);
	size->items_per_tab = size->listcount / size->num_tab + 1;
}

void	ft_print_item(t_clist *item)
{
	if (item->is_cursor)
		tputs(tgetstr("us", NULL), TPUTS_END);
	if (item->is_selected)
		tputs(tgetstr("mr", NULL), TPUTS_END);
	ft_putstr_fd(item->str, FD);
	tputs(tgetstr("me", NULL), TPUTS_END);
}


void	ft_putheader(t_window *size, int tabs)
{
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 0), 1, tputs_putchar);
	ft_putstr_fd("  ____________________.____     __", FD);
	ft_putstr_fd("_____________________________", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 1), 1, tputs_putchar);
	ft_putstr_fd(" /   _____/\\_   _____/|    |    \\_  ", FD);
	ft_putstr_fd(" _____/\\_   ___ \\__    ___/", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 2), 1, tputs_putchar);
	ft_putstr_fd(" \\_____  \\  |    __)_ |    |     |    ", FD);
	ft_putstr_fd("__)_ /    \\  \\/ |    |   ", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 3), 1, tputs_putchar);
	ft_putstr_fd(" /        \\ |        \\|    |___  |    ", FD);
	ft_putstr_fd("    \\\\     \\____|    |   ", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 4), 1, tputs_putchar);
	ft_putstr_fd("/________ //________ /|_______ / /_____", FD);
	ft_putstr_fd("___/ \\_______ /|____|   \n", FD);
	tputs(tgoto(CM, POSX, POSY), TPUTS_END);
}

void	ft_print(t_window *size, t_clist **list)
{
	t_clist	*lst;
	int		tabs;

	ft_fill_struct_window(size, list);
	lst = *list;
	tabs = TABS;
	if (TABS < size->max_len && size->num_tab + 2 * size->max_len < size->co)
	{
		tabs = size->max_len + 2;
		size->tab_counter = 0;
	}
	ft_putheader(size, tabs);
	while (lst->next != NULL)
	{
		ft_print_item(lst);
		size->arg_printed++;
		if (size->arg_printed >= size->items_per_tab)
		{
			size->tab_counter++;
			size->arg_printed = 0;
		}
		tputs(tgoto(CM, POSX, POSY), TPUTS_END);
		lst = lst->next;
	}
	ft_print_item(lst);
}
