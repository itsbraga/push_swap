/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 22:26:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

/******************************************************************************/

typedef enum Bool
{
	false,
	true
}		t_bool;

// idx est la ou est situe la valeur dans la stack
// pos est la ou doit etre situee la valeur apres le tri
typedef struct s_stack
{
	int				content;
	int				idx;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/******************************************************************************/

/*  Instructions    */
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		do_rr(t_stack **a, t_stack **b, int *cost_b, int *cost_a);

void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		do_rrr(t_stack **a, t_stack **b, int *cost_b, int *cost_a);

void		pa(t_stack **from_b, t_stack **to_a);
void		pb(t_stack **from_a, t_stack **to_b);

/*  Costs and Moves  */
void		set_cost2move(t_stack **a, t_stack **b);
void		cheapest_move(t_stack **a, t_stack **b);

/*  Algorithm   */
void		sort_mini(t_stack **a, t_stack **b);
void		sort(t_stack **a, t_stack **b);
t_bool		is_sorted(t_stack *node);

/*  Stack handler   */
t_stack		*stack_new(int number);
t_stack		*get_last(t_stack *node);
t_stack		*get_before_last(t_stack *node);
void		add2bottom(t_stack **stack, t_stack *new);

/*  Protection functions    */
void		clear(t_stack **stack);
void		is_error(t_stack **a, t_stack **b);
void		free_split(char **argv);

/*  Util functions  */
int			stack_size(t_stack *node);
int			get_median(t_stack *node);
t_stack		*find_min(t_stack *node);
int			find_min_content(t_stack *node);
t_stack		*find_max(t_stack *node);
int			get_distance_from_min(t_stack **a, int min);

void		set_idx(t_stack **stack);
void		set_pos(t_stack **stack);
int			set_lowest_idx(t_stack **a);
void		get_target(t_stack **b, t_stack **a);

/*  Check args and parse    */
t_bool		have_duplicate(char **argv);
t_bool		global_check_successful(char **argv);

t_stack		*parse_n_fill(char **argv);

#endif