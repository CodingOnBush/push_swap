/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:57:50 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:21:27 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_ra(t_node **a)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr_fd("ra\n", 1);
}
