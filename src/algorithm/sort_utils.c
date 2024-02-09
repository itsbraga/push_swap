/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/02/09 22:15:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int	get_median(t_stack *node)
{
	return (stack_size(node) / 2);
}

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

/*  Find the elem with the highest content. */
// t_stack     *find_max(t_stack *node)
// {
//     t_stack *max;
//     t_stack *tmp;

//     if (!node)
//         return (NULL);
//     max = node;
//     tmp = node;
//     while (tmp)
//     {
//         if (tmp->content > max->content)
//             max = tmp;
//         tmp = tmp->next;
//     }
//     return (max);
// }

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
