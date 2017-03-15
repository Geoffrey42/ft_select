/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:41:21 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 16:26:39 by ggane            ###   ########.fr       */
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
	struct s_cycle	*cursor_position;
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
** warning_screen.c
*/

void				display_warning_screen(t_dlist *args);

/*
** moving_cursor_functions.c
*/

void				move_up(t_dlist **args);
void				move_down(t_dlist **args);
void				place_cursor_at(int row, int col);
void				select_or_unselect_word(t_dlist **args);

/*
** keyboard_keys.c
*/

int					is_up_arrow_key(char *keyboard);
int					is_down_arrow_key(char *keyboard);
int					is_left_arrow_key(char *keyboard);
int					is_right_arrow_key(char *keyboard);
int					is_space_bar(char *keyboard);

/*
** screen_size_functions.c
*/

int					check_window_width(t_dlist **args);
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

/*
** test_functions.c
*/

void				display_buffer_aside(char *buffer, size_t size, int col);
void				putstr_aside(char *str, int row, int col);
void				display_name_aside(t_cycle *element, int col);
void				display_info_aside(t_dlist *args, int col);

#endif
