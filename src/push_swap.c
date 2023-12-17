/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:32 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:09:46 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_swap(t_node **a, t_node **b)
{
	if (ft_stack_len(*a) == 2)
		ft_swap_sa(a);
	else if (ft_stack_len(*a) == 3)
		ft_sort_three(a);
	else
		ft_sort_turk(a, b);
}

