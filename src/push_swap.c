/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:56 by allblue           #+#    #+#             */
/*   Updated: 2023/12/26 13:57:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_error()
{
	ft_putstr_fd("€rror\n", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	a = ft_create_stack(av);
	if (!a)
	{
		ft_putstr_fd("€rror(a null)\n", 1);
		ft_print_error();
	}
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			ft_sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
