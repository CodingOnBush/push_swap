/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:12 by momrane           #+#    #+#             */
/*   Updated: 2023/12/30 14:47:55 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}					t_node;

char	*get_next_line(int fd);
int		ft_createlst(int fd, t_node **lst);
void	ft_lstappend(t_node **lst, char *buff);
void	ft_update_lst(t_node **lst);
void	*ft_freelst(t_node **lst);
char	*ft_create_str(t_node *lst);
char	*ft_get_after_nl(char *str);
char	*ft_strchr(char *s, char c);
int		ft_get_len(t_node *lst);
int		ft_lstchr(t_node *lst);

#endif