#include "push_swap.h"

int	ft_is_sorted(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}
