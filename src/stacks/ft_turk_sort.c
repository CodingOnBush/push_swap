/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:08 by allblue           #+#    #+#             */
/*   Updated: 2023/12/26 13:34:07 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rr(a, b);
	ft_update_indexes(*a);
	ft_update_indexes(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rrr(a, b);
	ft_update_indexes(*a);
	ft_update_indexes(*b);
}

void	ft_prep_a_for_push(t_stack_node **a, t_stack_node *top_node)
{
	while (*a != top_node)
	{
		if (top_node->above_median)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_prep_b_for_push(t_stack_node **b, t_stack_node *top_node)
{
	while (*b != top_node)
	{
		if (top_node->above_median)
			ft_rb(b);
		else
			ft_rrb(b);
	}
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
	// ft_push_node_on_top(a, cheapest_node, 'a');
	ft_prep_a_for_push(a, cheapest_node);
	// ft_push_node_on_top(b, curr_target, 'b');
	ft_prep_b_for_push(b, curr_target);	
	ft_pb(a, b);
}


static void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	// ft_push_node_on_top(a, (*b)->target_node, 'a');
	ft_prep_a_for_push(a, (*b)->target_node);
	ft_pa(a, b); 
}

static void	ft_min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != ft_find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (ft_find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ft_ra(a);
		else
			ft_rra(a);
	}
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
