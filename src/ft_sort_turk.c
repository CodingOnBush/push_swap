/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_turk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:33:36 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:59:49 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_turk(t_node **a, t_node **b)
{
	int	alen;

	alen = ft_stack_len(*a);
	if (alen-- > 3 && !ft_is_sorted(*a))
		ft_push_pb(a, b);
	if (alen-- > 3 && !ft_is_sorted(*a))
		ft_push_pb(a, b);
	while (alen-- > 3 && !ft_is_sorted(*a))
	{
		
	}
	ft_sort_three(a);
	while (*b)
	{
		/* code */
	}
	
	
}
