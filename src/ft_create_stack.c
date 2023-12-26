/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:48:20 by allblue           #+#    #+#             */
/*   Updated: 2023/12/26 16:51:38 by momrane          ###   ########.fr       */
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

static int	ft_isspace(char c)
{
	if (ft_strchr(" \t\n\r\f\v", c) != NULL)
		return (1);
	return (0);
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
			{
				printf("duplicate: %ld\n", ft_atol(av[i]));
				return (0);
			}
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

static int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_is_input_valid(char **av)
{
	int		i;
	long	val;

	i = 0;
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
		{
			ft_putstr_fd("Error(is not nb)\n", 1);
			return (0);
		}
		val = ft_atol(av[i]);
		if (!(val >= INT_MIN && val <= INT_MAX))
		{
			ft_putstr_fd("Error(overflow)\n", 1);
			return (0);
		}
		i++;
	}
	if (!ft_check_duplicate(av))
	{
		ft_putstr_fd("Error(duplicate)\n", 1);
		return (0);
	}
	return (1);
}

static int	ft_check_args(int ac, char **av)
{
	char	**tmp;
	int		i;
	char	*str;
	char	c;

	i = 1;
	while (i < ac)
	{
		j = 0;
		str = av[i];
		while (*str)
		{
			while (ft_isspace(*str))
				str++;
			if (ft_issign(*str))
				str++;
			while (ft_isdigit(*str))
				str++;
			if (ft_isspace(*str))
				str++;
			if (!ft_issign(*str) && !ft_isdigit(*str) && !ft_isspace(*str) && *str != '\0')
				return (0);
			str++;
		}
		i++;
	}
	return (1);
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

t_node	*ft_create_stack(int ac, char **av)
{
	t_node	*head;
	t_node	*new;
	char	*tmp;
	int		i;

	if (!ft_check_args(ac, av))
		return (NULL);
	head = NULL;
	i = 1;
	while (i < ac)
	{
		
		i++;
	}
	return (head);
}
