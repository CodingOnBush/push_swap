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
	ft_putchar(' ');
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	ft_putstr("Stack A: ");
	if (a == NULL)
		ft_putstr("NULL");
	while (a != NULL)
	{
		ft_putnbr(a->size);
		a = a->next;
	}
	ft_putstr("\nStack B: ");
	if (b == NULL)
		ft_putstr("NULL");
	while (b != NULL)
	{
		ft_putnbr(b->size);
		b = b->next;
	}
	ft_putchar('\n');
}
