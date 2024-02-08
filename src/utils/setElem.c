/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setElem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/08 20:18:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	setIdx(t_stack **stack)
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

void    setPos(t_stack **stack)
{
    t_stack    *tmp;
    int    	i;

    tmp = findMin(*stack);
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        tmp->idx = -1;
        tmp->target = -1;
        tmp->cost_a = -1;
        tmp->cost_b = -1;
        tmp = findMin(*stack);
        i++;
    }
}

int	setLowestIdx(t_stack **a)
{
	t_stack	*tmp;
	int	idx;

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
static int	setTargetIdx(t_stack **a, int pos, int targetPos, int targetIdx)
{
	t_stack	*tmp_a;
	
	tmp_a = *a;
	while (tmp_a)
	{
		if ((tmp_a->pos > pos) && (tmp_a->pos < targetPos))
		{
			targetIdx = tmp_a->idx;
			targetPos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (targetPos != INT_MAX)
		return (targetIdx);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->pos < targetPos)
		{
			targetIdx = tmp_a->idx;
			targetPos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (targetIdx);
}

/*	La target est la 'value' dans la stack_a (par rapport a la stack_b)
	le plus proche et plus grand que le 'current' dans la stack_b.
*/
void	getTarget(t_stack **b, t_stack **a)
{
	t_stack	*tmp_b;
	int	target;

	tmp_b = *b;
	target = 0;
	while (tmp_b)
	{
		target = setTargetIdx(a, tmp_b->pos, INT_MAX, target);
		tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}
