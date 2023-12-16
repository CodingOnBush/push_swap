/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:22 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:38:23 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sb(t_node **b)
{
	t_node *tmp;

	tmp = NULL;
	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	ft_putstr("sb\n");
}
