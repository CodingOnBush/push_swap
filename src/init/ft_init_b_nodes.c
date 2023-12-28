/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:54 by allblue           #+#    #+#             */
/*   Updated: 2023/12/28 15:31:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_set_b_target(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->nbr > b->nbr && curr_a->nbr < best_match)
			{
				best_match = curr_a->nbr;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_init_b_nodes(t_node *a, t_node *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	ft_update_indexes(a);
	ft_update_indexes(b);
	ft_set_b_target(a, b);
}