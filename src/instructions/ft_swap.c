/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:25 by allblue           #+#    #+#             */
/*   Updated: 2023/12/28 09:40:37 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

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

void	ft_sa(t_node **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
	ft_print_stacks(*a, NULL);
}

void	ft_sb(t_node **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
	ft_print_stacks(NULL, *b);
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
	ft_print_stacks(*a, *b);
}
