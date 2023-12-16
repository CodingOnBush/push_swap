/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:08 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:38:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *str)
{
	char	*out;
	int		len;

	len = ft_strlen(str) + 1;
	out = malloc(len);
	if (!out)
		return (NULL);
	ft_strlcpy(out, str, len);
	return (out);
}
