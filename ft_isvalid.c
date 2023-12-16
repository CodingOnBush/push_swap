#include "push_swap.h"

int	ft_isvalid(t_node *stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = stack;
	while (curr != NULL)
	{
		tmp = curr->next;
		while (tmp != NULL)
		{
			if (curr->nb == tmp->nb)
				return (0);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (1);
}
