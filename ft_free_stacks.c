/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:02 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:03 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **a)
{
	while (*a != NULL)
	{
		t_node *temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	free(*a);
}