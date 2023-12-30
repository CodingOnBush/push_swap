/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:32:05 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 14:53:53 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_apply_rotate(t_stack_node **a, t_stack_node **b, char *order)
{
	if (ft_strncmp(order, "ra", 2) == 0)
		ft_rotate(a);
	else if (ft_strncmp(order, "rb", 2) == 0)
		ft_rotate(b);
	else if (ft_strncmp(order, "rr", 2) == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

static void	ft_apply_reverse_rotate(t_stack_node **a, t_stack_node **b,
		char *order)
{
	if (ft_strncmp(order, "rra", 3) == 0)
		ft_rev_rotate(a);
	else if (ft_strncmp(order, "rrb", 3) == 0)
		ft_rev_rotate(b);
	else if (ft_strncmp(order, "rrr", 3) == 0)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
}

static void	ft_apply_swap(t_stack_node **a, t_stack_node **b, char *order)
{
	if (ft_strncmp(order, "sa", 2) == 0)
		ft_swap(a);
	else if (ft_strncmp(order, "sb", 2) == 0)
		ft_swap(b);
	else if (ft_strncmp(order, "ss", 2) == 0)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		ft_checker_error(a, b);
}

static void	ft_apply_push(t_stack_node **a, t_stack_node **b, char *order)
{
	if (ft_strncmp(order, "pa\n", 3) == 0)
		ft_push(a, b);
	else if (ft_strncmp(order, "pb\n", 3) == 0)
		ft_push(b, a);
	else
		ft_checker_error(a, b);
}

void	ft_apply_order(t_stack_node **a, t_stack_node **b, char *order)
{
	if (ft_strncmp(order, "s", 1) == 0)
		ft_apply_swap(a, b, order);
	else if (ft_strncmp(order, "p", 1) == 0)
		ft_apply_push(a, b, order);
	else if (ft_strncmp(order, "rra\n", 4) == 0)
		ft_rev_rotate(a);
	else if (ft_strncmp(order, "rrb\n", 4) == 0)
		ft_rev_rotate(b);
	else if (ft_strncmp(order, "rrr\n", 4) == 0)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
	else if (ft_strncmp(order, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(order, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(order, "rr\n", 3) == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		ft_checker_error(a, b);
}
