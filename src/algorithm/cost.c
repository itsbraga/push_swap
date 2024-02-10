/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/10 18:01:33 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	set_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

/*	Calculates the cost of moving each elem of stack B into the correct
*	position in stack A.
*	
*	cost_b represents the cost of getting the elem to the top of the B stack
*	cost_a represents the cost of getting to the right position in stack A.
*
*	If the elem is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive.
*/
void	get_cost2move(t_stack **a, t_stack **b)
{
	t_stack		*tmp_b;
	int			size_a;
	int			size_b;
	int			median_a;
	int			median_b;

	tmp_b = *b;
	size_a = stack_size(*a);
	size_b = stack_size(tmp_b);
	median_a = size_a / 2;
	median_b = size_b / 2;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->idx;
		if (tmp_b->idx > median_b)
			tmp_b->cost_b = (size_b - tmp_b->idx) * -1;
		tmp_b->cost_a = tmp_b->target_idx;
		if (tmp_b->target_idx > median_a)
			tmp_b->cost_a = (size_a - tmp_b->target_idx) * -1;
		tmp_b = tmp_b->next;
	}
}

void	lower_cost_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		lower_cost;
	int		cost_a;
	int		cost_b;

	tmp_b = *b;
	lower_cost = INT_MAX;
	while (tmp_b)
	{
		if (set_abs(tmp_b->cost_a) + set_abs(tmp_b->cost_b) < set_abs(lower_cost))
		{
			lower_cost = set_abs(tmp_b->cost_a) + set_abs(tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	exec_move(a, b, cost_a, cost_b);
}
