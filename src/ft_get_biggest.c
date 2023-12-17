/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_biggest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:05 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 14:56:43 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*ft_get_biggest(t_node *stack)
{
	t_node	*biggest;
	t_node	*tmp;

	biggest = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nb > biggest->nb)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}
