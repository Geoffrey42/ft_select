/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_selection_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:03:45 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 20:57:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	user_doesnt_quit_ft_select(char *keyboard)
{
	read(STDIN_FILENO, keyboard, KEY_BUFF_SIZE);
	if (keyboard[0] == 27 && keyboard[1] == 0 && keyboard[2] == 0)
		return (0);	
	if (keyboard[0] == 10 && keyboard[1] == 0 && keyboard[2] == 0)
		return (0);	
	return (1);
}

void	activate_user_selection_mode(t_dlist **args)
{
	char	keyboard_buffer[KEY_BUFF_SIZE];

	ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
	get_screen_size(args);
	display_columns(args);
	while (user_doesnt_quit_ft_select(keyboard_buffer))
	{
		ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
		if (user_resizes_his_screen(args))
		{
			clear_window();
			display_columns(args);
		}
		if (user_inputs_special_key(keyboard_buffer))
			do_as_user_asks(args, keyboard_buffer);
	}
}
