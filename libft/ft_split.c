/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:41:43 by momrane           #+#    #+#             */
/*   Updated: 2023/12/17 13:51:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_array(char **out, int i)
{
	while (i > 0)
	{
		i--;
		free(out[i]);
	}
	free(out);
	return (NULL);
}

static int	ft_count_words(const char *str, char sep)
{
	int	out;

	out = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str != sep && *str != '\0')
			out++;
		while (*str != sep && *str != '\0')
			str++;
	}
	return (out);
}

static int	ft_get_wlen(const char *str, char sep)
{
	if (!ft_strchr(str, sep))
		return (ft_strlen(str));
	else
		return (ft_strchr(str, sep) - str);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		wlen;
	int		i;

	out = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!out || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wlen = ft_get_wlen(s, c);
			out[i] = ft_substr(s, 0, wlen);
			if (!out[i])
				return (ft_free_array(out, i));
			i++;
			s += wlen;
		}
	}
	out[i] = NULL;
	return (out);
}

// #include <stdio.h>

// int	main(void)
// {
//  	char	**result;
// 	char	*str;
//  	int		i;

// 	str = "1 2 3 4 5";
// 	result = ft_split(str, ' ');
// 	i = 0;
//  	while (result[i] != NULL) {
//  		printf("%s\n", result[i]);
//  		i++;
//  	}
// 	ft_free_array(result, i);
// 	return (0);
// }
