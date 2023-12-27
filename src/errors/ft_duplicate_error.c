/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:51:55 by momrane           #+#    #+#             */
/*   Updated: 2023/12/27 15:52:10 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_duplicate_error(t_node *head)
{
	ft_free_stack(&head);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
