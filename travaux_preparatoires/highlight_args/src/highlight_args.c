/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:45:29 by ggane             #+#    #+#             */
/*   Updated: 2017/03/13 20:22:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "highlight.h"

int	outputchar(int c)
{
	return (write(1, &c, 1));
}

void	print_err_msg(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	get_terminal_description(void)
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

t_list	*copy_av_in_words_list(char **av, int ac)
{
	t_list	*words;

	words = NULL;
	while (ac > 0)
		ft_lstadd(&words, ft_lstnew(av[ac--], sizeof(char *)));
	return (words);
}

void	ask_capability(char *str)	
{
	char	*capability;

	if (!(capability = tgetstr(str, NULL)))
		print_err_msg("tgetstr() failed");
	tputs(capability, 0, outputchar);
}

void	print_list(t_list *list)
{
	t_list	*tmp;
	char	*words;
	int	abs;
	int	ord;

	tmp = list;
	ask_capability("so");
	ask_capability("mr");
	abs = 20;
	ord = 0;
	while (tmp)
	{
		tputs(tgoto(tgetstr("cm", NULL), abs, ord++), 1, outputchar);
		words = (char *)tmp->content;
		ft_putendl(words);
		tmp = tmp->next;
	}
	ask_capability("se");
	/* ft_putendl("coucou"); */
}

void	make_full_screen_window(void)
{
	ask_capability("ti");
}

void	exit_full_screen_window(void)
{
	ask_capability("te");
}

int		user_tapes_esc_key(char *buffer)
{
	read(STDIN_FILENO, buffer, 3);
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		return (1);
	return (0);
}

int		user_tapes_right_arrow_key(char *buffer)
{
	read(STDIN_FILENO, buffer, 3);
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		return (1);
	return (0);
}

void	highlight_next_word(t_list **words_list)
{
	t_list	*tmp;

	tmp = *words_list;
	(void)tmp;
}

void	clear_window(void)
{
	char	*capability;

	if (!(capability = tgetstr("cl", NULL)))
		print_err_msg("tgetstr() failed");
	tputs(capability, 0, outputchar);
}

void	display_words(t_list *words)
{
	t_list	*tmp_words;
	char	buffer[3];

	tmp_words = words;
	while (1)
	{
		ft_bzero(buffer, 3);
		if (user_tapes_right_arrow_key(buffer))
			highlight_next_word(&tmp_words);
		else if (user_tapes_esc_key(buffer))
		{
			clear_window();
			sleep(5);
			break ;
		}
	}
}

int		main(int ac, char **av)
{
	struct termios	term;
	t_list	*words;

	if (ac != 4)
		return (1);
	words = copy_av_in_words_list(av, ac);
	get_terminal_description();
	make_full_screen_window();
	print_list(words);
	put_term_in_raw_mode(&term);
	display_words(words);
	exit_full_screen_window();
	ft_putstr("lumiere ! ");
	put_term_in_cooked_mode(&term);
	ft_putstr("ombre ! ");
	return (0);
}
