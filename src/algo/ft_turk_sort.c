/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:23:28 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 15:13:35 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rr(a, b);
	ft_update_indexes(*a);
	ft_update_indexes(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rrr(a, b);
	ft_update_indexes(*a);
	ft_update_indexes(*b);
}

static void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*curr_target;

	cheapest_node = ft_get_cheapest_node(*a);
	curr_target = cheapest_node->target_node;
	if (cheapest_node->above_median == 1 && curr_target->above_median == 1)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0 && curr_target->above_median == 0)
		rev_rotate_both(a, b, cheapest_node);
	ft_prep_node_for_push(a, b, cheapest_node, 'a');
	ft_prep_node_for_push(a, b, curr_target, 'b');
	ft_pb(a, b);
}

static void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_prep_node_for_push(a, b, (*b)->target_node, 'a');
	ft_pa(a, b);
}

void	ft_turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len <= 3)
		ft_little_sort(a);
	else
	{
		if (len-- > 3 && !ft_stack_sorted(*a))
			ft_pb(a, b);
		if (len-- > 3 && !ft_stack_sorted(*a))
			ft_pb(a, b);
		while (len-- > 3 && !ft_stack_sorted(*a))
		{
			ft_init_a_nodes(*a, *b);
			ft_move_a_to_b(a, b);
		}
		ft_little_sort(a);
		while (*b)
		{
			ft_init_b_nodes(*a, *b);
			ft_move_b_to_a(a, b);
		}
		ft_update_indexes(*a);
		ft_min_on_top(a);
	}
}
