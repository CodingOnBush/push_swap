/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_nodes_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:57:04 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:09:26 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_init_nodes_a(t_node **a, t_node **b)
{
	ft_get_current_index(*a);
	ft_get_current_index(*b);
	ft_set_target_a(*a, *b);
	ft_get_cost_a(*a, *b);
	ft_set_cheapest(*a);
}
