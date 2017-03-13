/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:13:16 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 12:03:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	t_cycle		*args;

	args = stock_arguments(ac, av);
	open_ft_select_interface(args);
	erase_stocked_arguments(&args);
	return (0);
}
