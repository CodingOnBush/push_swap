/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:56 by allblue           #+#    #+#             */
/*   Updated: 2023/12/27 09:31:16 by allblue          ###   ########.fr       */
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
	if (!ft_args_valid(ac, av))
		ft_print_error();
	printf("OK\n");
	// t_node	*a;
	// t_node	*b;

	// b = NULL;
	// if (ac < 2)
	// 	return (0);
	// a = ft_create_stack(ac, av);
	// if (!a)
	// {
	// 	ft_putstr_fd("€rror(a null)\n", 1);
	// 	ft_print_error();
	// }
	// if (!ft_stack_sorted(a))
	// {
	// 	if (ft_stack_len(a) == 2)
	// 		ft_sa(&a);
	// 	else if (ft_stack_len(a) == 3)
	// 		ft_sort_three(&a);
	// 	else
	// 		sort_stacks(&a, &b);
	// }
	// ft_free_stack(&a);
	return (0);
}
