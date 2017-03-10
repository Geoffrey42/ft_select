/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:45:29 by ggane             #+#    #+#             */
/*   Updated: 2017/03/10 15:56:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "highlight.h"

int		outputchar(int c)
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

void	print_list(t_list *list)
{
	t_list	*tmp;
	char	*words;

	tmp = list;
	while (tmp)
	{
		words = (char *)tmp->content;
		ft_putendl(words);
		tmp = tmp->next;
	}
}

void	ask_capability(char *str)	
{
	char	*capability;

	if (!(capability = tgetstr(str, NULL)))
		print_err_msg("tgetstr() failed");
	tputs(capability, 0, outputchar);
}

void	make_full_screen_window(void)
{
	ask_capability("ti");
}

void	exit_full_screen_window(void)
{
	ask_capability("te");
}

int		main(int ac, char **av)
{
	/* struct termios	term; */
	t_list	*words;

	if (ac != 4)
		return (1);
	words = copy_av_in_words_list(av, ac);
	get_terminal_description();
	make_full_screen_window();
	print_list(words);
	/* put_term_in_raw_mode(&term); */
	/* display_words(words); */
	sleep(10);
	exit_full_screen_window();
	/* put_term_in_cooked_mode(&term); */
	return (0);
}
