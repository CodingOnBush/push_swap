/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:03 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:38:04 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	char	val;

	val = (char)c;
	while (*str)
	{
		if (*str == val)
			return ((char *)str);
		str++;
	}
	if (*str == val)
		return ((char *)str);
	return (NULL);
}
