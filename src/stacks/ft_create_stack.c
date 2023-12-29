/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:23:00 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 15:23:00 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack_node	*ft_new_node(int n)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	ft_add_node(t_stack_node **head, t_stack_node *new_node)
{
	t_stack_node	*last_node;

	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*head);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack_node	*ft_create_stack(int ac, char **av)
{
	t_stack_node	*out;
	t_stack_node	*new;
	char			*str;

	out = NULL;
	av++;
	while (ac-- > 1)
	{
		str = *av;
		while (*str != '\0')
		{
			if ((ft_isdigit(*str) || ft_issign(*str)))
			{
				new = ft_new_node(ft_atol(str));
				if (!new)
					return (ft_new_node_error(&out));
				ft_add_node(&out, new);
				str += ft_isnumber(str);
			}
			else
				str++;
		}
		av++;
	}
	return (out);
}
