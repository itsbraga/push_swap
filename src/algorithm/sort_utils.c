/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/01/18 00:28:52 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_stackSize(t_stack *stack)
{
    int size;

    size = 0;
    if (!stack)
        return (0);
    while (stack->next)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int     get_median(t_stack *stack)
{
    return (ft_stackSize(stack) / 2);
}

int	    get_target();