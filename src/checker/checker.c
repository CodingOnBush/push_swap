/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:32:02 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 13:19:12 by allblue          ###   ########.fr       */
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

static void	ft_print_node(t_stack_node **stack)
{
	if (*stack != NULL)
	{
		ft_putnbr_fd((*stack)->nbr, 1);
		ft_putchar_fd(' ', 1);
		*stack = (*stack)->next;
	}
	else
		ft_putchar_fd(' ', 1);
}

void	ft_print_stacks(t_stack_node **a, t_stack_node **b)
{
	int	i;

	i = 10;
	ft_putstr_fd("=============================\n", 1);
	ft_putstr_fd("a : ", 1);
	while (i-- > 0)
		ft_print_node(a);
	ft_putstr_fd("\nb : ", 1);
	while (i-- > 0)
		ft_print_node(b);
	ft_putstr_fd("\n=============================\n", 1);
}

static void	check_stacks(t_stack_node **a, t_stack_node **b)
{
	if (ft_stack_sorted(*a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(a);
	ft_free_stack(b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;
	// int				read;

	b = NULL;
	if (ac < 2 || !ft_check_args(ac, av))
		return (ft_args_error());
	a = ft_create_stack(ac, av);
	if (!a)
		return (0);
	if (ft_check_duplicates(&a) == 0)
		return (ft_duplicate_error(&a));
	// line = get_next_line(0);
	// printf("line: %s\n", line);
	// ft_print_stacks(&a, &b);
	// read = 1;
	while (1)
	{
		// ft_print_stacks(&a, &b);
		line = get_next_line(0);
		if (!line)
			break ;
		// printf("line: %s\n", line);
		ft_apply_order(&a, &b, line);
		free(line);
	}
	// printf("hey\n");
	// ft_print_stacks(&a, &b);
	check_stacks(&a, &b);
	free(line);
	return (0);
}
