/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/24 23:44:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	On laisse 5 valeurs dans la stack_a en pushant le reste dans la
	stack_b pour pouvoir ensuite appeler 'sort_five'
*/
static void	way2five(t_stack **a, t_stack **b);

static void	sort_three(t_stack **a, t_stack **b)
{
	
}

static void	sort_four(t_stack **a, t_stack **b);

static void	sort_five(t_stack **a, t_stack **b);

void	sortMini(t_stack **a, t_stack **b);