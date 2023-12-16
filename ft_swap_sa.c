#include "push_swap.h"

void	ft_swap_sa(t_node **a)
{
	t_node *tmp;

	tmp = NULL;
	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	ft_putstr("sa\n");
}
