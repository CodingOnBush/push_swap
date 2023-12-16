/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:33:46 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:33:47 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_append(int nb, t_node **stack)
{
	t_node	*new;
	t_node	*curr;

	new = ft_new_node(nb);
	if (!new)
		return (NULL);
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (*stack);
}
