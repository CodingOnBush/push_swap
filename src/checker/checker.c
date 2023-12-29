/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:32:02 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 18:51:23 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	init(int ac, char **av, t_stack_node **a, t_stack_node **b)
{
	if (ac < 2)
		return (0);
	if (!ft_check_args(ac, av))
		return (0);
	*a = ft_create_stack(ac, av);
	if (!(*a))
		return (0);
	if (!ft_check_duplicates(a))
		return (0);
	return (1);
}

static void	check_stacks(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	if (!ft_stack_sorted(*a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	b = NULL;
	if (ac < 2 || !ft_check_args(ac, av))
		return (ft_args_error());
	a = ft_create_stack(ac, av);
	if (!a)
		return (0);
	if (!ft_check_duplicates(&a))
		return (ft_duplicate_error(&a));
	line = get_next_line(0);
	while (line != NULL)
	{
		ft_apply_order(&a, &b, line);
		free(line);
		line = get_next_line(0);
		if (!line)
			break ;
	}
	check_stacks(&a, &b);
	free(line);
	return (0);
}
