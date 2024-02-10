/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/02/10 18:44:53 by art3mis          ###   ########.fr       */
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

// t_stack     *find_min(t_stack *node)
// {
//     t_stack *min;
//     t_stack *tmp;

//     if (!node)
//         return (NULL);
//     min = node;
//     tmp = node;
//     while (tmp)
//     {
//         if (tmp->content < min->content)
//             min = tmp;
//         tmp = tmp->next;
//     }
//     return (min);
// }
//
// int	get_min_idx(t_stack *node)
// {
// 	t_stack	*tmp;

// 	tmp = node;
// 	while (find_min(node)->content != tmp->content)
// 		tmp = tmp->next;
// 	return (tmp->idx);
// }

/*  Find the elem with the smallest content. */
t_stack	*find_min(t_stack *node)
{
	int		tmp;
	int		min;
	t_stack	*min_node;

	if (!node)
		return (NULL);
	tmp = 0;
	min = INT_MAX;
	min_node = NULL;
	while (node)
	{
		if ((node->pos == -1) && (!tmp || node->content < min))
		{
			min = node->content;
			min_node = node;
			tmp = 1;
		}
		node = node->next;
	}
	return (min_node);
}

int	find_min_content(t_stack *node)
{
	int	min;

	if (!node)
		return (0);
	min = node->content;
	while (node)
	{
		if (min > node->content)
			min = node->content;
		node = node->next;
	}
	return (min);
}

// int	find_max_content(t_stack *node)
// {
// 	int	max;

// 	if (!node)
// 		return (0);
// 	max = node->content;
// 	while (node)
// 	{
// 		if (max < node->content)
// 			max = node->content;
// 		node = node->next;
// 	}
// 	return (max);
// }

/*	A is scanned until a minimum value (min) is found and calculates
*	the distance of that elem from the top of the stack.
*/
int	get_distance_from_min(t_stack **a, int min)
{
	t_stack	*tmp;
	int		dist;

	if (!a)
		return (0);
	tmp = *a;
	dist = 0;
	while (tmp)
	{
		if (tmp->content == min)
			break ;
		dist++;
		tmp = tmp->next;
	}
	return (dist);
}
