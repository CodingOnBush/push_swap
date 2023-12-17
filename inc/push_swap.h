/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 15:17:33 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_node
{
	int				nb;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

void	*ft_append_node(t_node **stack, int nb);
t_node	*ft_append(int nb, t_node **stack);
t_node	*ft_create_stack(int ac, char **av);
void	*ft_free_array(char **out, int i);
void	*ft_free_split(char **split);
void	ft_free_stack(t_node **a);
t_node	*ft_get_biggest(t_node *stack);
void	ft_get_cost_a(t_node *a, t_node *b);
void	ft_get_current_index(t_node *stack);
void	ft_init_nodes_a(t_node **a, t_node **b);
int		ft_is_sorted(t_node *stack);
int		ft_isvalid(t_node *stack);
t_node	*ft_new_node(int nb);
void	*ft_print_error(void);
void	ft_print_stack(t_node *a, t_node *b);
void	ft_push_pa(t_node **a, t_node **b);
void	ft_push_pb(t_node **a, t_node **b);
void	ft_reverse_rotate_rra(t_node **a);
void	ft_reverse_rotate_rrb(t_node **b);
void	ft_reverse_rotate_rrr(t_node **a, t_node **b);
void	ft_rotate_ra(t_node **a);
void	ft_rotate_rb(t_node **b);
void	ft_rotate_rr(t_node **a, t_node **b);
void	ft_set_cheapest(t_node *stack);
void	ft_set_target_a(t_node *a, t_node *b);
void	ft_sort_four(t_node **a, t_node **b);
void	ft_sort_three(t_node **a);
void	ft_sort_turk(t_node **a, t_node **b);
int		ft_stack_len(t_node *s);
void	ft_swap_sa(t_node **a);
void	ft_swap_sb(t_node **b);
void	ft_swap_ss(t_node **a, t_node **b);
void	ft_push_swap(t_node **a, t_node **b);

#endif