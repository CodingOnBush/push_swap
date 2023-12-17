/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:57:55 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:21:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_rb(t_node **b)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr_fd("rb\n", 1);
}
