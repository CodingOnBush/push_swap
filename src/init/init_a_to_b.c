/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:51 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 20:43:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_update_indexes(t_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}

static void	ft_set_a_target(t_node *a, t_node *b)//Find `a` node's target in stack `b`
{
	t_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_node	*target_node; //To store the pointer to the target node in stack `b`
	long	best_match; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	ft_print_stacks(a, b);
	target_node = NULL; //Initialize the target node to NULL
	current_b = NULL; //Initialize the current `b` node to NULL
	while (a) //As long as we have nodes in stack `a`
	{
		best_match = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			printf("--------------------\n");
			printf("a->nbr: %d\n", a->nbr);
			printf("current_b->nbr: %d\n", current_b->nbr);
			printf("best_match: %ld\n", best_match);
			if (target_node != NULL)
				printf("target_node: %d\n", target_node->nbr);
			printf("current_b->nbr > best_match: %d\n", current_b->nbr > best_match);
			printf("a->nbr > current_b->nbr: %d\n", a->nbr > current_b->nbr);
			if (current_b->nbr > best_match && a->nbr > current_b->nbr) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			printf("new best_match: %ld\n", best_match);
			if (target_node != NULL)
				printf("new target_node: %d\n", target_node->nbr);
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = ft_find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		printf("\n\nfinal a->target_node: %d\n", a->target_node->nbr);
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

static void	ft_set_push_cost(t_node *a, t_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		//Assign the current `a` node's push cost, its' index value
		a->push_cost = a->index;
		
		//Check if the above_median data is 0, meaning it is below median
		if (a->above_median == 0)
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		
		//Check if `a` node's target node `b` has a "1" above median attribute, meaning the target `b` node is above median
		if (a->target_node->above_median == 1)
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next;
	}
}

void	ft_set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	ft_init_a_nodes(t_node *a, t_node *b)
{
	ft_update_indexes(a);
	ft_update_indexes(b);
	ft_set_a_target(a, b);
	ft_set_push_cost(a, b);
	ft_set_cheapest(a);
}
