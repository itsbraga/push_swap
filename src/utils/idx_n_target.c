/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_n_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/29 19:58:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	getIdx(t_stack **stack)
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

void	getFinalIdx(t_stack **stack);

/*	La target est la 'value' dans la stack_a (par rapport a la stack_b)
	le plus proche et plus grand que le 'current' dans la stack_b.
*/
int	getTarget(t_stack *node_b, t_stack *node_a);

/*	Cherche l'index d'ou est situee la target dans la stack_a (selon la
	target obtenue grace a la fonction precedente).
*/
int	getTargetIdx(t_stack **b, t_stack **a, int target);