/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:08 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:57:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_node *stack)
{
	t_node	*curr;

	if (!stack)
		return (1);
	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}
