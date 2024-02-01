/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/02/01 23:30:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     stackSize(t_stack *node)
{
    int size;

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

int     getMedian(t_stack *node)
{
    return (stackSize(node) / 2);
}
/*  Find the elem with the smallest content. */
t_stack     *findMin(t_stack *node)
{
    int     tmp;
    int     min;
    t_stack *minValue;

    if (!node)
        return (NULL);
    tmp = 0;
    min = INT_MAX;
    minValue = NULL;
    while (node)
    {
        if ((node->pos == -1) && (!tmp || node->content < min))
        {
            min = node->content;
            minValue = node;
            tmp = 1;
        }
        node = node->next;
    }
    return (minValue);
}

/*  Find the elem with the highest content. */
t_stack     *findMax(t_stack *node)
{
    t_stack *max;
    t_stack *tmp;

    if (!node)
        return (NULL);
    max = node;
    tmp = node;
    while (tmp)
    {
        if (tmp->content > max->content)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

int     getDistanceFromMin(t_stack **a, int min)
{
    t_stack *tmp;
    int     dist;
    
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