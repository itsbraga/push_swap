/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/13 23:49:01 by annabrag         ###   ########.fr       */
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
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		(argv++);
	if (!global_check_successful(argv))
		return (free_split(argc, argv), 1);
	a = convert_n_fill_stack(argc, argv);
	if (!a)
		exit_error_stack(&a, NULL, argc, argv);
	b = NULL;
	(set_pos(&a), push_swap(&a, &b));
	(clear_stack(&a), clear_stack(&b));
	free_split(argc, argv);
	return (EXIT_SUCCESS);
}
