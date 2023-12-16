/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:37:09 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:37:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_node *s)
{
	t_node	*current;
	int 	out;
	
	out = 0;
	current = s;
	while (current != NULL)
	{
		out++;
		current = current->next;
	}
	return (out);
}
