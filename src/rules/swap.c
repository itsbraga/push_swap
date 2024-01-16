/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:57:48 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 22:35:58 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_swap(t_stack *stack)
{
    int tmp;
    
    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
}

// swap the first two elem at the top of stack_a
void    ft_sa(t_stack **a)
{
    ft_swap(*a);
    ft_printf("sa\n");
}

// swap the first two elem at the top of stack_b
void    ft_sb(t_stack **b)
{
    ft_swap(*b);
    ft_printf("sb\n");
}

// swap the first two elem at the top of both stacks
void    ft_ss(t_stack **a, t_stack **b)
{
    ft_swap(*a);
    ft_swap(*b);
    ft_printf("ss\n");
}
