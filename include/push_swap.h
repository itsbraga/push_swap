/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 22:33:09 by art3mis          ###   ########.fr       */
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

typedef enum
{
    false,
    true
}       bool;

typedef struct s_stack
{
    int                 value;
    int                 idx;
    int                 idx_sorted;
    int                 cost_a;
    int                 cost_b;
    int                 target;
    struct s_stack     *next;
}       t_stack;

/******************************************************************************/

// Instructions
void        ft_swap(t_stack *stack);
void        ft_sa(t_stack **a);
void        ft_sb(t_stack **b);
void        ft_ss(t_stack **a, t_stack **b);

void        rotate(t_stack **stack);
void        ft_ra(t_stack **a);
void        ft_rb(t_stack **b);
void        ft_rr(t_stack **a, t_stack **b);

void        reverseRotate(t_stack **stack);
void        ft_rra(t_stack **a);
void        ft_rrb(t_stack **b);
void        ft_rrr(t_stack **a, t_stack **b);

void        ft_pa(t_stack **a, t_stack **b);
void        ft_pb(t_stack **a, t_stack **b);

// Algorithm
void	    sort_five(t_stack **a, t_stack **b);
void	    sort(t_stack **a, t_stack **b);
bool	    is_sorted(t_stack **stack);

// Stack functions
t_stack     *ft_stackNew(int number);
t_stack     *ft_last(t_stack *stack);
t_stack     *ft_beforelast(t_stack *stack);
void	    ft_addbottom(t_stack **stack, t_stack *new);
void	    get_cost(t_stack **a, t_stack **b);
void	    cost2move_both(t_stack **a, t_stack **b, int cost_a, int cost_b);

// Util functions
void        ft_free(t_stack **stack);
void        is_error(t_stack **a, t_stack **b);

void        get_idx(t_stack **stack);
int	        get_target();
int	        get_target_idx();

// Parsing
bool	    is_sign(char *argv);
bool	    arg_isdigit(char *argv);

#endif