#include "push_swap.h"

void	*ft_push(int nb, t_stack **stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->nb = nb;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
	return (new);
}
