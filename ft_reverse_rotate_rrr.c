#include "push_swap.h"

void	ft_reverse_rotate_rrr(t_node **a, t_node **b)
{
	ft_reverse_rotate_rra(a);
	ft_reverse_rotate_rrb(b);
	ft_putstr("rrr\n");
}
