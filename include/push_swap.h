/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/17 23:58:03 by panther          ###   ########.fr       */
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
void        swap(t_stack *stack);
void        sa(t_stack **a);
void        sb(t_stack **b);
void        ss(t_stack **a, t_stack **b);

void        rotate(t_stack **stack);
void        ra(t_stack **a);
void        rb(t_stack **b);
void        rr(t_stack **a, t_stack **b);

void        reverseRotate(t_stack **stack);
void        rra(t_stack **a);
void        rrb(t_stack **b);
void        rrr(t_stack **a, t_stack **b);

void        push(t_stack **stack);
void        pa(t_stack **a, t_stack **b);
void        pb(t_stack **a, t_stack **b);

// Algorithm
void	    sort_three(t_stack **a, t_stack **b);
void	    sort_four(t_stack **a, t_stack **b);
void	    sort_five(t_stack **a, t_stack **b);
void	    sortBig(t_stack **a, t_stack **b);
bool	    is_sorted(t_stack **stack);

// Stack functions
t_stack     *ft_stackNew(int number);
t_stack     *ft_last(t_stack *stack);
t_stack     *ft_beforelast(t_stack *stack);
void	    ft_addbottom(t_stack **stack, t_stack *new);
void	    get_cost(t_stack **a, t_stack **b);

// Util functions
void        ft_clear(t_stack **stack);
void        is_error(t_stack **a, t_stack **b);

void        get_idx(t_stack **stack);
int	        get_target();
int	        get_target_idx();

// Parsing
bool	    is_sign(char *argv);
bool	    arg_isdigit(char *argv);

#endif