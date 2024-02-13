/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:24 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/13 16:34:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*last;
	t_stack		*before_last;

	if (stack_size(*stack) < 2)
		return ;
	last = get_last(*stack);
	before_last = get_before_last(*stack);
	tmp = (*stack);
	(*stack) = last;
	(*stack)->next = tmp;
	before_last->next = NULL;
}

// rotates the elems of stack_a from one position downwards
// the last elem becomes the first one
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// rotates all the elems of stack_b from one position downwards
// the last elem becomes the first one
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// rotates all the elems of both stacks from one position downwards
// the last elem becomes the first one
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
