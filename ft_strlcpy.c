#include "push_swap.h"

int	ft_strlcpy(char *dest, const char *src, int size)
{
	// int	srclen;
	int	i;

	// srclen = 0;
	i = 0;
	if (!src || !dest)
		return (0);
	// srclen = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
