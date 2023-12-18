/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:25 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 08:33:31 by allblue          ###   ########.fr       */
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
	// peut être que ça marche si je swap que les valeurs
	// int temp = (*head)->nbr;
	// (*head)->nbr = (*head)->next->nbr;
	// (*head)->next->nbr = temp;
}

void	ft_sa(t_node	**a) //Swap the first two nodes of stack `a` and print the instruction
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_node **b) //Swap the first two nodes of stack `b` and print the instruction
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_node **a, t_node **b) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}