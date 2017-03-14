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

static int	is_arrow_key(int key)
{
	if (key == 65 || key == 66 || key == 67 || key == 68)
		return (1);
	return (0);
}

static int	user_inputs_special_key(char *keyboard)
{
	if (keyboard[0] == 27 && keyboard[1] == 91 && is_arrow_key(keyboard[2]))
		return (1);
	return (0);
}

static void	do_as_user_asks(t_dlist **args, char *keyboard)
{
	t_cycle		*cursor;

	ft_putendl("---");
	ft_putstr((*args)->cursor_position->name);
	ft_putendl("---");
	cursor = (*args)->cursor_position;
	if (keyboard[2] == 65 && cursor->prev)
	{
		cursor->hover = 0;
		cursor = cursor->prev;
		cursor->hover = 1;
		(*args)->cursor_position = cursor;
	}
	if (keyboard[2] == 66 && cursor->next)
	{
		cursor->hover = 0;
		cursor = cursor->next;
		cursor->hover = 1;
		(*args)->cursor_position = cursor;
	}
}

void		activate_user_selection_mode(t_dlist **args)
{
	char	keyboard_buffer[KEY_BUFF_SIZE];

	ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
	get_screen_size(args);
	place_cursor_on_first(args);
	display_columns(args);
	while (user_doesnt_quit_ft_select(keyboard_buffer))
	{
		ft_bzero(keyboard_buffer, KEY_BUFF_SIZE);
		if (user_resizes_his_screen(args))
			clear_window();
		if (user_inputs_special_key(keyboard_buffer))
		{
			ft_putendl("user inputs arrow key");
			do_as_user_asks(args, keyboard_buffer);
		}
		clear_window();
		display_columns(args);
		clear_window();
		print_dlist(*args);
	}
}
