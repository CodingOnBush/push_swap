#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	if (ac < 2)
		return (0);
	a = ft_create_stack(ac, av);
	if (!a || ft_is_sorted(a) || !ft_isvalid(a))
		return (0);
	b = NULL;
	ft_push_swap(&a, &b);
	return (0);
}
