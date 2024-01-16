/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:18:15 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 19:46:43 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack  *tmp;
    t_stack  *last;

    tmp = (*stack);
    (*stack) = (*stack)->next;
    last = ft_last(*stack);
    tmp->next = NULL;
    last->next = tmp;
}

// rotates the elems of stack_a from one position upwards
// the first elem becomes the last one
void    ft_ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

// rotates all the elems of stack_b from one position upwards
// the first elem becomes the last one
void    ft_rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

// rotates all the elems of both stacks from one position upwards
// the first elem becomes the last one
void    ft_rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}