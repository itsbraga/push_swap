/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:16:14 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 22:01:19 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(t_stack **stack)
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

void    is_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		ft_free(a);
	if (b == NULL || *b != NULL)
		ft_free(b);
    write(2, "Error\n", 6);
    exit(1);
}
