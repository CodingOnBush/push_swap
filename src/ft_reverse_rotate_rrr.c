/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_rrr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:57:44 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:21:54 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse_rotate_rrr(t_node **a, t_node **b)
{
	ft_reverse_rotate_rra(a);
	ft_reverse_rotate_rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
