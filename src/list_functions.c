#include "ft_select.h"

t_cycle		*stock_arguments(int ac, char **av)
{
	t_cycle	*args;
	int	i;

	args = NULL;
	i = 0;
	if (ac == 1)
		exit(1);
	while (i < ac - 1)
	{
		append_list(&args, create_new_element(av[i], i));
		i++;
	}
	return (args);
}

void		append_list(t_cycle **args, t_cycle *new)
{
	t_cycle	*tmp;

	if (!args)
	{
		args = new;
		return ;
	}
	else
		tmp = args;
	while (tmp)
	{
	}
}

void		erase_stocked_arguments(t_cycle **args)
{
}
