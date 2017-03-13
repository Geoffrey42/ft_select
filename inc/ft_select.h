/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:41:21 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 16:16:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# ifdef __linux__
# include <termcap.h>
# endif

# ifdef __APPLE__
# include <term.h>
# endif

# include <sys/ioctl.h>
# include "libft.h"

typedef struct		s_dlist
{
	int				lenght;
	struct s_cycle	*head;
	struct s_cycle	*tail;
}					t_dlist;

typedef struct		s_cycle
{
	char			*name;
	int				line;
	int				hover;
	int				selected;
	int				node_number;
	struct s_cycle	*prev;
	struct s_cycle	*next;
}					t_cycle;

void				open_ft_select_interface(t_dlist *args);

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

#endif
