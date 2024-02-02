/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:15 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/02 21:55:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	On laisse 5 valeurs dans la stack_a en pushant le reste dans la
	stack_b pour pouvoir ensuite appeler 'sort_five'
*/
static void	way2five(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stackSize(*a);
	while (size_a > 5)
	{
		if ((*a) < findMin(*b))
			rrb(b);
		pb(a, b);
		size_a--;	
	}
	sortMini(a, b);
}

// void	finalSort(t_stack **a)
// {
// 	int	lowest_idx;
// 	int	size;
	
// 	lowest_idx = 
// 	size = stackSize(*a);
// }

/*	Means that we sort nodes above five	*/
void	sort(t_stack **a, t_stack **b)
{
	way2five(a, b);
	while (*b)
	{
		setIdx(a);
		setIdx(b);
		getTarget(b, a);
		setCost2move(a, b);
		cheapestMove(a, b);
	}
	if (isSorted(*a) == false)
		finalSort(a);
}