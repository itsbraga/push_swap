/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/17 23:42:06 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sorted(t_stack **stack)
{
	t_stack	*node;
	
	node = *stack;
	if (!node)
		return (false);
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

void	sort_three(t_stack **a, t_stack **b);

void	sort_four(t_stack **a, t_stack **b);

void	sort_five(t_stack **a, t_stack **b);

void	sortBig(t_stack **a, t_stack **b);