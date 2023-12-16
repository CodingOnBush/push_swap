#include "push_swap.h"

int	ft_stack_len(t_node *s)
{
	t_node	*current;
	int 	out;
	
	out = 0;
	current = s;
	while (current != NULL)
	{
		out++;
		current = current->next;
	}
	return (out);
}
