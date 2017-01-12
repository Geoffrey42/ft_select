/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:07:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 15:23:21 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int		is_esc(char *buf)
{
	return (buf[0] == 27 && buf[1] == 10);
}

int		is_cntrl_z(char *buf)
{
	return (buf[0] == 26);
}

int		is_cntrl_c(char *buf)
{
	return (buf[0] == 3);
}

int		is_alt_r(char *buf)
{
	return (buf[0] == -62);
}
