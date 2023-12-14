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
	long int nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if ((nb / 10) > 0)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	ft_putstr("Stack A: ");
	while (a)
	{
		ft_putnbr(a->size);
		ft_putchar(' ');
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("Stack B: ");
	while (b)
	{
		ft_putnbr(b->size);
		ft_putchar(' ');
		b = b->next;
	}
	ft_putchar('\n');
}
