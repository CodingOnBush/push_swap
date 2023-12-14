#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (0);
	b = NULL;
	printf("ac = %d\n", ac);
	a = ft_create_stack(ac, av);
	ft_push_swap(a, b);
	return (0);
}