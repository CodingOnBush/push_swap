/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:33:54 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:23:21 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isnumber(char *str)
{
	int	out;

	out = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isdigit(*str))
			out = 1;
		str++;
	}
	return (out);
}

t_node	*ft_create_stack(int ac, char **av)
{
	t_node	*out;
	char	**tmp;
	int		i;

	i = 1;
	out = NULL;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (NULL);
		while (*tmp)
		{
			if (!ft_isnumber(*tmp) || !ft_append_node(&out, ft_atoi(*tmp)))
			{
				ft_putstr_fd("Error\n", 1);
				return (ft_free_split(tmp));
			}
			tmp++;
		}
		i++;
	}
	return (out);
}
