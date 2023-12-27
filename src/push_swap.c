/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:56 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 18:33:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (!ft_check_args(ac, av))
		return (ft_print_error());
	b = NULL;
	a = ft_create_stack(ac, av);
	if (!a)
		return (ft_print_error());
	ft_print_stacks(a, b);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			ft_sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_turk_sort(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
