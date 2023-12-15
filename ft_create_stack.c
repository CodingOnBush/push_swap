#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isnumber(char *str)
{
	int	out;

	out = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isdigit(*str))
			out = 1;
		str++;
	}
	return (out);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	t_stack	*out;
	char	**tmp;
	int		i;

	i = 1;
	out = NULL;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (NULL);
		while (*tmp)
		{
			if (!ft_isnumber(*tmp) || !ft_push(ft_atoi(*tmp), &out))
			{
				ft_putstr("Error\n");
				return (ft_free_split(tmp));
			}
			tmp++;
		}
		i++;
	}
	return (out);
}
