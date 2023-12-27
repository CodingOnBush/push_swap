/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:48:20 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 09:31:07 by allblue          ###   ########.fr       */
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


static int	ft_isspace(char c)
{
	char	*spaces;

	spaces = " \t\n\r\f\v";
	while (*spaces)
	{
		if (c == *spaces)
			return (1);
		spaces++;
	}
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_check_number(char *s)
{
	int		i;

	i = 0;
	if (ft_issign(s[i]))
	{
		if (!ft_isdigit(s[i + 1]))
			return (-1);
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
		i++;
	return (i);
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (ft_isspace(*s))
		s++;
	if (ft_issign(*s))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static int	ft_check_duplicate(int ac, char **av)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 1;
	while (k < ac)
	{
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
		k++;
	}
	return (1);
}

static int	ft_check_args_number(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isdigit(av[i][j]) || ft_issign(av[i][j])))
			{
				if (ft_check_number(&av[i][j]) <= 0)
					return (0);
				j += ft_check_number(&av[i][j]);
			}
			if (av[i][j] == '\0')
				break ;
			if (!ft_isspace(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_args_valid(int ac, char **av)
{
	if (ac < 2 || !ft_check_args_number(ac, av))
		return (0);
	if (!ft_check_duplicate(ac, av))
		return (0);
	return (1);
}

t_node	*ft_create_stack(int ac, char **av)
{
	t_node	*head;
	t_node	*new;
	char	*tmp;
	int		i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		
		i++;
	}
	return (head);
}
