/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:24 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/17 23:39:47 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    reverseRotate(t_stack **stack)
{
    t_stack  *tmp;
    t_stack  *last;
    t_stack  *before_last;

    last = ft_last(*stack);
    before_last = ft_beforelast(*stack);
    tmp = (*stack);
    (*stack) = last;
    (*stack)->next = tmp;
    before_last->next = NULL;
}

// rotates the elems of stack_a from one position downwards
// the last elem becomes the first one
void    rra(t_stack **a)
{
    reverseRotate(a);
    ft_printf("rra\n");
}

// rotates all the elems of stack_b from one position downwards
// the last elem becomes the first one
void    rrb(t_stack **b)
{
    reverseRotate(b);
    ft_printf("rrb\n");
}

// rotates all the elems of both stacks from one position downwards
// the last elem becomes the first one
void    rrr(t_stack **a, t_stack **b)
{
    reverseRotate(a);
    reverseRotate(b);
    ft_printf("rrr\n");
}