/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:08 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 09:08:06 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_both(t_node **a,
						t_node **b,
						t_node *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b, 0); //Rotate both `a` and `b` nodes
	ft_update_indexes(*a);
	ft_update_indexes(*b);
}

static void	rev_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b, 0); //Reverse rotate both `a` and `b` nodes
	ft_update_indexes(*a); //Refresh current node positions
	ft_update_indexes(*b);
}

static void	move_a_to_b(t_node **a, t_node **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_node	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, 0);
}

static void	move_b_to_a(t_node **a, t_node **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, 0); 
}

static void	min_on_top(t_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != ft_find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (ft_find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_stacks(t_node **a, t_node **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
		pb(b, a, 0);
	if (len_a-- > 3 && !ft_stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(b, a, 0);
	while (len_a-- > 3 && !ft_stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init_nodes_a(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	ft_sort_three(a);
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	ft_update_indexes(*a); //Refresh the current position of stack `a`
	min_on_top(a); //Ensure smallest number is on top
}
