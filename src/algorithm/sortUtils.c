/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/01/29 19:58:19 by annabrag         ###   ########.fr       */
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