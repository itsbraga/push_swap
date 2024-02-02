/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:21:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/02 20:51:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	setAbs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

static void	last_ra(t_stack **a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(a);
			cost_a--;
		}
		else
		{
			rra(a);
			cost_a++;
		}
	}
}

static void	last_rb(t_stack **b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rb(b);
			cost_b--;
		}
		else
		{
			rrb(b);
			cost_b++;
		}
	}
}	

static void	execMoves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	do_rrr(a, b, &cost_a, &cost_b);
	do_rr(a, b, &cost_a, &cost_b);
	last_ra(a, cost_a);
	last_rb(b, cost_b);
	pa(b, a);
}

void	cheapestMove(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int	costMax;
	int	cost_a;
	int	cost_b;

	(void)a;
	tmp_b = *b;
	costMax = INT_MAX;
	while (tmp_b)
	{
		if (setAbs(tmp_b->cost_a) + setAbs(tmp_b->cost_b) < costMax)
		{
			costMax = setAbs(tmp_b->cost_a) + setAbs(tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	execMoves(a, b, cost_a, cost_b);
}