/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 16:15:43 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	display_info(t_cycle *element)
{
	ft_putstr("name : ");
	ft_putendl(element->name);
	ft_putstr("line : ");
	ft_putnbrdl(element->line);
	ft_putstr("hover : ");
	ft_putnbrdl(element->hover);
	ft_putstr("selected : ");
	ft_putnbrdl(element->selected);
	ft_putstr("node_number : ");
	ft_putnbrdl(element->node_number);
	ft_putendl("----------");
}

void		print_dlist(t_dlist *args)
{
	t_cycle	*browse;

	if (!args)
	{
		ft_putendl("list is empty");
		return ;
	}
	browse = args->head;
	ft_putstr("list lenght : ");
	ft_putnbrdl(args->lenght);
	ft_putendl("----------");
	while (browse)
	{
		display_info(browse);
		browse = browse->next;
	}
}

static void	display_formatted(t_cycle *selection)
{
	ft_putstr(selection);
	ft_putchar(' ');
}

void		display_user_selection(t_dlist *args)
{
	t_cycle	*selection;

	if (!args)
		return ;
	selection = args->head;
	while (selection)
	{
		display_formatted(selection);
		selection = selection->next;
	}
}
