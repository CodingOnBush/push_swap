/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:45:10 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 14:38:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_ra(t_stack_node **a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack_node **b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
}
