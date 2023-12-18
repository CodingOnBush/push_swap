/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:56 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 14:34:58 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_error(void)
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
	av = ft_split(av[1], ' ');
	a = ft_create_stack(av);
	if (!a)
		ft_print_error();
	// ft_print_stack(a, b);
	// int i = 1;
	// while (a)
	// {
	// 	printf("[node : %d | address : %p]\n", i, a);
	// 	printf("a->prev = %p\n", a->prev);
	// 	printf("a->nbr = %d\n", a->nbr);
	// 	printf("a->index = %d\n", a->index);
	// 	printf("a->push_cost = %d\n", a->push_cost);
	// 	printf("a->above_median = %d\n", a->above_median);
	// 	printf("a->cheapest = %d\n", a->cheapest);
	// 	printf("a->target_node = %p\n", a->target_node);
	// 	printf("a->next = %p\n", a->next);
	// 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	// 	a = a->next;
	// 	i++;
	// 	if (i == 10)
	// 		break ;
	// }
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			ft_sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	// ft_print_stack(a, b);
	if (ft_stack_sorted(a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(&a);
	return (0);
}
