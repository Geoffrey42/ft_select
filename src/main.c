/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:13:16 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 14:48:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	t_dlist		*args;

	args = stock_arguments(ac, av);
	print_dlist(args);
	/* open_ft_select_interface(args); */
	erase_stocked_arguments(&args);
	print_dlist(args);
	return (0);
}
