/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:04:08 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/24 21:16:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stackNew(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = number;
	new->idx = 0;
	new->final_idx = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->target = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*ft_beforelast(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next && node->next->next == NULL)
		node = node->next;
	return (node);
}

void	ft_addbottom(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = ft_last(*stack);
		tmp->next = new_node;
	}
	else
		*stack = new_node;
}