#include "push_swap.h"

void	ft_push_swap(t_node **a, t_node **b)
{
	ft_print_stack(*a, *b);
	
	ft_push_pb(a, b);
	ft_push_pb(a, b);
	ft_push_pb(a, b);

	ft_print_stack(*a, *b);
}
