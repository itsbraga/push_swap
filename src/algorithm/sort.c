/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:15 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/09 22:11:16 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	On laisse 5 valeurs dans la stack_a en pushant le reste dans la
	stack_b pour pouvoir ensuite appeler 'sort_five'
*/
static void	way2five(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	while (size_a > 5)
	{
		if ((*a) < find_min(*b))
			rrb(b);
		pb(a, b);
		size_a--;
	}
	sort_mini(a, b);
}

static void	final_sort(t_stack **a)
{
	int	lowest_idx;
	int	size;

	lowest_idx = set_lowest_idx(a);
	size = stack_size(*a);
	if (lowest_idx > get_median(*a))
	{
		while (lowest_idx < size)
		{
			rra(a);
			lowest_idx++;
		}
	}
	else
	{
		while (lowest_idx > 0)
		{
			ra(a);
			lowest_idx--;
		}
	}
}

/*	Means that we sort nodes above five	*/
void	sort(t_stack **a, t_stack **b)
{
	way2five(a, b);
	while (*b)
	{
		set_idx(a);
		set_idx(b);
		get_target(b, a);
		set_cost2move(a, b);
		cheapest_move(a, b);
	}
	if (is_sorted(*a) == false)
		final_sort(a);
}
