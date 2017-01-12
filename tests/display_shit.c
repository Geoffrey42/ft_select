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

typedef struct		s_screen
{
	int		largeur;
	int		hauteur;
}			t_screen;

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

size_t	get_my_term_in_lib(char *term_name)
{
	char	term_buffer[2048];

	bzero(term_buffer, 2048);
	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("tgetent() failed\n");
		exit(EXIT_FAILURE);
	}
	return (strlen(term_buffer));
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

void		clean_screen(size_t size)
{
	char	*buffer;
	char	*capability;

	if (!(buffer = (char *)malloc(sizeof(char) * size)))
		exit(EXIT_FAILURE);
	capability = tgetstr("cl", &buffer);
}

int		check_if_screen_size_unchanged(t_screen *screen, int *boolean)
{
	int	largeur_actuelle;
	int	hauteur_actuelle;

	largeur_actuelle = tgetnum("co");
	hauteur_actuelle = tgetnum("li");
	if (*boolean == 0)
	{
		printf("largeur a compare : %d\n", largeur_actuelle);
		printf("hauteur a compare : %d\n", hauteur_actuelle);
		*boolean = 1;
	}
	if (largeur_actuelle != screen->largeur)
		return (0);
	if (hauteur_actuelle != screen->hauteur)
		return (0);
	return (1);
}

void		print_shit_accordingly_to_screen(t_screen *screen)
{
	int	lignes;
	int	colonnes;
	int	i;

	lignes = 0;
	colonnes = 0;
	i = 1;
	while (lignes != screen->hauteur)
	{
		while (colonnes != screen->largeur)
		{
			//printf("%d", i);
			printf("-");
			colonnes++;
			//if (colonnes != screen->largeur)
			//	printf(" ");
		}
		colonnes = 0;
		printf("\n");
		lignes++;
		i++;
		if (i == 10)
			i = 1;
	}
}

t_screen	*get_screen_size(void)
{
	t_screen	*screen;

	if (!(screen = (t_screen *)malloc(sizeof(t_screen))))
			return (NULL);
	screen->largeur = tgetnum("co");
	screen->hauteur = tgetnum("li");
	printf("largeur : (%d)\n", screen->largeur);
	printf("hauteur : (%d)\n", screen->hauteur);
	return (screen);
}

void	display_shit(size_t size)
{
	t_screen	*screen;
	//int		stop;
	int		boolean;

	screen = get_screen_size();
	//stop = 5;
	boolean = 0;
	while (1)
	{
	//	print_shit_accordingly_to_screen(screen);
		if (!check_if_screen_size_unchanged(screen, &boolean))
		{
			printf("taille de l'ecran a change\n");
			clean_screen(size);
			free(screen);
			screen = get_screen_size();
		}
	//	stop--;
	}
	free(screen);
	screen = NULL;
}

int	main(int ac, char **av, char **env)
{
	struct termios	term;
	char		*term_name;
	size_t		size;

	term_name = get_my_term_in_env();
	size = get_my_term_in_lib(term_name);
	get_my_term_attributes(&term);
	put_my_term_in_raw(&term);
	display_shit(size);
	reset_default_term(&term);
	return (0);
}
