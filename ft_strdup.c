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
