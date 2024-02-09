/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleError.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:16:14 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 21:54:35 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	is_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		clear(a);
	if (b == NULL || *b != NULL)
		clear(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}
