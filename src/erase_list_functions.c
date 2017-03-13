/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:40:20 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 18:57:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		delete_cycle_list(t_dlist **args)
{
	t_cycle	*browse;
	t_cycle	*tmp;
	char	*name_to_delete;

	browse = (*args)->head;
	while (browse)
	{
		tmp = browse;
		name_to_delete = tmp->name;
		ft_strdel(&name_to_delete);
		ft_memdel((void **)&tmp);
		browse = browse->next;
	}
}

static void		delete_dlist(t_dlist **args)
{
	ft_memdel((void **)args);
}

void			erase_stocked_arguments(t_dlist **args)
{
	delete_cycle_list(args);
	delete_dlist(args);
}
