/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 23:19:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	show_stack(t_stack *node, char c)
// {
// 	t_stack			*tmp;
// 	unsigned int	idx;

// 	if (!node)
// 		return ;
// 	tmp = node;
// 	idx = 0;
// 	write(1, "\n", 1);
// 	while (tmp)
// 	{
// 		ft_printf("Stack (%d) ➔	  %d\n", idx++, tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("		  —\n");
// 	ft_printf("		  %c\n\n", c);
// }

static void	push_swap(t_stack **a, t_stack **b)
{
	int		size_a;

	size_a = stack_size(*a);
	if (!is_sorted(*a))
	{
		if (size_a == 2)
			sa(a);
		if (size_a >= 3 && size_a <= 5)
			sort_mini(a, b);
		if (size_a > 5)
			sort(a, b);
		// show_stack(*a, 'A');
		// show_stack(*b, 'B');
		clear(a);
		clear(b);
	}
	return ;
}

static int	split_case(char **argv, t_stack *a)
{
	t_stack		*b;
	int			i;

	i = -1;
	argv = ft_split(argv[1], ' ');
	if (global_check_successful(argv) == true)
	{
		a = parse_n_fill(argv);
		if (!a)
			(free_split(argv), is_error(&a, NULL));
		b = NULL;
		if (is_sorted(a) == true)
			clear(&a);
		else
			(set_pos(&a), push_swap(&a, &b));
		free_split(argv);
		return (EXIT_SUCCESS);
	}
	free_split(argv);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc < 2)
		return (ft_printf(YELLOW "Too few arguments to use this program\n",
				EXIT_FAILURE));
	if (argc == 2)
	{
		if (split_case(argv, a) == EXIT_FAILURE)
			is_error(&a, NULL);
		return (EXIT_SUCCESS);
	}
	else if (global_check_successful(argv) == true)
	{
		(argv++);
		a = parse_n_fill(argv);
		if (!a)
			is_error(&a, NULL);
		b = NULL;
		(set_pos(&a), push_swap(&a, &b));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
