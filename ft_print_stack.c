#include "push_swap.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			ft_putchar(str[i++]);
}

static void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_putnbr(a->nb);
			a = a->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (b != NULL)
		{
			ft_putnbr(b->nb);
			b = b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar('\n');
	}
    ft_putstr("_ _\n");
    ft_putstr("a b\n");
}
