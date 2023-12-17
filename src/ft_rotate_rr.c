/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:58:00 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:21:44 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_rr(t_node **a, t_node **b)
{
	ft_rotate_ra(a);
	ft_rotate_rb(b);
	ft_putstr_fd("rr\n", 1);
}
