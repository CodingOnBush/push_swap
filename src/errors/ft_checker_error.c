/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:28:13 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 15:23:04 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_checker_error(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putstr_fd("Checker error\n", 1);
	exit(1);
}
