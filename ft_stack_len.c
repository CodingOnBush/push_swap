#include "push_swap.h"

int	ft_stack_len(t_stack *s)
{
	t_stack	*current;
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
