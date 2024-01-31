/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/01 00:36:15 by art3mis          ###   ########.fr       */
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
    int                 content;
    int                 idx;
    int                 final_idx;
    int                 target;
    int                 cost_a;
    int                 cost_b;
    struct s_stack     *next;
}               t_stack;

/******************************************************************************/

/*  Instructions    */
void        sa(t_stack **a);
void        sb(t_stack **b);
void        ss(t_stack **a, t_stack **b);

void        ra(t_stack **a);
void        rb(t_stack **b);
void        rr(t_stack **a, t_stack **b);

void        rra(t_stack **a);
void        rrb(t_stack **b);
void        rrr(t_stack **a, t_stack **b);

void        pa(t_stack **b, t_stack **a);
void        pb(t_stack **a, t_stack **b);

/*  Costs   */
void        getCost2move(t_stack **a, t_stack **b);

/*  Algorithm   */
// void     way2five(t_stack **a, t_stack **b);
void        sortMini(t_stack **a, t_stack **b);
void        sort(t_stack **a, t_stack **b);
bool        isSorted(t_stack *node);

/*  Stack handler   */
t_stack     *stackNew(int number);
t_stack     *getLast(t_stack *node);
t_stack     *getBeforeLast(t_stack *node);
void        addBottom(t_stack **stack, t_stack *new);

/*  Protection functions    */
void        clear(t_stack **stack);
void        isError(t_stack **a, t_stack **b);

/*  Util functions  */
int         stackSize(t_stack *node);
int         getMedian(t_stack *node);
t_stack     *findMin(t_stack *node);
t_stack     *findMax(t_stack *node);
int         getDistanceFromMin(t_stack **a, int min);

void        getIdx(t_stack **stack);
void        getFinalIdx(t_stack **stack);
int         getTarget(t_stack *node_b, t_stack *node_a);
int         getTargetIdx(t_stack **b, t_stack **a, int target);

/*  Check args and parse    */
bool        haveDuplicate(char **argv);
bool        globalCheckIsSuccess(char **argv);

t_stack     *ParseAndFill(int argc, char *argv);

#endif