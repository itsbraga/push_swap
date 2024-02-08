/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:16:32 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/08 20:18:19 by annabrag         ###   ########.fr       */
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
void    pa(t_stack **from_b, t_stack **to_a)
{
	push(from_b, to_a);
	ft_printf(RED "pa\n" RESET);
}

// take the first elem at the top of stack_a and push it to stack_b
void    pb(t_stack **from_a, t_stack **to_b)
{
	push(from_a, to_b);
	ft_printf(RED "pb\n" RESET);
}
