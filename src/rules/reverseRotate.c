/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:24 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/02 20:46:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void     reverseRotate(t_stack **stack)
{
    t_stack  *tmp;
    t_stack  *last;
    t_stack  *before_last;

    if (!(*stack) || !((*stack)->next) || !((*stack)->next->next))
        return ;
    last = getLast(*stack);
    before_last = getBeforeLast(*stack);
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
    ft_printf(YELLOW "rra\n" RESET);
}

// rotates all the elems of stack_b from one position downwards
// the last elem becomes the first one
void    rrb(t_stack **b)
{
    reverseRotate(b);
    ft_printf(YELLOW "rrb\n" RESET);
}

// rotates all the elems of both stacks from one position downwards
// the last elem becomes the first one
void    rrr(t_stack **a, t_stack **b)
{
    if (stackSize(*a) > 1)
        reverseRotate(a);
    if (stackSize(*b) > 1)
        reverseRotate(b);
    ft_printf(YELLOW "rrr\n" RESET);
}

void    do_rrr(t_stack **a, t_stack **b, int *cost_b, int *cost_a)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        rrr(a, b);
    }   
}