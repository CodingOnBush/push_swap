/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:51 by allblue           #+#    #+#             */
/*   Updated: 2023/12/28 15:36:58 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_set_a_targets(t_node *a, t_node *b)
{
	t_node	*curr_b;
	t_node	*target_node;
	long	best_match;

	target_node = NULL;
	curr_b = NULL;
	while (a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->nbr > best_match && a->nbr > curr_b->nbr)
			{
				best_match = curr_b->nbr;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = ft_find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	ft_set_push_cost(t_node *a, t_node *b)
{
	t_node	*curr_target;
	int	alen;
	int	blen;

	alen = ft_stack_len(a);
	blen = ft_stack_len(b);
	while (a)
	{
		curr_target = a->target_node;
		a->push_cost = a->index;
		if (a->above_median == 0)
			a->push_cost = alen - (a->index);
		if (curr_target->above_median == 0)
			a->push_cost += blen - (curr_target->index);
		else
			a->push_cost += curr_target->index;
		a = a->next;
	}
}

static void	ft_set_cheapest(t_node *stack)
{
	long	cheapest;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	ft_init_a_nodes(t_node *a, t_node *b)
{
	ft_update_indexes(a);
	ft_update_indexes(b);
	ft_set_a_targets(a, b);
	ft_set_push_cost(a, b);
	ft_set_cheapest(a);
}
