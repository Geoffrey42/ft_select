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

#include "ft_select.h"

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
			ft_putstr("var_name : [");
			ft_putstr(var_name);
			ft_putendl("]");
			ft_strdel(&var_name);
			return (get_var_value(env[i]));
		}
		ft_strdel(&var_name);
		i++;
	}
	return (NULL);
}

int		find_termcap_description(char **env)
{
	char	term_buffer[2048];
	char	*term_type;
	int		status;

	term_type = get_term(env);
	ft_putstr("term_type : [");
	ft_putstr(term_type);
	ft_putendl("]");
	status = tgetent(term_buffer, term_type);
	if (!status)
		ft_putstr("term_type is not defined.\n");
	if (status < 0)
		ft_putstr("Could not access to termcap DB.\n");
	if (status == 1)
		ft_putstr("Access to termcap DB granted.\n");
	ft_strdel(&term_type);
	return (status);
}

void	get_screen_size(void)
{
	int		largeur;
	int		hauteur;

	largeur = tgetnum("co");
	hauteur = tgetnum("li");
	ft_putstr("largeur : ");
	ft_putnbrdl(largeur);
	ft_putstr("hauteur : ");
	ft_putnbrdl(hauteur);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	if (find_termcap_description(env) != 1)
		return (1);
	get_screen_size();
	return (0);
}
