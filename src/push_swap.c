/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:06:54 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 13:07:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_print_node(t_stack_node **stack)
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

static void	ft_print_stacks(t_stack_node *a, t_stack_node *b)
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

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (!ft_check_args(ac, av))
		ft_args_error();
	b = NULL;
	a = ft_create_stack(ac, av);
	if (!a)
		ft_args_error();
	// ft_print_stacks(a, b);
	if (!ft_stack_sorted(a))
		ft_turk_sort(&a, &b);
	// ft_print_stacks(a, b);
	ft_free_stack(&a);
	return (0);
}
