/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:28 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:38:29 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	if (ac < 2)
		return (0);
	a = ft_create_stack(ac, av);
	if (!a || ft_is_sorted(a) || !ft_isvalid(a))
		return (0);
	b = NULL;
	ft_print_stack(a, b);
	ft_push_swap(&a, &b);
	ft_print_stack(a, b);
	ft_free_stack(&a);
	return (0);
}
