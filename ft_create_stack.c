#include "push_swap.h"

t_stack	*ft_create_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		tmp = (t_stack*)malloc(sizeof(t_stack));
		tmp->size = ft_atoi(av[i]);
		tmp->next = stack;
		tmp->prev = NULL;
		if (stack)
			stack->prev = tmp;
		stack = tmp;
		i++;
	}
	return (stack);
}
