/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortMini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/06 18:01:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	sortThree(t_stack **stack)
// {
// 	t_stack	*min;
// 	t_stack	*max;

// 	if (!(*stack))
// 		return ;
// 	min = findMin(*stack);
// 	if (!min)
// 	{
// 		printf("min est nul\n");
// 		return ;
// 	}
// 	max = findMax(*stack);
// 	if (!max)
// 		return ;
// 	// if (isSorted(*stack) == true)
// 	// 	return ;
// 	if ((*stack)->content == max->content)
// 		ra(stack);
// 	if ((*stack)->content < (*stack)->next->content
// 		&& ((*stack)->next->content == max->content))
// 		rra(stack);
// 	if ((*stack)->content != min->content)
// 		sa(stack);
// }

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

static void	sortFour(t_stack **a, t_stack **b)
{
	int	min;
	int	dist;

	min = findMinContent(*a);
	// if (!min)
	// 	return ;
	dist = getDistanceFromMin(a, min);
	if (dist <= 2 && dist != 0)
		ra(a);
	if (dist == 2)
		ra(a);
	if (dist == 3)
		rra(a);
	if (isSorted(*a) == true)
		return ;
	pb(a, b);
	sortThree(a);
	pa(b, a);
}

static void	sortFive(t_stack **a, t_stack **b)
{
	int	min;
	int	dist;

	min = findMinContent(*a);
	// if (!min)
	// 	return ;
	dist = getDistanceFromMin(a, min);
	if (isSorted(*a) == true)
		return ;
	if (dist <= 2 && dist != 0)
		ra(a);
	if (dist == 2)
		ra(a);
	if (dist == 3 || dist == 4)
		rra(a);
	if (dist == 3)
		rra(a);
	pb(a, b);
	sortFour(a, b);
	pa(b, a);
}

void	sortMini(t_stack **a, t_stack **b)
{
	int size;

	size = stackSize(*a);
	if (size == 3)
		sortThree(a);
	if (size == 4)
		sortFour(a, b);
	if (size == 5)
		sortFive(a, b);
}