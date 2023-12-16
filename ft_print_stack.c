/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:22 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:23 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("=============================\n");
	ft_putstr("a : ");
	while (a != NULL)
	{
		ft_print_node(&a);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_putstr("b : ");
	while (b != NULL)
	{
		ft_print_node(&b);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_putstr("=============================\n");
}
