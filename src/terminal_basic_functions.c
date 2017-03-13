/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_basic_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:42:31 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 17:32:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_terminal_description(void)
{
	char	buffer[2048];
	char	*term_type;
	int		ret;

	if (!(term_type = getenv("TERM")))
		exit_with_err_msg("Specify a terminal type with `setenv TERM '.");
	ret = tgetent(buffer, term_type);
	if (!ret)
		exit_with_err_msg("Terminal entry not found.");
	else if (ret < 0)
		exit_with_err_msg("Terminfo database could not be found");
}

void	put_term_in_raw_mode(struct termios *term)
{
	if (tcgetattr(STDIN_FILENO, term) == -1)
		exit_with_err_msg("tcgetattr() failed");
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, term) == -1)
		exit_with_err_msg("tcsetattr() failed");
}

void	put_term_in_cooked_mode(struct termios *term)
{
	if (tcgetattr(STDIN_FILENO, term) == -1)
		exit_with_err_msg("tcgetattr() failed");
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, term) == -1)
		exit_with_err_msg("tcsetattr() failed");
}

void	ask_capability(char *str)
{
	char	*capability;

	if (!(capability = tgetstr(str, NULL)))
		exit_with_err_msg("tgetstr() failed");
	tputs(capability, 0, outputchar);
}
