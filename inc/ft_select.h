/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:41:21 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 20:53:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# ifdef __linux__
#  include <termcap.h>
# endif

# ifdef __APPLE__
#  include <term.h>
# endif

# include <termios.h>
# include <sys/ioctl.h>
# include "libft.h"
# define KEY_BUFF_SIZE 3

typedef struct		s_dlist
{
	int				list_length;
	int				screen_length;
	int				screen_width;
	int				return_key;
	struct s_cycle	*head;
	struct s_cycle	*tail;
}					t_dlist;

typedef struct		s_cycle
{
	char			*name;
	int				line;
	int				hover;
	int				is_select;
	int				node_number;
	struct s_cycle	*prev;
	struct s_cycle	*next;
}					t_cycle;

/*
** screen_size_functions.c
*/

int					user_resizes_his_screen(t_dlist **args);
void				get_screen_size(t_dlist **args);

/*
** user_selection_mode.c
*/

void				activate_user_selection_mode(t_dlist **args);

/*
** user_display_functions.c
*/

void				display_columns(t_dlist **args);

/*
** cursor.c
*/

void				turn_cursor_invisible(void);
void				turn_cursor_visible(void);
void				place_cursor_on_first(t_dlist **args);

/*
** print_list_functions.c
*/

void				print_dlist(t_dlist *args);
void				display_user_selection(t_dlist *args);

/*
** create_list_functions.c
*/

t_dlist				*stock_arguments(int ac, char **av);

/*
** erase_list_functions.c
*/

void				erase_stocked_arguments(t_dlist **args);

/*
** generic_display_functions.c
*/

int					outputchar(int c);
void				exit_with_err_msg(char *err_msg);

/*
** terminal_basic_functions.c
*/

void				get_terminal_description(void);
void				put_term_in_raw_mode(struct termios *term);
void				put_term_in_cooked_mode(struct termios *term);
void				ask_capability(char *str);

/*
** interface.c
*/

void				clear_window(void);
void				open_ft_select_interface(struct termios *term);
void				close_ft_select_interface(struct termios *term);

#endif
