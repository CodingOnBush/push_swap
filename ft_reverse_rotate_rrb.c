#include "push_swap.h"

void	ft_reverse_rotate_rrb(t_node **b)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = NULL;
		tmp->next = *b;
		*b = tmp;
	}
	ft_putstr("rrb\n");
}
