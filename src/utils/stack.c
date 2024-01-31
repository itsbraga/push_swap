/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:04:08 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/31 22:27:40 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stackNew(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = number;
	new->idx = 0;
	new->final_idx = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->target = -1;
	new->next = NULL;
	return (new);
}

t_stack	*getLast(t_stack *node)
{
	t_stack *tmp;

	tmp = node;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*getBeforeLast(t_stack *node)
{
	t_stack *tmp;

	tmp = node;
	if (!tmp)
		return (NULL);
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	addBottom(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = getLast(*stack);
		tmp->next = new_node;
	}
	else
		*stack = new_node;
}