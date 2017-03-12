/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:01:41 by ggane             #+#    #+#             */
/*   Updated: 2017/03/10 15:17:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	print_err_msg(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	find_terminal_description(void)
{
	char	buffer[2048];
	char	*term_type;
	int		ret;

	if (!(term_type = getenv("TERM")))
		print_err_msg("Specify a terminal type with `setenv TERM '.");
	ret = tgetent(buffer, term_type);
	if (!ret)
		print_err_msg("Terminal entry not found.");
	else if (ret < 0)
		print_err_msg("Terminfo database could not be found");
	printf("terminal description is found\n");
}

void	ask_capability(char *str)	
{
	char	*capability;

	if (!(capability = tgetstr(str, NULL)))
		print_err_msg("tgetstr() failed");
	tputs(capability, 0, ft_putchar);
}

int		main(void)
{
	find_terminal_description();
	ask_capability("ti");
	sleep(10);
	ask_capability("te");
	return (0);
}
