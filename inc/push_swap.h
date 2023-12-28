/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 00:18:40 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void	ft_apply_order(t_stack_node **a, t_stack_node **b, char *order);

//
// ├── errors
void	ft_new_node_error(t_stack_node *head);
void	ft_duplicate_error(t_stack_node *head);
void	ft_print_error();
void	ft_args_error();
void	ft_create_stack_error();

//
// ├── init
// │   ├── ft_check_args.c
void	ft_check_duplicates(t_stack_node *head);
int		ft_check_args(int ac, char **av);
// │   ├── ft_init_utils.c
int		ft_isnumber(char *s);
long	ft_atol(char *s);
int		ft_issign(char c);
int		ft_isspace(char c);
void	ft_update_indexes(t_stack_node *stack);

//
// ├── instructions
// │   ├── ft_push.c
void	ft_push(t_stack_node **dst, t_stack_node **src);
void	ft_pa(t_stack_node **a, t_stack_node **b);
void	ft_pb(t_stack_node **a, t_stack_node **b);
// │   ├── ft_rev_rotate.c
void	ft_rev_rotate(t_stack_node **stack);
void	ft_rra(t_stack_node **a);
void	ft_rrb(t_stack_node **b);
void	ft_rrr(t_stack_node **a, t_stack_node **b);
// │   ├── ft_rotate.c
void	ft_rotate(t_stack_node **stack);
void	ft_ra(t_stack_node **a);
void	ft_rb(t_stack_node **b);
void	ft_rr(t_stack_node **a, t_stack_node **b);
// │   ├── ft_swap.c
void	ft_swap(t_stack_node **stack);
void	ft_sa(t_stack_node **a);
void	ft_sb(t_stack_node **b);
void	ft_ss(t_stack_node **a, t_stack_node **b);

//
// ├── stacks
// │   ├── ft_create_stack.c
t_stack_node	*ft_create_stack(int ac, char **av);
// │   ├── ft_sort_stacks.c
void	ft_turk_sort(t_stack_node **a, t_stack_node **b);
// │   ├── ft_little_sort.c
void	ft_little_sort(t_stack_node **a);
// │   ├── ft_stack_utils.c
int		ft_stack_len(t_stack_node *stack);
t_stack_node	*ft_find_last(t_stack_node *stack);
int		ft_stack_sorted(t_stack_node *stack);
t_stack_node	*ft_find_min(t_stack_node *stack);
t_stack_node	*ft_find_max(t_stack_node *stack);
t_stack_node	*ft_get_cheapest_node(t_stack_node *stack);
void	ft_free_stack(t_stack_node **stack);

//***Nodes initiation
void			ft_init_a_nodes(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `a` to `b`
void			ft_init_b_nodes(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `b` back to `a`
void			ft_update_indexes(t_stack_node *stack); //Set the node's current index
void			ft_push_node_on_top(t_stack_node **s, t_stack_node *n, char c); //Prep the required nodes on top for pushing

//***Algorithm

#endif