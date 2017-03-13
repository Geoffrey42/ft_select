/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_display_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:23:48 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 16:47:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		outputchar(int c)
{
	return (write(1, &c, 1));
}

void	print_err_msg(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}
