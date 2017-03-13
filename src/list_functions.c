/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:14:12 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 13:49:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist		*stock_arguments(int ac, char **av)
{
	t_dlist	*args;
	int		i;

	i = 0;
	if (ac == 1)
		exit(1);
	args = create_dlist();
	while (i < ac - 1)
	{
		append_list(&args, create_new_element(av[i], i));
		i++;
	}
	return (args);
}

t_dlist		*create_dlist(void)
{
	t_dlist	*new;

	if (!(new = (t_dlist *)malloc(sizeof(*new))))
		return (NULL);
	new->lenght = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_cycle		*create_new_element(char *arg, int nb)
{
	t_cycle		*new;

	if (!(new = (t_cycle *)malloc(sizeof(*new))))
		return (NULL);
	new->name = ft_strdup(arg);
	new->line = -1;
	new->hover = -1;
	new->selected = -1;
	new->node_number = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		append_list(t_dlist **args, t_cycle *new)
{
	if ((*args)->tail)
	{
		(*args)->tail->next = new;
		new->prev = (*args)->tail;
		(*args)->tail = new;
	}
	else
	{
		(*args)->head = new;
		(*args)->tail = new;
	}
	(*args)->lenght++;
}

static void	display_info(t_cycle *element)
{
	ft_putendl("----------");
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

void		print_list(t_dlist *args)
{
	t_cycle	*browse;

	browse = args->head;
	ft_putstr("list lenght : ");
	ft_putnbrdl(args->lenght);
	while (browse)
	{
		display_info(browse);
		browse = browse->next;
	}
}

void		erase_stocked_arguments(t_dlist **args)
{
}
