#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (!ft_isdigit(str[i]) && !ft_issign(str[i]) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
