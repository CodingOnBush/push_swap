/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:08 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}
