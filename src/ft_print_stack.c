/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:22 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:20:29 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

static void	ft_print_node(t_node **stack)
{
	if (*stack != NULL)
	{
		ft_putnbr((*stack)->nb);
		*stack = (*stack)->next;
	}
	else
		ft_putchar(' ');
}

void	ft_print_stack(t_node *a, t_node *b)
{
	ft_putstr_fd("=============================\n", 1);
	ft_putstr_fd("a : ", 1);
	while (a != NULL)
	{
		ft_print_node(&a);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b : ", 1);
	while (b != NULL)
	{
		ft_print_node(&b);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("=============================\n", 1);
}