/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortUtils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/02 20:10:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	isSorted(t_stack *node)
{
	t_stack	*tmp;
	
	tmp = node;
	if (!tmp)
		return (false);
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

// void	putMinAtBottom(t_stack **a, t_stack **b)
// {
// 	t_stack	*min_a;
// 	t_stack	*min_b;
// 	t_stack	*tmp;

// 	min_a = findMin(*a);
// 	min_b = findMin(*b);
// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if ()
// 	}
// }