/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:02:17 by momrane           #+#    #+#             */
/*   Updated: 2023/12/27 15:02:58 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_isspace(char c)
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

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

long	ft_atol(char *s)
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

int	ft_isnumber(char *s)
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
