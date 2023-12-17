/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:58:23 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:58:24 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_three(t_node **a)
{
	t_node	*biggest;

	biggest = ft_get_biggest(*a);
	if (*a == biggest)
		ft_rotate_ra(a);
	else if ((*a)->next == biggest)
		ft_reverse_rotate_rra(a);
	if ((*a)->nb > (*a)->next->nb)
		ft_swap_sa(a);
}
