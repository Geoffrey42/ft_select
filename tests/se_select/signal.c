/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:15:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 12:25:27 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"






void	ft_signals()
{
	signal(SIGWINCH, resize);
	signal(SIGSEGV, segv);
	signal(SIGTSTP, tempstop);
	signal(SIGCONT, resume);
	signal(SIGSTOP, stop);
}

