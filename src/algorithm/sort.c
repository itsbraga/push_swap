/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 22:33:36 by art3mis          ###   ########.fr       */
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

void	sort_five(t_stack **a, t_stack **b);

void	sort(t_stack **a, t_stack **b);