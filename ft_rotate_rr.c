#include "push_swap.h"

void	ft_rotate_rr(t_node **a, t_node **b)
{
	ft_rotate_ra(a);
	ft_rotate_rb(b);
	ft_putstr("rr\n");
}
