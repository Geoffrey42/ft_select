/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:32:23 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 13:35:53 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		display_warning_screen(t_dlist *args)
{
	clear_window();
	place_cursor_at(args->screen_length / 2, args->screen_width / 2);
	ft_putstr("WARNING");
}
