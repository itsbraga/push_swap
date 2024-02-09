/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setElem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 22:19:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_idx(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->idx = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_pos(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	tmp = find_min(*stack);
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp->idx = -1;
		tmp->target = -1;
		tmp->cost_a = -1;
		tmp->cost_b = -1;
		tmp = find_min(*stack);
		i++;
	}
}

int	set_lowest_idx(t_stack **a)
{
	t_stack		*tmp;
	int			idx;

	tmp = *a;
	idx = 0;
	while (tmp->pos != 0)
	{
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}

/*	Cherche l'index d'ou est situee la target dans la stack_a	*/
static int	set_target_idx(t_stack **a, int pos, int target_pos, int target_idx)
{
	t_stack		*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if ((tmp_a->pos > pos) && (tmp_a->pos < target_pos))
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_pos != INT_MAX)
		return (target_idx);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->pos < target_pos)
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_idx);
}

/*	La target est la 'value' dans la stack_a (par rapport a la stack_b)
	le plus proche et plus grand que le 'current' dans la stack_b.
*/
void	get_target(t_stack **b, t_stack **a)
{
	t_stack		*tmp_b;
	int			target;

	tmp_b = *b;
	target = 0;
	while (tmp_b)
	{
		target = set_target_idx(a, tmp_b->pos, INT_MAX, target);
		tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}
