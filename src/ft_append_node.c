/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:25:01 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:56:21 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*ft_append_node(t_node **stack, int nb)
{
	t_node *new;
	t_node *last;

	if (!stack)
		return (NULL);
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return (*stack);
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (*stack);
}
