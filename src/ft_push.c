/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:05 by momrane           #+#    #+#             */
/*   Updated: 2023/12/18 14:14:58 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_push(t_node **dst, t_node **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_node	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_node` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	ft_pa(t_node **a, t_node **b) //Push on top of `b`, the top `a` and print the instruction
{
	ft_push(a, b); 
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_node **b, t_node **a) //Push on top of `a`, the top `b` and print the instruction
{
	ft_push(b, a);
	ft_putstr_fd("pb\n", 1);
}