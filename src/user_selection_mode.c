/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_selection_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:03:45 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 16:29:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		user_doesnt_quit_ft_select(t_dlist **args, char *keyboard)
{
	if (keyboard[0] == 27 && keyboard[1] == 0 && keyboard[2] == 0)
		return (0);	
	else if (keyboard[0] == 10)
	{
		(*args)->return_key = 1;
		return (0);	
	}
	return (1);
}

static void		check_user_input(t_dlist **args, char *keyboard)
{
	get_screen_size(args);
	read(STDIN_FILENO, keyboard, KEY_BUFF_SIZE);
	if (is_up_arrow_key(keyboard))
		move_up(args);
	else if (is_down_arrow_key(keyboard))
		move_down(args);
	else if (is_space_bar(keyboard))
		select_or_unselect_word(args);
}

void			activate_user_selection_mode(t_dlist **args)
{
	char		keyboard_buffer[KEY_BUFF_SIZE];

	while (user_doesnt_quit_ft_select(args, keyboard_buffer))
	{
		ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
		check_user_input(args, keyboard_buffer);
		display_columns(args);
	}
}
