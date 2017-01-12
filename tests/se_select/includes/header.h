/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:15:33 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 16:48:21 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define CM tgetstr("cm", NULL)
# define HEADHEIGHT 5
# define POSY size->arg_printed + HEADHEIGHT
# define TPUTS_END 1, tputs_putchar
# define TABS size->co / (size->num_tab + 2)
# define POSX (tabs * size->tab_counter)
# define FD 2

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include <term.h>
# include "libft.h"
# include "signal.h"
# include <sys/ioctl.h>

typedef struct	s_window
{
	int	li;
	int	co;
	int	num_tab;
	int	max_len;
	int	arg_printed;
	int	listcount;
	int	items_per_tab;
	int	tab_counter;
}				t_window;

typedef struct		s_clist
{
	char			*str;
	struct s_clist	*next;
	struct s_clist	*prev;
	int				is_selected;
	int				is_cursor;
}					t_clist;

int		ft_maxlen(t_clist **list);
void	ft_refresh(t_window *size, t_clist **list, struct termios *term);
void	ft_clstadd(t_clist **alst, t_clist *new);
t_clist	*ft_clstnew(char *str);
void	ft_clstaddend(t_clist **alst, t_clist *new);
int		ft_clistcount(t_clist **alst);
t_clist	*ft_move_up(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_down(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_left(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_right(t_window *size, t_clist **list, t_clist *item);
int		is_rtn(char *buf);
int		is_arrow(char *buf);
int		ft_get_size(t_window *size);
int		tputs_putchar(int c);
int		ft_set_stage(struct termios *term);
int		ft_set_tabs(t_window *size, t_clist **list);
t_clist	*ft_get_list(char **argv);
void	ft_putheader(t_window *size, int tabs);
void	ft_print(t_window *size, t_clist **list);
int		is_space(char *buf);
t_clist	*ft_select(t_window *size, t_clist **list, t_clist *item);
int		ft_list_del(t_clist **alst);
int		is_bspace(char *buf);
t_clist	*ft_del_lst_item(t_clist **list, t_clist *item);
t_clist	*ft_del_item(t_window *size, t_clist **list, t_clist *item);
t_clist	*list_end(t_clist *item);
t_clist	*list_start(t_clist *item);
t_clist	*ft_del_start_end(t_clist **old, t_clist *item);
int		num_tab_needed(t_window *size, t_clist **list);
void	ft_fill_struct_window(t_window *size, t_clist **list);
void	ft_print_item(t_clist *item);
t_clist	*what_arrow(int drctn, t_window *size, t_clist **list, t_clist *item);
int		is_esc(char *buf);
int		is_cntrl_z(char *buf);
int		is_cntrl_c(char *buf);
int		is_alt_r(char *buf);
void	ft_signals();
int		is_del(char *buf);
int		ft_wait_for_input(t_window *size, t_clist **list, struct termios *term);
int		ft_unset_stage(struct termios *term);

#endif
