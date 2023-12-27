/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:48:20 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 15:54:55 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*ft_create_node(int n)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	ft_add_node(t_node **head, t_node *new_node)
{
	t_node	*last_node;

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

static void	ft_check_duplicates(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (current->nbr == temp->nbr)
				ft_duplicate_error(head);
			temp = temp->next;
		}
		current = current->next;
	}
}

t_node	*ft_create_stack(int ac, char **av)
{
	t_node	*head;
	t_node	*new;
	int		i;
	int		j;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isdigit(av[i][j]) || ft_issign(av[i][j])))
			{
				new = ft_create_node(ft_atol(&av[i][j]));
				ft_add_node(&head, new);
				j += ft_isnumber(&av[i][j]);
			}
			else
				j++;
		}
		i++;
	}
	ft_check_duplicates(head);
	return (head);
}