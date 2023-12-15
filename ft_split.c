#include "push_swap.h"

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

char	**ft_split(const char *str, char sep)
{
	char	**out;
	int		wlen;
	int		i;

	out = malloc((ft_count_words(str, sep) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			wlen = ft_get_wlen(str, sep);
			out[i] = ft_substr(str, 0, wlen);
			if (!out[i])
				return (ft_free_array(out, i));
			i++;
			str += wlen;
		}
	}
	out[i] = NULL;
	return (out);
}
