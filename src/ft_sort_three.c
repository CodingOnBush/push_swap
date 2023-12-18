/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:14 by allblue           #+#    #+#             */
/*   Updated: 2023/12/17 23:30:30 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_three(t_node **a)
{
	t_node	*big_node;

	big_node = ft_find_max(*a);
	if (*a == big_node)
		ra(a, 0);
	else if ((*a)->next == big_node)
		rra(a, 0);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a);
}
