#include "ft_select.h"

int	main(int ac, char **av)
{
	t_cycle		*args;

	args = stock_arguments(ac, av);
	open_ft_select_interface(args);
	erase_stocked_arguments(&args);
	return (0);
}
