#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (!ft_isdigit(*str) && !ft_issign(*str) && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
