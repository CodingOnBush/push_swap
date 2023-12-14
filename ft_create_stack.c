#include "push_swap.h"

t_stack	*ft_create_stack(int ac, char **av)
{
	t_stack	*out;
	t_stack	*prev;
	t_stack	*next;
	int		i;

	i = 1;
	out = NULL;
	while (i < ac)
	{
		printf("i: %d\n", i);
		printf("av[i]: %s\n", av[i]);
		i++;
	}
	return (out);
}
