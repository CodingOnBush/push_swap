#include "push_swap.h"

void	ft_rotate_rb(t_node **b)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr("rb\n");
}
