/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortMini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/01 00:37:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sortThree(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (isSorted(*stack) == true)
		return ;
	else if ((a < b) && (b > c) && (a < c))
	{
		rra(stack);
		sa(stack);
	}
	else if ((a < b) && (b > c) && (a > c))
		rra(stack);
	else if ((a > b) && (b < c) && (a < c))
		sa(stack);
	else if ((a > b) && (b < c) && (a > c))
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}

// static void	sortFour(t_stack **a, t_stack **b)
// {
// 	t_stack	*min;
// 	// int	dist;

// 	min = findMin(*a);
// 	// dist = getDistanceFromMin(a, min);
// 	if (isSorted(*a) == true)
// 		return ;
// 	// if (dist <= 2 && dist != 0)
// 	// 	ra(a);
// 	// if (dist == 2)
// 	// 	ra(a);
// 	// if (dist == 3)
// 	// 	rra(a);
// 	pb(a, b);
// 	sortThree(a);
// 	pa(b, a);
// }

// static void	sortFive(t_stack **a, t_stack **b)
// {
// 	t_stack	*min;
// 	// int	dist;

// 	min = findMin(*a);
// 	// dist = getDistanceFromMin(a, min);
// 	if (isSorted(*a) == true)
// 		return ;
// 	// if (dist <= 2 && dist != 0)
// 	// 	ra(a);
// 	// if (dist == 2)
// 	// 	ra(a);
// 	// if (dist == 3 || dist == 4)
// 	// 	rra(a);
// 	// if (dist == 3)
// 	// 	rra(a);
// 	pb(a, b);
// 	sortFour(a, b);
// 	pa(b, a);
// }

void	sortMini(t_stack **a, t_stack **b)
{
	int size;

	size = stackSize(*a);
	if (size == 3)
		sortThree(a);
	(void)b;
	// if (size == 4)
	// 	sortFour(a, b);
	// if (size == 5)
	// 	sortFive(a, b);
}