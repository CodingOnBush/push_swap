/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:26 by momrane           #+#    #+#             */
/*   Updated: 2023/11/16 07:51:51 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*l;

	if (!lst || !f)
		return ;
	l = lst;
	while (l != NULL)
	{
		(f)(l->content);
		l = l->next;
	}
}

// #include <stdio.h>
// 
// void init_content(void *content)
// {
// 	printf("content : %s\n", (char *)content);
// }
// 
// int main(void) {
// 	t_list *lst = ft_lstnew("salut");
// 	ft_lstadd_back(&lst, ft_lstnew("coucou"));
// 	ft_lstadd_back(&lst, ft_lstnew("bonjour"));
// 
// 	ft_lstiter(lst, &init_content);
// 	return (0);
// }