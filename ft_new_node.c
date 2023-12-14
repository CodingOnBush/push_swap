#include "push_swap.h"

t_stack	*ft_new_node(int size)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->size = size;
	new->next = NULL;
	return (new);
}
