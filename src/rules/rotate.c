/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:18:15 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/31 22:33:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void     rotate(t_stack **stack)
{
    t_stack  *tmp;
    t_stack  *last;

    if (!(*stack) || !((*stack)->next) || !((*stack)->next->next))
        return ;
    tmp = (*stack);
    (*stack) = (*stack)->next;
    last = getLast(*stack);
    tmp->next = NULL;
    last->next = tmp;
}

// rotates the elems of stack_a from one position upwards
// the first elem becomes the last one
void    ra(t_stack **a)
{
    rotate(a);
    ft_printf(BLUE "ra\n" RESET);
}

// rotates all the elems of stack_b from one position upwards
// the first elem becomes the last one
void    rb(t_stack **b)
{
    rotate(b);
    ft_printf(BLUE "rb\n" RESET);
}

// rotates all the elems of both stacks from one position upwards
// the first elem becomes the last one
void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf(BLUE "rr\n" RESET);
}
