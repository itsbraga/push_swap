/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/24 23:46:02 by annabrag         ###   ########.fr       */
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
    int                 final_idx;
    int                 target;
    int                 cost_a;
    int                 cost_b;
    struct s_stack     *next;
}       t_stack;

/******************************************************************************/

// Instructions
static void     swap(t_stack **stack);
void            sa(t_stack **a);
void            sb(t_stack **b);
void            ss(t_stack **a, t_stack **b);

static void     rotate(t_stack **stack);
void            ra(t_stack **a);
void            rb(t_stack **b);
void            rr(t_stack **a, t_stack **b);

static void     reverseRotate(t_stack **stack);
void            rra(t_stack **a);
void            rrb(t_stack **b);
void            rrr(t_stack **a, t_stack **b);

static void     push(t_stack **stack);
void            pa(t_stack **a, t_stack **b);
void            pb(t_stack **a, t_stack **b);

// Move costs
static int      cost2move_a(t_stack **a);
static int      cost2move_b(t_stack **b);
static int      cost2move_both(t_stack **a, t_stack **b);

// Algorithm
static void     way2five(t_stack **a, t_stack **b);
static void	    sort_three(t_stack **a, t_stack **b);
static void	    sort_four(t_stack **a, t_stack **b);
static void	    sort_five(t_stack **a, t_stack **b);
void            sortMini(t_stack **a, t_stack **b);
void            sortBig(t_stack **a, t_stack **b);
bool            is_sorted(t_stack **stack);

// Stack functions
t_stack         *ft_stackNew(int number);
t_stack         *ft_last(t_stack *node);
t_stack         *ft_beforelast(t_stack *node);
void            ft_addbottom(t_stack **stack, t_stack *new);

// Util functions
static void     ft_clear(t_stack **stack);
void            is_error(t_stack **a, t_stack **b);

int             ft_stackSize(t_stack *node);
int             get_median(t_stack *node);

void            get_idx(t_stack **stack);
void            get_final_idx(t_stack **stack);
int             get_target(t_stack *node_b, t_stack *node_a);
int             get_target_idx(t_stack **b, t_stack **a, int target);

// Parsing
static bool     is_sign(char *argv);
static bool     arg_isdigit(char *argv);
static bool     arg_iszero(char *argv);
static bool     is_duplicate(char **argv);
static bool     globalCheck(char **argv);

#endif