#include "push_swap.h"

void	ft_swap_sb(t_node **b)
{
	t_node *tmp;

	tmp = NULL;
	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	ft_putstr("sb\n");
}
