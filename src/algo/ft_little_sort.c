/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:23:06 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 15:13:19 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_little_sort(t_stack_node **a)
{
	t_stack_node	*biggest;

	if (ft_stack_len(*a) == 2)
		ft_sa(a);
	else
	{
		biggest = ft_find_max(*a);
		if (*a == biggest)
			ft_ra(a);
		else if ((*a)->next == biggest)
			ft_rra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a);
	}
}
