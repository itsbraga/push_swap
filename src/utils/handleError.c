/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleError.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:16:14 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/08 20:15:34 by annabrag         ###   ########.fr       */
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

void    isError(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		clear(a);
	if (b == NULL || *b != NULL)
		clear(b);
	write(2, "Error\n", 6);
	exit(1);
}
