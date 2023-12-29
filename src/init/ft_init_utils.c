/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:02:17 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 13:22:26 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (ft_issign(s[i]))
	{
		if (!ft_isdigit(s[i + 1]))
			return (-1);
		i++;
	}
	while (ft_isdigit(s[i]) && s[i] != '\0')
		i++;
	if (!ft_isspace(s[i]) && s[i] != '\0')
		return (-1);
	return (i);
}

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

void	ft_update_indexes(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}
