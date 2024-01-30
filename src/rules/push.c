/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:16:32 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/30 17:57:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void    push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

// take the first elem at the top of stack_b and push it to stack_a
void    pa(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_printf(RED "pa\n" RESET);
}

// take the first elem at the top of stack_a and push it to stack_b
void    pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf(RED "pb\n" RESET);
}
