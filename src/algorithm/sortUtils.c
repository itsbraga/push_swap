/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/01/30 18:49:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     stackSize(t_stack *node)
{
    int size;

    size = 0;
    if (!node)
        return (0);
    while (node)
    {
        size++;
        node = node->next;
    }
    return (size);
}

int     getMedian(t_stack *node)
{
    return (stackSize(node) / 2);
}

int     findMin(t_stack *node)
{
    int min;

    if (!node)
        return (0);
    min = node->value;
    while (node)
    {
        if (node->value < min)
            min = node->value;
        node = node->next;
    }
    return (min);
}

int     getDistanceFromMin(t_stack **a, int min)
{
    t_stack *tmp;
    int     dist;
    
    tmp = *a;
    dist = 0;
    while (tmp)
    {
        if (tmp->value == min)
            break ;
        dist++;
        tmp = tmp->next;
    }
    return (dist);
}