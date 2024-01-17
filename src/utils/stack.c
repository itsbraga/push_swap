/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:04:08 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/18 00:26:04 by panther          ###   ########.fr       */
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
	new->idx_sorted = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->target = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_beforelast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next && stack->next->next == NULL)
		stack = stack->next;
	return (stack);
}

void	ft_addbottom(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = ft_last(*stack);
		tmp->next = new;
	}
	else
		*stack = new;
}

void	get_cost(t_stack **a, t_stack **b);