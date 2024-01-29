/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:57:48 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/29 17:28:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void    swap(t_stack **stack)
{
    t_stack  *tmp;
    
    if (!(*stack) || !((*stack)->next))
        return ;
    tmp = (*stack);
    (*stack) = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

// swap the first two elem at the top of stack_a
void    sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

// swap the first two elem at the top of stack_b
void    sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

// swap the first two elem at the top of both stacks
void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
