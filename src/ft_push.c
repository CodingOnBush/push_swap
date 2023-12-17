/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:34:12 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:41:22 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_push(t_node **stack1, t_node **stack2)
{
	t_node	*node;

	if (!(*stack2))
		return ;
	node = *stack2;
	*stack2 = (*stack2)->next;
	if (!(*stack2))
		(*stack2)->prev = NULL;
	node->prev = NULL;
	if (!(*stack1))
	{
		*stack1 = node;
		(*stack1)->next = NULL;
	}
	else
	{
		node->next = *stack1;
		node->next->prev = node;
		*stack1 = tmp;
	}
}

void	ft_pa(t_node **a, t_node **b)
{
	ft_push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_node **a, t_node **b)
{
	ft_push(b, a);
	ft_putstr_fd("pb\n", 1);
}
