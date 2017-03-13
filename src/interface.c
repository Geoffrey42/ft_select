/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:19:34 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 19:04:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_window(void)
{
	ask_capability("cl");
}

static void		open_full_screen_window(void)
{
	ask_capability("ti");
}

void			open_ft_select_interface(struct termios *term)
{
	get_terminal_description();
	open_full_screen_window();
	clear_window();
	turn_cursor_invisible();
	put_term_in_raw_mode(term);
}

static void		close_full_screen_window(void)
{
	ask_capability("te");
}

void			close_ft_select_interface(struct termios *term)
{
	turn_cursor_visible();
	clear_window();
	close_full_screen_window();
	put_term_in_cooked_mode(term);
}
