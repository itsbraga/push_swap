/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:16:32 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/17 23:40:38 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    push(t_stack **stack);

// take the first elem at the top of stack_a and push it to stack_b
void    pa(t_stack **a, t_stack **b);

// take the first elem at the top of stack_b and push it to stack_a
void    pb(t_stack **a, t_stack **b);
