/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:41:21 by ggane             #+#    #+#             */
/*   Updated: 2017/01/09 17:11:56 by ggane            ###   ########.fr       */
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

typedef struct	s_cycle
{
	char	*name;
	int	line;
	int	hover;
	int	selected;
	int	number;
	s_cycle	*prev;
	s_cycle	*next;
}		t_cycle;

void		open_ft_select_interface(t_cycle *args);

/*
** list_functions.c
*/

t_cycle		*stock_arguments(int ac, char **av);
void		erase_stocked_arguments(t_cycle **args);

#endif
