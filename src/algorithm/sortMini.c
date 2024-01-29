/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortMini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/29 21:05:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	On laisse 5 valeurs dans la stack_a en pushant le reste dans la
	stack_b pour pouvoir ensuite appeler 'sort_five'
*/
// static void	way2five(t_stack **a, t_stack **b);

static void	sortThree(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a < b) && (b < c) && (a < c))
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
	
}

// static void	sortFive(t_stack **a, t_stack **b);

void	sortMini(t_stack **a, t_stack **b)
{
	int size;

	size = stackSize(*a);
	if (size == 3)
		sortThree(a);
	else if (size == 4)
		sortFour(a, b);
}