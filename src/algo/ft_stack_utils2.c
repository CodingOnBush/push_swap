/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:23:18 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 15:13:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*ft_get_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_push_node_on_top(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	ft_prep_node_for_push(t_stack_node **a, t_stack_node **b,
		t_stack_node *n, char node)
{
	if (node == 'a')
	{
		while (*a != n)
		{
			if (n->above_median)
				ft_ra(a);
			else
				ft_rra(a);
		}
	}
	else if (node == 'b')
	{
		while (*b != n)
		{
			if (n->above_median)
				ft_rb(b);
			else
				ft_rrb(b);
		}
	}
}

void	ft_min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != ft_find_min(*a)->nbr)
	{
		if (ft_find_min(*a)->above_median)
			ft_ra(a);
		else
			ft_rra(a);
	}
}
