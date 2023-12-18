/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:48:20 by allblue           #+#    #+#             */
/*   Updated: 2023/12/17 23:09:46 by allblue          ###   ########.fr       */
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

static void	ft_add_node(t_node **head, t_node *new_node) //Define a function that adds a node to the stack
{
	t_node	*last_node;

	if (!head || !new_node)
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

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static int	ft_check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_input_valid(char **av)
{
	int		i;
	long	val;

	i = 0;
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
			return (0);
		val = ft_atol(av[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		i++;
	}
	if (!ft_check_duplicate(av))
		return (0);
	return (1);
}

t_node	*ft_create_stack(char **av)
{
	t_node	*head;
	t_node	*node;
	int		i;

	i = 0;
	head = NULL;
	if (!ft_is_input_valid(av))
		return (NULL);
	while (av[i])
	{
		node = ft_create_node(ft_atoi(av[i]));
		if (!node)
			return (NULL);
		ft_add_node(&head, node);
		i++;
	}
	return (head);
}
