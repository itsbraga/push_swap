/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:39:23 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/29 19:58:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Par rapport a la mediane, quel est le mouvement le moins couteux
	a bouger dans a ?
	Les mouvements au-dessus de la mediane seront positifs et entraineront
	un mouvement de type vers le haut (ex: sa, ra).
	Les mouvements en-dessous de la mediane seront negatifs et entraineront
	un mouvement de type vers le bas (ex: rra).
*/
int	cost2move_a(t_stack **a)
{
	int	med;

	med = getMedian(*a);
	return 0;
	
}

/*	Par rapport a la mediane, quel est le mouvement le moins couteux
	a bouger dans b ?
	Les mouvements au-dessus de la mediane seront positifs et entraineront
	un mouvement de type vers le haut (ex: sb, rb).
	Les mouvements en-dessous de la mediane seront negatifs et entraineront
	un mouvement de type vers le bas (ex: rrb).
*/
int	cost2move_b(t_stack **b);

/*	Par rapport a la mediane, quelle est la paire de 'value' dans a et b
	les moins couteux a deplacer, toujours par rapport a la mediane ?
	autrement dit, il s'agit du cas : (cost_a + cost_b)
*/
int	cost2move_both(t_stack **a, t_stack **b);