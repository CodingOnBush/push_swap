/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:06:09 by momrane           #+#    #+#             */
/*   Updated: 2023/12/29 15:37:34 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	char			*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char s[] = "Hello, World!";
// 	char c = 'W';
// 	char *res = ft_strchr(s, c);

// 	printf("s: %s\n", s);
// 	if (res != NULL)
// 		printf("'%c' trouvé à la position : %ld\n", c, res - s);
// 	else
// 		printf("'%c' pas trouvé dans la chaîne\n", c);

// 	return (0);
// }