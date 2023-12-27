/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:46:42 by momrane           #+#    #+#             */
/*   Updated: 2023/12/27 15:55:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_valid_number(char *s)
{
	long	nb;

	if (ft_issign(*s) || ft_isdigit(*s))
	{
		if (ft_isnumber(s) <= 0)
			return (0);
		nb = ft_atol(s);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		return (1);
	}
	return (0);
}

static int	ft_check_numbers(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while (ft_isspace(av[i][j]))
				j++;
			if (av[i][j] == '\0')
				break ;
			if (!ft_valid_number(&av[i][j]))
				return (0);
			j += ft_isnumber(&av[i][j]);
		}
		i++;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_check_numbers(ac, av))
		return (0);
	return (1);
}
