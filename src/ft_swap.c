/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:41:44 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:46:46 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(t_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	t_node	**first; //Define a pointer to the first node of the stack
	t_node	**second; //Define a pointer to the second node of the stack

	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	first = head; //Assign the pointer to point to the first node of the stack
	second = first->next; //Assign the pointer to point to the second node of the stack
	head = second; //Update the `head` pointer to point to the second node of the stack
	head->prev = NULL; //Update the `prev` pointer of the `new head` to `NULL`
	first->next = second->next; //Update the `next` pointer of the `old head` to point to the node after the `new head`
	first->prev = second; //Update the `prev` pointer of the `old head` to point to the `new head`
	if (second->next) //Check if there's a `next` node after the `new head` and
		second->next->prev = first; //If so, update its `prev` pointer to point back to the `old head`
	second->next = first; //Update the `next` pointer of the `new head` to point to the `old head`
}

void	ft_sa(t_stack_node	**a) //Swap the first two nodes of stack `a` and print the instruction
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack_node **b) //Swap the first two nodes of stack `b` and print the instruction
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack_node **a, t_stack_node **b) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}