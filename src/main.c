/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:13:16 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 18:58:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	struct termios	terminal;
	t_dlist			*args;

	args = stock_arguments(ac, av);
	open_ft_select_interface(&terminal);
	/* activate_user_selection_mode(&args); */
	print_dlist(args);
	sleep(10);
	close_ft_select_interface(&terminal);
	/* display_user_selection(args); */
	erase_stocked_arguments(&args);
	return (0);
}
