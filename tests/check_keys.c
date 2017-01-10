/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:40:49 by ggane             #+#    #+#             */
/*   Updated: 2017/01/09 18:18:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__
#include <termcap.h>
#endif

#ifdef __APPLE__
#include <term.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*get_var_value(char *env)
{
	char	*value;
	char	*equal;
	size_t	size;

	equal = strchr(env, '=');
	size = strlen(equal + 1);
	if (!(value = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	bzero(value, size + 1);
	value = strncpy(value, equal + 1, size);
	return (value);
}

size_t	get_size_name(char *env)
{
	size_t	size;

	size = 0;
	while (env[size])
	{
		if (env[size] == '=')
			break ;
		size++;
	}
	return (size);
}

char	*get_var_name(char *env)
{
	char	*var_name;
	size_t	size;

	size = get_size_name(env);
	if (!(var_name = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	bzero(var_name, size + 1);
	var_name = strncpy(var_name, env, size);
	return (var_name);
}

char	*get_term(char **env)
{
	char	*var_name;
	int		i;

	i = 0;
	while (env[i])
	{
		var_name = get_var_name(env[i]);
		if (!strcmp(var_name, "TERM"))
		{
			printf("var_name : [%s]\n", var_name);
			free(var_name);
			var_name = NULL;
			return (get_var_value(env[i]));
		}
		free(var_name);
		var_name = NULL;
		i++;
	}
	return (NULL);
}

size_t	find_termcap_description(char **env)
{
	char	term_buffer[2048];
	char	*term_type;
	int		status;

	bzero(term_buffer, 2048);
	term_type = get_term(env);
	printf("term_type : [%s]\n", term_type);
	status = tgetent(term_buffer, term_type);
	if (!status)
		printf("term_type is not defined.\n");
	if (status < 0)
		printf("Could not access to termcap DB.\n");
	if (status == 1)
		printf("Access to termcap DB granted.\n");
	free(term_type);
	term_type = NULL;
	return (strlen(term_buffer));
}

void	get_screen_size(void)
{
	int		largeur;
	int		hauteur;

	largeur = tgetnum("co");
	hauteur = tgetnum("li");
	printf("largeur : (%d)\n", largeur);
	printf("hauteur : (%d)\n", hauteur);
}

/*void		display_keys(void)
{
}*/

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char	*buffer;
	size_t	size;
	char	*capability;

	size = find_termcap_description(env);
	if (!(buffer = (char *)malloc(sizeof(char) * size)))
	get_screen_size();
	capability = tgetstr("ks", &buffer);
	printf("buffer : [%s]\n", buffer);
	printf("capability : [%s]\n", capability);
	while (1)
	{
		//display_keys(description);
	}
	return (0);
}
