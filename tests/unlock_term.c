#ifdef __linux__
#include <termcap.h>
#endif

#ifdef __APPLE__
#include <term.h>
#endif

#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	reset_default_term(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
	{
		printf("tcgetattr() failed\n");
		exit(EXIT_FAILURE);
	}
	(*term).c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, TCSADRAIN, term))
	{
		printf("tcsetattr() failed\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	put_my_term_in_raw(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term))
	{
		printf("tcsetattr() failed\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	get_my_term_attributes(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
	{
		printf("tcgetattr() failed\n");
		exit(EXIT_FAILURE);
	}
}

void	get_my_term_in_lib(char *term_name)
{
	char	term_buffer[2048];

	bzero(term_buffer, 2048);
	if (tgetent(NULL, term_name) == -1)
	{
		printf("tgetent() failed\n");
		exit(EXIT_FAILURE);
	}
}

char	*get_my_term_in_env(void)
{
	char	*term_name;

	if (!(term_name = getenv("TERM")))
	{
		printf("getenv() failed\n");
		exit(EXIT_FAILURE);
	}
	return (term_name);
}

void	check_keys(void)
{
	char	buffer[3];
	int	i = 10;

	while (i > 0)
	{
		read(0, buffer, 3);
		if (buffer[2] == 65)
			printf("up arrow key entered\n");
		if (buffer[2] == 67)
			printf("right arrow key entered\n");
		if (buffer[2] == 66)
			printf("down arrow key entered\n");
		if (buffer[2] == 68)
			printf("left arrow key entered\n");
		printf("buffer[2] : (%d)\n", buffer[2]);
		i--;
	}
}

int	main(int ac, char **av, char **env)
{
	struct termios	term;
	char		*term_name;

	printf("start unlock_term\n");
	term_name = get_my_term_in_env();
	get_my_term_in_lib(term_name);
	get_my_term_attributes(&term);
	put_my_term_in_raw(&term);
	check_keys();
	reset_default_term(&term);
	printf("end unlock_term\n");
	return (0);
}
