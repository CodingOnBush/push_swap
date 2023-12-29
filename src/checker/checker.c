/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:32:02 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 15:30:01 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_print_ok(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putstr_fd("OK\n", 1);
}

static void	ft_print_ko(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	char			*line;
	t_stack_node	*a;
	t_stack_node	*b;

	if (!ft_check_args(ac, av))
		ft_checker_error(NULL, NULL);
	b = NULL;
	a = ft_create_stack(ac, av);
	if (!a)
		ft_checker_error(NULL, NULL);
	if (!ft_check_duplicates(&a))
		ft_checker_error(&a, &b);
	line = get_next_line(0);
	while (line != NULL)
	{
		ft_apply_order(&a, &b, line);
		line = get_next_line(0);
	}
	if (ft_stack_sorted(a))
		ft_print_ok(&a, &b);
	else
		ft_print_ko(&a, &b);
	free(line);
	return (0);
}
