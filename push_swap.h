/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 09:34:20 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_node
{
	int				nb;
	struct s_node	*next;
}					t_node;

void	ft_push_swap(t_node **a, t_node **b);

// split
int		ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, int len);
int		ft_strlcpy(char *dest, const char *src, int size);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	**ft_split(const char *str, char sep);
void	*ft_free_array(char **out, int i);

// create, check, print and free stack
void	ft_print_stack(t_node *a, t_node *b);
t_node	*ft_create_stack(int ac, char **av);
int		ft_atoi(char *str);
int		ft_stack_len(t_node *s);
t_node	*ft_new_node(int nb);
void	*ft_print_error(void);
void	ft_putstr(char *str);
void	*ft_free_split(char **split);
t_node	*ft_append(int nb, t_node **stack);
int		ft_is_sorted(t_node *stack);
int		ft_isvalid(t_node *stack);

// operations
void	ft_push_pa(t_node **a, t_node **b);
void	ft_push_pb(t_node **a, t_node **b);

void	ft_swap_sa(t_node **a);
void	ft_swap_sb(t_node **b);
void	ft_swap_ss(t_node **a, t_node **b);

void	ft_rotate_ra(t_node **a);
void	ft_rotate_rb(t_node **b);
void	ft_rotate_rr(t_node **a, t_node **b);

void	ft_reverse_rotate_rra(t_node **a);
void	ft_reverse_rotate_rrb(t_node **b);
void	ft_reverse_rotate_rrr(t_node **a, t_node **b);

#endif