/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_display_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:28:29 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 20:22:19 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		display_in_underline_mode(char *name)
{
	ask_capability("us");
	ft_putendl(name);
	ask_capability("ue");
}

static void		display_in_reverse_video(char *name)
{
	ask_capability("so");
	ask_capability("mr");
	ft_putendl(name);
	ask_capability("se");
}

static void		display_underline_and_reverse_video(char *name)
{
	ask_capability("us");
	ask_capability("so");
	ask_capability("mr");
	ft_putendl(name);
	ask_capability("se");
	ask_capability("ue");
}

static void		display_with_specific_appearance(t_cycle *element)
{
	if (element->hover && !element->is_select)
		display_in_underline_mode(element->name);
	else if (element->is_select && !element->hover)
		display_in_reverse_video(element->name);
	else if (element->hover && element->is_select)
		display_underline_and_reverse_video(element->name);
	else if (!(element->hover) && !(element->is_select))
		ft_putendl(element->name);
}

void			display_columns(t_dlist **args)
{
	t_cycle	*element;

	if (!args)
		return ;
	element = (*args)->head;
	while (element)
	{
		display_with_specific_appearance(element);
		element = element->next;
	}
}
