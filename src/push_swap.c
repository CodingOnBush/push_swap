/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:32 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:31:40 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
	t_node *a;
	t_node *b;

	if (ac < 2)
		return (0);
	a = ft_create_stack(ac, av);
	b = NULL;
	if (!a || ft_is_sorted(a) || !ft_isvalid(a))
		return (0);
	ft_print_stack(a, b);
	if (ft_stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
		ft_push_pa(&a);
	else if (ft_stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
		ft_sort_three(&a);
	else
		ft_sort_turk(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	ft_free_stack(&a);
	return (0);
}
