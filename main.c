#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (0);
	a = ft_create_stack(ac, av);
	if (!a)
		return (0);
	b = NULL;
	ft_print_stack(a, b);
	return (0);
}
