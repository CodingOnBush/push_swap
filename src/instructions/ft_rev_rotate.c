/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:22:37 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 14:37:24 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	ft_rra(t_stack_node **a)
{
	ft_rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack_node **b)
{
	ft_rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
