/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:11:02 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 14:11:45 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_rev_rotate(t_node **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_node	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = ft_find_last(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	ft_rra(t_node **a) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	ft_rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_node **b) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	ft_rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_node **a, t_node **b) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}