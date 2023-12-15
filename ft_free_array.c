#include "push_swap.h"

void	*ft_free_array(char **out, int i)
{
	while (i > 0)
	{
		i--;
		free(out[i]);
	}
	free(out);
	return (NULL);
}
