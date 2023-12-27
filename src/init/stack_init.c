/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:21 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 16:20:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	append_node(t_node **stack, int n) //Define a function that searches for the last node to append to the linked list
{
	t_node	*node; //To store a pointer to the new node to be created with the value `n`
	t_node	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_node)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->nbr = n; //Set the `next` data of of the new node to `n` value
	if (!(*stack)) //Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->prev = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = ft_find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->prev = last_node; //Update the previous pointer of the new node and complete the appending
	}
}


void	prep_for_push(t_node **stack, t_node *top_node, char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
		else
			return ;
	}
}