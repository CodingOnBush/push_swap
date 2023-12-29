#include "../../inc/push_swap.h"

static void	ft_print_ok(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putstr_fd("OK\n", 1);
	exit(1);
}

static void	ft_print_ko(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putstr_fd("KO\n", 1);
	exit(1);
}

static void	ft_print_node(t_stack_node **stack)
{
	if (*stack != NULL)
	{
		ft_putnbr_fd((*stack)->nbr, 1);
		ft_putchar_fd(' ', 1);
		*stack = (*stack)->next;
	}
	else
		ft_putchar_fd(' ', 1);
}

static void	ft_print_stacks(t_stack_node *a, t_stack_node *b)
{
	ft_putstr_fd("=============================\n", 1);
	ft_putstr_fd("a : ", 1);
	while (a != NULL)
		ft_print_node(&a);
	ft_putstr_fd("\nb : ", 1);
	while (b != NULL)
		ft_print_node(&b);
	ft_putstr_fd("\n=============================\n", 1);
}

int	main(int ac, char **av)
{
	char			*line;
	t_stack_node	*a;
	t_stack_node	*b;

	// if (!ft_check_args(ac, av))
	// {
	// 	ft_putstr_fd("checker error\n", 1);
	// 	// ft_args_error();
	// 	return (0);
	// }
	b = NULL;
	a = ft_create_stack(ac, av);
	// if (!a)
	// 	ft_create_stack_error();
	if (ft_stack_sorted(a))
		ft_print_ok(&a, &b);
	line = NULL;
	// ft_print_stacks(a, b);
	while ((line = get_next_line(0)))
		ft_apply_order(&a, &b, line);
	// ft_print_stacks(a, b);
	if (ft_stack_sorted(a))
		ft_print_ok(&a, &b);
	else
		ft_print_ko(&a, &b);
	free(line);
	return (0);
}

// #include <unistd.h>  // Pour la fonction read
// #include <stdio.h>   // Pour les fonctions de la bibliothèque standard (printf, etc.)

// int main()
// {
//     char buffer[100];  // Un tampon pour stocker les données lues

//     // Utilisation de la fonction read pour lire depuis STDIN_FILENO (clavier)
//     // read renvoie le nombre d'octets lus, ou -1 en cas d'erreur
//     ssize_t bytesRead = read(0, buffer, sizeof(buffer));

//     if (bytesRead == -1) {
//         perror("Erreur lors de la lecture depuis l'entrée standard");
//         return 1;  // Code d'erreur
//     }

//     // Affichage des données lues
//     printf("Données lues depuis l'entrée standard : %.*s", (int)bytesRead, buffer);

//     return 0;  // Succès
// }
