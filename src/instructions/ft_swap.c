/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:22:49 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 14:36:24 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	*head = (*head)->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
}

void	ft_sa(t_stack_node **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack_node **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
