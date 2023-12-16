/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:33:42 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:33:43 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_hundred(t_node **a, t_node **b)
{
	int		chunk_size;
	int		chunk_count;
	int		i;
	int		j;
	t_node	*biggest;

	chunk_size = ft_stack_len(*a) / 5;
	chunk_count = 0;
	while (chunk_count < 5)
	{
		i = 0;
		while (i < chunk_size)
		{
			biggest = ft_get_biggest(*a);
			j = 0;
			while (biggest != *a)
			{
				ft_rotate_ra(a);
				j++;
			}
			ft_push_pb(a, b);
			i++;
		}
		chunk_count++;
	}
	ft_sort_five(a, b);
	while (*b)
		ft_push_pa(a, b);
}
