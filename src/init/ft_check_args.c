/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:46:42 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 23:58:49 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_isvalid_nb(char *s)
{
	long	nb;

	if (!ft_issign(*s) && !ft_isdigit(*s))
		return (0);
	if (ft_isnumber(s) <= 0)
		return (0);
	nb = ft_atol(s);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int	ft_check_duplicates(t_stack_node **head)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	current = *head;
	while (current->next != NULL)
	{
		temp = current->next;
		while (temp)
		{
			if (current->nbr == temp->nbr)
				return (0);
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	char	*str;
	int		numbers_found;

	numbers_found = 0;
	while (ac-- > 1)
	{
		av++;
		str = *av;
		while (*str != 0)
		{
			numbers_found = 1;
			if (!ft_isspace(*str))
			{
				if (!ft_isvalid_nb(str))
					return (0);
				str += ft_isnumber(str);
			}
			else
				str++;
		}
	}
	return (numbers_found);
}
