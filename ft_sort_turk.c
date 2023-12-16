/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_turk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:33:36 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:43:22 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_turk(t_stack **a, t_stack **b)
{
	ft_push_pb(a, b);
	ft_push_pb(a, b);
	if (ft_stack_len(*a) == 3)
		ft_sort_three(a);
	
}
