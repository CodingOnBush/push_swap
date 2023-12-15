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
