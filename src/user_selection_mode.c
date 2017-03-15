/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_selection_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:03:45 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 10:08:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	user_doesnt_quit_ft_select(t_dlist **args, char *keyboard)
{
	read(STDIN_FILENO, keyboard, KEY_BUFF_SIZE);
	if (keyboard[0] == 27 && keyboard[1] == 0 && keyboard[2] == 0)
		return (0);	
	if (keyboard[0] == 10 && keyboard[1] == 0 && keyboard[2] == 0)
	{
		(*args)->return_key = 1;
		return (0);	
	}
	return (1);
}

void	activate_user_selection_mode(t_dlist **args)
{
	char	keyboard_buffer[KEY_BUFF_SIZE];

	while (user_doesnt_quit_ft_select(args, keyboard_buffer))
	{
		ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
		check_user_input(args, keyboard_buffer);
		display_columns(args);
	}
}
