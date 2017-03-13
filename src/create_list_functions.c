/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:42:55 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 18:02:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_dlist		*create_dlist(void)
{
	t_dlist	*new;

	if (!(new = (t_dlist *)malloc(sizeof(*new))))
		return (NULL);
	new->lenght = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

static t_cycle		*create_new_element(char *arg, int nb)
{
	t_cycle		*new;

	if (!(new = (t_cycle *)malloc(sizeof(*new))))
		return (NULL);
	new->name = ft_strdup(arg);
	new->line = -1;
	new->hover = 0;
	new->selected = 0;
	new->node_number = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void			append_list(t_dlist **args, t_cycle *new)
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

t_dlist				*stock_arguments(int ac, char **av)
{
	t_dlist	*args;
	int		i;

	i = 1;
	if (ac == 1)
		exit(1);
	args = create_dlist();
	while (i <= ac - 1)
	{
		append_list(&args, create_new_element(av[i], i));
		i++;
	}
	return (args);
}
