/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:39:23 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/02 20:20:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	setCost2move(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int	size_a;
	int	size_b;

	tmp_b = *b;
	size_a = stackSize(*a);
	size_b = stackSize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->idx;
		if (tmp_b->idx > getMedian(*b))
			tmp_b->cost_b = (size_b - tmp_b->idx) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > getMedian(*a))
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}