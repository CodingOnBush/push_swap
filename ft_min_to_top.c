/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:13 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:35:29 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_to_top(t_node **a)
{
	t_node	*min;
	int		min_pos;

	min = ft_get_min(*a);
	min_pos = ft_get_pos(*a, min);
	if (min_pos <= ft_stack_len(*a) / 2)
	{
		while (*a != min)
			ft_rotate_ra(a);
	}
	else
	{
		while (*a != min)
			ft_reverse_rotate_rra(a);
	}
}
