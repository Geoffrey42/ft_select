/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:46:50 by ggane             #+#    #+#             */
/*   Updated: 2017/03/09 16:03:01 by ggane            ###   ########.fr       */
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

void	check_capability(char *str)
{
	char	*capability;

	if (!(capability = tgetstr(str, NULL)))
		print_err_msg("tgetstr() failed");
	tputs(capability, 0, ft_putchar);
}

void	put_term_in_raw_mode(struct termios *term)
{
	if (tcgetattr(STDIN_FILENO, term) == -1)
		print_err_msg("tcgetattr() failed");
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, term) == -1)
		print_err_msg("tcsetattr() failed");
}

void	put_term_in_cooked_mode(struct termios *term)
{
	if (tcgetattr(STDIN_FILENO, term) == -1)
		print_err_msg("tcgetattr() failed");
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, term) == -1)
		print_err_msg("tcsetattr() failed");
}

void	display_keys(void)
{
	char	buffer[3];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 7)
	{
		bzero(buffer, 3);
		read(STDIN_FILENO, buffer, 3);
		if (buffer[0] == 27 && buffer[1] == 91)
		{
			if (buffer[2] == 65)
				printf("up arrow key entered\n");
			if (buffer[2] == 67)
				printf("right arrow key entered\n");
			if (buffer[2] == 66)
				printf("down arrow key entered\n");
			if (buffer[2] == 68)
				printf("left arrow key entered\n");
		}
		else if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0) /* echap */
		{
			printf("echap key entered\n");
			break ;
		}
		while (j < 3)
		{
			printf("buffer[%d] : (%d)\n", j, buffer[j]);
			j++;
		}
		j = 0;
		i++;
	}
}

int		main(void)
{
	struct termios	term;

	find_terminal_description();
	put_term_in_raw_mode(&term);
	display_keys();
	put_term_in_cooked_mode(&term);
	return (0);
}
