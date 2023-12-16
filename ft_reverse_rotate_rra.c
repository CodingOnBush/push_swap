/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_rra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:28 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:57 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_rra(t_node **a)
{
	t_node *tmp;
	t_node *last;

	tmp = NULL;
	last = NULL;
	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = NULL;
		tmp->next = *a;
		*a = tmp;
	}
	ft_putstr("rra\n");
}
