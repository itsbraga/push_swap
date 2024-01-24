/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/01/24 21:12:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_stackSize(t_stack *node)
{
    int size;

    size = 0;
    if (!node)
        return (0);
    while (node->next)
    {
        size++;
        node = node->next;
    }
    return (size);
}

int     get_median(t_stack *node)
{
    return (ft_stackSize(node) / 2);
}

int     get_min(t_stack *node)
{
    
}