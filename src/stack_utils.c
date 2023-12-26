/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:23 by allblue           #+#    #+#             */
/*   Updated: 2023/12/26 09:53:13 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stack_len(t_node *stack)
{
	int	out;

	if (!stack)
		return (0);
	out = 0;
	while (stack)
	{
		stack = stack->next;
		out++;
	}
	return (out);
}

t_node	*ft_find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*ft_find_min(t_node *stack)
{
	t_node	*current_min;

	if (!stack)
		return (NULL);
	current_min = stack;
	while (stack)
	{
		if (stack->nbr < current_min->nbr)
			current_min = stack;
		stack = stack->next;
	}
	return (current_min); 
}

t_node	*ft_find_max(t_node *stack)
{
	t_node	*current_max;

	if (!stack)
		return (NULL);
	current_max = stack;
	while (stack)
	{
		if (stack->nbr > current_max->nbr)
			current_max = stack;
		stack = stack->next;
	}
	return (current_max);
}

t_node	*ft_get_cheapest_node(t_node *stack)
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
