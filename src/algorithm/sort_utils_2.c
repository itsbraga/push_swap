/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 22:26:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_sorted(t_stack *node)
{
	t_stack		*tmp;

	if (!node)
		return (false);
	tmp = node;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	set_cost2move(t_stack **a, t_stack **b)
{
	t_stack		*tmp_b;
	int			size_a;
	int			size_b;

	tmp_b = *b;
	size_a = stack_size(*a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->idx;
		if (tmp_b->idx > get_median(*b))
			tmp_b->cost_b = (size_b - tmp_b->idx) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > get_median(*a))
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}
