/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:43:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:10:12 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_four(t_node **a, t_node **b)
{
	ft_push_pb(a, b);
	ft_sort_three(a);
	ft_push_pa(a, b);
	if ((*a)->nb > (*a)->next->nb)
		ft_swap_sa(a);
}
