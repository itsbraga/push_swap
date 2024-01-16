/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 19:47:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_idx(t_stack **stack)
{
	t_stack *tmp;
	int	i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->idx = i;
		tmp = tmp->next;
		i++;
	}
}

int	    get_target();

int	    get_target_idx();