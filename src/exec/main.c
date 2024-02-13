/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/13 21:28:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int		size_a;

	size_a = stack_size(*a);
	if (size_a <= 5 && !is_sorted(*a))
		sort_mini(a, b);
	else if (size_a > 5 && !is_sorted(*a))
		sort(a, b);
	show_stack(*a, 'A');
	show_stack(*b, 'B');
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!global_check_successful(argv))
		return (EXIT_FAILURE);
	if (argc == 2)
		split_case(argv, a);
	else if (argc > 2)
	{
		(argv++);
		a = convert_n_fill_stack(argv);
		if (!a)
			exit_error_stack(&a, NULL);
		b = NULL;
		(set_pos(&a), push_swap(&a, &b));
		(clear_stack(&a), clear_stack(&b));
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	t_stack		*a;
// 	t_stack		*b;

// 	a = NULL;
// 	if (argc < 2)
// 		return (EXIT_FAILURE));
// 	if (argc == 2)
// 	{
// 		if (split_case(argv, a) == EXIT_FAILURE)
// 			exit_error_stack(&a, NULL);
// 		return (EXIT_SUCCESS);
// 	}
// 	else if (global_check_successful(argv) == true)
// 	{
// 		(argv++);
// 		a = convert_n_fill_stack(argv);
// 		if (!a)
// 			exit_error_stack(&a, NULL);
// 		b = NULL;
// 		(set_pos(&a), push_swap(&a, &b));
// 		return (EXIT_SUCCESS);
// 	}
// 	return (EXIT_FAILURE);
// }
