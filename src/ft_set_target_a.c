/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:58:09 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:58:10 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*ft_find_max(t_node *stack)
{
	return (NULL);
}

void	ft_set_target_a(t_node *a, t_node *b)
{
	t_node	*curr_b;
	t_node	*target;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->nb < a->nb && curr_b->nb > best_match_index)
			{
				best_match_index = curr_b->index;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = ft_find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}
