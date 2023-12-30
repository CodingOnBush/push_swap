/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 12:59:00 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

typedef struct s_stack_node
{
	long				nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// checker/
void					ft_apply_order(t_stack_node **a, t_stack_node **b,
							char *order);
// errors/
int						ft_args_error(void);
void					ft_checker_error(t_stack_node **a, t_stack_node **b);
int						ft_create_stack_error(void);
int						ft_duplicate_error(t_stack_node **head);
void					*ft_new_node_error(t_stack_node **head);
void					ft_print_error(void);
// init/
int						ft_check_duplicates(t_stack_node **head);
int						ft_check_args(int ac, char **av);
void					ft_init_a_nodes(t_stack_node *a, t_stack_node *b);
void					ft_init_b_nodes(t_stack_node *a, t_stack_node *b);
int						ft_isnumber(char *s);
int						ft_isspace(char c);
int						ft_issign(char c);
long					ft_atol(char *s);
void					ft_update_indexes(t_stack_node *stack);
// instructions/
void					ft_push(t_stack_node **dst, t_stack_node **src);
void					ft_pa(t_stack_node **a, t_stack_node **b);
void					ft_pb(t_stack_node **a, t_stack_node **b);
void					ft_rev_rotate(t_stack_node **stack);
void					ft_rra(t_stack_node **a);
void					ft_rrb(t_stack_node **b);
void					ft_rrr(t_stack_node **a, t_stack_node **b);
void					ft_rotate(t_stack_node **stack);
void					ft_ra(t_stack_node **a);
void					ft_rb(t_stack_node **b);
void					ft_rr(t_stack_node **a, t_stack_node **b);
void					ft_swap(t_stack_node **stack);
void					ft_sa(t_stack_node **a);
void					ft_sb(t_stack_node **b);
void					ft_ss(t_stack_node **a, t_stack_node **b);
// stacks/
t_stack_node			*ft_create_stack(int ac, char **av);
void					ft_little_sort(t_stack_node **a);
int						ft_stack_len(t_stack_node *stack);
t_stack_node			*ft_find_last(t_stack_node *stack);
int						ft_stack_sorted(t_stack_node *stack);
t_stack_node			*ft_find_min(t_stack_node *stack);
t_stack_node			*ft_find_max(t_stack_node *stack);
t_stack_node			*ft_get_cheapest_node(t_stack_node *stack);
void					ft_free_stack(t_stack_node **stack);
void					ft_push_node_on_top(t_stack_node **s, t_stack_node *n,
							char c);
void					ft_prep_node_for_push(t_stack_node **a,
							t_stack_node **b, t_stack_node *n, char node);
void					ft_min_on_top(t_stack_node **a);
void					ft_turk_sort(t_stack_node **a, t_stack_node **b);

#endif