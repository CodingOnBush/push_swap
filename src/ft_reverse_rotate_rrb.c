/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_rrb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:21:10 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse_rotate_rrb(t_node **b)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = NULL;
		tmp->next = *b;
		*b = tmp;
	}
	ft_putstr_fd("rrb\n", 1);
}
