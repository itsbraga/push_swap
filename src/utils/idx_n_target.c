/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_n_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/24 21:09:25 by annabrag         ###   ########.fr       */
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

void	get_final_idx(t_stack **stack);

/*	La target est la 'value' dans la stack_a (par rapport a la stack_b)
	le plus proche et plus grand que le 'current' dans la stack_b.
*/
int	get_target(t_stack *node_b, t_stack *node_a);

/*	Cherche l'index d'ou est situee la target dans la stack_a (selon la
	target obtenue grace a la fonction precedente).
*/
int	get_target_idx(t_stack **b, t_stack **a, int target);