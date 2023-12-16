#include "push_swap.h"

void	ft_rotate_ra(t_node **a)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr("ra\n");
}
