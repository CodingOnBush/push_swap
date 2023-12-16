/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:17 by momrane           #+#    #+#             */
/*   Updated: 2023/12/16 17:38:18 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *str, unsigned int start, int len)
{
	char			*out;
	unsigned int	slen;

	if (!str)
		return (0);
	slen = ft_strlen((char *)str);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start >= (unsigned int)len)
		out = (char *)malloc((len + 1) * sizeof(char));
	else
		out = (char *)malloc((slen - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(out, (str + start), (len + 1));
	return (out);
}
