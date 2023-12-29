/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:06:54 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 18:30:20 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!ft_check_args(ac, av))
		return (ft_args_error());
	a = ft_create_stack(ac, av);
	if (!a)
		return (ft_create_stack_error());
	if (ft_check_duplicates(&a) == 0)
		return (ft_duplicate_error(&a));
	if (!ft_stack_sorted(a))
		ft_turk_sort(&a, &b);
	ft_free_stack(&a);
	return (0);
}
