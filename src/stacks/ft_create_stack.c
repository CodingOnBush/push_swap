/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:48:20 by allblue           #+#    #+#             */
/*   Updated: 2023/12/28 23:43:31 by allblue          ###   ########.fr       */
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
		ft_new_node_error(*head);
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
	long	nb;
	int		i;
	int		j;

	out = NULL;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isdigit(av[i][j]) || ft_issign(av[i][j])))
			{
				nb = ft_atol(&av[i][j]);
				ft_add_node(&out, ft_new_node(nb));
				j += ft_isnumber(&av[i][j]);
			}
			else
				j++;
		}
		i++;
	}
	ft_check_duplicates(out);
	return (out);
}
