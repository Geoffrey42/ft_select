/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:06:32 by ggane             #+#    #+#             */
/*   Updated: 2017/03/15 13:10:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		is_up_arrow_key(int *keyboard)
{
	if (keyboard[0] == 27 && keyboard[1] == 91 && keyboard[2] == 65)
		return (1);
	return (0);
}

int		is_down_arrow_key(int *keyboard)
{
	if (keyboard[0] == 27 && keyboard[1] == 91 && keyboard[2] == 66)
		return (1);
	return (0);
}
