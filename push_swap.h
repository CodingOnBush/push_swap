/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:53:30 by momrane           #+#    #+#             */
/*   Updated: 2023/12/15 16:35:20 by allblue          ###   ########.fr       */
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
	int				nb;
	struct s_stack	*next;
}					t_stack;

int		ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, int len);
int		ft_strlcpy(char *dest, const char *src, int size);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	**ft_split(const char *str, char sep);
void	*ft_free_array(char **out, int i);

void	ft_print_stack(t_stack *a, t_stack *b);
t_stack	*ft_create_stack(int ac, char **av);
void	ft_push_swap(t_stack *a, t_stack *b);
int		ft_atoi(char *str);
int		ft_stack_len(t_stack *s);
t_stack	*ft_new_node(int size);
void	*ft_print_error(void);
void	ft_putstr(char *str);
void	*ft_free_split(char **split);

void	*ft_push(int nb, t_stack **stack);

#endif