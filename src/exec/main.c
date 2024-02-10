/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/10 18:45:01 by art3mis          ###   ########.fr       */
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
	// show_stack(*a, 'A');
	// show_stack(*b, 'B');
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!global_check_successful(argv))
		is_error(NULL, NULL);
	if (argc == 2)
		split_case(argv, a);
	else if (argc > 2)
	{
		(argv++);
		a = parse_n_fill(argv);
		if (!a)
			is_error(&a, NULL);
		b = NULL;
		(set_pos(&a), push_swap(&a, &b), clear(&a), clear(&b));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

// int	main(int argc, char **argv)
// {
// 	t_stack		*a;
// 	t_stack		*b;

// 	a = NULL;
// 	if (argc < 2)
// 		return (ft_printf(YELLOW "Too few arguments to use this program\n",
// 				EXIT_FAILURE));
// 	if (argc == 2)
// 	{
// 		if (split_case(argv, a) == EXIT_FAILURE)
// 			is_error(&a, NULL);
// 		return (EXIT_SUCCESS);
// 	}
// 	else if (global_check_successful(argv) == true)
// 	{
// 		(argv++);
// 		a = parse_n_fill(argv);
// 		if (!a)
// 			is_error(&a, NULL);
// 		b = NULL;
// 		(set_pos(&a), push_swap(&a, &b));
// 		return (EXIT_SUCCESS);
// 	}
// 	return (EXIT_FAILURE);
// }
