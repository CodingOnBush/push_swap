/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:20:56 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 14:22:03 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_print_node(t_node **stack)
{
	if (*stack != NULL)
	{
		ft_putnbr_fd((*stack)->nbr, 1);
		ft_putchar_fd(' ', 1);
		*stack = (*stack)->next;
	}
	else
		ft_putchar_fd(' ', 1);
}

void	ft_print_stack(t_node *a, t_node *b)
{
	ft_putstr_fd("=============================\n", 1);
	ft_putstr_fd("a : ", 1);
	while (a != NULL)
		ft_print_node(&a);
	ft_putstr_fd("\nb : ", 1);
	while (b != NULL)
		ft_print_node(&b);
	ft_putstr_fd("\n=============================\n", 1);
}
