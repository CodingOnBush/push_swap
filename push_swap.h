/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/14 16:29:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	struct s_stack	*prev;
	int				size;
	struct s_stack	*next;
}					t_stack;

void	ft_print_stack(t_stack *a, t_stack *b);
t_stack	*ft_create_stack(int ac, char **av);
void	ft_push_swap(t_stack *a, t_stack *b);
int		ft_atoi(const char *str);
int		ft_stack_len(t_stack *s);
t_stack	*ft_new_node(int size);

#endif