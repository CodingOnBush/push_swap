/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:10 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid(t_node *stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = stack;
	while (curr != NULL)
	{
		tmp = curr->next;
		while (tmp != NULL)
		{
			if (curr->nb == tmp->nb)
				return (0);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (1);
}
