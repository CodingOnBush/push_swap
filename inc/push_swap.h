/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/27 15:03:47 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//
// ├── errors
void	ft_exit_error();
void	ft_print_error();

//
// ├── init
// │   ├── ft_check_args.c
int		ft_check_args(int ac, char **av);
// │   ├── ft_init_utils.c
long	ft_atol(char *s);
int		ft_isnumber(char *s);
int		ft_issign(char c);
int		ft_isspace(char c);

//
// ├── instructions
// │   ├── ft_push.c
void	ft_pa(t_node **a, t_node **b);
void	ft_pb(t_node **a, t_node **b);
// │   ├── ft_rev_rotate.c
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);
// │   ├── ft_rotate.c
void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);
// │   ├── ft_swap.c
void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);

//
// ├── stacks
// │   ├── ft_create_stack.c
t_node	*ft_create_stack(int ac, char **av);
// │   ├── ft_print_stack.c
void	ft_print_stack(t_node *a, t_node *b);
// │   ├── ft_sort_stacks.c
void	sort_stacks(t_node **a, t_node **b);
// │   ├── ft_sort_three.c
void	ft_sort_three(t_node **a);
// │   ├── ft_stack_utils.c
int		ft_stack_len(t_node *stack);
t_node	*ft_find_last(t_node *stack);
int		ft_stack_sorted(t_node *stack);
t_node	*ft_find_min(t_node *stack);
t_node	*ft_find_max(t_node *stack);
t_node	*ft_get_cheapest_node(t_node *stack);

//***Handle errors
int				error_syntax(char *str_n); 
int				error_duplicate(t_node *a, int n);
void			ft_free_stack(t_node **stack);
void			free_errors(t_node **a);

//***Stack initiation
void			init_stack_a(t_node **a, char **argv); //Initiate stack `a` before processing
// char			**split(char *s, char c); //To handle input of numbers as a string argument, e.g. enclosed in " "

//***Nodes initiation
void			ft_init_a_nodes(t_node *a, t_node *b); //To prep all nodes for pushing `a` to `b`
void			ft_init_b_nodes(t_node *a, t_node *b); //To prep all nodes for pushing `b` back to `a`
void			ft_set_indexes(t_node *stack); //Set the node's current index
void			ft_set_cheapest(t_node *stack); //Set the stack's cheapest node
void			prep_for_push(t_node **s, t_node *n, char c); //Prep the required nodes on top for pushing

//***Algorithm

#endif