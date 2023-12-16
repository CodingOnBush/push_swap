/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:34:16 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:34:17 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int nb)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
