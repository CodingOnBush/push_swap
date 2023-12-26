/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/26 15:16:23 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <limits.h> //To define MIN and MAX macros
# include "../libft/libft.h"
# include <stdio.h> //To use printf

typedef struct s_node //A container of data enclosed in {} braces. `s_` for struct
{
	int				nbr; //The number to sort
	int				index; //The number's position in the stack
	int				push_cost; //How many commands in total
	int				above_median; //Used to calculate `push_cost`
	int				cheapest; //The node that is the cheapest to do commands
	struct s_node	*target_node; //The target node of a node in the opposite stack
	struct s_node	*next; //A pointer to the next node
	struct s_node	*prev; //A pointer to the previous node
}	t_node; //The "shortened name", "t_node". `t_` for type

void	ft_print_error(void); //Print the error message
int	ft_check_str(char *str); //Check if the string is a number

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
t_node	*ft_get_cheapest_node(t_node *stack); //Get the cheapest node of a stack
void			prep_for_push(t_node **s, t_node *n, char c); //Prep the required nodes on top for pushing

//***Stack utils
int				ft_stack_len(t_node *stack); //Calculate the length of a stack
t_node	*ft_find_last(t_node *stack); //Find the last node of a stack
int			ft_stack_sorted(t_node *stack); //To check whether a stack is sorted
t_node	*ft_find_min(t_node *stack); //Find the smallest number
t_node	*ft_find_max(t_node *stack); //Find the biggest number
void			ft_print_stack(t_node *a, t_node *b); //Print the stacks
t_node	*ft_create_stack(int ac, char **av); //Create a stack from the arguments

//***Commands
void			ft_sa(t_node **a);
void			ft_sb(t_node **b);
void			ft_ss(t_node **a, t_node **b);
void			ft_ra(t_node **a);
void			ft_rb(t_node **b);
void			ft_rr(t_node **a, t_node **b);
void			ft_rra(t_node **a);
void			ft_rrb(t_node **b);
void			ft_rrr(t_node **a, t_node **b);
void			ft_pa(t_node **a, t_node **b);
void			ft_pb(t_node **b, t_node **a);

//***Algorithm
void			ft_sort_three(t_node **a);
void			sort_stacks(t_node **a, t_node **b); //Turk algorithm

#endif