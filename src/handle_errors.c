/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:10:47 by allblue           #+#    #+#             */
/*   Updated: 2023/12/18 08:47:14 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	error_syntax(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
	if (!a) //Check for an empty stack
		return (0);
	while (a) //Loop until the end of stack `a` is reached
	{
		if (a->nbr == n) //Check if the current node's value is equal to `n`. Refer to `init_stack_a()`
			return (1);
		a = a->next; //Move to the next node to check for duplicates
	}
	return (0);
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_node **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	ft_free_stack(a);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
