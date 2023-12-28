/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:46:42 by momrane           #+#    #+#             */
/*   Updated: 2023/12/28 15:31:02 by momrane          ###   ########.fr       */
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

void	ft_check_duplicates(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current->next != NULL)
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

int	ft_check_args(int ac, char **av)
{
	int		i;

	if (ac < 2)
		return (0);
	while (ac-- > 1)
	{
		i = 0;
		while (av[ac][i] != '\0')
		{
			if (!ft_isspace(av[ac][i]))
			{
				if (!ft_isvalid_nb(&av[ac][i]))
					return (0);
				i += ft_isnumber(&av[ac][i]);
			}
			else
				i++;
		}
	}
	return (1);
}
