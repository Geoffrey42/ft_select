/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:40:49 by ggane             #+#    #+#             */
/*   Updated: 2017/01/09 17:10:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <curses.h>
#include <term.h>
#include <termios.h>
//#include "ft_select.h"

char	*get_var_value(char *env)
{
	char	*value;
	char	*equal;
	size_t	size;

	value = NULL;
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
			return (get_var_value(env[i]));
		}
		free(var_name);
		var_name = NULL;
		i++;
	}
	return (NULL);
}

int		main(int ac, char **av, char **env)
{
	char	term_buffer[2048];
	char	*term_type;
	int		success;

	term_type = get_term(env);
	printf("term_type : [%s]\n", term_type);
	success = tgetent(term_buffer, term_type);
	if (!success)
		printf("term_type is not defined.\n");
	if (success < 0)
		printf("Could not access to termcap DB.\n");
	if (success == 1)
		printf("Access to termcap DB granted.\n");
	free(term_type);
	term_type = NULL;
	return (0);
}
